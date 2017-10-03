#include "stdio.h"



int main() {
  int i=0, amount, coins;
  int coinArray[6] = {100, 50, 20, 10, 5, 1};

  printf("enter amount in cents \n");
  scanf("%d", &amount);


  while (amount > 0) {
    if (amount >= coinArray[i]) {
      amount -= coinArray[i];
      coins++;
    }else{
      i++;
    }
  }
  printf("%d \n", coins);

  return 0;
}
