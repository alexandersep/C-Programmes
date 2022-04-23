#include <stdio.h>

#define NUM_OF_CA 3 // number of CA's 
#define NUM_OF_QZ 3 // number of Quizes 

#define CA_PERC 2 // percentage for CA 
#define Q_PERC 3 // percentage for Quiz 
#define MAX_PERC ((CA_PERC * NUM_OF_CA) + (Q_PERC * NUM_OF_QZ)) // Max percentage for CA's and Quizes

// Ask the user for a grade, given the assessment testing
// as well as the amount of questions in that assessment and the double array of information
// to be used later in calculation
void askForGrade(char *assessment, int numOfQuestions, double *assessmentGrades) {
	for (int i = 0; i < numOfQuestions; i++) {
		printf("What was your grade for %s %d as decimal: ",assessment, (i+1));
        scanf("%lf", &assessmentGrades[i]);
    }  
}

// Calculate the grade out of MAX_PERC
double calculateGrade(double *cas, double *q) {
	double answer = 0.0;
	for (int i = 0; i < NUM_OF_CA; i++) {
		answer += CA_PERC * cas[i]; 	
	}
	for (int i = 0; i < NUM_OF_QZ; i++) {
		answer += Q_PERC * q[i]; 	
	}
	return answer;
}

int main() {
	double cas[NUM_OF_CA], q[NUM_OF_QZ];
	printf("Calculator of Grade in Applied Probability II, out of %d\n", MAX_PERC); 

	askForGrade("Continous Assessment",NUM_OF_CA, cas);
	askForGrade("Quiz",NUM_OF_QZ, q);

	printf("Your score out of %d%% is %.2f%%\n", MAX_PERC, calculateGrade(cas, q));

	return 0;
}
