#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void print_list(node_t*);
void listFree(node_t**);
void mergeSort(node_t**, int(*)(int, int));
node_t* sortedMerge(node_t*, node_t*, int(*)(int, int));
void frontBackSplit(node_t*, node_t**, node_t**);
void listFree(node_t**);
void push(node_t**,int);

#define N 5

int sumDigits(int);
int cmp(int, int);

int main(){
    srand(time(NULL));
    node_t* llist = NULL;
    for (int i = 0; i < N; i++){
        push(&llist, rand() % 101);
    }
    printf("List: ");
    print_list(llist);

    mergeSort(&llist, cmp);
    printf("Sored: ");
    print_list(llist);
    listFree(&llist);
    return 0;
}

void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void push(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

node_t* sortedMerge(node_t* listA, node_t* listB, int(*cmp)(int, int)){
    node_t* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(listA->data, listB->data) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(node_t* list, node_t** front, node_t** back){
    node_t* slow = list;
    node_t* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(node_t** list, int(*cmp)(int, int)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    node_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}

int sumDigits(int num){
    int sum = 0;
    while (num != 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int cmp(int a, int b){
    int sumDigitsA = sumDigits(a);
    int sumDigitsB = sumDigits(b);
    return sumDigitsB - sumDigitsA;
}