#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

/*typedef struct node {
    int data;
    struct node* next;
} node_t;

void push(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

void print(node_t* llist){
    while (llist){
        printf("%d ", llist->data);
        llist = llist->next;
    }
    putchar('\n');
}

size_t size_list(node_t* llist){
    size_t cnt = 0;
    while (llist){
        cnt++;
        llist = llist->next;
    }
    return cnt;
}

void printRev(node_t* llist){
    size_t len = size_list(llist);
    int* buff = malloc(len * sizeof(int));
    node_t* current = llist;
    int i = 0;
    while (current != NULL){
        buff[i] = current->data;
        current = current->next;
        i++;
    }
    for (int i = len - 1; i >= 0; i--){
        printf("%d ", buff[i]);
    }
    putchar('\n');
    free(buff);
}

void printR(node_t* llist){
    if (llist == NULL){
        putchar('\n');
        return;
    }
    printf("%d ", llist->data);
    printR(llist->next);
}

void printRRev(node_t* llist){
    if (llist == NULL){
        return;
    }
    printR(llist->next);
    printf("%d ", llist->data);
}
*/

int cmp(int a, int b){
    return a - b;
}

int main(void){
    /*node_t* head1 = NULL;
    push(&head1, 100);
    push(&head1, 50);
    push(&head1, 20);
    push(&head1, 10);
    putchar('\n');

    node_t* head2 = NULL;
    push(&head2, 95);
    push(&head2, 45);
    push(&head2, 4);
    push(&head2, -35);

    node_t* sorted = sortedMerge(head1, head2, cmp);
    print_list(sorted);

    node_t* A = NULL, *B = NULL;
    frontBackSplit(sorted, &A, &B);
    print_list(A);
    print_list(B);
    */

    node_t* ll = NULL;
    push(&ll, 10);
    push(&ll, -10);
    push(&ll, 234);
    push(&ll, -34);
    push(&ll, 0);
    push(&ll, 10000);

    mergeSort(&ll, cmp);
    print_list(ll);
    return 0;
}