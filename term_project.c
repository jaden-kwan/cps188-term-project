#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024   // idk define the maximum length of each line from CSV

/* 
Hey guys, welcome to the repo! Feel free to push your commits to this 
main file, but only put your code live in this program once you're sure 
it won't mess with the rest of the program!

I threw some random stuff in the main function to kinda outline a structure,
but basically if you want to explain what your question solves briefly
replace that with "Question #", and initialize all variables at the beginning.
*/


/* QUESTION 1
Based on the land average temperature column, calculate the yearly averages for each 
year between 1760 and 2015 (the average of the twelve months of each year). One average 
per year. Ignore the years 1750-1759. Based on the land average temperature column, 
calculate the average land temperature for the different centuries: 18th century (1760-1799), 
19th century (1800-1899), 20th century (1900-1999) and 21st century (2000-2015). One average per century.
*/


int main(){
    FILE *file;
    
    file = fopen("GlobalTemperatures.csv", "r");
    if (!file){
        printf("Cannot open file!\n");
        return 1;
        //lets you know that you don't have the csv file in the right place
    }

    printf("Welcome to the Term Project Program!");


    printf("Question 1");

    printf("Question 2");

    printf("Question 3");

    printf("Question 4");

    printf("Question 5");

    printf("Question 6");

    printf("Question 7");

    printf("Question 8");

    printf("Question 9");

    printf("Question 10");

    printf("Question 11");
    

    printf("Thank you, goodbye!");

    return 0;
}