#include <stdio.h>
#include <stdlib.h>

// The files have to be sorted already
// This program does not use an array to store the values
int main(void) {
	FILE *infile;
	FILE *infile2;
	FILE *outfile;
	int buff1, buff2, temp,switches = 0;
	int exist1 = 0,exist2 = 0;

	infile = fopen("q3_1.txt","r");
	infile2 = fopen("q3_2.txt","r");
	outfile = fopen("q3.txt","w");

	while (!feof(infile) && !feof(infile2)){
		if (exist1==0){
			fscanf(infile,"%d",&buff1);
			exist1 = 1;
			//printf("buff1: %d\n",buff1);
		}
		if (exist2==0){
			fscanf(infile2,"%d",&buff2);
			exist2 = 1;
			//printf("buff2: %d\n",buff2);
		}
		printf("buff1: %d\n",buff1);
		printf("buff2: %d\n\n",buff2);
		if (buff1 < buff2){
			temp = buff1;
			switches = buff2;
			exist1 = 0;
		}
		else{
			temp = buff2;
			switches = buff1;
			exist2 = 0;
		}
		fprintf(outfile,"%d\n",temp);
	}
	fprintf(outfile,"%d\n",switches);
	if (!feof(infile)){
		while(!feof(infile)){
			fscanf(infile,"%d",&buff1);
			fprintf(outfile,"%d\n",buff1);
		}
	}
	if (!feof(infile2)){
		while(!feof(infile2)){
			fscanf(infile2,"%d",&buff2);
			fprintf(outfile,"%d\n",buff2);
		}
	}
	fclose(infile);
	fclose(infile2);
	fclose(outfile);
}
