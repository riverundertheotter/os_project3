#ifndef BARRIER_H
#define BARRIER_H


#include <semaphore.h>

namespace synchronization
{
   // Provides a reusable barrier
   class barrier {
   private:
   	  sem_t mutex;
	  sem_t turnstile1;
	  sem_t turnstile2;
	  int count;
	  int total_threads;
   public:

      // Constructor
      barrier( int numberOfThreads );

      // Destructor
      ~barrier( );

      // Function to wait at the barrier until all threads have reached the barrier
      void arriveAndWait( void );
   };

}

#endif
