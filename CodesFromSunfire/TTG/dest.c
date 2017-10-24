#include <stdio.h>
#include <string.h>
#define INPUTMAX 20
#define OUTPUTMAX 40

void convert_string(char [INPUTMAX+1],char [OUTPUTMAX+1]);
int main(void){
	char str[INPUTMAX+1];
	char dest[OUTPUTMAX+1];
	int len;
	printf("Enter the input: ");
	fgets(str,INPUTMAX+1,stdin);
	len = strlen(str);
	if (str[len-1] == '\n') str[len-1] = '\0';
	
	convert_string(str,dest);
	printf("DEST: %s\n",dest);
}

void convert_string(char str[INPUTMAX+1],char dest[OUTPUTMAX+1]){
	int i;
	int length = strlen(str);
	int counter = 0;
	for (i=0;i<length;i++){
		if (i == length-1){
			dest[counter++] = str[i];
			dest[counter] = '\0';
		}
		else if (str[i] == ' '){
			continue;
		}
		else{
			dest[counter++] = str[i];
			dest[counter++] = '*';
		}
	}
}
