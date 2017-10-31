#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMMAND_HELP 0
#define COMMAND_EXIT 1
#define COMMAND_SUM 2
#define COMMAND_AVE 3
#define COMMAND_INVALID 4

/* Function prototypes */
int parse_command();

int check_command(char* input);

void print_help();

int simple_sum();

int simple_average();


int main() {
	// print welcome information
	printf("Welcome to Nanotable!\n");
	printf("Type \"help\" for more information...\n");

	
	parse_command();

	return 0;
}

//This function is the command parser that is needed for the programme to work in a REPL style
//it will keep on running in loop untili the exit command "exit" is given by the user
int parse_command() {
	char tmp_command[100] = "";
	int command_code;
    do {
	printf("Waiting for command...\n");
	scanf("%s", tmp_command);

	command_code = check_command(tmp_command);    

	if (command_code == COMMAND_HELP) {
		print_help();
	}
	else if (command_code == COMMAND_EXIT) {
		printf("See you!\n");
	}
	else if (command_code == COMMAND_SUM) {
		simple_sum();
	}
	else if (command_code == COMMAND_AVE) {
		simple_average();
	}
	else {
		// others
		printf("No such command: %s, please input command again!\n", tmp_command);
	} } while (command_code != COMMAND_EXIT);
	return 0;
}

//This function is asks the users to type in the number of the coming integers
//and then takes the following integers to print its sum
int simple_sum() {
	int num_int,count,scan_no,temp;
	int sum=0;
	printf("Please indicate the number of integers:\n");
	scanf("%d",&num_int);
	for(count=1; count<=num_int; count++){
		temp=count;
			if (count>=21) {
				temp=temp%10;}
			if (temp==0){
				printf("Please input the %dth number:\n",count);
				scanf("%d",&scan_no);
				sum+=scan_no;}
			else if (temp==1){
				printf("Please input the %dst number:\n",count);
				scanf("%d",&scan_no);
				sum+=scan_no;}
			else if(temp==2) {
		    	printf("Please input the %dnd number:\n",count);
				scanf("%d",&scan_no);
				sum+=scan_no;}	
			else if(temp==3) {
				printf("Please input the %drd number:\n",count);
				scanf("%d", &scan_no);
				sum+=scan_no;}
			else if(temp>3&&temp<21) {
				printf("Please input the %dth number:\n",count);
				scanf("%d",&scan_no);
				sum+=scan_no;}
			
	}
		

	printf("sum is %d\n", sum);
	return 0;
}
//This function asks users to type in the number of the coming integers
//then it takes the following integers and calculates their average
int simple_average() {
	int num_int,count,scan_no,temp;
	double avg;
	int sum=0;
	printf("Please indicate the number of integers:\n");
	scanf("%d",&num_int);
	for(count=1; count<=num_int; count++){
		temp=count;
			if (count>=21) {
				temp=temp%10;}
			if (temp==0){
				printf("Please input the %dst number:\n",count);
				scanf("%d",&scan_no);
				sum+=scan_no;}
			else if (temp==1) {
  				printf("Please input the %dst number:\n",count);	
				scanf("%d",&scan_no);
				sum+=scan_no;}
			else if (temp==2) {
				printf("Please input the %dnd number:\n",count);
				scanf("%d",&scan_no);	
				sum+=scan_no;}
			else if (temp==3) {
				printf("Please input the %drd number:\n",count);
				scanf("%d",&scan_no);
				sum+=scan_no;}
			else if (temp>3&&temp<21){
				printf("Please input the %dth number:\n",count);
				scanf("%d",&scan_no);
				sum+=scan_no;}
	}

	avg =(double)sum/(double)num_int;

	printf("average is %.0lf\n", round(avg));
	return 0;
}

// DO NOT MODIFY THE FOLLOWING PART!

// This function takes a command as input and returns an integer as output.
/* INPUT    OUTPUT
   help     0
   EXIT     1
   SUM      2
   AVE      3
   others   4
 */
int check_command(char* input) {
	if (strcmp(input,"help") == 0) {
		return COMMAND_HELP;
	}
	else if (strcmp(input,"exit") == 0) {
		return COMMAND_EXIT;
	}
	else if (strcmp(input,"sum") == 0) {
		return COMMAND_SUM;      
	}
	else if (strcmp(input,"ave") == 0) {
		return COMMAND_AVE;
	}
	else {
		return COMMAND_INVALID;
	}
}

// This function prints the help information
void print_help() {
	printf("Commands available: sum, ave, help, exit\n");
}
