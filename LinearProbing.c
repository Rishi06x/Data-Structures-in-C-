#include<stdio.h>
#include<stdlib.h>
#define size 10

typedef struct{
    int key[size];
    int value[size];
    int occupied[size];
} table;

int hashfunction(int key){
    return key % size;
}

void insert(table *hashtable, int key, int value){
    int index = hashfunction(key);
    int originalIndex = index;
    while(hashtable->occupied[index] == 1){
        index = (index + 1) % size;
        if(index == originalIndex){
            printf("Hashtable is full\n");
            return;
        }
    }
    hashtable->occupied[index] = 1;
    hashtable->value[index] = value;
    hashtable->key[index] = key;
    printf("Inserted key %d with value %d at index %d\n", key, value, index);
}

int search(table *hashtable, int key){
    int index = hashfunction(key);
    int originalIndex = index;
    while(hashtable->occupied[index] == 1){
        if(hashtable->key[index] == key){
            return hashtable->value[index];
        }
        index = (index + 1) % size;
        if(index == originalIndex){
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n");
    return -1;
}

void display(table *hashtable){
    printf("HashTable:\n");
    for(int i = 0; i < size; i++){
        if(hashtable->occupied[i] == 1){
            printf("Index %d: key: %d, value: %d\n", i, hashtable->key[i], hashtable->value[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

void initialize(table *hashtable){
    for(int i = 0; i < size; i++){
        hashtable->occupied[i] = 0;
    }
}

int main(){
    table hashtable;

    for(int i = 0; i < size; i++){
        hashtable.key[i] = -1;
        hashtable.value[i] = -1;
        hashtable.occupied[i] = 0;
    }

    initialize(&hashtable);
    insert(&hashtable, 23, 100);
    insert(&hashtable, 43, 200);
    insert(&hashtable, 22, 300);
    insert(&hashtable, 24, 400);
    insert(&hashtable, 53, 500);
    insert(&hashtable, 14, 600);
    insert(&hashtable, 10, 700);

    display(&hashtable);

    int key = 53;
    int value = search(&hashtable, key);
    if(value != -1) {
        printf("Value for key %d: %d,Index:%d\n", key, value);
    }
    else{
        printf("Key not found\n");
    }
    return 0;
}
