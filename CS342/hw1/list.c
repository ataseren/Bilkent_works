#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n)
{
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

//Adds a node with given integer to a linked list
void addNewNode(struct Node** head, int number)
{
    //New node has been created
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    //New pointer has been created to traverse on the linked list
    struct Node *pointToList = *head;

    //Data and pointer of the node has been set
    newNode->data = number;
    newNode->next = NULL;
    
    //In case if list is empty
    if (*head == NULL)
    {
       *head = newNode;
    }
    else
    {
        while (pointToList->next != NULL)
        {
            pointToList = pointToList->next;
        }

        //New node has been inserted to the linked list by
        //using the pointer of last node to point new node
        pointToList->next = newNode;
    }
}
int main()
{
    struct Node* head = NULL;

    srand(time(NULL));
    /* 
    printf("%d ", rand());
    printf("%d ", rand());
    printf("%d ", rand());
    */

    //To save the time when insertion starts
    struct timeval beforeInsertion;
    gettimeofday(&beforeInsertion, NULL);

    //Insertion of 10000 nodes with random numbers
    for(int i = 0; i < 10000; i++)
    {
        addNewNode(&head, rand());
    }

    //To save the time when insertion ends
    struct timeval afterInsertion;
    gettimeofday(&afterInsertion, NULL);
    printf("Execution of the insertion of 10000 nodes with random values took %ld seconds and %ld microseconds\n", afterInsertion.tv_sec - beforeInsertion.tv_sec, 
    afterInsertion.tv_sec - beforeInsertion.tv_sec+ afterInsertion.tv_usec - beforeInsertion.tv_usec);
    return 0;
}