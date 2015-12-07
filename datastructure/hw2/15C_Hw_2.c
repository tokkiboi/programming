/*********************************************************************************
** CIS 15C															  Winter, 2013
** Data Structures
******************
**
** Homework 2: QUEUE ADT
**
**********************************************************************************

   Your program will consist of two source files and one header file:
        15C_Hw_2.c
        queueADT.c // given
        queueADT.h // given

   Basic Assignment:
   A variation of Problem 19, page 188: Write a menu driven user interface to test each of
   the operations in the ADT. Replace the integers in the queue by strings that
   hold 3 letter names. To test your program use the test cases at page 188 and replace
   input 5 by Ann, 8 by Bob, 14 by Dan, and 32 by Tom.

   Advanced Assignment:
   Problem 23, page 191: Queue simulation using multiple queue servers and a
   single queue

   Save the output as a comment at the end of the program!
**********************************************************
**
**  Written By: Instructor
**    Amrita Mukherjee                    // <-- write your name here
**
**  Date:    1/21/2013              // <-- write the date here
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "queueADT.h"

#ifdef _MSC_VER
#include <crtdbg.h>  // needed to check for memory leaks (Windows only!)
#endif

int main( void )
{
	QUEUE *queue;
	QUEUE_NODE *queueNode;
	void* dataInPtr;
	void* dataOutPtr;
	int queue_status;
	int queue_element_count;
	
	queue = createQueue ();

	//a.print queue status, Empty
	printf("Test Case(a) : Print queue status, Empty\n\n");
	queue_status = emptyQueue(queue);
	if(queue_status == 1)
	{
		printf("queue status : Empty\n");
	}
	else
	{
		printf("queue status : not empty\n");
	}
	printf("\n\n");
	
	//b.Dequeue and print data. Should return error
	printf("Test Case(b) : Dequeue and print data\n\n");
	dequeue( queue, &dataOutPtr );
	printf("\n\n");
		
	//c. Enqueue data into queue
	printf("Test Case(c) : Enqueue data into queue : Ann\n\n");
	dataInPtr = (char*)calloc((strlen("Ann")+1), sizeof(char) );
	strcpy(dataInPtr, "Ann");
	enqueue( queue, dataInPtr);
	
	//d. Enqueue data into queue
	printf("Test Case(d) : Enqueue data into queue : Bob\n\n");
	dataInPtr = (char*)calloc(strlen("Bob")+1, sizeof(char) );
	strcpy(dataInPtr, "Bob");
	enqueue( queue, dataInPtr);

	//e.Print queue status, Empty
	printf("Test Case(e) : Print queue status, Empty\n\n");
	queue_status = emptyQueue(queue);
	if(queue_status == 1)
	{
		printf("queue status : Empty\n");
	}
	else
	{
		printf("queue status : not empty\n");
	}
	printf("\n\n");
	
	//f.Print queue status, Full
	printf("Test Case(f) : Print queue status, Full\n\n");
	queue_status = fullQueue( queue );
	if(queue_status == 1)
	{
		printf("queue status : Full\n");
	}
	else
	{
		printf("queue status : not full\n");
	}
	printf("\n\n");
	
	//g. Print data at the front
	printf("Test Case(g) : Print data at the front\n\n");
	queueFront  ( queue, &dataOutPtr );
	printf("Data at the queue front is : %s\n", queue->front->dataPtr);
	printf("\n\n");
	
	//h. Print data at the rear
	printf("Test Case(h) : Print data at the rear\n\n");
	queueRear   ( queue, &dataOutPtr );
	printf("Data at the queue rear is : %s\n", queue->rear->dataPtr);
	printf("\n\n");

	//i. Print entire queue
	printf("Test Case(i) : Print entire queue\n\n");
	printf("The entire queue is : ");
	queueNode = queue->front;
	while(queueNode != NULL)
	{
		printf("%s ", queueNode->dataPtr);
		queueNode = queueNode->link;
	}
	printf("\n\n");

	//j.Print number of element in queue
	printf("Test Case(j) : Print number of element in queue\n\n");
	queue_element_count = queueCount( queue );
	printf("total no of element in queue is %d\n", queue_element_count);
	printf("\n\n");
	
	//k.Dequeue and print data
	printf("Test Case(k) : Dequeue and print data\n\n");
	dequeue( queue, &dataOutPtr );
	printf("after dequeueing we got : %s\n", dataOutPtr);
	free(dataOutPtr);
	printf("\n\n");

	//l.Dequeue and print data
	printf("Test Case(l) : Dequeue and print data\n\n");
	dequeue( queue, &dataOutPtr );
	printf("after dequeueing we got : %s\n", dataOutPtr);
	free(dataOutPtr);
	printf("\n\n");
	
	//m.Dequeue and print data
	printf("Test Case(m) : Dequeue and print data\n\n");
	dequeue( queue, &dataOutPtr );
	printf("\n\n");
	
	//n. Enqueue data into queue
	printf("Test Case(n) : Enqueue and print data : Dan\n\n");
	dataInPtr = (char*)calloc(strlen("Dan")+1, sizeof(char) );
	strcpy(dataInPtr, "Dan");
	enqueue( queue, dataInPtr );
	
	//o. Print data at the front
	printf("Test Case(o) : Print data at the front\n\n");
	queueFront  ( queue, &dataOutPtr );
	printf("Data at the queue front is : %s\n", queue->front->dataPtr);
	printf("\n\n");
	
	//p. Print data at the rear
	printf("Test Case(p) : Print data at the rear\n\n");
	queueRear   ( queue, &dataOutPtr );
	printf("Data at the queue rear is : %s\n", queue->rear->dataPtr);
	printf("\n\n");
	

	//q. Enqueue data into queue
	printf("Test Case(q) : Enqueue data into queue : Tom\n\n");
	dataInPtr = (char*)calloc(strlen("Tom")+1, sizeof(char) );
	strcpy(dataInPtr, "Tom");
	enqueue( queue, dataInPtr );
	
	//r. print data at the front
	printf("Test Case(r) : Print data at the front\n\n");
	queueFront( queue, &dataOutPtr );
	printf("Data at the queue front is : %s\n", queue->front->dataPtr);
	printf("\n\n");
	
	//s. Print data at the rear
	printf("Test Case(s) : Print data at the rear\n\n");
	queueRear   ( queue, &dataOutPtr );
	printf("Data at the queue rear is : %s\n", queue->rear->dataPtr);
	printf("\n\n");

	//t. Destroy queue and quit
	printf("Test Case(t) : Destroy queue and quit\n\n");
	destroyQueue( queue );
	#ifdef _MSC_VER
    printf( _CrtDumpMemoryLeaks() ? "Memory Leak\n" : "No Memory Leak\n");
    #endif    
	system("pause");
    return 0;
}

/*

Test Case(a) : Print queue status, Empty

queue status : Empty


Test Case(b) : Dequeue and print data

Error message : queue already empty, cannot be dequeued


Test Case(c) : Enqueue data into queue : Ann

Test Case(d) : Enqueue data into queue : Bob

Test Case(e) : Print queue status, Empty

queue status : not empty


Test Case(f) : Print queue status, Full

queue status : not full


Test Case(g) : Print data at the front

Data at the queue front is : Ann


Test Case(h) : Print data at the rear

Data at the queue rear is : Bob


Test Case(i) : Print entire queue

The entire queue is : Ann Bob

Test Case(j) : Print number of element in queue

total no of element in queue is 2


Test Case(k) : Dequeue and print data

after dequeueing we got : Ann


Test Case(l) : Dequeue and print data

after dequeueing we got : Bob


Test Case(m) : Dequeue and print data

Error message : queue already empty, cannot be dequeued


Test Case(n) : Enqueue and print data : Dan

Test Case(o) : Print data at the front

Data at the queue front is : Dan


Test Case(p) : Print data at the rear

Data at the queue rear is : Dan


Test Case(q) : Enqueue data into queue : Tom

Test Case(r) : Print data at the front

Data at the queue front is : Dan


Test Case(s) : Print data at the rear

Data at the queue rear is : Tom


Test Case(t) : Destroy queue and quit

No Memory Leak
Press any key to continue . . .

*/

