#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * delayer(void * arg)
{
  int j;
  for(j = 0; j < (unsigned long int)arg; j++)
    {

      if ((j % 1000) == 0) {} 

    }
  return arg;
}
int main(int argc, char ** argv)
{
  pthread_t mythreads[20];
  int count = 100000000;

  int i;
  for(i = 0; i < 20; i++) 
    {
      pthread_create(&mythreads[i], NULL, delayer, (void *)((i+1)*count));
    }

  for(i = 0; i < 20; i++) 
    {
      pthread_join(mythreads[i],NULL);
    }

  return 0;
}
