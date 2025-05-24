#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int * array;
    // Add more fields here
    int pos;
    int size;
    int capacity;
} ArrayList;


void init_arraylist(ArrayList *list, int c)
{
   
    // dynamically allocate space for the array
    // initialize the size, capacity, and current position
    list->capacity=c;
    list->size=0;
    list->array=(int*)malloc(sizeof(int)*c);
    list->pos=0;
}


void clear(ArrayList *list)
{
    printf("cleared list\n");
    // clear the list but do not free the array
    // modify the size, capacity, and current position
    list->size=0;
    list->capacity/=2;
    list->pos=0;
}

int get_size(ArrayList *list)
{
    printf("size is %d\n",list->size);
    
    return list->size;
}


void resize(ArrayList *list, int new_capacity)
{
    int previous = list->capacity;
    // allocate space for new array with new_capacity
    // print log message
    list->array=(int*)realloc(list->array,sizeof(int)*new_capacity);
    list->capacity=new_capacity;
    printf("resized array from %d to %d\n",previous,new_capacity);
}


void append(ArrayList *list, int value)
{
    
    // call resize if necessary
    // add value to the end of the list
    if (list->size==list->capacity)
    {
        resize(list,list->capacity*2);
    }
    list->array[list->size]=value;
    list->size++;
    printf("appended %d\n",value);
    
}


void insert(ArrayList *list, int value)
{
    
    // call resize if necessary
    // shift the elements to the right to make space
    // add value at the current position
    if (list->size==list->capacity)
    {   
        resize(list,list->capacity*2);
    }
    for (int i=list->size-1; i>=list->pos; i--)
    {
        list->array[i+1]=list->array[i];
    }
    list->array[list->pos]=value;
    list->size++;
    printf("inserted %d\n",value);

}


int remove_at_current(ArrayList *list)
{
    
    if(list->size==0) return -1;
    
    // save the value of the current element in a variable
    // shift the elements to the left to fill the gap
    // change the size, and current position as necessary
    // call resize if necessary
    // return the saved value
    int val = list->array[list->pos];
    
    if ((list->size-1)*4<list->capacity)
    {  
       resize(list,(list->capacity)/2);
        
    }
    for (int i=list->pos; i<=list->size-2; i++)
    {
        list->array[i]=list->array[i+1];
    }
    list->size--;
    printf("removed %d\n",val);
    return val;

}

int find(ArrayList *list, int value)
{
    
    for (int i=0; i<list->size; i++)
    {
       if (list->array[i]==value) {printf("found %d at %d\n",value,i); return i;}
    }
    printf("did not find %d in the list\n",value);

    return -1;
    // traverse the list and return the position of the value
    // return -1 if the value is not found
}


void move_to_start(ArrayList *list)
{
    
    // consider the cases when the list is empty
    if (list->size==0) printf("Can't move to start as size is zero\n");
    else {list->pos=0;
    printf ("moved current position to 0\n");}
}


void move_to_end(ArrayList *list)
{
    
    // consider the cases when the list is empty
    if (list->size==0) printf("Can't move to end as size is zero\n");
    else {list->pos=list->size-1; printf("moved current position to %d\n",list->pos);}
}


void prev(ArrayList *list)
{
    
    // no change if the current position is at the start
    if (list->pos!=0) {printf("moved current position from %d to %d\n",list->pos,list->pos-1);
    list->pos--;}
    else printf("current position is already zero\n");
}


void next(ArrayList *list)
{
    
    // no change if the current position is at the end
    if (list->pos!=list->size-1) {printf("moved current position from %d to %d\n",list->pos,list->pos+1);
        list->pos++;}
        else printf("can't move current position from %d\n",list->pos);
}


void move_to_position(ArrayList *list, int position)
{
    printf("moved current position from %d to %d\n",list->pos,position);
    list->pos=position;
}


int get_current_position(ArrayList *list)
{
    printf("current position is %d\n",list->pos);
    return list->pos;
}


int get_current_element(ArrayList *list)
{
    printf("current element is %d\n",list->array[list->pos]);
    return list->array[list->pos];
}


void print_list(ArrayList *list)
{
    
    if (list->size==0) {printf("<  >\n"); return;}
        printf("<"); 
    for (int i=0; i<list->size; i++)
    {
        if (list->pos==i) {
            printf(" |%d ",list->array[i]);
        }
        else printf(" %d ",list->array[i]);
    }
    printf(">\n");
    
}


void free_list(ArrayList *list)
{
    
    // free the array before terminating the program
    free(list->array);
}

void skip (ArrayList *list)
{
    if (list->pos==0) printf("Already at beginning\n");
    else 
    {
        list->pos=list->pos-1;

    }
    print_list(list);
}
void swap_with(ArrayList *list, int index)
{
    int val = get_current_element(list);
    int val2=list->array[index];
    list->array[index]=val;
    list->array[list->pos]=val2;


    print_list(list); 

}
void discard(ArrayList *list)
{
     for (int i=list->pos; i<list->size-1; i++)
     {
        list->array[i]=list->array[i+1];
     }
     list->size--;
}


