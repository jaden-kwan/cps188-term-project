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
        //lets you know that you don't have the csv file in the right place7
    }

    printf("Welcome to the Term Project Program!");


 printf("\n Question 1 \n\n");
    /* Question 1, Find the land Temperature 
     * average between 1760 - 2015 */
     
    int count = 0, i =0, n;
    char temp[MAX_LENGTH];
    char *token, *monthlyavg, *year;
    double currentyearlyavg=0,yearaverage[255], dmonthlyavg, centuryavg[MAX_LENGTH], century ;
	//takes the first line and puts it into temp
	fgets(temp,MAX_LENGTH,file);
	
	do {
		// first is useless so go to the second
		fgets(temp,MAX_LENGTH,file);
		
		// split the line at the commas
		token = strtok(temp,",");
		monthlyavg = strtok(NULL,",");
		// split the line at the dashes to get the year
		year = strtok(token,"-"); 
		
		//convert the year to a int and check its alteast 1960
		if ( atoi(year) >= 1760){
			if (monthlyavg != NULL){
			// convert the monthly average to a double (float)
			dmonthlyavg=atof(monthlyavg);
			currentyearlyavg += dmonthlyavg;
			count += 1;
		} }
		/* if the count reaches 12 (a year has 12 months)
		 * take the running total and find the average*/
		if (count == 12){
			currentyearlyavg = currentyearlyavg/12;
			yearaverage[i]=currentyearlyavg;
			//move to next spot in array
			i++;
			//reset count and yearly average
			count = 0;
			currentyearlyavg=0;
		}
		
	}while (!(feof(file)));
	
	
	fclose(file);
	
	//print it 
	printf("   Year	 Avg Temp(C*)\n   ----  ----------\n");
	for (i=0; i <=255; i++)
		printf("   %d  %lf\n",i+1760,yearaverage[i]);
		
    printf("\nQuestion 2\n\n");
    /* Calculate the average land temperature value for every century*/
    
    count = 0;
	n=0;
	

	printf("Century    AverageTemperature\n");
    for (i = 1760; i <= 1760+256; i++){
		if  (i % 100 ==0 || i  == 2016){
			
	
			century /= count;
			centuryavg[n] = century;
			
			printf("%d-%d   %lf \n",i-count,i-1,centuryavg[n]);

			
			n++;
			count=0;
			century =0;
		}
		century += yearaverage[i-1760] ;
		count++;

	}
	

    
    
    file = fopen("GlobalTemperatures.csv", "r");
	
    double monthlyaverage[12] ;
    char months[][MAX_LENGTH]= { {"January"}, {"Febuary"},{"March"},{"April"},{"May"},{"June"},{"July"},{"August"},{"September"},{"October"},{"November"},{"December"}}  ;

    printf("\nQuestion 3\n\n");
    
    count = 0;
    
    do {
		// first is useless so go to the second
		fgets(temp,MAX_LENGTH,file);
		
		// split the line at the commas
		token = strtok(temp,",");
		monthlyavg = strtok(NULL,",");
		// split the line at the dashes to get the year
		year = strtok(token,"-"); 
		//convert the year to a int and check its alteast 1960
		if ( atoi(year) >= 1900){
			/*printf(" %d  %lf %d\n" , atoi(year),atof(monthlyavg),count);*/
			if (monthlyavg != NULL){
				if (count == 0){
					monthlyaverage[0] = monthlyaverage[0] + atof(monthlyavg);
					count++;
				}else if (count == 1){
					monthlyaverage[1] += atof(monthlyavg);
					count++;
				}else if (count == 2){
					monthlyaverage[2] += atof(monthlyavg);
					count++;
				}else if (count == 3){
					monthlyaverage[3] += atof(monthlyavg);
					count++;
				}else if (count == 4){
					monthlyaverage[4] += atof(monthlyavg);
					count++;
				}else if (count == 5){
					monthlyaverage[5] += atof(monthlyavg);
					count++;
				}else if (count == 6){
					monthlyaverage[6] += atof(monthlyavg);
					count++;
				}else if (count == 7){
					monthlyaverage[7] += atof(monthlyavg);
					count++;
				}else if (count == 8){
					monthlyaverage[8] += atof(monthlyavg);
					count++;
				}else if (count == 9){
					monthlyaverage[9] += atof(monthlyavg);
					count++;
				}else if (count == 10){
					monthlyaverage[10] += atof(monthlyavg);
					count++;
				}else if (count == 11){
					monthlyaverage[11] += atof(monthlyavg);
					count++;
				}
			}
			}
		if (count == 12){
			count = 0;
		}
	}
	while (!(feof(file)));
	
	fclose(file);
	
	for (i = 0 ; i < 12 ; i++){
		monthlyaverage[i] /= 116;
	}
    
    printf("Month      Avg Temp\n-----      -----\n");
    for (i = 0 ; i < 12 ; i++){
		printf("%-9s % 6.3lf \n",&months[i][0],monthlyaverage[i]);
	}
    
    
    

    printf("\nQuestion 4\n");

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
