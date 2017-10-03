#include "stdio.h"


int main() {

  int input;
  char * new_str ;

  scanf("%d", &input);

while (input >= 10) {
  input -= 10;
  if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    new_str[0] = '\0';   // ensures the memory is an empty string
    strcat(new_str, "X");
} else {
    fprintf(STDERR,"malloc failed!\n");
    // exit?
}
}
if input == 9 {
  input -= 9;
  if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    new_str[0] = '\0';   // ensures the memory is an empty string
    strcat(new_str, "IX");
} else {
    fprintf(STDERR,"malloc failed!\n");
    // exit?
}
}

if input < 9 && input >= 5 {
  input -= 5;
  if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    new_str[0] = '\0';   // ensures the memory is an empty string
    strcat(new_str, "V");
} else {
    fprintf(STDERR,"malloc failed!\n");
    // exit?
}
}

while (input < 9 && input > 5) {
  input -= 1;
  if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    new_str[0] = '\0';   // ensures the memory is an empty string
    strcat(new_str, "I");
} else {
    fprintf(STDERR,"malloc failed!\n");
    // exit?
}
}

if input == 4 {
  input -= 4;
  if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    new_str[0] = '\0';   // ensures the memory is an empty string
    strcat(new_str, "I");
} else {
    fprintf(STDERR,"malloc failed!\n");
    // exit?
}
}

while (input < 4 && input > 0) {
  input -= 1;
  if((new_str = malloc(strlen(str1)+strlen(str2)+1)) != NULL){
    new_str[0] = '\0';   // ensures the memory is an empty string
    strcat(new_str, "I");
} else {
    fprintf(STDERR,"malloc failed!\n");
    // exit?
}
}

printf("%s", new_str);

  return 0;
}
