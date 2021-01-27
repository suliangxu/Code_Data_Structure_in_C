//
// Created by slx on 2021/1/27.
//

#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
#define ElementType int

struct Node{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L);
void PrintList(List L);

int main(){
    PtrToNode L;

    MakeEmpty(L);

    PrintList(L);

    return 0;
}

List MakeEmpty(List L){
    int length, value;
    Position tmp, new;

    printf("Input the number of nodes:");
    scanf("%d", &length);

    tmp = L;
    for (int i=0; i<length; i++){
        printf("Input the %dth value: ", i+1);
        scanf("%d", &value);

        new = (Position)malloc(sizeof(ElementType));
        new->Element = value;
        tmp->Next = new;
        tmp = tmp->Next;
    }

    tmp->Next = NULL;

    printf("Input Over!\n");

    return L;
}

void PrintList(List L){
    Position now = L->Next;  // 头结点

    printf("\nThe content of the List:\n");
    while (now != NULL){
        if (now->Next == NULL)
            printf("%d ", now->Element);
        else
            printf("%d --> ", now->Element);

        now = now->Next;
    }
}