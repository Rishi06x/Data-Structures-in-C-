#include<stdio.h>
#define size 10

typedef struct{
    int key[size];
    int value[size];
    int occupied[size];
}hashtable;

void initialize(hashtable *table){
    for(int i=0; i<size; i++){
        table->occupied[i] = 0;
    }
}

int hashFunction(int key){
    return key % size;
}

void insert(hashtable *table, int key, int value){
    int index = hashFunction(key);
    int i=0;
    while(table->occupied[index] == 1){
        index = (index + i*i) % size;
        i++;
    if(i>=size){
    printf("HashTable is full\n");
    return;
    }
    }
    table->key[index] = key;
    table->value[index] = value;
    table->occupied[index] = 1;
    printf("Key %d inserted with value %d at index %d\n", key, value, index);
}

int search(hashtable *table, int key){
    int index = hashFunction(key);
    int i=0;
    while(table->occupied[index] == 1){
        if(table->key[index] == key){
            return table->value[index];
        }
        index = (index + i*i) % size;
        i++;
        if(i>=size){
            printf("Key not found\n");
            return -1;
        }
    }
    printf("Key not found\n");
    return -1;
}

void display(hashtable *table){
    printf("Key: Value\n");
    for(int i=0; i<size; i++){
        if(table->occupied[i] == 1){
            printf("%d: %d\n", table->key[i], table->value[i]);
        }
    }
    printf("\n");
}

int main(){
    hashtable table;
    initialize(&table);
    insert(&table, 10, 100);
    insert(&table, 25, 200);
    insert(&table, 33, 300);
    insert(&table, 45, 400);
    insert(&table, 5, 500);
    insert(&table, 11, 600);

    display(&table);

    int key = 20;
    int value = search(&table,key);

    if(value != -1) {
        printf("Value for key %d: %d\n", key, value);
    }
    else{
        printf("Key not found\n");
    }
    return 0;

    
}