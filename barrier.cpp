#include <semaphore.h>
#include <iostream>
#include "barrier.h"

namespace synchronization {

   barrier::barrier( int numberOfThreads ) {
      // Write your code here
	  // initialize mutex as binary semaphore for mutual exclusion
	  sem_init(&mutex, 0, 1);
	  // initialize turnstile1 and turnstile2 as counting initially blocking all threads
	  sem_init(&turnstile1, 0, 0);
	  sem_init(&turnstile2, 0, 0);
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
	  	for (int i = 0; i < total_threads; i++) {
	  		sem_post(&turnstile1); // open first turnstile
		}
	  }
	  // signal mutex to leave critical section
	  // wait on turnstile1 allowing threads to proceed in sync
	  sem_post(&mutex);
	  sem_wait(&turnstile1);
	  // next phase
	  // wait on mutex to enter crit section again
	  sem_wait(&mutex);
	  count--;
	  if (count == 0) {
	  	for (int i = 0; i < total_threads; i++) {
	  		sem_post(&turnstile2); // open second turnstile
		}
	  }
	  // signal mutex to leave crit section
	  // wait on turnstile2, making sure threads are sync'ed for next round
      sem_post(&mutex);
	  sem_wait(&turnstile2);
	  return;
   }
}
