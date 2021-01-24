#include <stdio.h>
#include <stdlib.h>

struct Element{
    int integer;
    struct Element *next;
};

struct List {
    struct Element *firstElement;
    int size;
};

struct List *initList()
{
    struct List *list = malloc(sizeof(*list));
    struct Element *element = malloc(sizeof(*element));
    if( list == NULL || element == NULL)
    {
        printf("Error in dynamic allocation.\n");
        exit(EXIT_FAILURE);
    }
    else
    element->integer = 0;
    element->next= NULL;
    list->firstElement = element;
    list->size = 1;
    return list;
}

void insertion(struct List *list, int toAdd)
{
    struct Element *element = malloc(sizeof(*element));
    if(element == NULL)
    {
        printf("Error in dynamic allocation.");
        exit(EXIT_FAILURE);
    }
    element->integer = toAdd;
    element->next = list->firstElement;
    list->firstElement = element;
    list->size++;
}


void deleteFirstElement(struct List *list)
{
    if (list == NULL)
    {
        printf("Error in dynamic allocation.");
        exit(EXIT_FAILURE);
    }
    if (list->firstElement != NULL)
    {  
        struct Element *toDelete = list->firstElement;
        list->firstElement = list->firstElement->next;
        free(toDelete);
        list->size--;
    }
    else
        printf("Nothing to delete.");

}

void deleteLastElement(struct List *list)
{
    if (list == NULL)
    {
        printf("Error in dynamic allocation.");
        exit(EXIT_FAILURE);
    }
    struct Element *currentElement = list->firstElement;
    while(currentElement->next->next != NULL)
        currentElement = currentElement->next;
    struct Element *toDelete = currentElement->next;
    currentElement->next = currentElement->next->next;
    free(toDelete);
    list->size --;
}

void insertionIndex(struct List *list, int index, int toAdd)
{
    struct Element *addElement = malloc(sizeof(*addElement));
    if(list == NULL || addElement == NULL)
    {
        printf("Error in dynamic allocation.");
        exit(EXIT_FAILURE);
    }
    addElement->integer = toAdd;

    int i = 0;
    struct Element *currentElement = list->firstElement;
    while(i<index-1)
    {
        currentElement = currentElement->next;
        i++;
    }
    addElement->next = currentElement->next;
    currentElement->next = addElement;
    list->size++;
}



void showList(struct List *list)
{
    if (list == NULL)
    {
        printf("Error in dynamic allocation.");
        exit(EXIT_FAILURE);
    }
    printf("[");
    struct Element *currentElement = list->firstElement;
    while(currentElement != NULL)
    {
        printf(" %d ",currentElement->integer);
        currentElement = currentElement->next;
    }
    printf(" NULL ]\n");
}


int main(int argc, char *argv[])
{
    struct List *list = initList();
    insertion(list,3);
    insertion(list,5);
    insertion(list,7);
    showList(list);
    deleteLastElement(list);
    showList(list);
    insertionIndex(list,2,15);
    showList(list);
    insertionIndex(list,list->size,24);
    showList(list);
    
    return 0;
}   