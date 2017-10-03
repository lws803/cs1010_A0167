#include "stdio.h"
#include<stdlib.h>
#include<stdbool.h>


//Basic struct of a node
struct test_struct
{
    int val;
    struct test_struct *next;
};


//Declaration of head and tails
struct test_struct *head = NULL;
struct test_struct *curr = NULL;



//Create a list
struct test_struct* create_list(int val)
{
    printf("\n creating list with headnode as [%d]\n",val);
    //Memory allocation of a list with pointers
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    //allocate current pointer with a value, then move on and declare next pointer as null
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}


struct test_struct* add_to_list(int val, bool add_to_end)
{
    if(NULL == head)
    {
        return (create_list(val));
    }

    if(add_to_end)
        printf("\n Adding node to end of list with value [%d]\n",val);
    else
        printf("\n Adding node to beginning of list with value [%d]\n",val);

    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    if(add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}



void print_list(void)
{
    struct test_struct *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%d] \n",ptr->val);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}


int main() {
  int i = 0, ret = 0;
  struct test_struct *ptr = NULL;


  for(i = 5; i<10; i++){
    add_to_list(i,true);
  }

  print_list();

  return 0;
}
