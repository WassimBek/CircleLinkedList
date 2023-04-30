#include <stdio.h>
#include <stdlib.h>

typedef struct Circle {
    int data;
    struct Circle *Next;
} Circle;

Circle *Fill_Empty(int data2) {
    Circle *Node = malloc(sizeof(Circle)); 
    Node->data = data2;
    Node->Next = Node;
    return Node;
}

Circle *Adding_Begin(Circle *Start, int data, Circle *End) {
    Circle *New_p = malloc(sizeof(Circle));
    New_p->data = data;
    New_p->Next = NULL;
    if (End == NULL)
        return Fill_Empty(data);
    else {
        New_p->Next = Start;
        End->Next = New_p;
        return New_p;
    }
}

void print(Circle *Display_List) {
    Circle *temp = Display_List;
    do {
        printf("%d ", temp->data);
        temp = temp->Next;
    } while (temp != Display_List);
}

int main() {
    Circle *Begin = NULL;
    Circle *Last = NULL;
    int n;
    printf("How Many Number in your list : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        Begin = Adding_Begin(Begin, i, Last);
        if (i == 1)
            Last = Begin;
    }
    print(Begin);
    return 0;
}
