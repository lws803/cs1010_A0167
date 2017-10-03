#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

///http://www.thegeekstuff.com/2012/08/c-linked-list-example/
//Sample on how to build a linked list in C


struct test_struct {
  //Value held by this struct
  int val;
  //Address of the next struct
  struct test_struct *next;
};

//Define head and current of the linked list.
struct test_struct *head = NULL;
struct test_struct *curr = NULL;

struct test_struct* create_list(int val)
{
  //Set pointer to the address of the new struct
  struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));

  //Node creation failed.
  if (ptr == NULL) {
    return NULL;
  }

  //Assign the next struct's val to the new value
  ptr->val = val;
  //Assign the next struct's pointer to null.
  ptr ->next = NULL;

  //Assign new head and current to pointer, only for init of linked list.
  head = curr = ptr;
  printf("New list created\n");
  return ptr;
}

struct test_struct* add_to_list(int val) {
  if (head == NULL){
    //If no linked list exist, create a list
    return (create_list(val));
  }
  //Set pointer to the address of the new struct
  struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));

  //node creation failed
  if (ptr == NULL){
    return NULL;
  }
  //Assign the next struct's val to the new value
  ptr->val = val;
  //Assign the next struct's pointer to null.
  ptr->next = NULL;

  //Assign this struct's pointer to the new struct's address
  curr-> next = ptr;
  //Then change the current pointer to the next struct
  curr = ptr;

  // Returns next pointer
  return ptr;
}

void print_list(void)
{
  struct test_struct *ptr = head;

  printf("\n -------Printing list Start------- \n");
  while(ptr != NULL)
  {
      printf("%d\n",ptr->val);
      ptr = ptr->next;
  }
  printf("-------Printing list End------- \n");

  return;
}


int main(void) {
  //Sets ptr to the head which is NULL cause a linked list hasnt been created
  //Note: This is the universal pointer variable. 
  struct test_struct *ptr = head;

  int x =0;

  while (x==0) {
    int number;
    printf("Enter a number: \n");
    scanf("%d", &number);
    add_to_list(number);
    print_list();
  }

  return 0;
}
