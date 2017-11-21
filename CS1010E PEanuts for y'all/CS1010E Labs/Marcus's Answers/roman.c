#include <stdio.h>

void scanArray( int arr[] , int year ) ;
void printRoman( int arr[] , int i , char a , char b , char c ) ;

int main(void) {
	int year , n , i ;
	int arr[4] = {0} ;
	char a , b , c ;

	printf("Enter the year : ") ;
	scanf("%d" , &year) ; 
	scanArray( arr , year ) ;
	printf("Year %d in roman numerals is " , year ) ;

	n = arr[0] ;
	while ( n > 0 ) {
		printf("M") ;
		n-- ;
	}

	a = 'C' ;
	b = 'D' ;
	c = 'M' ;
	i = 1 ;
	printRoman( arr , i , a , b , c ) ;

	a = 'X' ;
	b = 'L' ;
	c = 'C' ;
	i = 2 ;
	printRoman( arr , i , a , b , c ) ;

	a = 'I' ;
	b = 'V' ;
	c = 'X' ;
	i = 3 ;
	printRoman( arr , i , a , b , c ) ;

	printf("\n") ;
	
   return 0;
}

void scanArray( int arr[] , int year ) {
	int i ;

	for ( i = 3 ; i >= 0 ; i-- ) {
		arr[i] = year % 10 ;
		year /= 10 ;
	}
	return ;
}

void printRoman( int arr[] , int i , char a , char b , char c ) {
	int n = arr[i] ;

	if ( n >= 5 && n < 9 ) {
		printf("%c" , b ) ;
		n -= 5 ;

		while ( n > 0 ) {
			printf("%c" , a ) ;
			n-- ;
		}
	}

	else if ( n == 4 ) {
		printf("%c%c" , a , b ) ;
	}

	else if ( n == 9 ) {
		printf("%c%c" , a , c ) ;
	}

	else {
		while ( n > 0 ) {
			printf("%c" , a ) ;
			n-- ;
		}		
	}

	return ;
}