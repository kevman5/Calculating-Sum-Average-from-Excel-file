
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


int main() {
    FILE *file;
    char *sp, str[100], sales[30], profit1[30];
    double avg, sum=0, sum1=0, avg1;
    int total, profit;
    // ^^ these are all of my variables

    file = fopen("c:\\NVIDIA\\excelNumbers.csv", "r");  //<< -- open file as a Read file not write!
    if (file == NULL) {     // < -- if file is null print the error, if not, continue
        printf("Error opening this file! \n");
        return 1;
    }
    while (fgets(str,100,file) != NULL) {       // < -- while it is not NULL do these below;
        printf(str);  // < -- this lists all info in the file
        sp = strtok(str, ",");

        sp = strtok(NULL, ","); // < -- separating by commas
        strcpy(sales, sp);

        sp = strtok(NULL, ",");

        strcpy(profit1, sp);
        /*printf("profit is :  %d\n\n",profit1); // this was to test to make sure i'm retrieving the right information
        printf("the sales: %s\n\n", sales); // this was to test to make sure i'm retrieving the right information*/
        sum += atof(sales); // < -- calculating sum
        sum1 += atof(profit1); // < -- calculating sum
        total++; // < -- counter

    }
    // these are all of my prints to list the totals and the calculation for avg
    printf("\n\nSum of the total sales: %.2f\n", sum);
    avg = sum / total;
    printf("Avg of the total sales: %.2f\n", avg);

    printf("Sum of the total profits: %.2f\n", sum1);
    avg1 = sum1 / total;
    printf("Avg of the total profits: %.2f\n ", avg1);
    fclose(file); //< -- closes file
    return 0;


}



