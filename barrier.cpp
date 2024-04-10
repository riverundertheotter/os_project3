#include "barrier.h"

namespace synchronization
{
   private: 
	  // mutex: semaphore for mutual exclusion
	  // turnstile1: semaphore for blocking threads in the current phase
	  // turnstile2: semaphore for preparing the next phase
	  // count: number of threads that have arrived
	  // total_threads: total num of threads to synchronize


   barrier::barrier( int numberOfThreads ) {
      // Write your code here
	  // initialize mutex as binary semaphore for mutual exclusion
	  // initialize turnstile1 and turnstile2 as counting initially blocking all threads
	  // set count to 0
	  // set total_threads to numberOfThreads
	  return;
   }

   barrier::~barrier( ) {
      // Write your code here
	  // destroy mutex, turnstile1 and 2
      return;
   }

   void barrier::arriveAndWait( void ) {
      // Write your code here
	  // wait on mutex to enter critical section
	  // increment count
	  // if count == total_threads then
	  // 	loop total_threads times
	  // 		signal turnstile1 to open it and let threads through
	  // signal mutex to leave critical section
	  // wait on turnstile1 allowing threads to proceed in sync
	  //
	  // next phase
	  //
	  // wait on mutex to enter crit section again
	  // count--;
	  // if count == 0 then
	  // 	loop total_threads times
	  // 		signal turnstile2 to open for next phase
	  // signal mutex to leave crit section
	  // wait on turnstile2, ensuring threads are sync'ed for next round
      return;
   }

}
