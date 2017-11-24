#include <stdio.h>
#include <string.h>

void printEach( char word[] , char *ptr ) ;

int main(void) {
	char word1[40] , word2[40] , word1Old[40] ;
	int cmp ;
	char *ptr1 , *ptr2 ;

	printf("Enter Word 1: ") ;
	scanf("%s" , word1) ;
	printf("The first word is %s\n" , word1 ) ;

	printf("Enter Word 2: ") ;
	scanf("%s" , word2) ;
	printf("The second word is %s\n" , word2 ) ;

	printf("\nLet's try strcpy\n") ;	

	strcpy( word1Old , word1 ) ;

	printf("Word 1 has been saved. Old: %s , New: %s\n" , word1Old , word1 ) ;

	printf("\nLet's try strlen\n") ;

	printf("The length of Word 1 is %d.\n" , strlen(word1) ) ;
	printf("The length of Word 2 is %d.\n" , strlen(word2) ) ;	

	printf("\nLet's try strcat\n") ;

	printf("Both words joined together forms: %s\n" , strcat(word1 , word2)) ;

	printf("\nLet's try strcmp\n") ;	

	cmp = strcmp( word1Old , word2 ) ;

	if ( cmp < 0 ) {
		printf("Word 1 is smaller than Word 2\n") ;
	}

	else if ( cmp > 0 ) {
		printf("Word 1 is larger than Word 2\n") ;
	}

	else {
		printf("Both words are the same\n") ;
	}

	printf("\nLet's play with pointers\n") ;	

	ptr1 = word1Old ;
	ptr2 = word2 ;

	printf("Word 1:\n") ;
	printEach( word1Old , ptr1 ) ;	
	printf("Word 2:\n") ;	
	printEach( word2 , ptr2 ) ;	

   return 0;
}

void printEach( char word[] , char *ptr ) {
	int i ;

	for ( i = 0 ; word[i] != 0 ; i++ ) {
		printf("iteration %d, array: %c , ptr: %c \n" , i+1 , word[i] , *(ptr + i)) ;
	}

	return ;

}