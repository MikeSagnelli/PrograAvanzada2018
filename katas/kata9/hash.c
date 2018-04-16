#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

unsigned doHash(int key, unsigned size){
    // unsigned hash = 5381;
    // int c;

    // while (c = key++){
    //     hash = ((hash << 5) + hash) + c;
    // }
    return key % size;
}

void hashInit(HashInt *hash, unsigned size){
    hash->size = size;
    hash->data = (HashElement *)calloc(size, sizeof(HashElement));
}

static void hashDoInsert(HashInt *hash, int key, int value){
    unsigned indekey = doHash(key, hash->size);
    HashElement *currentHashElement = &(hash->data[indekey]);
    if(currentHashElement->elements == NULL){
        currentHashElement->elements = (Element *)malloc(2 * sizeof(Element));
        currentHashElement->count = 0;
        currentHashElement->length = 2;
    }
    if(currentHashElement->length == currentHashElement->count){
        currentHashElement->length *= 2;
        currentHashElement->elements = (Element *)realloc(currentHashElement->elements, currentHashElement->length * sizeof(Element));
    }
    currentHashElement->elements[currentHashElement->count].key = key;
    currentHashElement->elements[currentHashElement->count].value = value;
    currentHashElement->count += 1;
}

static void hashDoUpdate(HashInt *hash, int key, int value){
    unsigned pos = doHash(key, hash->size);
    Element *currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;

    for(int i = 0; i < currentElementsLength; i++){
        if(key == currentElements[i].key){
            currentElements[i].value = value;
            break;
        }
    }
}

int * hashGet(HashInt *hash, int key){
    int pos = doHash(key, hash->size);
    Element *currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;
    int *value = NULL;

    for(int i = 0; i < currentElementsLength; i++){
        if(key == currentElements[i].key){
            value = (int *)malloc(sizeof(int));
            *value = currentElements[i].value;
            break;
        }
    }

    return value;
}

void hashInsert(HashInt *hash, int key, int value){
    int *oldValue = hashGet(hash, key);
    if(oldValue == NULL){
        hashDoInsert(hash, key, value);
    }
    else{
        hashDoUpdate(hash, key, value);
    }
}