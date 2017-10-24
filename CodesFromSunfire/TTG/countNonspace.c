#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void){
	char str[20] = "This is a statement\0";
	
	int i=0,counter=0;
	while (str[i] != '\0'){
		if (!isspace(str[i])){
			counter++;
		}
		i++;
	}
	printf("%d",counter);
}