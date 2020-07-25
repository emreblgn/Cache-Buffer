# Simple Cache Buffer Design

Implementation of a cache buffer system that use doubly linked list using language C.

**The program has 4 main part:**

1. Implementation of double linked list nodes and data structure.</h3>

   - Every node keeps adress of the page, total request count, pointer of the previous node and pointer of the next node.

2. Solution of the given operation with using doubly linked list.
   - Reading input.
   - Processing input.
     - If input address already exist in cache buffer its request count increase by 1. If its request count is bigger than threshold value 't' node will be moved to head node.
   - Controlling cache buffer.
     - Cache buffer has a capacity 'l' if this capacity is exceeded last node will be deleted.

3. Repeating 2nd part for every request.

4. Clearing the buffer.
   - User can ask for clear the cache and stop the program.

**Sample Inputs and Outputs**

![](/images/input-1.png)

![](/images/input-2.png)





