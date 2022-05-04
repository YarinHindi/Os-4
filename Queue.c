#include "Node.c"
#include <strings.h>
#include "stdio.h"
#include "heap.c"

#define MAX_LENGTH 1024
typedef struct Queue {
    Node *head;
    Node * tail;
}Queue;

Node *Qtop(Node **head) {
    if(*head==NULL){}
    return (*head);
}

void initializeQueue(Node **head,Node **tail) {
    (*head) = NULL;
    (*tail)= NULL;
}


void Qpop(Node **head) {
    if ((*head)  == NULL) {
        return;
    }
    if ((*head)->next  == NULL) {
        Myfree((*head)->data);
        Myfree((*head));
        (*head)  = NULL;
        return;
    } else {
        Node *temp = (*head) ;
        (*head) = (*head)->next;
        Myfree(temp->data);
        Myfree(temp);
        return;
    }

}

void Qpush(Node **head,Node **tail, char *data) {
    Node *newNode = (Node*)(Mymalloc)(sizeof(Node));
    newNode->data = (char *)(Mymalloc)(MAX_LENGTH);
    for (int i = 0; i < MAX_LENGTH; ++i) {
        newNode->data[i] = data[i];
    }
    newNode->next = NULL;
    if ((*head) == NULL) {
        (*head) = newNode;
        (*tail) = newNode;
    } else {
        (*tail)->next = newNode ;
        (*tail) = newNode;
    }
}
void Qrelease(Node **head){
    Node *temp = (*head);
    Node *temp1 = (*head);
    while (temp!=NULL){
        temp1 = temp->next;
        Myfree(temp->data);
        Myfree(temp);
        temp = temp1;
    }



}
//int main(){
//    struct Queue * Q = (Queue*)(Mymalloc(sizeof(Queue)));
//    initializeQueue(&Q->head,&Q->tail);
//    push(&Q->head,&Q->tail,"hello");
//    push(&Q->head,&Q->tail,"my");
//    push(&Q->head,&Q->tail,"name");
//    push(&Q->head,&Q->tail,"is");
//    Node *  temp = Q->head;
//    while (Q->head!=NULL){
//        printf("%s\n", top(&Q->head)->data );
//        pop(&Q->head);
//    }
//}