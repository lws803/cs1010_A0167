#include <stdio.h>

int main(int argc, char const *argv[]) {
	
	// fopen(), fclose(), fscanf(), fprintf()

	// NULL, EOF are useful constants for file processing (NULL is not \0)

	return 0;
}


void readFile () {
	FILE *infile; // To create a pointer access to a file 

	infile = fopen ("prices.in", "r"); // open file for reading 

	// To open a file with error handling** - good practice  
	if ((infile = fopen("prices.in", "r")) == NULL) {
		printf("File does not exist\n");
		exit (1);
	}



	fscanf (infile, "%d", &size); // to scan the file 
	// returns EOF if input error occurs 

	fclose (infile); // to close the file
}


void writeFile () {
	FILE *outfile;

	outfile = fopen ("prices.out", "w"); // open file for write mode 
	// use "a+" if you want to append if the file already exists 
	fprintf(outfile, "hello world\n"); // prints hello world to the file
	// returns negative value if error occurs 
	fclose (outfile);
}


void read_string_from_file () {
	FILE *infile;
	char wow[MAX];
	fgets (wow, 100, infile); // Reads the string to wow[] from infile	
}


// Cool tip: To reverse an array and write to file, just read the input file backwards and print simultaneously to the dest file 

