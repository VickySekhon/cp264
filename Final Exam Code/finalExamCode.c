// breadth/depth-first traversal/search on binary trees and graphs, and applications, in adjacency matrix representations. 
void depthFirstSearchGraph(int adj[][MAX], int visited, int start) {
	int stack[MAX], top = -1; 
	printf("%d", start); 
	visited[start] = 1; // visit a vertex 
	stack[++top] = start; // add it to the stack 
	while (top != -1) { 
		start = stack[top]; 
		for (i = 0, i<MAX, i++){ // look through every value in the row 
			if (adj[start][i] && visited[i] == 0){ 
				stack[++top] = i; 
				printf("%d", i);
				visited[i] = 1; 
				break; 
			}
		}
		if (i==MAX) top--; 
	}
	return; 
}  

void depthfirstgrpah(int adj[][MAX], int visited, int start) {
	int stack[MAX], top = -1, i; 
	stack[++top] = start;
	printf("%d", start);
	visited[start] = 1;

	while (top != -1) {
		start = stack[top];
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				stack[++top] = i; 
				printf("%d", i);
				visited[i] = 1; 
				break;
			}
		}
		if (i == MAX) top--;  
	}
}

void depthFirstSearchGraph2(int adj[][MAX], int visited, int start){ 

	int stack[MAX], top = -1, i; 
	printf("%d", start); 
	stack[++top] = start; // add it to the stack 
	visited[start] = 1; 

	while (top != -1){ 
		start = stack[top]; 
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				stack[++top] = i; 
				printf("%d", i); 
				visited[i] = 1; 
				break;
			}
		}
		if (i == MAX) top--;
	}
}

void depthFirstSearchGraph3(int adj[][MAX], int visited, int start){
	int stack[MAX], top = -1, i; 
	printf("%d", start);
	stack[++top] = start; 
	visited[start] = 1; 
	while (top != -1) {
		start = stack[top];
		for (i = 0; i<MAX; i++) {
			if (adj[start][i] && visited[i] == 0){
				printf("%d", i); 
				stack[++top] = i; 
				visited[i] == 1; 
				break;
			}
		} 
		if (i == MAX) top--; 
	}
}

void breadth_first_search(int adj[][MAX], int visited[], int start) {
	int queue[MAX], rear = -1, front = -1, i;
	queue[++rear] = start;
	visited[start] = 1;
	while (rear != front) {
		start = queue[++front];
		printf("%d ", start);
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				queue[++rear] = i;
				visited[i] = 1;
			}
		}
	}
}

void depthFirstSearchAdjMat2(int adj[][MAX], int visited, int start) {
	int stack[MAX], top = -1, i; 
	printf("%d", start); 
	stack[++top] = start; 
	visited[start] = 1; 
	while (top != -1) {
		start = stack[top]; 
		for (i = 0; i < MAX; i++){
			if (adj[start][i] && visited[i] == 0) {
				printf("%d", i); 
				stack[++top] = i; 
				visited[i] = 1; 
				break; 
			}
		}
		if (i == MAX) top--; 
	}
}

int bstInsert2(BSTNODE root, int key) {
	BSTNODE node = (BSTNODE *)(malloc(sizeof(BSTNODE))); 
	if (node) {
		node->value = key; 
		node->right = NULL;
		node->left = NULL; 
	} else {
		printf("Memory allocation failed."); 
		return -1; 
	}

	BSTNODE ptr = root, parent = NULL; 
	while (ptr != NULL) { 
		parent = ptr; 
		if (key == ptr->value) { 
			free(ptr); 
			return -1; 
		}
		else if (key < ptr->value) ptr = ptr->left; 
		else ptr = ptr->right; 
	}
	if (parent) { 
		if (key < parent->value) parent->left = node; 
		else if (key > parent->value) parent->right = node; 
	} else {
		root = node; 
	}
	
	update_height(root->height); 
	return 1; 
}

int bstSearch(BSTNODE root, int key) {
	BSTNODE temp = root; 

	while (temp) {
		if (key < temp->value) temp = temp->left; 
		else if (key > temp->value) temp = temp->right; 
		else return 1; 
	} 

	return -1; 
}

void heapSort(int a[], int n) { 
	int i = 0, val; 

	for (i = 0; i < n; i++) {
		heapify_up(a, i);
	}

	for (i = n - 1, i <= 0; i--) {
		val = a[i]; 
		a[i] = a[0]; 
		a[0] = val; 
		heapify_down(a, 0, i - 1); 
	}
}


 


void breadthFirstSearchAdjMatrix(int adj[][MAX], int visited, int start) {
	int queue[MAX], front = -1, rear = -1, i; 
	queue[++rear] = start; 
	visited[start] = 1; 
	while (front != rear) { 
		start = queue[++front]; 
		printf("%d", start); 
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				queue[++rear] = i; 
				visited[i] = 1;
			}
		}
	}

}


void depthfirst(int adj[][MAX], int visited[], int start) {
	int stack[MAX], top = -1, i; 
	printf("%d", start); 
	stack[++top] = start; 
	visited[i] = 1; 
	while (top != -1) { 
		start = stack[top];
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				printf("%d", i); 
				stack[++top] = i;
				visited[i] = 1; 
				break;  
			}
		} 
		if (i == MAX) top--; 
	}
}

int insertBinary(BSTNODE root, int key) {
	BSTNODE new_node = (BSTNODE *)malloc(sizeof(BSTNODE)); 
	if (new_node) {
		new_node->value = key; 
		new_node->left = NULL; 
		new_node->right = NULL;
	} else {
		printf("Memory leak.");
		return 0; 
	}

	BSTNODE parent = NULL, ptr = root; 
	while (ptr) {
		parent = ptr; 
		if (key == ptr->value) {
			printf("Value exists");
			return 0; 
		} else if (key < ptr->value) {
			ptr = ptr->left; 
		} else if (key > ptr->value) {
			ptr = ptr->right; 
		}
	}
	if (!parent) {
		root = new_node; 
 	} else if (key < parent->value) {
 		parent->left = new_node; 
 	} else if (key > parent->value) {
 		parent->right = new_node; 
 	} 

 	update_height(root);
 	return 1; 

}

void searchTree(BSTNODE root, int key) {
	if (root) { 
		BSTNODE ptr = root; 
		while (ptr != NULL) {
			if (ptr->value == key) {
				return 1;
			} else if (key < ptr->value) {
				ptr = ptr->left; 
			} else if (key > ptr->value) {
				ptr = ptr->right; 
			}
		}
	}
	return 0; 
}

void right_rotate(BSTNODE x) { 
	// bf(x) = 2, bf(x->left) >= 0
	/*
		X
	   / \ 
	  Y   O
	 / \ 
	O   T2
   / 
  O
	  Y  
	 / \ 
	O   X
   /   / \ 
  O   T2  O
	*/

	BSTNODE	y = x->left; 
	BSTNODE t2 = y->right; 

	y->right = x; 
	x->left = t2; 

	y->height = max(height(y->left), height(y->right)); 
	x->height = max(height(x->left), height(x->right)); 
	return x; 
}


void left_rotate(BSTNODE x) { 
	// bf(x) = -2, bf(x->right) <= 0
	/*
		X
	   / \ 
	  O   Y
	     / \ 
	    T2   O
	         \
	          O 
	  Y  
	 / \ 
	X   O
   / \   \ 
  O   T2  O
	*/

	BSTNODE y = x->right; 
	BSTNODE t2 = y->left; 

	y->left = x; 
	x->right = t2; 

	x->height = max(height(x->left), height(x->right)); 
	y->height = max(height(y->left), height(y->right)); 
	return x; 
}



void heap_sort(int a[], int n) {
/*
	  9  
	 / \ 
	4   7
   / \   \ 
  1   3   2
*/
	int i, val; 
	// create max-heap 
	for (i = 0; i < n; i++) {
		heapify_up(a, i);
	}

	// swap max with first element and put it in the rightmost position of the array
	// heapify_down to restore heap property 
	for (i - 1; i >= 0; i--) { 
		_swapPositions(a, i, 0);
		heapify_down(a, 0, i-1);
	}
}

void _swapPositions(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j]; 
	a[j] = temp; 
	return; 
}


void breadth_first_graph(int adj[][MAX], int visited, int start) {
	int queue[MAX], rear = -1, front = -1, i; 
	queue[++rear] = start;
	visited[start] = 1; 
	printf("%d", i);	
	while (front != rear) {
		start = queue[++front]; 
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) { 
				queue[++rear] = i; 
				visited[i] = 1; 
			}
		}
	}
}

void post_order_traverse(BSTNODE root) { 
	/*
		X
	   / \ 
	  O   Y
	 /   / \ 
	Q   E   D
	  
	Q, O, E, D, Y, X      
	*/
	if (root == NULL) {
		return;
	}

	post_order_traverse(root->left); 
	post_order_traverse(root->right); 
	printf("%d", root); 
}


void pre_order_traverse(BSTNODE root) { 
	/*
		X
	   / \ 
	  O   Y
	 /   / \ 
	Q   E   D
	  
	X, O, Q, Y, E, D 
	*/
	if (root == NULL) {
		return;
	}

	printf("%d", root); 
	post_order_traverse(root->left); 
	post_order_traverse(root->right); 
}

void depthFirstTree(BSTNODE root) { 
	/*
		1. visit a node and push it onto the stack
		2. pop a node from the stack, print it and then push its children (R->L)
	*/

	int stack[MAX], top = -1, i; 
	BSTNODE ptr = root; 
	stack[++top] = ptr;
	while (top != -1) { 
		node = stack[top--];
		printf("%d", node->value);
		if (node->right) stack[++top] = node->right; 
		if (node->left) stack[++top] = node->left; 
	}
}



void heapify_down(int heap, int index, int n) { 
	/*
	n = 5 
	        5         val, index = 0
		   / \ 
child     8   3
		 / \ 
		6   9
	
	        8         val, index = 1
		   / \ 
          5   3
		 / \ 
		6   9 child

			8         val, index = 4
		   / \ 
          9   3
		 / \ 
		6   5 child 

		9
	   / \ 
	  8   3
	 / \ 
	6   5
	*/ 
	int child; 
	int temp; 
	int val = heap[child]; 			
	while (child >= 0 && child <= n - 1) {
		child = (index * 2) + 1;
		if (child <= n - 1 && heap[child] < heap[child+1]) {
			child++; 
		}
		if (child >= n || heap[child] < val) {
			break; 
		} 
		else {
			temp = heap[index]; 
			heap[index] = val; 
			heap[child] = temp; 
			index = child; 
		}

	}

}

void heapify_down(int heap, int n, int index) { 
	int temp, val, child = 0; 
	val = heap[index]; 
	while (child >= 0 && child <= n - 1) { 
		child = (index * 2) + 1; // left child 
		if (child <= n - 1 && heap[child] < heap[child + 1]) { 
			child++; 
		}
		if (child >= n || heap[child] < heap[index]) {
			break; 
		} else {
			temp = heap[child]; 
			heap[child] = heap[index]; 
			heap[index] = temp; 
			index = child; 
		}
	}
}

void heapify_down(int heap, int n, int index) {
	int temp, val, child; 
	val = heap[index]; 
	while (child >= 0 && child < n) {
		child = (2*index) + 1;
		if (child < n && heap[child] < heap[child + 1]){
			child++; 
		} 
		if (child >= n || heap[child] < heap[index]) {
			break;
		} else {
			temp = heap[child];
			heap[child] = heap[index];
			heap[index] = temp; 
			index = child; 
		}
	}
}


void heapify_up(int heap, int index){
	int temp, parent, val = heap[index]; 
	while (index > 0) {
		parent = (index/2) + 1;        
		if (parent < 0 || heap[parent] >= val) {
			break; 
		} else {
			temp = heap[parent];
			heap[parent] = heap[index];
			heap[index] = temp; 
			index = parent;
		}
	}
}


void heapify_up(int heap, index index) {
	int parent, temp, val = heap[index]; 
	while (index > 0) {
		parent = (index-1)/2; 
		if (parent < 0 || heap[parent] >= val) {
			break;
		} else {
			temp = heap[parent]; 
			heap[parent] = heap[index];
			heap[index] = heap[parent]; 
			index = parent; 
		}
	}
}

/*
1. Briefly describe the scenarios of using array and linked lists.

when you need to store random ordered data that doesn't need to be maintained in a specific way. 
E.g use an array or a linked list to store all the countries you've visited.  

2. Briefly describe the scenarios of using queue and stack.

when you when you need to track the order in which data are inserted and most recently inserted data respectively. 
E.g use a queue to track customers queuing in a line for a restaurant. Use a stack to track what tasks you must complete, adding tasks with the most (n) dependencies to the beginning of the stack and tasks with 0 to n-1 dependencies successively. 

3. Use Hoffman tree to encode a given sequence of symbol and
frequencies.

Done!	

4. Get prefix, infix, postfix expression of given expression tree.

Done  

5. Comparison of binary tree, BST, AVL, RBT, in search, insert, delete operations.

			BST | AVL | RBT 

Search  O(h)     O(log n)   O(log n)
  
Insert  O(h)     O(log n)   O(log n), O(log n)

Delete  O(h)     O(log n)   O(log n), O(log n)

6. Insert a given sequence of key values into BST, AVL

YESSSS

1) x
    \ 
     x      rotate left 
      \ 
       x

2) x
  /  \ 
 x    x      right left rotation  
     / \ 
    x   x
    \ 
      x


3) x
  /  \ 
 x    x      left rotation
     / \ 
    x   x
         \
          x 

7. Insert a given sequence of numbers into a hash table using linear probing.

Yes,

(k % m + i) % m

8. Insert a given sequence of numbers into binary heap, and delete-min 

	insert: nodes to the leftmost available position (heapify_up as required)

	delete-min/max: replace min/max node with last node (heapify_down as required)

9. Find MST, shortest path in a given weighted graph.

 	use Prim's algorithm (start at any vertex and choose smallest edge connected to it)

10. Incremental algorithm and aggregate algorithm for simple stats (count, min, max, meffan) computing on linked list and binary tree.



typedef struct bstNode{
	int data;
	struct bstNode *right; 
	struct bstNode *left; 
} NODE; 

typedef struct linkedNode{
	int data; 
	struct *linkedNode next; 
} LISTNODE; 

typedef struct stats{
	int count; 
	int min; 
	int max; 
} STATS;

STATS bstStats(NODE **root) {
	STATS stats = {0}; 
	NODE *ptr; 
	int max = NULL, min = NULL, count = 0;
	int stack[MAX], top = -1;

	stack[++MAX] = root; 
	while (top != -1) {
		ptr = stack[top--];  
		if (ptr) {
			count++; 
			if (ptr->value > max) {
				max = ptr->value; 
			} 
			if (ptr->value < min) {
				min = ptr->value; 
			}
		}
		if (ptr->left) ptr = stack[++top];
		if (ptr->right) ptr = stack[++top]; 
	}
	stats.max = max; 
	stats.min = min; 
	stats.count = count;
	return stats;
} 

STATS statsLinkedList(LISTNODE *start) {
	STATS stats = {0}; 
	LISTNODE *ptr = start; 
	int min, max, count; 

	while (ptr != NULL) {
		count++; 
		if (min < ptr->data) min = ptr->data;
		if (max > ptr->data) max = ptr->data; 
		ptr = ptr->next; 
	}

	stats.min = min; 
	stats.max = max;
	stats.count = count; 
	return stats;
}



1. Write C functions to insert an element, to delete elements, search in a singly linked list.
2. Write a C function to display element backward from a singly linked list using iterative algorithm with auxiliary data structure.
3. For binary tree, write C functions to do traversal (in pre-order, in-order and post-order), depth-first-order, breath-first-order, to compute number of nodes, height, number of leaves.
4. For BST, write C functions to search, insert and delete using iterative algorithms.
5. Hash tables and applications, i.e., design a hash table and function to count words and their frequencies of given text string.
6. Binary heap, heapify-up, heapify-down, insert, delete-min, change-key, heap sort.
7. breadth/depth-first traversal/search on binary trees and graphs, and applications, in adjacency matrix representations
*/

/*
10. Incremental algorithm and aggregate algorithm for simple stats (count, min, max, meffan) computing on linked list and binary tree.
*/

typedef struct bstNode{
	int data;
	struct bstNode *right; 
	struct bstNode *left; 
} NODE; 

typedef struct linkedNode{
	int data; 
	struct *linkedNode next; 
} LISTNODE; 

typedef struct stats{
	int count; 
	int min; 
	int max; 
} STATS;

STATS bstStats(NODE **root) {
	STATS stats = {0}; 
	NODE *ptr; 
	int max = NULL, min = NULL, count = 0;
	int stack[MAX], top = -1;

	stack[++MAX] = root; 
	while (top != -1) {
		ptr = stack[top--];  
		if (ptr) {
			count++; 
			if (ptr->value > max) {
				max = ptr->value; 
			} 
			if (ptr->value < min) {
				min = ptr->value; 
			}
		}
		if (ptr->left) ptr = stack[++top];
		if (ptr->right) ptr = stack[++top]; 
	}
	stats.max = max; 
	stats.min = min; 
	stats.count = count;
	return stats;
} 

STATS statsLinkedList(LISTNODE *start) {
	STATS stats = {0}; 
	LISTNODE *ptr = start; 
	int min, max, count; 

	while (ptr != NULL) {
		count++; 
		if (min < ptr->data) min = ptr->data;
		if (max > ptr->data) max = ptr->data; 
		ptr = ptr->next; 
	}

	stats.min = min; 
	stats.max = max;
	stats.count = count; 
	return stats;
}



void in_order_traversal(BSTNODE root) {
	// left subtree, root, right subtree
	/*
	  9  
	 / \ 
	4   7
   / \   \ 
  1   3   2

	1, 4, 3, 9, 7, 2
	 */

	if (root == NULL) {
		return; 
	}

	in_order_traversal(root->left); 
	printf("%d", root); 
	in_order_traversal(root->right); 
}

void rotate_left(BSTNODE x) {
	BSTNODE y = x->right; 
	BSTNODE t2 = y->left; 

	y->left = x; 
	x->right = t2; 

	x->height = max(height(x->right), height(x->left)); 
	y->height = max(height(y->right), height(y->left)); 
}


void bfs_bst(BSTNODE root) { 
	if (!root) {
		return;
	}

	int queue[MAX], rear = -1, front = -1, val, i; 
	queue[++rear] = root; 
	while (rear != front) {
		val = queue[++front]; 
		printf("%d", val); 
		if (val->left) queue[++rear] = val->left;
		if (val->right) queue[++rear] = val->right;
	}
}	



//Write C functions to insert an element, to delete elements, search in a singly linked list.
void insertSinglyLinked(SL list, int key) {
	NODE new_node = (NODE *)malloc(sizeof(NODE)); 
	new_node->value = key; 
	new_node->next = NULL; 

	if (list->head == NULL) {
		list->head = new_node; 
	} else { 
		NODE prev = NULL; 
		NODE curr = list->head; 
		while (curr != NULL) {
			prev = curr; 
			curr = curr->next; 
		}
		prev->next = new_node; 
	}
	list->count++; 
}

NODE deleteSinglyLinked(SL list, int key) {
	if (list->head != null) {
		prev = NULL; 
		NODE curr = list->head; 
		while (curr != NULL && curr->value != key) {
			prev = curr; 
			curr = curr->next; 
		}
		if (curr != NULL) { // found node with the key 
			if (prev == NULL) list->head = curr->next; 
			else {
				prev->next = curr->next; 
			}
			list->count--; 
			return curr; 
		}
	}
	return NULL; // key not found 
}

int searchSinglyLinkedList(SL list, int key){
	if (list->head != NULL){
		NODE curr = list->head; 
		while (curr != NULL && curr->value != key){
			curr = curr->next;
		}
		if (curr != NULL) return 1; // found node with key
	}
	return -1; 
}


// Write a C function to display element backward from a singly linked list using iterative algorithm with auxiliary data structure.
void reverseSinglyLinkedList(SL list) {
	if (list->head != NULL){
		NODE temp, prev = list->head;
		NODE curr = list->head->next; 
		while (curr != NULL){ 
			temp = curr->next;
			curr->next = prev;	 
			prev = curr; 	
			curr = temp; 
		}
	}
}

void displayBackwardsUsingStack(Stack stack, SL list) {
	if (list->head != NUll) {
		NODE curr = list->front; 
		while (curr != NULL){
			stack->push(curr->value);
			curr = curr->next;
		}
		while (stack->top != -1) {
			int n = stack->pop(); 
			printf("%d", n);
		}
	}
}


// For binary tree, write C functions to do traversal (in pre-order, in-order and post-order), depth-first-order, breath-first-order, to compute number of nodes, height, number of leaves. 

// preorder (root, left tree, right tree)
BSTNODE treePreOrderTraversal(BSTNODE root) {
	if (root == NULL) return 

	printf("%d", root->value); 
	treePreOrderTraversal(root->left); 
	treePreOrderTraversal(root->right); 
}

// inorder (left tree, root, right tree)
BSTNODE treeInOrderTraversal(BSTNODE root) {
	if (root == NULL) return 

	treePreOrderTraversal(root->left); 
	printf("%d", root->value); 
	treePreOrderTraversal(root->right); 
}

// postorder (left tree, right tree, root)
BSTNODE treePostOrderTraversal(BSTNODE root) {
	if (root == NULL) return 

	treePreOrderTraversal(root->left); 
	treePreOrderTraversal(root->right); 
	printf("%d", root->value); 
}

// depthfirst (stack) 
void treeDepthFirstTraversal(BSTNODE root) {
	if (root == NULL) return;

	int stack[MAX], top = -1; 
	stack[++top] = root; 
	while (top != 1){ 
		node = stack[top--]; 
		printf("%d", node->value); 
		if (node->right != NULL) stack[++top] = node->right; 
		if (node->left != NULL) stack[++top] = node->left; 
	}
}

// breadthfirst (queue)
void treeBreadthFirstTraversal(BSTNODE root) { 
	if (root == NULL) return; 

	int queue[MAX], front = -1; 
	queue[++front] = root; 
	while (front != -1) {
		BSTNODE node = queue[front]; 
		printf("%d", node->value); 
		if (node->left != NULL) queue[++front] = node->left; 
		if (node->right != NULL) queue[++front] = node->right; 
	}
}

// nodeCount 
int treeNodeCount(BSTNODE root) {
	if (root == NULL) return 0; 

	return 1 + treeNodeCount(root->left) + treeNodeCount(root->right);
}

// heightCount
int treeHeight(BSTNODE root) {
	if (root == NULL) return 0; 

	return max(treeHeight(root->left), treeHeight(root->right)) + 1; 
}

// leafCount
int treeLeafCount(BSTNODE root) { 
	if (root->right == NULL && root->left == NULL) return 1; 

	return treeLeafCount(root->left) + treeLeafCount(root->right); 

}

// For BST, write C functions to search, insert and delete using iterative algorithms.

int bstInsert(BSTNODE root, int key) {
	BSTNODE node = (BSTNODE *)malloc(sizeof(BSTNODE)); 
	if (node) {
		node->value = key; 
		node->left = NULL; 
		node->right = NULL; 		
	} else {
		printf("Memory leak.");
		return -1; 	
	}

	BSTNODE temp = root, parent = NULL; 
	while (temp != NULL) {
		parent = temp; 
		if (key < temp->value) {
			temp = temp->left; 
		} else if (key > temp->value) {
			temp = temp->right; 
		} else {
			free(node); 
			return -1;
		}
	}
	if (parent == NULL) {
		root = node; 
	} else if (key < parent->value) {
		parent->left = node;
	} else {
		parent->right = node; 
	}

	update_height(root); 
	return 1; 
}

int bstSearch(BSTNODE root, int key) {
	BSTNODE temp = root; 
	while (temp) {
		if (key < temp->value) {
			temp = temp->left;
		} else if (key > temp->value) {
			temp = temp->right; 
		} else {
			return 1; 
		}
	}
	return -1;
}


typedef struct linkedNode{
	int data; 
	struct linkedNode *next; 
} LISTNODE; 

void insertEndOfSinglyLinkedList(LISTNODE **startp, int val) {
	LISTNODE new_node = (LISTNODE *)malloc(sizeof(LISTNODE));
	if (!new_node) {
		printf("Memory allocation failed.");
		return;
	}

	new_node->data = val; 
	new_node->next = NULL;

	LISTNODE *ptr = *startp, *prev = NULL; 

	while (ptr != NULL) {
		prev = ptr;
		ptr = ptr->next;
	}

	if (prev == NULL) {
		*startp = new_node; 
	} else {
		prev->next = new_node;
	}
}


void insertAtTheEndOfLinkedList(LISTNODE **startp, int key) {
	LISTNODE *new_node = (LISTNODE *)malloc(sizeof(LISTNODE)); 
	if (!new_node) {
		printf("Memory allocation failed");
	} 
	new_node->data = key; 
	new_node->next = NULL; 

	LISTNODE *ptr = *startp, prev = NULL; 

	while (ptr != NULL) {
		prev = ptr; 
		ptr = ptr->next; 
	}

	if (prev == NULL) {
		*startp = new_node; 
	} else {
		prev->next = new_node;
	}

}


BSTNODE bstDelete(BSTNODE root, int key) { 
	/*
	2 cases:

	1) deleting node with one child: replace the node with its child
	2) deleting node with two children: replace node with the smallest node of its right subtree 

	*/ 
	if (root) {
		BSTNODE parent == NULL;
		BSTNODE ptr = root;  
		while (ptr && ptr->value != key) { 
			if (key == ptr->value) {
				// case 2
				if (ptr->left && ptr->right) {

				} 
				// case 1 
				else {
					BSTNODE child = ptr->left ? ptr->right: ptr->right; // get the single child 
					if (parent != NULL) {
						if (parent->left == ptr) {
							parent->left = child; 
						} else {
							parent->right = child; 
						}
						free(ptr); 
					} 
				}
			} else if (key < ptr->value) {
				parent = ptr; 
				ptr = ptr->left;  
			} else if (key > ptr->value) {
				parent = ptr;  
				ptr = ptr->right; 
			}
		}
		if (!) {
			return NULL; // tree is empty 
		} 
	}
}


BSTNODE bstDelete(BSTNODE root, int key) { 
	/*
	2 cases:

	1) deleting node with one child: replace the node with its child
	2) deleting node with two children: replace node with the smallest node of its right subtree 

	*/ 
	if (root == NULL) {
		return NULL; 
	} 

	BSTNODE parent == NULL, child = NULL;
	BSTNODE ptr = root;  
	while (ptr && ptr->value != key) { 
		parent = ptr;
		if (key < ptr->value) { 
			ptr = ptr->left;  
		} else if (key > ptr->value) {
			ptr = ptr->right; 
		}
	}

	if (!ptr) return NULL;

	// case 1
	if (ptr->right == NULL || ptr->left == NULL) {
		if (ptr->right && !ptr->left) child = ptr->right; 
		else if (ptr->left && !ptr->right) child = ptr->left; 

		if (parent) {
			if (parent->right == ptr) {
				parent->right = child; 
			} else if (parent->left == ptr) {
				parent->left = child; 
			}
		} else {
			root = child; 
		}
		free(root);
		return root; 

	// case 2 
	BSTNODE parent_of_successor = ptr; 
	BSTNODE sucessor = ptr->right; 
	while (sucessor->left) {
		parent_of_successor = sucessor; 
		sucessor = sucessor->left; 
	}
	if (ptr == parent_of_successor) {
		sucessor->left = ptr->left;
	} else {
		parent_of_successor->left = sucessor->right; 
		sucessor->left = ptr->left; 
		sucessor->right = ptr->right;
	}
	ptr = sucessor; 
	}

	
	if (parent == NULL) {
		root = NULL; 
	} else if (parent->left == ptr) {
		parent->left = ptr;  
	} else {
		parent->right = ptr;
	}
	free(ptr);
}


BSTNODE bstDelete(BSTNODE root, int key) {
	if (root == NULL) {
		return NULL; 
	}

	BSTNODE parent = NULL, child = NULL;
	BSTNODE ptr = root; 

	while (ptr && ptr->value != key) {
		parent = ptr; 
		if (key < ptr->value) {
			ptr = ptr->left;
		} else if (key > ptr->value) {
			ptr = ptr->right; 
		} 
	}

	if (!ptr) {
		printf("node with key doesn't exist");
		return NULL; 
	} 

	if (ptr->right) {
		ptr = ptr->right; 
	} else if (ptr->left) {
		ptr = ptr->left; 
	} else {
		BSTNODE parent_of_successor = ptr;
		BSTNODE sucessor = ptr->right; 

		while (sucessor != NULL) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left; 
		} 

		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right; 
			sucessor->left = ptr->left; 
			sucessor->right = ptr->right; 
		}
		ptr = sucessor; 
	}
	if (parent == NULL) {
		root = ptr; 
	} else if (parent->left == ptr) {
		parent->left = ptr;
	} else {
		parent->right = ptr; 
	}
	free(ptr);
}


BSTNODE bstDelete(BSTNODE root, int key) {
	if (root == NULL) {
		return NULL; 
	}

	BSTNODE parent = NULL, ptr = root, temp; 

	while (ptr != NULL && ptr->value != key) { 
		parent = ptr; 
		if (key < ptr->value) {
			ptr = ptr->left; 
		} else if (key > ptr->value) {
			ptr = ptr->right; 
		}
	}

	if (!ptr) {
		printf("node with key doesnt exist");
	}

	if (!ptr->right){
		temp = ptr->left;
	} else if (!ptr->left) {
		temp = ptr->right; 
	} else {
		BSTNODE parent_of_successor = ptr, sucessor = ptr->right; 
		while (sucessor->left != NULL) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left; 
		}
		if (parent_of_successor == ptr) {
			successor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right; 
			sucessor->left = ptr->left; 
			sucessor->right = ptr->right; 
		}
		temp = ptr; 
	}
	if (parent == NULL) {
		root = temp; 
	} else if (parent->left == temp) {
		parent->left = temp; 
	} else {
		parent->right = temp; 
	}
	free(ptr);

}


void deleteBST(BSTNODE root, int key) {
	if (root == NULL) {
		return NULL; 
	} 

	BSTNODE parent = NULL, ptr = root, temp = NULL; 

	while (ptr && ptr->value != key) {
		parent = ptr; 
		if (key < ptr->value) ptr = ptr->left; 
		else if (key > ptr->value) ptr = ptr->right;
	}

	if (!ptr) {
		printf("Node with key does not exist.");
		return NULL; 
	} 

	if (!ptr->left) {
		temp = ptr->right;
	} else if (!ptr->right) {
		temp = ptr->left; 
	} else {
		BSTNODE parent_of_successor = ptr, sucessor = ptr->right; 
		while (sucessor->left) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left; 
		}

		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right; 
			sucessor->left = ptr->left; 
			sucessor->right = ptr->right;
		} 
		temp = ptr; 
	}
	if (!parent) {
		root = temp; 
	} else if (parent->left == ptr) {
		parent->left = temp; 
	} else {
		parent->right = temp; 
	}
	free(ptr);
}

void deleteFromBST(BSTNODE root, int key) {

	if (root == NULL) {
		return NULL;
	}
	BSTNODE parent = NULL, ptr = root, temp; 

	while (ptr && ptr->value != key) {
		parent = ptr; 
		if (key < ptr->value) {
			ptr = ptr->left; 
		} else if (key > ptr->value) {
			ptr = ptr->right; 
		}
	}

	if (!ptr) {
		printf("A node does not exist with the given key value.");
		return NULL;
	}
	
	if (!ptr->left) {
		temp = ptr->right;
	} else if (!ptr->right) {
		temp = ptr->left; 
	} else {
		BSTNODE parent_of_successor = ptr, sucessor = ptr->right; 
		while (sucessor->left) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left;
		}

		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left;
		} else {
			parent_of_successor->left = sucessor->right;  
			sucessor->left = ptr->left;
			successor->right = ptr->right;
		}
		temp = ptr;
	}
	if (!parent) {
		root = temp; 
	} else if (parent->left == ptr) {
		parent->left = temp; 
	} else if (parent->right == ptr) {
		parent->right = temp; 
	} 
	free(ptr);
}


void right_left_rotate(BSTNODE x) {
	x->right = rotate_right(x->right);
	rotate_left(x); 
}

void left_right_rotate(BSTNODE x) {
	x->left = rotate_left(x->left);
	rotate_right(x); 
}



if (parent_of_sucessor == ptr) {
	sucessor->left = ptr->left;
} else {
	parent_of_successor->left = sucessor->right;
}

// Heap sort 
void heap_sort2(int a[], int n) {
	int i, val;
	for (i = 0; i < n; i++) { // convert a[n] to max-heap by inserting a[i] for i=0 .. n-1 using heapify-up operations 
		heapify_up(a, i);
	}
	for (i = n - 1; i >= 0; i--) { // extract max and put at a[i] for i=n-1, ... 0.
		_swap(a, i, 0);
		heapify_down(a, 0, i - 1);
	}
}

void _swap(int a[], int i, int j){
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}



// heap sort (n log(n)), where n = heapify up, and log(n) = heapify down

void heap_sort(int a[], int n) {
	int i, val; 
	for (i = 0; i < n, i++) {
		heapify_up(a, i);
	}
	for (i = n - 1; i >= 0; i--) {
		val = a[i];
		a[i] = a[0];
		a[0] = val; 
		heapify_down(a, 0, i-1);
	}
}




void depthfirstgrpah(int adj[][MAX], int visited, int start) {
	int stack[MAX], top = -1, i; 
	stack[++top] = start;
	printf("%d", start);
	visited[start] = 1;

	while (top != -1) {
		start = stack[top--];
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				stack[++top] = i; 
				printf("%d", i);
				visited[i] = 1; 
				break;
			}
		}
		if (top == MAX) i--;  
	}
}





void heap_sort(int a[], int n) {
	int val, i; 
	for (i = 0; i < n; i++) {
		heapify_up(a, i);
	}
	for (i = n - 1; i >= 0; i--) {
		val = a[0];
		a[0] = a[i];
		a[i] = val; 
		heapify_down(a, 0, i-1);
	}
}

void heapify_down(int heap, int index, int n) {

	int child, temp, val = heap[index]; 

	while (child >= 0 && child <= n - 1) {
		child = (2*index) + 1; 
		if (child >= 0 && heap[child] > heap[child + 1]){
			child++; 
		}
		if (child <= 0 || heap[index] < heap[child]) {
			break;
		} else {
			temp = heap[child];
			heap[child] = heap[index];
			heap[index] = temp;
			index = child; 
		}
	}

}


void heapify_down(int heap, int index, int n) {
	int temp, child; 

	while (child >= 0 && child <= n - 1) {
		child = (index * 2) + 1;
		if (child >= 0 && heap[child] > heap[child + 1]) {
			child++;
		}  
		if (child <= 0 && heap[index] < heap[child]) {
			break; 
		} else {
			temp = heap[child];
			heap[child] = heap[index];
			heap[index] = heap[child]; 
			index = child; 
		}
	}
}
void heapify_up(int heap, int index){
	int temp, parent, val = heap[index]; 
	while (index > 0) {
		parent = (index/2) + 1;        
		if (parent < 0 || heap[parent] >= val) {
			break; 
		} else {
			temp = heap[parent];
			heap[parent] = heap[index];
			heap[index] = temp; 
			index = parent;
		}
	}
}











void heapify_up(int heap, int index, int n){
	int temp, parent; 
	while (index > 0){
		parent = (index/2) + 1;
		if (parent < 0 || heap[parent] <= heap[index]){
			break;
		} else {
			temp = heap[parent];
			heap[parent] = heap[index];
			heap[index] = temp; 
			index = parent;
 		}
	} 
}





void heap_sort(int heap, int index, int n) {
	int val, i, temp; 
	for (i = 0; i <= n - 1; i++) {
		int parent;	 
		while (i > 0) {
			parent = (i/2) + 1;
			if (parent < 0 || heap[parent] < heap[i]) {
				break; 
			} else {
				temp = heap[i];
				heap[i] = heap[parent];
				heap[parent] = temp;
				index = parent;
			}
		}
	}
	for (i = n - 1; i >= 0; i++) {
		val = heap[0];
		heap[0] = heap[i];
		heap[i] = val; 
		
		int child; 
		while (child >= 0 && child <= n - 1) {
			child = (i*2) + 1;
			if (child >= 0 && heap[child+1] < heap[child]) {
				child++; 
			} 
			if (child < 0 || heap[child] > heap[i]) {
				break; 
			} else {
				temp = heap[child];
				heap[child] = heap[i]; 
				heap[i] = temp; 
				i = child; 
			}
		}
	}
}

void heapify_down(int heap, int index, int n) {
	int temp, child; 
	while (child >= 0 && child <= n - 1) {
		child = (index*2) + 1;
		if (child >= 0 && heap[child+1] < heap[child]) {
			child++; 
		} 
		if (child < 0 || heap[child] > heap[index]) {
			break; 
		} else {
			temp = heap[child];
			heap[child] = heap[index]; 
			heap[index] = temp; 
			index = child; 
		}
	}
}


void heapify_up(int heap, int index) {
	int temp, parent; 
	while (index > 0) {
		parent = (index/2) + 1;
		if (parent < 0 || heap[parent] < heap[index]) {
			break; 
		} else {
			temp = heap[index];
			heap[index] = heap[parent];
			heap[parent] = temp;
			index = parent;
		}
	}
}







// heapsort, bst insert delete height leaf node, adj matrix bfs and dfs, 


void heap_sort(int heap[], int n) {
	int temp, val, i; 

	for (i = 0; i < n; i++) {
		int parent; 
		while (i > 0) {
			parent = (index-1)/2;
			if (parent < 0 || heap[parent] > heap[i]) break;
			else {
				temp = heap[parent];
				heap[parent] = heap[child]; 
				heap[child] = temp; 
				i = parent; 
			}
		}
	}

	for (i = n - 1; i >= 0; i--) {
		val = heap[0];
		heap[0] = heap[i];
		heap[i] = val; 

		temp = heap[i-1];
		int child; 
		while (i-1 >= 0 && i-1 < n) {
			child = 2*(i-1) + 1;
			if (child < n - 1 && heap[child] < heap[child+1]) child++;
			if (child >= n || temp > heap[child]) break;
			else {
				temp = heap[child];
				heap[child] = heap[i-1];
				heap[i-1] = temp; 
				i = child+1;
			}
		}
	}

}




void bstDelete(BSTNODE root, int key) {

	if (root == NULL) {
		return;
	}

	BSTNODE parent = NULL, ptr = root, temp; 

	while (ptr && ptr->data != key) {
 		parent = ptr; 
 		if (key < ptr->data) ptr = ptr->left; 
 		if (key > ptr->data) ptr = ptr->right; 
	}


	if (!ptr) {
		printf("Node with key does not exist.");
		return;
	}


	if (ptr->right == NULL) {
		temp = ptr->left;
	} else if (ptr->left == NULL) {
		temp = ptr->right;
	} else {

		BSTNODE parent_of_successor = ptr, sucessor = ptr->right; 

		while (sucessor->left) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left; 
		}

		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right; 
			sucessor->left = ptr->left; 
			sucessor->right = ptr->right;
		}
		temp = sucessor;
	}

	if (parent == NULL) {
		root = temp; 
	} else if (parent->left == ptr) {
		parent->left = temp;
	} else if (parent->right == ptr) {
		parent->right = temp; 
	}

	free(ptr); 
}








int bstInsert(BSTNODE root, int key) {

	BSTNODE new_node = (BSTNODE *)malloc(sizeof(BSTNODE));

	if (!new_node) {
		printf("Memory allocation failed.");
		return -1; 
	}


	new_node->data = key; 
	new_node->left = NULL; 
	new_node->right = NULL;


	BSTNODE parent = NULL, ptr = root; 

	while (ptr) {
		parent = ptr;
		if (ptr->value == key) {
			printf("Node with key already exists.");
			return 0;
		} else if (key < ptr->data) {
			ptr = ptr->left; 
		} else if (key > ptr->data) {
			ptr = ptr->right;
		}
	} 


	if (parent == NULL) {
		root = new_node; 
	} else if (parent->left == ptr) {
		parent->left = new_node; 
	} else if (parent->right == ptr) {
		parent->right = new_node;
	}

	update_height(root);

	return 1; 
}




BSTNODE bstSearch(BSTNODE root, int key) {
	BSTNODE ptr = root; 

	while (ptr) {
		if (ptr->data == key) return ptr; 
		else if (key < ptr->data) ptr = ptr->left;
		else if (key > ptr->data) ptr = ptr->right; 
	}


	return NULL; 
}









int heightOfBST(BSTNODE root) {
	if (root == NULL) {
		return 0; 
	}

	return 1 + max(heightOfBST(root->left), heightOfBST(root->right));
}


int leafCountBST(BSTNODE root) {
	if (root == NULL) return 0; 
	else if (root->left == NULL && root->right == NULL) {
		return 1; 
	}

	return leafCountBST(root->left) + leafCountBST(root->right);
}




void dfsAdjMat(int adj[][MAX], int visited, int start) {
	int stack[MAX], top = -1, i; 
	stack[++top] = start; 
	visited[start] = 1;
	printf("%d", start);

	while (top != -1) {
		start = stack[top];
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				stack[++top] = i; 
				visited[i] = 1;
				printf("%d", i); 
				break; 
			}
		}
		if (i == MAX) top--;
	}
}



void bfsAdjMat(int adj[][MAX], int start, int visited) {
	int queue[MAX], rear = -1, front = -1, i; 

	queue[++rear] = start;
	visited[start] = 1; 

	while (front != rear) {
 		start = queue[++front];
 		printf("%d", start); 
 		for (i = 0; i < MAX; i++) {
 			if (adj[start][i] && visited[i] == 0) {
 				queue[++rear] = i;
 				visited[i] = 1;
 			}
 		}
	}
}













































void heap_sort(int heap[], 	int n) {
	int temp, val, i; 
	int parent; 
	for (i = 0; i < n; i++) {
		while (i > 0){ 
			parent = (i-1)/2;
			if (parent < 0 || heap[parent] > heap[i]) {
				break; 
			} else {
				temp = heap[parent]; 
				heap[parent] = heap[i]; 
				heap[i] = temp; 
				i = parent; 
			}
		}
	}
	for (i = n - 1; i >= 0; i--) {
		val = heap[0];
		heap[0] = heap[i]; 
		heap[i] = val; 

		int child, j = i - 1; 
		while (child >= 0 && child <= j) {
			child = (j*2)+1; 
			if (child >= 0 && heap[child] < heap[child+1]){
				child++; 
			} 
			if (child < 0 || heap[j] > heap[child]) {
				break; 
			} else {
				temp = heap[child]; 
				heap[child] = heap[j];
				heap[j] = temp; 
				j = child;
			}
		}
	}
}










void heapify_down(int a[], int index, int n) {
	int temp, child; 
	int val = a[index]; 
	int i = index;
	while (i >= 0 && i < n) {
		child = (2*i) + 1; 
		if (child < n - 1 && heap[child] < heap[child+1]) {
			child++; 
		}
		if (child >= n || val > heap[child]){ 
			break;
		} else {
			temp = heap[child];
			heap[child] = heap[i];
			heap[i] = temp; 
			i = child;
		}
	}
}



void heapify_down(int a[], int index, int n){
	int child, temp; 
	int val = a[index];

	while (index >= 0 && index < n) {
		child = (index*2) + 1;
		if (child < n - 1 && heap[child] < heap[child+1]) {
			child++; 
		} 
		if (child >= n || heap[index] > heap[child]) {
			break;
		} else {
			temp = heap[child];
			heap[child] = heap[index];
			heap[index] = temp; 
			index = child;
		}
	}
}






void heapifyu_dwon(int a[], int index, index n) {
	int child, temp; 
	int val = heap[index];

	while (index >= 0 && index < n) {
		child = (index*2) + 1; 
		if (child < n - 1 && heap[child] < heap[child+1]){
			child++; 
		} 
		if (child >= n || heap[index] > heap[child]) {
			break;
		} else {
			temp = heap[index]; 
			heap[index] = heap[child];
			heap[child] = temp; 
			index = child; 
		}
	}
}











void heapify_up(int a[], int index) {
	int parent, temp; 
	int val = heap[index]; 

	while (index > 0) {
		parent = (index-1)/2; 
		if (parent < 0 || heap[parent] >= val) {
			break;
		} else {
			temp = heap[index];
			heap[index] = heap[parent]; 
			heap[parent] = temp;
			index = parent; 
		}
	}
}


void heapify_up(int heap[], int index) {
	int parent, temp; 
	int val = heap[index];

	while (index > 0) {
		parent = (index-1)/2; 
		if (parent < 0 || heap[parent] >= val) {
			break;
		} else {
			temp = heap[parent]; 
			heap[parent] = heap[index];
			heap[index] = temp;
			index = parent;
		}
	}
}



void heapify_up(int heap[], int index) {
	int parent, temp; 
	int val = heap[index];

	while (index > 0) {
		parent = (index-1)/2; 
		if (parent < 0 || heap[parent] >= val) {
			break;
		} else {
			temp = heap[index];
			heap[index] = heap[parent];
			heap[parent] = temp; 
			index = parent; 
		}
	}
}




void heapify_down(int a[], int index, int n) {
	int child, temp; 
	int val = heap[index];

	while (index >= 0 && index < n) {
		child = (2*index) + 1; 
		if (child < n - 1 && heap[child] < heap[child+1]) {
			child++;
		} 
		if (child >= n || val > heap[child]) {
			break;
		} else {
			temp = heap[index];
			heap[index] = heap[child];
			heap[child] = temp; 
			index = child; 
		}
	}
}


void heapify_down(int heap[], int index, int n) {
	int child, temp;
	int val = heap[index];

	while (index >= 0 && index < n) {
		child = (index*2) + 1; 
		if (child < n - 1 && heap[child] < heap[child+1]) {
			child++; 
		}
		if (child >= n || val > heap[child]) {
			break;
		} else {
			temp = heap[index];
			heap[index] = heap[child];
			heap[child] = temp; 
			index = child; 
		}
	}
}




void heapify_up(int heap[], int index){
	int parent, temp; 
	int val = heap[index];

	while (index > 0) {
		parent = (index-1)/2;
		if (parent < 0 || heap[parent] > heap[index]) {
			break;
		} else {
			temp = heap[parent];
			heap[parent] = heap[index];
			heap[index] = temp; 
			index = parent; 
		}
	}
}




void heapify_down(int heap[], int index, int n) {
	int child, temp; 
	int val = heap[index]; 

	while (index >= 0 && index < n) {
		child = (2*index) + 1;
		if (child < n - 1 && heap[child] < heap[child + 1]) {
			child++; 
		} 
		if (child >= n || val > heap[child]) {
			break;
		} else {
			temp = heap[child];
			heap[child] = heap[index]; 
			heap[index] = temp; 
			index = child; 
		}
	}

}




void heap_sort(int heap[], int n) {
	int val, i, temp; 

	for (i = 0; i < n; i++) {

		int parent;	
		int val = heap[i]; 

		while (i > 0) {
			parent = (index-1)/2; 
			if (parent < 0 || heap[parent] > heap[i]) {
				break;
			} else {
				temp = heap[parent]; 
				heap[parent] = heap[i];
				heap[i] = temp; 
				i = parent; 
			}
		}
	} 

	for (i = n - 1; i >= 0; i--) {
		val = heap[0];
		heap[0] = heap[i]; 
		heap[i] = temp; 

		int child; 
		val = heap[i-1];

		while (i-1 >= 0 && i-1 < n) {
			child = 2*(i-1) + 1;
			if (child < n - 1 && heap[child] < heap[child+1]) {
				child++;
			}
			if (child >= n || val > heap[child]) {
				break;
			} else {
				temp = heap[child];
				heap[child] = heap[i-1];
				heap[i-1] = temp;
				i = child+1; 
			}
		}  
	}
}




void heap_sort(int heap[], int n) {
	int temp, i, val; 

	for (i = 0; i < n; i++) {
		int parent;
		val = heap[i];
		while (i > 0) {
			parent = (i-1)/2; 
			if (parent < 0 || heap[parent] > heap[i]) {
				break; 
			} else {
				temp = heap[parent];
				heap[parent] = heap[i];
				heap[i] = temp;
				i = parent; 
			}
		}
	}

	for (i = n - 1; i >= 0; i--) {
		val = heap[0];
		heap[0] = heap[i];
		heap[i] = val; 

		int child; 
		val = heap[i-1];
		while (i-1 >= 0 && i-1 < n) {
			int child = 2*(i-1) + 1; 
			if (child < n - 1 && heap[child] < heap[child+1]){
				child++;
			}
			if (child >= n || val > heap[child]) {
				break;
			} else {
				temp = heap[child];
				heap[child] = heap[i-1];
				heap[i-1] = temp;
				i = child+1;
			}
		}


	}
}







void heapify_up(int heap[], int index) {
	int parent, temp; 
	int val = heap[index];

	while (index > 0) {
		parent = (index-1)/2; 
		if (parent < 0 || heap[parent] > heap[index]) {
			break;
		} else {
			temp = heap[parent];
			heap[parent] = heap[index];
			heap[index] = temp; 
			index = parent; 
		}
	}
}


void heapify_down(int heap[], int index, int n) {
	int child, temp; 
	int val = heap[index]; 

	while (index >= 0 && index < n) {
		child = (2*index)+1;
		if (child < n - 1 && heap[child] < heap[child+1]) {
			child++;
		} 
		if (child >= n || val > heap[child]) {
			break;
		} else {
			temp = heap[child];
			heap[child] = heap[index];
			heap[index] = temp; 
			index = child; 
		}
	}
}




void dfs_adj_mat(int adj[][MAX], int start, int visited) {
	int stack[MAX], top = -1, i; 
	stack[++top] = start; 
	visited[start] = 1;
	printf("%d", start); 

	while (top != -1) {
		start = stack[top--];
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				printf("%d", i); 
				stack[++top] = i; 
				visited[i] = 1; 
				break;
			}
		} 
		if (i == MAX) top--; 
	}
}



void bfs_adj_mat(int adj[][MAX], int start, int visited) {
	int queue[MAX], rear = -1, front = -1, i; 

	queue[++rear] = start; 
	visited[start] = 1; 

	while (front != rear) {
		start = queue[++front];
		printf("%d", start); 
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				queue[++rear] = i; 
				visited[i] = 1;
			}
		}
	}
}



typedef struct bstNode {
	int data;
	struct bstNode *left;
	struct bstNode *right; 
} BSTNODE; 


int bstInsert(BSTNODE root, int key) {
	BSTNODE new_node = (BSTNODE *)malloc(sizeof(BSTNODE));

	if (!new_node) {
		printf("Memory allocation failed.");
		return -1;
	} 

	new_node->data = key; 
	new_node->left = NULL;
	new_node->right = NULL;

	BSTNODE parent = NULL, ptr = root; 
	
	while (ptr) {
		parent = ptr; 
		if (key == ptr->value) return -1; 
		else if (key < ptr->value) ptr = ptr->left;
		else if (key > ptr->value) ptr = ptr->right;  
	}


	if (parent == NULL) {
		root = new_node;
	} else if (key < parent->data) {
		parent->left = new_node;
	} else {
		parent->right = new_node;
	}

	update_height(root);

	return 1; 
}



void bst_search(BSTNODE root, int key) {
	BSTNODE ptr = root; 
	while (ptr){
		if (key < ptr->data) ptr = ptr->left; 
		else if (key > ptr->data) ptr = ptr->right; 
		else {
			return 1; 
		}
	}

	return -1;
}



int bstDelete(BSTNODE root, int key) {
	if (root == NULL) {
		return -1; 
	}

	BSTNODE parent = NULL, ptr = root, temp; 

	while (ptr && ptr->data != key) {
		parent = ptr; 
		if (key < ptr->value) {
			ptr = ptr->left;
		} else if (key > ptr->value) {
			ptr = ptr->right; 
		}
	}

	if (!ptr) {
		return 0; 
	}

	if (ptr->left) {
		temp = ptr->left;
	} else if (ptr->right) {
		temp = ptr->right; 
	} else {
		int parent_of_sucessor = ptr, successor = ptr->right;
		
		while (sucessor->left) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left;
		}

		if (parent_of_successor == ptr) {
			successor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right; 
			sucessor->left = ptr->left; 
			sucessor->right = ptr->right; 
		}
		temp = ptr; 

	}
	if (parent == NULL){
		root = temp; 
	} else if (parent->left == ptr) {
		parent->left = temp;
	} else {
		parent->right = temp;
	}
	free(ptr);
}






void bstDelete(BSTNODE root, int key) {
	if (root == NULL) {
		return;
	}

	BSTNODE parent = NULL, ptr = root, temp; 

	while (ptr && ptr->data != key) {
		parent = ptr; 
		if (key < ptr->data) {
			ptr = ptr->left;
		} else if (key > ptr->data) {
			ptr = ptr->right;
		}
	} 

	if (ptr == NULL) {
		printf("Value with key does not exist.");
		return; 
	}

	if (ptr->left == NULL) {
		temp = ptr->right; 
	} else if (ptr->right == NULL) {
		temp = ptr->left; 
	} else {

		int parent_of_sucessor = ptr, sucessor = ptr->right; 

		while (sucessor->left) {
			parent_of_successor = sucessor;
			sucessor = sucessor->left; 
		}

		// parent of sucessor == ptr 
		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left; 
		}
		// sucessor is the leftmost node in ptr->right's tree
		else {
			parent_of_sucessor->left = sucessor->right;
			sucessor->left = ptr->left;
			sucessor->right = ptr->right; 
		}
		temp = sucessor;
		
	}
	if (parent == NULL) {
		root = temp; 
	} else if (parent->left == ptr) {
		parent->left = temp;
	} else {
		parent->right = temp; 
	}
	free(ptr); 
}




void deleteBST(BSTNODE root, int key) {
	if (root == NULL) {
		return; 
	}

	BSTNODE parent = NULL, ptr = root, temp; 

	while (ptr && ptr->data != key) {
		parent = ptr; 
		if (key < ptr) ptr = ptr->left; 
		else if (key > ptr) ptr = ptr->right; 
	}

	if (ptr = NULL) {
		printf("Node with key does not exist.");
		return; 
	}

	if (ptr->left == NULL){
		temp = ptr->right;
	} else if (ptr->right == NULL) {
		temp = ptr->left;
	} else {

		int parent_of_sucessor = ptr, sucessor = ptr->right;

		while (sucessor->left) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left; 
		}

		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right;
			sucessor->left = ptr->left;
			sucessor->right = ptr->right;
		}
		temp = sucessor; 
	}

	if (parent == NULL) {
		root = temp;
	} else if (parent->left == ptr) {
		parent->left = temp;
	} else {
		parent->right = temp;
	}
	free(ptr);
} 





void deleteBST(BSTNODE root, int key) {
	if (root == NULL) {
		return; 
	}

	BSTNODE parent = NULL, ptr = root, temp; 

	while (ptr && ptr->data != key) {
		parent = ptr; 
		if (key < ptr->data) ptr = ptr->left; 
		else if (key > ptr->data) ptr = ptr->right; 
	}

	if (!ptr) {
		printf("Node with key does not exist.");
		return;
	} 

	if (ptr->left == NULL) {
		temp = ptr->right;
	} else if (ptr->right == NULL) {
		temp = ptr->left; 
	} else {

		BSTNODE parent_of_sucessor = ptr, sucessor = ptr->right;

		while (sucessor->left != NULL) {
			parent_of_successor = sucessor; 
			successor = sucessor->left;
		}

		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right; 
			sucessor->left = ptr->left;
			sucessor->right = ptr->right;
		}

		temp = sucessor; 
	}

	if (parent == NULL) {
		root = temp; 
	} else if (parent->left == ptr) {
		parent->left = temp; 
	} else {
		parent->right = temp; 
	}
	free(ptr);
}




// height leaf node 

int bstHeight(BSTNODE root) {
	if (root == NULL) {
		return 0;
	}

	return max(bstHeight(root->right), bstHeight(root->left)) + 1;  
}




int leafCount(BSTNODE root) {
	if (root == NULL) {
		return 0;
	} else if (root->left == NULL && root->right == NULL) {
		return 1; 
	}

	return leafCount(root->left) + leafCount(root->right);	
}





// write a c function TREEINFO treeinfo(TNODE root) that computes the height and the leaves of the bst passedby root

typedef struct node {
	float data;
	struct node *left;
	struct node *right; 
} TNODE; 

typedef struct treeInfo {
	int height; 
	int leafCount; 
} TREEINFO;


TREEINFO treeinfo(TNODE root) {
	TREEINFO info = {0}; 
	int height = 0, leafCount = 0;

	if (root == NULL) {
		return info;
	} else if (root->left == NULL && root->right == NULL) {
		info.leafCount++; 
	} 

	TREEINFO left_height = treeinfo(root->left);
	TREEINFO right_height = treeinfo(root->right);	
	height = max(left_height, right_height) + 1;

	info.height= height;
	
	return info;

}



void insertSinglyLinked(NODE start, int key) {
	NODE new_node = (NODE *)malloc(sizeof(NODE));

	if (!new_node) {
		printf("Memory allocation failed.");
		return;
	}

	new_node->data = key;
	new_node->next = NULL; 

	NODE prev = NULL, curr = start; 

	while (curr) {
		prev = curr;
		curr = curr->next;
	}

	if (prev == NULL) {
		start = new_node;
	} else {
		prev->next = new_node; 
	}

}




typedef struct node {
	int data;
	struct node *left; 
	struct node *right; 
} TNODE;

TNODE breadth_first_search(TNODE *root, int key) {
	if (root == NULL) {
		return NULL; 
	}

	QUEUE *queue = NULL; 
	enqueue(&queue, root); 


	while (queue != NULL) {
		TNODE *ptr = dequeue(&queue, ptr); 	
		if (ptr->data == key) {
			return ptr; 
		} else if (key < ptr->data && ptr->left != NULL) {
			enqueue(&queue, ptr->left);
		} else if (key > ptr->data && ptr->right != NULL) {
			enqueue(&queue, ptr->right); 
		}
	}

	return NULL; 
}




TNODE depth_first_search(TNODE root, int key) {
	if (root == NULL) {
		return NULL; 
	}

	STACK *stack = NULL; 
	push(&stack, root);

	while (stack != NULL) {
		TNODE *ptr = pop(&stack); 
		if (ptr->data == key) {
			return ptr; 
		} else if (key < ptr->data && ptr->left) {
			push(&stack, ptr->left);
		} else if (key > ptr->data && ptr->right) {
			push(&stack, ptr->right);
		}
	}

	return NULL;

}








/*

1. Briefly describe the scenarios of using array and linked lists.

when you need to store random ordered data that doesn't need to be maintained in a specific way. 
E.g use an array or a linked list to store all the countries you've visited.  

2. Briefly describe the scenarios of using queue and stack.

when you when you need to track the order in which data are inserted and most recently inserted data respectively. 
E.g use a queue to track customers queuing in a line for a restaurant. Use a stack to track what tasks you must complete, adding tasks with the most (n) dependencies to the beginning of the stack and tasks with 0 to n-1 dependencies successively. 

3. Use Hoffman tree to encode a given sequence of symbol and
frequencies.

Done!	

4. Get prefix, infix, postfix expression of given expression tree.

Done  

5. Comparison of binary tree, BST, AVL, RBT, in search, insert, delete operations.

			BST | AVL | RBT 

Search  O(h)     O(log n)   O(log n)
  
Insert  O(h)     O(log n)   O(log n), O(log n)

Delete  O(h)     O(log n)   O(log n), O(log n)

6. Insert a given sequence of key values into BST, AVL

YESSSS

1) x
    \ 
     x      rotate left 
      \ 
       x

2) x
  /  \ 
 x    x      right left rotation  
     / \ 
    x   x
    \ 
      x


3) x
  /  \ 
 x    x      left rotation
     / \ 
    x   x
         \
          x 

7. Insert a given sequence of numbers into a hash table using linear probing.

Yes,

(k % m + i) % m

8. Insert a given sequence of numbers into binary heap, and delete-min 

	insert: nodes to the leftmost available position (heapify_up as required)

	delete-min/max: replace min/max node with last node (heapify_down as required)

9. Find MST, shortest path in a given weighted graph.

 	use Prim's algorithm (start at any vertex and choose smallest edge connected to it)

10. Incremental algorithm and aggregate algorithm for simple stats (count, min, max, meffan) computing on linked list and binary tree.



typedef struct bstNode{
	int data;
	struct bstNode *right; 
	struct bstNode *left; 
} NODE; 

typedef struct linkedNode{
	int data; 
	struct *linkedNode next; 
} LISTNODE; 

typedef struct stats{
	int count; 
	int min; 
	int max; 
} STATS;

STATS bstStats(NODE **root) {
	STATS stats = {0}; 
	NODE *ptr; 
	int max = NULL, min = NULL, count = 0;
	int stack[MAX], top = -1;

	stack[++MAX] = root; 
	while (top != -1) {
		ptr = stack[top--];  
		if (ptr) {
			count++; 
			if (ptr->value > max) {
				max = ptr->value; 
			} 
			if (ptr->value < min) {
				min = ptr->value; 
			}
		}
		if (ptr->left) ptr = stack[++top];
		if (ptr->right) ptr = stack[++top]; 
	}
	stats.max = max; 
	stats.min = min; 
	stats.count = count;
	return stats;
} 

STATS statsLinkedList(LISTNODE *start) {
	STATS stats = {0}; 
	LISTNODE *ptr = start; 
	int min, max, count; 

	while (ptr != NULL) {
		count++; 
		if (min < ptr->data) min = ptr->data;
		if (max > ptr->data) max = ptr->data; 
		ptr = ptr->next; 
	}

	stats.min = min; 
	stats.max = max;
	stats.count = count; 
	return stats;
}
*/








/*
5. Hash tables and applications, i.e., design a hash table and function to count words and their frequencies of given text string.

6. Binary heap, heapify-up, heapify-down, insert, delete-min, change-key, heap sort.
*/








/*

Write a C function to display element backward from a singly linked list using iterative algorithm with auxiliary data structure.

3. For binary tree, write C functions to do traversal (in pre-order, in-order and post-order), depth-first-order, breath-first-order, to compute number of nodes, height, number of leaves

Hash tables and applications, i.e., design a hash table and function to count words and their frequencies of given text string. 
*/


// Write a C function to display element backward from a singly linked list using iterative algorithm with auxiliary data structure.

void displayBackwardsSinglyLinkedList(SL_LIST a) {

	if (a == NULL) {
		return;
	}

	STACK stack = NULL; 
	SL_LIST curr = a; 

	while (curr) {
		push(&stack, curr);
		curr = curr->next; 
	}


	while (stack != NULL) {
		curr = pop(&stack);
		printf("%d", curr->data);
	}

	return; 

}



int totalNodesBST(BSTNODE root) {
	if (root == NULL) {
		return 0;
	}

	QUEUE queue = NULL; 
	BSTNODE temp;
	int node_count = 0;
	enqueue(&queue, root); 

	while (queue != NULL) {
		temp = dequeue(&queue); 
		node_count++;

		if (temp->left) {
			enqueue(&queue, temp->left);
		} 
		if (temp->right) {
			enqueue(&queue, temp->right);
		}
	}

	return node_count;

}










// hash tables



typedef struct hashnode {
  int key;
  int value;
} hashnode;

typedef struct hashtable {
  hashnode **hnp; // pointer pointing to the first element of an array of hashnode pointers 
  int size;       // the maximum of number of array elements
  int count;      // number of data elements in the hash table
} hashtable;


int hash(int key) {
  return key % SIZE;
}


hashnode *search(hashtable *ht, int key) { 
  int i = hash(key);
  while (ht->hnp[i] != NULL) {
    if (ht->hnp[i]->key == key && ht->hnp[i]->key != -1)
      return ht->hnp[i];

    ++i;
    if (i >= ht->size)
      i %= ht->size; //wrap around the table
  }
  return NULL;
}









/*
SIZE = 3

table -> hp -> [key, value] -> [key, value] -> [key, value]  

*/ 


typedef struct hashnode{ 
	char key[SIZE]; 
	int value; 
} HASHNODE; 

typedef struct hashtable{ 
	struct hashnode **hp;
	int size; 
	int count; 
} HASHTABLE;


HASHNODE *create_hash_node(char *key, int value) {
	HASHNODE *node = (HASHNODE *)malloc(sizeof(HASHNODE)); 
	strcpy(node->key, key); 
	node->value = value; 
	return node;
}

HASHTABLE *create_hash_table(int size) {
	HASHTABLE *table = (HASHTABLE *)malloc(sizeof(HASHTABLE)); 
	*table->hp = (HASHNODE **)malloc(sizeof(HASHNODE*)*size); 
	
	for (int i = 0; i < size; i++) {
		table->hp[i] = NULL; 
	} 

	table->size = size; 
	table->count = 0;
	return table;
}

// key % SIZE 
int hash(char *key) {
	int i = 0, k;
	while (key[i] != '\0') {
 		k += key[i];
 		i++; 
	}
	return k % SIZE;
}

HASHTABLE countFrequencyOfWordsInString(char *string) {
	char key[SIZE]; 
	int i, k; 

	HASHTABLE *table = create_hash_table(SIZE); 

	while (string[i] != '\0') {
		while (string[i] != ' ') {
			key[k] = string[i];
			k++, i++; 
		}
		key[k] = '\0';

		HASHNODE *keyExists = search(table, key);

		if (keyExists) {
			keyExists->value++; 
		} else {
			insert(table, new_hash_node(key, 1)); 
		}
	}	
	return table; 
}







// heapsort, bst insert delete height leaf node, adj matrix bfs and dfs, 


void heap_sort(int heap[], int n) {
	int i, val, temp; 

	for (i = 0; i < n; i++) {
		int parent; 
		while (i > 0) {
			parent = (i-1)/2; 
			if (parent < 0 || heap[parent] > heap[i]) {
				break;
			} else {
				temp = heap[parent];
				heap[parent] = heap[i];
				heap[i] = temp; 
				i = parent; 
			}
		}
	}

	for (i = n - 1; i >= 0; i--) {
		val = heap[0];
		heap[0] = heap[i];
		heap[i] = val; 

		int child;
		while (i-1 >= 0 && i-1 < n) {
			child = 2*(i-1)+1; 
			if (child < n - 1 && heap[child] < heap[child] + 1) {
				child++; 
			} 
			if (child >= 0 || heap[i-1] > heap[child]) {
				break;
			} else {
				temp = heap[child];
				heap[child] = heap[i-1];
				heap[i-1] = temp; 
				i = child+1;
			}
		}

	}
}




void heap_sort(int heap[], int n) {
	int temp, i, val; 

	for (i = 0; i < n; i++) {
		int parent;
		val = heap[i];
		while (i > 0) {
			parent = (i-1)/2; 
			if (parent < 0 || heap[parent] > heap[i]) {
				break; 
			} else {
				temp = heap[parent];
				heap[parent] = heap[i];
				heap[i] = temp;
				i = parent; 
			}
		}
	}

	for (i = n - 1; i >= 0; i--) {
		val = heap[0];
		heap[0] = heap[i];
		heap[i] = val; 

		int child; 
		val = heap[i-1];
		while (i-1 >= 0 && i-1 < n) {
			int child = 2*(i-1) + 1; 
			if (child < n - 1 && heap[child] < heap[child+1]){
				child++;
			}
			if (child >= n || val > heap[child]) {
				break;
			} else {
				temp = heap[child];
				heap[child] = heap[i-1];
				heap[i-1] = temp;
				i = child+1;
			}
		}


	}
}




void heapify_up(int heap[], int index) {
	int parent, temp; 

	while (parent >= 0) {
		parent = (index-1)/2; 
		if (parent < 0 || heap[parent] > heap[index]) {
			break;
		} else {
			temp = heap[parent];
			heap[parent] = heap[index];
			heap[index] = temp; 
			index = parent; 
		}
	}
}


void heapify_down(int heap[], int index, int n) {
	int child, temp; 

	while (index >= 0 && index < n) {
		child = (2*index)+1; 
		if (child < n - 1 && heap[child] < heap[child] + 1) {
			child++; 
		} 
		if (child <= 0 || heap[index] > heap[child]) {
			break;
		} else {
			temp = heap[child];
			heap[child] = heap[index];
			heap[index] = temp; 
			index = child;
		}
	}
}




int bst_insert(BSTNODE *root, int key){

	BSTNODE new_node = (BSTNODE *)malloc(sizeof(BSTNODE)); 

	if (!new_node) {
		printf("Memory allocation failed.");
		return 0;
	}

	new_node->data = key; 
	new_node->left = NULL; 
	new_node->right = NULL;

	BSTNODE ptr = root, parent = NULL; 

	while (ptr) {
		parent = ptr; 
		if (ptr->data == key) {
			printf("Node with key exists.");
			return 0; 
		} else if (key < ptr->data) {
			ptr = ptr->left;
		} else if (key > ptr->data) {
			ptr = ptr->right;
		}
	}

	if (parent == NULL) {
		root = new_node;
	} else if (parent->right == ptr) {
		parent->right = new_node; 
	} else if (parent->left == ptr) {
		parent->left = new_node; 
	}

	update_height(root);

	return 1;
}



int delete_BST(BSTNODE root, int key) {

	if (root == NULL) {
		return 0; 
	}

	BSTNODE ptr = root, parent = NULL, temp; 

	while (ptr && ptr->data != key) {
		parent = ptr; 
		if (key < ptr->data) {
			ptr = ptr->left; 
		} else if (key > ptr->data) {
			ptr = ptr->right; 
		}
	}

	if (!ptr) {
		return 0; 
	}

	if (ptr->left == NULL) {
		temp = ptr->right; 
	} else if (ptr->right == NULL) {
		temp = ptr->left; 
	} else {

		BSTNODE parent_of_successor = ptr, successor = ptr->right;

		while (sucessor->left) {
			parent_of_successor = sucessor; 
			sucessor = sucessor->left;
		}

		if (parent_of_successor == ptr) {
			sucessor->left = ptr->left; 
		} else {
			parent_of_successor->left = sucessor->right; 
			sucessor->left = ptr->left;
			sucessor->right = ptr->right; 
		}
		temp = successor;
	}

	if (parent == NULL) {
		root = temp; 
	} else if (parent->left == ptr) {
		parent->left = temp; 
	} else {
		parent->right = temp; 
	}

	free(ptr);
	return 1; 
}





void bstSearch(BSTNODE root, int key) {

	BSTNODE ptr = root, parent = NULL; 

	while (ptr) {
		if (ptr->data == key) {
			return ptr;
		} else if (key < ptr->data) {
			ptr = ptr->left; 
		} else if (key > ptr->data) {
			ptr = ptr->right; 
		}
	}

	return NULL; 
}




int heightOfBST(BSTNODE root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + max(heightOfBST(root->left), heightOfBST(root->right));
}


int leafCountOfBST(BSTNODE root) {
	if (root == NULL) {
		return 0;
	} else if (root->left == NULL && root->right == NULL) {
		return 1;
	} 
	return leafCountOfBST(root->left) + leafCountOfBST(root->right); 
}









void dfTraversalBST(BSTNODE root) {

	STACK stack = NULL;
	BSTNODE ptr; 

	push(&stack, root);
 
	while (stack != NULL) {
		ptr = pop(&stack);
		printf("%d", ptr->data);
		if (ptr->left) {
			push(&stack, ptr->left);
		} 
		if (ptr->right) {
			push(&stack, ptr->right);
		}
	}

}



void dfTraversalBST(BSTNODE root) {

	STACK stack = NULL;
	BSTNODE ptr; 

	push(&stack, root);
 
	while (stack != NULL) {
		ptr = pop(&stack);
		printf("%d", ptr->data);
		if (ptr->left) {
			push(&stack, ptr->left);
		} 
		if (ptr->right) {
			push(&stack, ptr->right);
		}
	}

}

int dfsBST(BSTNODE root, int key) {

	STACK stack = NULL;
	BSTNODE ptr; 

	push(&stack, root);
 
	while (stack != NULL) {
		ptr = pop(&stack);
		if (ptr->data == key) return ptr; 
		else {
			if (ptr->left) {
				push(&stack, ptr->left);
			} 
			if (ptr->right) {
				push(&stack, ptr->right);
			}
		} 
	}
	return NULL; 

}




void bfTraversalBST(BSTNODE root) {

	QUEUE queue = NULL;
	BSTNODE ptr; 

	enqueue(&queue, root);
 
	while (queue != NULL) {
		ptr = dequeue(&queue);
		printf("%d", ptr->data);
		if (ptr->left) {
			enqueue(&queue, ptr->left);
		} 
		if (ptr->right) {
			enqueue(&queue, ptr->right);
		}
	}
}



int bfsBST(BSTNODE root, int key) {
	if (root == NULL) {
		return NULL; 
	}

	QUEUE queue = NULL; 
	BSTNODE ptr;

	enqueue(&queue, root); 

	while (ptr) {
		ptr = dequeue(&queue);
		if (ptr->data == key) {
			return ptr;
		} else {
			if (ptr->left) {
				enqueue(&queue, ptr->left);
			}
			if (ptr->right) {
				enqueue(&queue, ptr->right);
			}
		}
	}

	return NULL; 
}





void depthFirstAdjMat(int a[][MAX], int visited, int start) {

	int stack[MAX], top = -1, i; 

	stack[++top] = start;
	visited[start] = 1; 
	printf("%d", start); 

	while (top != -1) {
		start = stack[top];
		for (i = 0; i < MAX; i++) {
			if (adj[start][i] && visited[i] == 0) {
				stack[++top] = i; 
				visited[i] = 1;
				printf("%d", i);
				break; 
			}
		}
		if (i == MAX) top--; 
	}

}


int dfsAdjMat(int a[][MAX], int visited, int start, int key) {

	int stack[MAX], top = -1, i; 

	stack[++top] = start;
	visited[start] = 1; 

	while (top != -1) {
		start = stack[top];
		if (start == key) return start;
		else {
			for (i = 0; i < MAX; i++) {
				if (adj[start][i] && visited[i] == 0) {
					stack[++top] = i; 
					visited[i] = 1;
					break; 
				}
			}
			if (i == MAX) top--; 
		}
	}

	return 0;
}



int bfsAdjMat(int a[][MAX], int visited, int start) {

	int queue[MAX], rear = -1, front = -1, i; 

	queue[++rear] = start;
	visited[start] = 1; 

	while (rear != front) {
		start = queue[++front];
		printf("%d", start);
		for (i = 0; i < MAX; i++) {
			if (a[start][i] && visited[i] == 0) {
				queue[++rear] = i; 
				visited[i] = 1;
			}
		}
	}
 
}




/*
Briefly describe the scenarios of using array and linked lists.

arrays can be used for random access as they offer constant time complexity when retrieving any data element. Additionally arrays are fixed in length, which is particularly helpful for when you know the number of data elements you are working with beforehand. This eliminates the concern of dynamically allocating and freeing memory. 

linked lists are particularly helpful when you do not know the size of the data you are working with. Because nodes are created dynamically, you can adjust the size of your linked list at a moment's notice. They are also efficient when inserting and deleting elements, as pointers are simply updated rather than the data themselve. 


2. Briefly describe the scenarios of using queue and stack.

queues are used when you need to preserve and track the order in which data elements are inserted. The queue follows a FIFO mechanism, which means that the first inserted data memeber will be the first removed data member. This is particularly useful for lineups, hence the name 'queue'.

stacks are used when you need to frequently access the last inserted data element. Stacks follow a LIFO mechanism, which means that the most recently inserted data member will be the first data member removed from the stack. This can be seen in task scheduling or backtracking algorithms.  


3. Use Hoffman tree to encode a given sequence of symbol and
frequencies.

Yessir, left = 0, right = 1

4. Get prefix, infix, postfix expression of given expression tree.

Yessir

5. Comparison of binary tree, BST, AVL, RBT, in search, insert, delete operations.


       | BST | AVL | RBT |
-------|-----|-----|-----|
Search |O(h) O(logn) O(logn)
delete |O(h) O(logn) O(logn), O(logn)
insert |O(h) O(logn) O(logn), O(logn)

rest are constant time 


6. Insert a given sequence of key values into BST, AVL
7. Insert a given sequence of numbers into a hash table using linear probing.
8. Insert a given sequence of numbers into binary heap, and delete-min 9. Find MST, shortest path in a given weighted graph.
10. Incremental algorithm and aggregate algorithm for simple stats (count, min, max, mean) computing on linked list and binary tree.
*/
