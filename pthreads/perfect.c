// Sources: 
// is_percect function: https://www.geeksforgeeks.org/perfect-number/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;

#define NUM_TO_TEST 10000 // N is 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#define checkResults(string, val) {                  \
	if (val) {                                       \
		printf("Failed with %d at %s", val, string); \
		exit(1);                                     \
	}                                                \
}

// Returns true if n is perfect
int is_perfect(int n) {

    // To store sum of divisors
    int sum = 1;
  
    // Find all divisors and add them
    for (int i=2; i*i<=n; i++) {
        if (n % i == 0) {
            if(i * i != n)
                sum += i + n/i;
            else
                sum += i;
        }
    }   

    // If sum of divisors is equal to
    // n, then n is a perfect number
    if (sum == n && n != 1)
         return true;
 
    return false;
}

void *PerfectThreads(void *i) {
	int countSoFar, rc;	

	// critical section with mutex
  	rc = pthread_mutex_lock(&mutex);
	checkResults("pthread_mutex_lock()\n", rc);

	countSoFar = is_perfect((int)i);
  	count = count+countSoFar;

  	rc = pthread_mutex_unlock(&mutex);
	checkResults("pthread_mutex_lock()\n",rc);

	pthread_exit(NULL);
}

int main(int argc, const char * argv[]) {
	pthread_t threads[NUM_TO_TEST]; 
	long rc, t;
	for (t = 0; t < NUM_TO_TEST; t++) {
		rc = pthread_create(&threads[t], NULL, PerfectThreads,(void *) t+1);// t+1 since we start from 1..N not 0...N-1
		if (rc) {
			printf("ERROR return code from pthread_create(): %ld\n", rc);
			exit(-1);
		}
	}
	// wait for threads to exit
	for(t = 0; t < NUM_TO_TEST; t++) {
		pthread_join(threads[t], NULL);
	}
	printf("%d\n", count);
	
	return 0;
}
