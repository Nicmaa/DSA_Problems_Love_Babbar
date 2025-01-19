#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef Node *List;

void createReversedList(int n, List *l)
{
    Node *aux = malloc(sizeof(Node));
    if (aux == NULL)
    {
        printf("Error in memory allocation.\n");
        exit(1);
    }
    aux->data = n;
    aux->next = *l;
    *l = aux;
}

void printList(List l)
{
    while (l)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

int main()
{
    List l = NULL;
    int num;
    printf("Write numbers [0 to stop]: ");
    while (scanf("%d", &num) == 1 && num != 0)
        createReversedList(num, &l);
    printf("Reversed List: ");
    printList(l);
    return 0;
}
