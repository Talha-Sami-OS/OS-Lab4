#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>


void *runner(void *param); /* the thread */

int main(int argc, const char * argv[]){
	
	int temp_f; //temporary strorage for fork

	pthread_t tid;

	pthread_attr_t attr;

	temp_f = fork();
  
  	if (temp_f == 0) { 	//start a child process

	  pthread_attr_init(&attr);

	  pthread_create(&tid,&attr,runner,NULL);

	  pthread_join(tid,NULL);

	  int f1 = 0, f2 = 1, next = 0;
	  int n;
	  printf("Enter a positive number:\t");
	  scanf("%d", &n);
	  
	  if( n <= 0){
		  printf("%d\t, f1");
	  }

	  else 
	  {
		  printf("Fibonacci Series: %d, %d, ", f1, f2);
		  next = f1 + f2;
		  
		  while (next <= n) {
			  printf("%d, ", next);
		  	  f1 = f2;
		      f2 = next;
		  	  next = f1 + f2;
    	    }
		}

	} 
  	
	else if (temp_f > 0) { /* parent provess */
	  return NULL;
 	}
}


void *runner(void *param) {

  	pthread_exit(0);

}
