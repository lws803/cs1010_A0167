#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 101

int main() {
  int i,input,N;
  char letter[2] = "";
  char DNA[MAX] = "";
  char check[5][3] = {"AG","CT","TA","GC","AA"};
  /* initialize random seed: */
	srand ( time(NULL) );
	/* Generate a random number: */
	/* number = rand() % 10 + 1;*/
  N=100; /*  user can input this value too*/
  i=0;
  while(i < N) {
    input = rand() % 4 + 1; /* from 1 to 4 */
    /* printf("Input value = %d\n",input); */
    switch(input){
      case 1:
		letter[0] = 'A';
        //printf("A");
        break;
      case 2:
		letter[0] = 'G';
        //printf("G");
        break;
      case 3:
		letter[0] = 'C';
        //printf("C");
        break;
      case 4:
		letter[0] = 'T';
        //printf("T");
        break;
      default:
        printf("String generation completed\n");
        break;
    }
	strcat(DNA,letter);
    i++;
  }
  printf("%s\n\n",DNA);
  frequencies(DNA);
  checkOccur(check,DNA);
  return 0;
}

int frequencies(char dna[]){
    int A=0,G=0,C=0,T=0;
    int i;
    int len = strlen(dna);
    for (i=0;i<len;i++){
        switch(dna[i]){
        case 'A': A++; break;
        case 'G': G++; break;
        case 'C': C++; break;
        case 'T': T++; break;
        }
    }
    printf("Nucleotide Frequencies:\n");
    printf("A: Occurences: %d, Probability = %0.2f\n",A,A/100.0);
    printf("G: Occurences: %d, Probability = %0.2f\n",G,G/100.0);
    printf("T: Occurences: %d, Probability = %0.2f\n",T,T/100.0);
    printf("C: Occurences: %d, Probability = %0.2f\n\n",C,C/100.0);
}

int checkOccur(char searchList[][3],char dna[MAX]){
    int i,j,counter = 0,highestCount = -1,highest = 0,first = 1;

    for (j=0;j<5;j++){
        char tempstr[3];
        int occurance[MAX] = {-1};
        counter = 0;
        for (i=0;i<MAX-1;i++){
            tempstr[0] = dna[i];
            tempstr[1] = dna[i+1];
            tempstr[2] = '\0';
            if (!strcmp(searchList[j],tempstr)){
                occurance[counter++] = i;
            }
        }
        if (first){
            highest = j;
            highestCount = counter;
            first = 0;
        }
        else{
            if (counter > highestCount){
                highest = j;
                highestCount = counter;
            }
        }

        printf("Base Pair: %s\n",searchList[j]);
        printf("Number of Occurences: %d\n",counter);
        printf("Indices: \(");
        for (i=0;i<counter-1;i++){
            printf("%d, ",occurance[i]);
        }
        printf("%d\)\n\n",occurance[i]);
    }
    printf("Base pair with the highest count: %s\n",searchList[highest]);
}
