


// design a hash table and function to count words and their frequencies of given text string. 


#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define SIZE 20

typedef struct hashnode {

     char *key[SIZE];
     int value; 
} HASHNODE;


typedef struct hashtable {
     struct hashnode **hnp; 
     int size; 
     int count; 
} HASHTABLE;


HASHNODE *new_hashnode(char key[], int value) {
     HASHNODE *node = (HASHNODE*)malloc(sizeof(HASHNODE));
     strcpy(*node->key, key);
     node->value = value;
     return node; 
}

HASHTABLE *new_hashtable(int size) {
     HASHTABLE *h_table = (HASHTABLE *)malloc(sizeof(HASHTABLE));
     h_table->hnp = (HASHNODE**)malloc(sizeof(HASHNODE*)*size);

     int i; 
     for (i = 0; i<size; i++) {
          h_table->hnp[i] = NULL; 
     }
     
     h_table->count = 0;
     h_table->size = size; 
     return h_table; 
}
// division method = (k%m)
int hash(char *key) {
     int i, k; 
     while (key[i] != '\0') {
          k += key[i];
          i++; 
     }
     return k % SIZE; 
}




HASHNODE *search(HASHTABLE *ht, char *key) {
     int i = hash(key);
     while (ht->hnp[i] != NULL) {
          if (strcmp(*ht->hnp[i]->key, key) == 0) {
               return ht->hnp[i];
          }
          ++i;
          if (i >= ht->size) {
               i %= ht->size; 
          }
     }
     return NULL; 
}

void insert(HASHTABLE *ht, HASHNODE *hn) {
     int i = hash(*hn->key);
     while (ht->hnp[i] != NULL) {
          ++i;
          if (i >= ht->size) {
               i %= ht->size; 
          }
     }
     ht->hnp[i] = hn; 
     ht->count++; 
}
HASHTABLE *calculateFrequencyOfWords(char str[]){

     HASHTABLE *table = new_hashtable(SIZE); 
     
     int i = 0; 
     while (str[i] != '\0') {
          if (str[i] != ' ') {
               char key[SIZE];
               int j = 0; 
               while (str[i] != ' ') {
                    key[j] = str[i];
                    j++;
                    i++;
               }
               key[j] = '\0';
               HASHNODE *node = search(table, key);
               if (node) {
                    node->value++;
               } else {
                    insert(table, new_hashnode(key, 1));
               }
          }
     }
     return table;
}



hashtable calculateFrequencyOfWordsInText(char *string){

     hashtable *table = new_hashtable(SIZE);
     char key[SIZE];
     int i, j;

     while (string[i] != '\0') {
          while (string[i] != ' '){
               key[j] = string[i];
               i++, j++;
          }
          key[j] = '\0';

          hashnode val = search(&table, key);
          if (val) {
               val->value++;
          } else {
               insert(&table, new_hashnode(key, 1));
          }
     }
     return table;
}




int main() {
     char str[] = "vast expanse random occurrence shimmering stars twinkling midnight sky sky vast endless holds secrets untold mysteries waiting unfold unfold layers existence peel back veil reality reveal hidden truths truths like whispers wind echo corridors time time relentless march forward yet eternally cyclical nature";

     HASHTABLE *table = calculateFrequencyOfWords(str);
     int i;
     for (i = 0; i < SIZE; i++) {
          if (table->hnp[i] != NULL) {
               printf("%s: %d\n", table->hnp[i]->key, table->hnp[i]->value);
          }
     }
     return 0;
     
}















HASHNODE *search(HASHTABLE *table, int key) {
     if (table->count = 0) {
          return; 
     }

     int i = key % table->size; 
     HASHNODE *ptr = *(table->hnp+i);
     while (ptr) {
          if (ptr->key == key) {
               return ptr;
          } 
          ptr = ptr->next; 
     }
     return NULL; 
}




// insert 

void insert_hash_table(hashtable *table, hashnode *node) {
     int key = node->key; 
     int index = hash(key);
     hashnode *start = *(table->hnp+index), prev = NULL; 

     while (start != NULL && key > start->key) {
          prev = start;
          start = start->next; 
     }

     if (prev == NULL) {
          *(table->hnp+index) = node; 
     } else {
          prev->next = node;
     }
     node->next = start; 
     table->count++; 
}


// search 

hashnode search_hash_table(hashtable *table, int key) {

     if (table->count == 0) {
          return NULL; 
     }

     int i = hash(key); 
     hashnode *node = *(table->hnp+i); 

     while (node) {
          if (node->key == key) {
               return node; 
          } 
          node = node->next;
     }

     return NULL; 

}



// insert 
// node = next | value | key 
// table = hnp | size | count 
void insert_hash_table(hashtable *table, hashnode *node) {
     
     int key = node->key; 
     int i = hash(key); 

     hashnode *ptr = *(table->hnp + i), prev = NULL; 

     while (ptr && key > ptr->key) {
          prev = ptr; 
          ptr = ptr->next; 
     }

     if (prev == NULL) {
          *(table->hnp+i) = node;
     } else {
          prev->next = node;
     }
     node->next = ptr; 

     table->count++; 
}


int delete_hash_table(hashtable *table, int key) {
     if (table->count == 0) {
          return 0; 
     }

     int i = hash(key);

     hashnode *ptr = *(table->hnp+i), prev = NULL; 

     while (ptr && key > ptr->key) {
          prev = ptr; 
          ptr = ptr->next; 
     }

     if (ptr && ptr->key == key)
     {
          if (prev)
          {
               prev->next = ptr->next;
          } else {
               *(table->hnp+i) = NULL; 
          }
          free(ptr);
          table->count--; 
          return 1;
     }
     return 0; 

}




hashnode search_hash_table(hashtable table, int key) {

     int i = hash(key); 

     hashnode *ptr = *(table->hnp+i), prev = NULL; 

     while (ptr) {
          if (ptr->key ==  key) {
               return ptr;
          }
          ptr = ptr->next;
      }

      return NULL; 
}




void insert_hash_table(hashtable *table, hashnode *node) {

     int key = node->key; 
     int i = hash(key);
     hashnode *ptr = *(table->hnp+i), prev = NULL; 

     while (ptr && key > ptr->value) {
          prev = ptr; 
          ptr = ptr->next; 
     }
     if (prev ==  NULL) {
          *(table->hnp+i) = node;
     } else {
          prev->next = node;
     }
     node->next = ptr; 

     table->count++; 
}



int delete_hash_table(hashtable *table, int key) {

     if (table->count == 0) {
          printf("The hashtable is empty");
          return 0; 
     }

     int i = hash(key);
     hashnode *ptr = *(table->hnp+i), prev = NULL; 

     while (ptr && key > ptr->key) {
          prev = ptr;
          ptr = ptr->next; 
     }

     if (ptr && ptr->key == key) {
          if (prev == NULL) {
               *(table->hnp+i) = NULL; 
          } else {
               prev->next = ptr->next;
          }
          free(ptr);
          table->count--;
          return 1;
     }
     return 0;
}








typedef struct hashnode { 

     char key[SIZE]; 
     int value; 

     // if linked: 
     struct hashnode *next; 

};

typedef struct hashtable {

     int count; 
     int size; 
     struct hashnode **hnp; 

};










/*

10. Incremental algorithm and aggregate algorithm for simple stats (count, min, max, mean) computing on linked list and binary tree.
*/


typedef struct stats{
     int count; 
     int min; 
     int max; 
     float mean; 
} STATS; 


STATS bstStats(BSTNODE root)  {
     STATS stats = {0};

     if (root == NULL) {
          return stats;
     }

     BSTNODE ptr; 
     STACK stack = NULL; 

     int count = 0;
     int min = root->data, max = root->data; 
     float mean = 0.0; 

     push(&stack, root);

     while (stack != NULL) {
          ptr = pop(&stack);

          count++; 
          mean += ptr->data; 
          if (ptr->data < min) min = ptr->data;
          if (ptr->data > max) max = ptr->data; 

          if (ptr->left) push(&stack, ptr->left);
          if (ptr->right) push(&stack, ptr->right);
     }
     if (count != 0) stats.mean = mean/count;
     else stats.mean = 0;  
     stats.max = max;
     stats.min = min; 
     stats.count = count; 

     return stats; 
}



STATS linkedListStats(NODE head) {

     STATS stats = {0}; 

     if (head == NULL) return stats;

     int max = head->data, min = head->data; 
     int count = 0;
     float mean = 0.0; 

      NODE curr = head;

     while (curr != NULL) {
          count++;
          mean += curr->data; 

          if (curr->data < min) min = curr->data;
          if (curr->data > max) max = curr->data; 

          curr = curr->next; 
     }

     if (count != 0) {
          stats.mean = mean/0;
     } else {
          stats.mean = 0;
     }
     stats.count = count;
     stats.max = max;
     stats.min = min; 
     return stats;
}






typedef struct hashnode {
     char key[SIZE];
     int value; 
     struct hashnode *next; 
} hashnode;

typedef struct hashtable {
     struct hashnode **hnp; 
     int count; 
     int size;
} hashtable; 



hashnode *new_hashnode(char *key, int value) {
     hashnode *new_node = (hashnode *)malloc(sizeof(hashnode)); 
     strcpy(new_node->key, key);
     new_node->value = value;
     new_node->next = NULL; 
     return new_node;
}


hashnode *new_hashtable(int size) {
     hashtable *table = (hashtable *)malloc(sizeof(hashtable));
     *(table->hnp) = (hashnode **)malloc(sizeof(hashnode *)*size);
     
     for (int i = 0; i < size; i++) {
          *(table->hnp+i) = NULL; 
     }
     table->count = 0; 
     table->size = 0; 

     return table; 
}



hashnode search_hashtable(hashtable *table, int key) {

     int indx = hash(key);

     hashnode *ptr = *(table->hnp+indx);

     while (ptr) {
          if (ptr->value == key) return ptr; 
          ptr = ptr->next; 
     }

     return NULL; 
}




int insert_hashtable(hashtable *table, hashnode *node) {

     char *key = node->key; 
     int i = hash(key);

     hashnode *ptr = *(table->hnp+i), *prev = NULL;

     while (ptr && strcmp(ptr->key, key) < 0) {
          prev = ptr; 
          ptr = ptr->next; 
     }

     if (prev == NULL) {
          *(table->hnp+i) = node; 
     } else { 
          prev->next = node;
     }
     node->next = ptr;
     table->count++;

     return 1;
}





int delete_hashtable(hashtable *table, int value) {
     if (table->count == 0) {
          return -1;
     }

     int i = hash(value);

     hashnode *curr = *(table->hnp+i), prev = NULL;

     while (curr && curr->value != value) {
          prev = curr; 
          curr->curr->next;
     }

     if (prev == NULL) {
          *(table->hnp+i) = NULL;
     } else {
          prev->next = curr->next; 
     }
     free(curr);
     table->count--;     
     return 1; 

}






































