#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char address[10];
	int count;
	struct node *prev;
	struct node *next;
};

typedef struct node NODE;
static NODE *head;
static NODE *last;
int t;
int l;

NODE *newNode();				// Create a new node structure and return it.
int addressAvailable(NODE*);	// Return 1 if address of the node is already available, 0 if not. 
NODE *findAddress(NODE*);		// Find address in linked list and return its node. 
void setHead(NODE*);			// Set selected node to head node.
void *addNodeToList(NODE*);		// Add selected node to list.
void lengthControl();			// Control the length of the linked list.
void countControl(NODE*);		// Control count variable of the selected node.
void clearCache();				// Clear the cache.

int main(){
	
	printf("Enter t value: ");
	scanf("%d", &t);
	printf("Enter l value: ");
	scanf("%d", &l);
	NODE *p;
	printf("Please enter the addresses one by one, if you want to stop the program and clear the cache enter 'STOP'\n");
	while(1){
		p = newNode();
		scanf("%s", p->address);
		
		if(strcmp(p->address, "STOP") == 0){
			clearCache();
			return 0;
		}
		
		addNodeToList(p);
		countControl(p);
		lengthControl();

		for(p=head; p!=NULL; p=p->next){
			
			if(p==head){
				printf("%s,%d ",p->address, p->count);
			}
			else{
				printf("<=> %s,%d ",p->address, p->count);
			}
		}
		printf("\n");
	}
	return 0;
}

NODE *newNode(){
	
	NODE *p;
	p = (NODE*) malloc (sizeof(NODE));
	if(p == NULL){
		printf("Malloc failed.\n");
		exit(1);
	}
	p->count = 1;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

int addressAvailable(NODE *e){
	
	NODE *p;
	for(p = head; p->next != NULL; p=p->next){
		if(strcmp(e->address, p->address) == 0){
			return 1;
		}
	}
	if(strcmp(e->address, p->address) == 0){
			return 1;
		}
	return 0;
}

NODE *findAddress(NODE *e){
	
	NODE *p;
	for(p = head; p->next != NULL; p=p->next){
		if(strcmp(e->address, p->address) == 0){
			return p;
		}
	}
	return p;
}

void setHead(NODE *e){
	if(head == e){
		return;
	}
	if(e->next != NULL){
		e->next->prev = e->prev;
	}
	e->prev->next = e->next;
	e->prev = NULL;
	e->next = head;
	head->prev = e;
	head = e;
}

void *addNodeToList(NODE *e){
	if(head == NULL){
		head = e;
		return;
	}
	if(addressAvailable(e)){
		
		NODE *p;
		p = findAddress(e);
		p->count++;
		e->count = p->count;
		
	}else{
	e->next = head;
	head->prev = e;
	head = e;
	}
}

void lengthControl(){
	
	NODE *p;
	int i = 1;
	
	for(p = head; p->next != NULL; p = p->next){
		i++;
	}
	
	if(i>l){
		p->prev->next = p->next;
		free(p);
	}
}

void countControl(NODE *e){

	NODE *p = head;
	int found = 0;
	while(p != NULL && found == 0){
		
		if(strcmp(e->address, p->address) == 0  && e->count > t){
			found = 1;
			setHead(p);
			free(e);
		}
		p = p->next;
	}
}

void clearCache(){
	
	NODE *p;
	for(p = head; p->next != NULL; p = p->next){
		free(p);
	}
	printf("Cache cleared.");
}
