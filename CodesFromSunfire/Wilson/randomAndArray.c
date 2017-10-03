//
//  main.c
//  CprogTest
//
//  Created by Ler Wilson on 12/9/17.
//  Copyright © 2017 Ler Wilson. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void myRand();
void charTest();
void ArrayTest();
void arrayCount();


int main(int argc, const char * argv[]) {
    arrayCount();
    
    return 0;
}


void myRand () {
    srand(time(NULL));
    for (int i = 0; i<= 10; i++) {
        printf("%d\n", rand()%401 + 1); // Prints from 1 to 100
    }
}

void charTest () {
    char c;
    
    while (c != 'n') {
        scanf(" %c", &c); // space added to keep new line from being registered as part of the char set.
        printf("%c\n", c);
    }
}


void ArrayTest () {
    int array[4] = {0};
    int array2[] = {1,2,3,4,5};
    
    for (int i =0; i<4; i++)
        printf("%d\n", array[i]);
}

void arrayCount() {
    int array[] = {1,2,3,4,5};
    int i = 0;
    
    while (1) {
        if (array[i] == '\0') {
            printf("%d\n", i);
            break;
        }
        i++;
    }
}
