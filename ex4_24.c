#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>


#define total_points    1000000
#define threads   1

int value_circle = 0;
void *runner(void *param); /* the thread in the circle*/
 
int main (int argc, const char * argv[]) {
    
    int i = 0 ;
    double pi_value;    
    int points_per_thread = total_points / threads;
    
    pthread_t runners[threads]; /* the thread identifier */
 

    for (i = 0; i < threads; i++)
        /* create the thread */
        pthread_create(&runners[i], 0, runner, &points_per_thread);
     
    for (i = 0; i < threads; i++)
    /* wait for the thread to exit */
        pthread_join(runners[i],NULL);
     
    /* estimating Pi */
    printf("Number of total points of circle = %d\n", total_points);
    pi_value = 4.0 * value_circle / total_points;
    printf("The approximate value of Pi = %f\n",pi_value);
     
    return 0;
}
 
/* The thread will execute in this function */ 
void *runner(void *param)
{
    int total_points;
    total_points = *((int *)param);
    int i;
    int count = 0;
    double x,y;
     
    for (i = 0; i < total_points; i++) {
         
        // to obtain a random numbers point
        double x = (double)rand() / RAND_MAX;   //creates a double random number
        double y = (double)rand() / RAND_MAX;
       
        if ( sqrt(x*x + y*y) <= 1.0 )   //x, y point is point within the circle
            count++; 
        else 
            return NULL;   
    }
     
    value_circle += count;
         
    pthread_exit(0);
}
