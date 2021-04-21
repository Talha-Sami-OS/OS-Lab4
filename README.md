# OS-Lab4
//2017-EE-25//2017-EE-18
//programing assignment 

//exercise 4.24
An interesting way of calculating pi is to use a technique known as Monte Carlo, which involves randomization. By using formula 
pi = 4 x ( number of points in circle ) / ( total number of points ). 
...>ex4_24.c : This is the C program for the Monte Carlo program.
This program generates random x and y coordinates inside a circle based on user input, falling inside the square using logic x^2+y^2<=1.

\\exercixe 4.27
The Fibonacci sequence is the series of numbers 0, 1, 1, 2, 3, 5, 8, .... the tast is to create multithreaded program that generates the Fibonacci sequence. we have implemented pthread to create a separate thread d that will generate the Fibonacci numbers, placing the sequence in data that can be shared by the threads, according to the count user provided.
...>ex4_27.c : This is the C program for the Fibonacci series program.
This program generates fibonacci series according to the user input by creating separate thread.

\\exercixe 7.17
Using Monte Carlo technique, Modify that program so that you create several threads, each of which generates random
points and determines if the points fall within the circle. Each thread will have to update the global count of all points that fall within the circle. Protect against race conditions on updates to the shared global variable by using mutex locks.
Each point produce points_per_thread random points, for computng slave threads.
...>ex7_17.c : This is the C program for the Modified Monte Carlo program using mutex locks.
This program generates random x and y coordinates inside a circle based on user input, falling inside the square using logic x^2+y^2<=1.
