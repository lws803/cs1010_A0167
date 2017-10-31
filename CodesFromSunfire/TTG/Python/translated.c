// translated from python
#include <stdio.h>
#define MAX 10

int main(void) {
    int arr[MAX] = {0};
    int dest[MAX] = {0};
    int i,size;

    printf("Start from: ");         //defining size
    scanf("%d",&size);

    generate(arr,MAX,size);
    reversal(arr,dest,MAX);

    printf("Generated array of 10 elements\n");

    printf("[%d,",arr[0]);          //print(myArray)
    for (i=1;i<MAX-1;i++)
        printf(" %d,",arr[i]);
    printf(" %d]\n",arr[MAX-1]);

    printf("[%d,",dest[0]);         //print(reversal)
    for (i=1;i<MAX-1;i++)
        printf(" %d,",dest[i]);
    printf(" %d]\n",dest[MAX-1]);
    return 0;
}

void generate(int arr[],int size,int start){
    int i;
    for (i=0;i<size;i++){
        arr[i] = start + i;
    }
}

void reversal(int arr[],int dest[],int size){
    int i,j,temp;
    for (i=size-1,j=0; i>=0 ;i--,j++){
        dest[j] = arr[i];
    }
}
