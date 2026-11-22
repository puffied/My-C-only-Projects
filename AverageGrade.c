#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct GradeStats   
{
    float average;
    int best_grade;
    int worst_grade;
};

void clear(void) 
{  
   system("clear");
}

struct GradeStats calculate(int totalSum, int count, int grades[]) 
{
    struct GradeStats stats;

    stats.average = (float)totalSum / count;

    stats.best_grade = 6;
    stats.worst_grade = 1;

    for (int i = 0; i < count; i++) {
        if (grades[i] < stats.best_grade) {
            stats.best_grade = grades[i];
        }
    }

     for (int i = 0; i < count; i++) {
        if (grades[i] > stats.worst_grade) {
            stats.worst_grade = grades[i];
        }
    }

    return stats;


}


int gradeCheck(void) 
{
    int num_grades;
    int sum=0;
   

    printf("C Average-Grade Checker (DE - Grades)\n\n");

    while (1) 
    {
        printf("How many grades do you want to enter? ");

    


        if (scanf("%d", &num_grades) != 1) {
        printf("Please enter a number.\n");
        sleep(1);
        clear();
        continue;
        }


        if (num_grades < 2) {
            printf("You must enter at least two grades!\n");
            sleep(1);
            clear();
            continue;
        }

        if (num_grades > 100) {
            printf("Only 100 grades are allowed!\n");
            sleep(1);
            clear();
            continue;
        }
        break;
    }
    
    

    int grades[num_grades];
    

    for (int i = 0; i < num_grades; i++)
    {
        while (1) {
            printf("Enter the %d. grade: ", i + 1);

            if (scanf("%d", &grades[i]) != 1) 
            {
                printf("Please enter a valid number.\n");
                sleep(1);
                clear();
                continue;
            }


            if (grades[i] < 1 || grades[i] > 6) 
            {
                printf("Only grades from 1 to 6 are allowed!\n");
                sleep(1);
                clear();
                continue;
            }

            

            sum += grades[i];
            break;

        }
        
    }

    struct GradeStats result = calculate(sum, num_grades, grades);

    
    
    printf("\n\n\n\nBest grade: %d\n", result.best_grade);
    printf("Worst grade: %d\n", result.worst_grade);
    printf("\nAverage grade: %.2f\n", result.average);


    return 0;
}

int main(void)
{
    return gradeCheck();
}