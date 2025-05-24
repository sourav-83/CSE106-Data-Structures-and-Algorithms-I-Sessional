#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    // add *next and *prev here
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct
{
    // add Node* head, tail, current_position and other necessary fields here
    Node* head;
    Node* tail;
    int pos;
    int size;

} LinkedList;


void init_linkedlist(LinkedList *list)
{
    
    // initialize head, tail with null
    list->head=NULL;
    list->tail=NULL;
    list->size=0;
    list->pos=0;

}


void clear(LinkedList *list)
{
    printf("cleared list\n");
    // traverse the list and free each node
    // set head and tail to null
    Node* temp;
    while (list->head!=NULL)
    {
        temp=list->head;
        list->head=list->head->next;
        free(temp);
    }
    list->tail=NULL;
    list->size=0;
}


int get_size(LinkedList *list)
{
    printf("size is %d\n",list->size);
    return list->size;
    
}


void append(LinkedList *list, int value)
{
    printf("appended %d\n",value);
    // create a new node and set its value
    // consider the case when the list is empty and when it isnt
    if (list->size==0)
    {
        list->head= (Node*) malloc(sizeof(Node));
        list->head->data=value;
        list->head->next=NULL;
        list->head->prev=NULL;
        list->tail=list->head;

    }
    else{
        Node* temp = (Node*) malloc(sizeof(Node));
        temp->data = value;
        temp->next = NULL;
        list->tail->next = temp;
        temp->prev=list->tail;
        list->tail = temp;
    }
    list->size++;
}


void insert(LinkedList *list, int value)
{
    
    // create a new node and set its value
    // place it at the current position (check order of operations)
    // consider the case when the list is empty and when it isnt
    printf("inserted %d\n",value);
    if (list->size==0)
    {
        list->head= (Node*) malloc(sizeof(Node));
        list->head->data=value;
        list->head->next=NULL;
        list->head->prev=NULL;
        list->tail=list->head;
        list->size=1;
        list->pos=0;

    }
    else{
        Node* temp = list->head;
        for (int i=0; i<list->pos; i++)
        {
            temp=temp->next;
        }
        if (temp==list->head)
        {
            Node* tobeinserted = (Node*) malloc(sizeof(Node));
            tobeinserted->data=value;
            tobeinserted->prev=NULL;
            tobeinserted->next=list->head;
            list->head->prev=tobeinserted;
            list->size++;
            list->head=tobeinserted;
            return;
        }
        Node* previous = temp->prev;
        Node* tobeinserted =  (Node*) malloc(sizeof(Node));
        tobeinserted->data=value;
        tobeinserted->next=temp;
        previous->next=tobeinserted;
        tobeinserted->prev=previous;
        temp->prev=tobeinserted;
        list->size++;
    }
}


int remove_at_current(LinkedList *list)
{
    
    // consider the case when current code is at the begining or at the end
    
    if (list->pos==0 && list->size!=1)
    {   
        Node*tobedeleted=list->head;
        Node*second=list->head->next;
        int val = list->head->data;
        list->head=second;
        list->head->prev=NULL;
        free(tobedeleted);
        list->size--;
        printf("removed %d\n",val);
        return val;
    }
    else if (list->pos==0 && list->size==1)
    {   int val = list->head->data;
        printf("removed %d\n",val);
        Node* temp = list->head;
        list->head=NULL;
        free(temp);
    }
    else if (list->pos==list->size-1)
    {
        Node*second=list->tail->prev;
        int val = list->tail->data;
        list->tail=second;
        list->tail->next=NULL;
        list->size--;
        printf("removed %d\n",val);
        return val;
    }
    return -1;
}


int find(LinkedList *list, int value)
{
    
    // traverse the list and return the position of the value
    int i = 0;
    Node* temp = list->head;
    while (temp!=NULL)
    {
        if (temp->data==value) {printf("found %d at %d\n",value,i); return i;}
        i++;
        temp = temp->next;
    }
    printf("did not find %d in the list\n",value);
    return -1;
}


void move_to_start(LinkedList *list)
{
    if (list->size==0) {printf("Can't move to start as size is zero\n"); return;}
    list->pos=0;
    printf ("moved current position to 0\n");
}


void move_to_end(LinkedList *list)
{
    if (list->size==0) {printf("Can't move to end as size is zero\n"); return;}
    list->pos=list->size-1;

}


void prev(LinkedList *list)
{
    
    if (list->pos>0) { printf("moved current position from %d to %d\n",list->pos,list->pos-1); list->pos--;}
}


void next(LinkedList *list)
{
    
    if (list->pos!=list->size-1) {printf("moved current position from %d to %d\n",list->pos,list->pos+1);
        list->pos++;}
}


void move_to_position(LinkedList *list, int position)
{
    printf("moved current position from %d to %d\n",list->pos,position);
    // traverse the list and stop at the given position
    list->pos=position;
}


int get_current_position(LinkedList *list)
{
    
    // traverse the list and stop when you are at the current position
    // return the position (integer)
    printf("current position is %d\n",list->pos);
    return list->pos;
    
}


int get_current_element(LinkedList *list)
{
    
    // return the value at the current position
    Node* temp = list->head;
    int i = 0;
    
    while (temp!=NULL)
    {   
        if (i==list->pos) break;
        i++;
        temp = temp->next;
    }
    printf("current element is %d\n",temp->data);
    return temp->data;
}


void print_list(LinkedList *list)
{
    
    if (list->size==0) {
        printf("<  >\n");
        return;
    }
    Node* temp = list->head;
    int i=0;
    printf("<");
    while (temp!=NULL)
    {   if (i==list->pos)
           {
              printf (" |%d ",temp->data);
           }
           else{
                  printf (" %d ",temp->data);
           }
        
        temp = temp->next;
        i++;
    }
    printf(">\n");

}


void free_list(LinkedList *list)
{
    
    struct Node* temp;
    list->size=0;
    while (list->head != NULL) {
        temp = list->head;        // Store current node in a temporary variable
        list->head = list->head->next;  // Move to the next node
        free(temp);         // Free the current node
    }
}

void skip (LinkedList *list)
{
    if (list->pos==0) printf("Already at beginning\n");
    else 
    {
        list->pos=list->pos-1;

    }
    print_list(list);
}
void discard(LinkedList *list)
{
     Node*temp=list->head;
     for (int i=0; i<list->pos; i++) temp=temp->next;
     while (temp->next!=NULL)
     {
        temp->data=temp->next->data;
        temp=temp->next;
     }
     list->size--;
     list->tail=list->tail->prev;
     list->tail->next=NULL;
     free(temp);
     print_list(list); 
}
void swap_with(LinkedList *list, int index)
{
    
    

    Node*temp=list->head;
    for (int i=0; i<list->pos; i++) temp=temp->next;
    int val = temp->data;
    Node*temp2=list->head;
    for (int i=0; i<index; i++) temp2=temp2->next;
    int val2 = temp2->data;
    temp->data=val2;
    temp2->data=val;
    print_list(list); 

    free(temp);
    free(temp2);

}