#include <stdio.h>

#define NUM_OF_ASS 3 // number of Assignments given this semester (3)

#define ASS_PERC 10 // percentage for Assignments (10) 
#define MAX_PERC (ASS_PERC * NUM_OF_ASS)

// Ask the user for a grade, given the assessment testing
// as well as the amount of questions in that assessment and the double array of information
// to be used later in calculation
void askForGrade(char *assessment, int numOfQuestions, double *assessmentGrades) {
    for (int i = 0; i < numOfQuestions; i++) {
        printf("What was your grade for %s %d as decimal: ",assessment, (i+1));
        scanf("%lf", &assessmentGrades[i]);
    }   
}

// Calculate the grade out of 15%
double calculateGrade(double *ass) {
    double answer = 0.0;
    for (int i = 0; i < NUM_OF_ASS; i++) {
        answer += ASS_PERC * ass[i];    
    }   

	printf("%lf is answer", answer);
    return answer;
}

int main() {
    double ass[NUM_OF_ASS];
    printf("Calculator of Grade in Applied Probability II, out of %d\n", MAX_PERC); 

    askForGrade("Assignment",NUM_OF_ASS, ass);

    printf("Your score out of %d%% is %.2f%%\n", MAX_PERC, calculateGrade(ass));

    return 0;
}
