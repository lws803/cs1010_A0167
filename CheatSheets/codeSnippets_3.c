// File read write with error handling for read
void readFile () {
	FILE *infile; // To create a pointer access to a file 

	infile = fopen ("prices.in", "r"); // open file for reading 

	// To open a file with error handling** - good practice  
	if ((infile = fopen("prices.in", "r")) == NULL) {
		printf("File does not exist\n");
		exit (1);
	}

	

	fscanf (infile, "%d", &size); // to scan the file 

	fclose (infile); // to close the file
}


void writeFile () {
	FILE *outfile;

	outfile = fopen ("prices.out", "w"); // open file for write mode 
	// use "a+" if you want to append if the file already exists 
	fprintf(outfile, "hello world\n"); // prints hell world to the file
	fclose (outfile);
}

void read_string_from_file () {
	FILE *infile;
	char wow[MAX];
	fgets (wow, 100, infile); // Reads the string to wow[] from infile

	
}

// Copy file to destfile
int copyFile(char sourcefile[], char destfile[]) {
	FILE	*sfp, *dfp;
	int ch;

	if ((sfp = fopen(sourcefile, "r")) == NULL) 
		exit(1);  // error - can't open source file
	if ((dfp = fopen(destfile, "w")) == NULL) {
		fclose(sfp); // close source file
		exit(2);  // error - can't open destination file
	}
	while ((ch = fgetc(sfp)) != EOF) {
		if (fputc(ch, dfp) == EOF) {
			fclose(sfp); fclose(dfp); 
			exit(3);  // error - can't write to file
		}
	}
	fclose(sfp); fclose(dfp); 
	return 0;
}

// Count lines in a file 

int countLines(char filename[]) {
	FILE *fp;
	int  count = 0;
	char s[MAX_LINE_LENGTH+1];

	if ((fp = fopen(filename, "r")) == NULL) 
		return -1;  // error 

	while (fgets(s, MAX_LINE_LENGTH+1, fp) != NULL) 
		count++;

	if (!feof(fp))	// read error encountered
		count = -1;  

	fclose(fp); 
	return count;
}


