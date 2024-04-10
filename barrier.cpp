#include <semaphore.h>
#include "barrier.h"

namespace synchronization
{
   private: 
	  // mutex: semaphore for mutual exclusion
	  sem_t mutex;
	  // turnstile1: semaphore for blocking threads in the current phase
	  sem_t turnstile1;
	  // turnstile2: semaphore for preparing the next phase
	  sem_t turnstile1;
	  // count: number of threads that have arrived
	  int count;
	  // total_threads: total num of threads to synchronize
	  int total_threads;

   barrier::barrier( int numberOfThreads ) {
      // Write your code here
	  // initialize mutex as binary semaphore for mutual exclusion
	  // initialize turnstile1 and turnstile2 as counting initially blocking all threads
	  count = 0;
	  total_threads = numberOfThreads;
	  return;
   }

   barrier::~barrier( ) {
      // Write your code here
      sem_destroy(&mutex);
	  sem_destroy(&turnstile1);
	  sem_destroy(&turnstile2);
	  return;
   }

   void barrier::arriveAndWait( void ) {
      // Write your code here
	  // wait on mutex to enter critical section
	  sem_wait(&mutex);
	  count++;
	  if (count == total_threads) {
	  // 	loop total_threads times
	  	for (int i = 0; i < total_threads; i++) {
	  // 	signal turnstile1 to open it and let threads through
	  	}
	  }
	  // signal mutex to leave critical section
	  // wait on turnstile1 allowing threads to proceed in sync
	  sem_wait(&turnstile1);
	  // next phase
	  //
	  // wait on mutex to enter crit section again
	  sem_wait(&mutex);
	  count--;
	  if (count == 0) {
	  // 	loop total_threads times
	  	for (int i = 0; i < total_threads; i++) {
	  // 		signal turnstile2 to open for next phase
	  	}
	  }
	  // signal mutex to leave crit section
	  // wait on turnstile2, ensuring threads are sync'ed for next round
      sem_wait(&turnstile2);
	  return;
   }

}
