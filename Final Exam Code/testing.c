

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define SIZE 20 


typedef struct hashnode { 
     char *key[SIZE]; 
     int value;
} HASHNODE;  

typedef struct hashtable {
     struct hashnode **hp; // pointing to a pointer of the start of an array of hashnode pointers
     int size; 
     int count; 
} HASHTABLE; 


HASHNODE *new_hashnode(char *key, int value) {
     HASHNODE *node = (HASHNODE *)malloc(sizeof(HASHNODE)); 
     *node->key = strdup(key);
     node->value = value; 
     return node; 
}


HASHTABLE *new_hashtable(int size) {
     HASHTABLE *table = (HASHTABLE *)malloc(sizeof(HASHTABLE));
     table->hp = (HASHNODE **)malloc(sizeof(HASHNODE*)*size);
     for (int i = 0; i < size; i++) {
          table->hp[i] = NULL; 
     }
     table->count = 0;
     table->size = size; 
     return table; 
}


void countFrequencyOfWordsInString(char *string) {
     HASHTABLE *table = new_hashtable(SIZE);

     char key[SIZE];
     int i, k;
     while (string[i] != '\0') {
          while (string[i] != ' ') {
               key[k] = string[i]; 
               i++; 
               k++; 
          }
          key[k] =  '\0'; 
          HASHNODE *node = search(table, key); 
          if (node) {
               node->value++; 
          } else {
               int index = hash(key); 
               table->hp[index] = new_hashnode(key, 1); 
          }
     }
}

int main() {
     char *key = "hello";
     int value = 10; 
     HASHNODE *node = new_hashnode(key, value);
     HASHTABLE *table = new_hashtable(20);
     printf("%s\n",*node->key);
     return 0;
}


typedef struct hashnode {
     char key[SIZE]; 
     int value;
     struct hashnode *next; 
} HASHNODE;

typedef struct hashtable {
     struct hashnode **hp; 
     int size;
     int count; 
} HASHTABLE; 


HASHNODE *new_node(char *key, int value) {
     HASHNODE *node = (HASHNODE *)malloc(sizeof(HASHNODE));
     node->next = NULL;
     strcpy(node->key, key);
     node->value = value;
     return node;
}

HASHTABLE *new_table(int size) {
     HASHTABLE *table = (HASHTABLE *)malloc(sizeof(HASHTABLE));
     table->hp = (HASHNODE **)malloc(sizeof(HASHNODE *)*size);
     for (int i = 0; i < size; i++) {
          *(table->hp+i) = NULL;
     }
     table->count = 0; 
     table->size = size;
     return table; 
}






























