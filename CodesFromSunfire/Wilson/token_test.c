#include <string.h>
#include <stdio.h>

int main () {
   char str[80] = "omae wa mou shindeiru";
   char str2[80] = "ore-wa-o-chin-chin-ga-daisuki-nandayo";
   const char s[2] = " ";
   const char s2[2] = "-";
   char *token;
   char *token2;
   
   /* get the first token */
   token = strtok(str, s);
   
   /* walk through other tokens */
   while( token != NULL ) {
      printf( "%s\n", token );
    
      token = strtok(NULL, s);
   }

   // Delim: '-'
   printf("-----Delim:'-'-----\n");
   token2 = strtok(str2, s2);
   while( token2 != NULL ) {
      printf( "%s\n", token2 );
    
      token2 = strtok(NULL, s2); // If we remove this, then it will result in an infinite loop 
   }


   char str3[] ="- This, a sample string.";
   char * pch;
   printf ("Splitting string \"%s\" into tokens:\n",str3);
   pch = strtok (str3," ,.-"); // Pass the string first (contains multiple delimiters)
   while (pch != NULL)
   {
      printf ("%s\n",pch); // Call and print subsequent tokens 
      pch = strtok (NULL, " ,.-");
   }

   
   return(0);
}