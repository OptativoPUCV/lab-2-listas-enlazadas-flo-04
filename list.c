#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* lista = (List*)malloc(sizeof(List));
    lista -> head = NULL;
    lista -> tail = NULL;
    lista -> current = NULL;
    
     return lista;
}

void * firstList(List * list) {
    
    Node* primero = list -> head;
    list -> current = primero;
    return primero->data;
}

void * nextList(List * list) {
    Node* sig = list->current->next;
    if(sig == NULL) return NULL;
    list->current = sig;
    return sig->data;
}

void * lastList(List * list) {
    Node* ultimo = list-> head;
    while(ultimo != NULL){
        ultimo = ultimo->next;
    }
    list->current = ultimo;
    return ultimo->data;
}

void * prevList(List * list) {
    Node* previo = list->current->prev;
    list->current = previo;
    return previo->data;
}

void pushFront(List * list, void * data) {
    Node* dato = createNode(data);
    if (list -> head != NULL){
        list->head -> prev = dato;
    }
    dato->next = list->head;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}