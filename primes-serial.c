#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DEFAULT_MAX_TESTS 16000000

inline int isprime(unsigned long number)
{
    unsigned long i;
      unsigned long s = sqrt(number);
        for(i=3;i<=s;i+=2)
            {
                  if(number % i == 0)
                          return 0;
                    }
          return 1;
}

int main(int argc, char* argv[]) {
    clock_t begin, end, current;
      double time_spent;
        int primes_found = 0;

          begin = clock();

            for (int i=0;i<DEFAULT_MAX_TESTS;i++) {
                  if (isprime(i)) {
                          primes_found += 1;
                              }
                      if (i%100000 == 0) {
                              current = clock();
                                    time_spent = (double)(current-begin)/CLOCKS_PER_SEC;
                                          printf("Elapsed time: %f sec. Current number: %d.\n",time_spent,i);
                                              }
                        }
              end = clock();
                time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

                  printf("Found %d primes under %d in %f seconds.\n", primes_found, DEFAULT_MAX_TESTS, time_spent);
}
