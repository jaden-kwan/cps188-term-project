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
					monthlyaverage[count] = monthlyaverage[count] + atof(monthlyavg);
					count++;
			}
			}
		if (count == 12){
			count = 0;
		}
	}while (!(feof(file)));
	
	fclose(file);
	
	for (i = 0 ; i < 12 ; i++){
		monthlyaverage[i] /= 116;
	}
    
    printf("Month      Avg Temp\n-----      -----\n");
    for (i = 0 ; i < 12 ; i++){
		printf("%-9s % 6.3lf \n",&months[i][0],monthlyaverage[i]);
	}
	
	
    
    
   

    printf("\n\nQuestion 4\n\n");
    
    
    file = fopen("GlobalTemperatures.csv", "r");
    double htemperature = -99, ctemperature = 100;
    int hyear, cyear,hmonth,cmonth;
    
    
    
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
			/*printf(" %d  %lf %d\n" , atoi(year),atof(monthlyavg),count);*/
			if (monthlyavg != NULL){
					count ++;
					if (atof(monthlyavg) > htemperature) {
						htemperature = atof(monthlyavg);
						hyear = atoi(year);
						hmonth = count;
					}
					if (atof(monthlyavg) < ctemperature) {
						ctemperature = atof(monthlyavg);
						cyear = atoi(year);
						cmonth = count;
					}
			}
			}
		if (count == 12){
			count = 0;
		}
		}while (!(feof(file)));
    
    printf("Hottest Month: %-9s%d  Temperature: %lf\n",&months[hmonth-1][0],hyear, htemperature);
    printf("Coldest Month: %-9s%d  Temperature: %lf\n",&months[cmonth-1][0],cyear, ctemperature);
    

    printf("\nQuestion 5\n\n");
    
    hyear=0, cyear=0;
    
    htemperature= yearaverage[0]; ctemperature = yearaverage[0];
    
	for (i=0; i <=255; i++){
		if (yearaverage[i] > htemperature){
			htemperature = yearaverage[i];
			hyear = i + 1760;
		}
		if (yearaverage[i] < ctemperature){
			ctemperature = yearaverage[i];
			cyear = i + 1760;
		}
    }
    
    printf("Hottest Year: %d Avg Temp: %lf\n",hyear, htemperature);
    printf("Coldest Year: %d Avg Temp: %lf\n",cyear, ctemperature);

    

    printf("\nQuestion 6\n");

    printf("Question 7");

    printf("Question 8");

    printf("Question 9");

    printf("Question 10");

    printf("Question 11");
    

    printf("Thank you, goodbye!");

    return 0;
}
