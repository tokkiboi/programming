/*********************************************************************************
** CIS 15C															  Winter, 2013
** Data Structures
******************
**
** Homework 1: Review
**        Pointers, Structures, Arrays, Linked Lists, and
**        Dynamic Allocation of Memory
**
**********************************************************************************

   This program builds and prints a matrix of linked list of random numbers.

   Basic Assignment:
   Given a square array of linked lists, create 2 linked lists.
    - the first linked list is to contain all nodes located above and on the left-right diagonal
    - the second linked list is to contain the remaining nodes.

   Advanced Assignment:
   Given a square array of linked lists, create 3 linked lists:
    - the first linked list is to contain all nodes located above the left-right diagonal
    - the second linked list is to contain all nodes located on the left-right diagonal
    - the third linked list is to contain the remaining nodes

   Write (at least) two functions, including the standard documentation:
   split and freeList

   Save the output as a comment at the end of the program!
**********************************************************
**
**  Written By: Instructor
**              Amrita Mukherjee
**
**  Date:       2013-01-09
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifdef _MSC_VER
#include <crtdbg.h>  // needed to check for memory leaks (Windows only!)
#endif
typedef struct node{
    int          data;
    struct node *link;
} NODE;

typedef struct{
	int rows;
	int cols;
	NODE **m;
}MATRIX;


MATRIX *createMatrix(int rows, int cols);
MATRIX *buildRandomMatrix( int rows, int cols );
void   printMatrix( MATRIX *matrix );

NODE   *buildRandomList( int n );
void   printList( NODE *pList );

void split( MATRIX *matrix, NODE **plist1, NODE **plist2 ); 
NODE* fetch_node(MATRIX* matrix, int row, int col); // 0 based row and column
void freeList(NODE *plist);

int main( void )
{
//  Local Definitions
	MATRIX *matrix;
	NODE *plist1;
	NODE *plist2;

//  Statements

	//matrix = buildRandomMatrix( 6, 6 );
    //matrix = buildRandomMatrix( 3, 3 );
	matrix = buildRandomMatrix( 2, 2 );
	//matrix = buildRandomMatrix( 1, 1 );
	//matrix = buildRandomMatrix( 0, 0 );
	//matrix = buildRandomMatrix( -10, -10 );
	//matrix = buildRandomMatrix( 5, 6 );

	if( !matrix )
		printf("Invalid sizes!\n");
	else
	{
		printf("ORIGINAL MATRIX:\n\n");
		printMatrix( matrix );

		split(matrix, &plist1, &plist2); 
		printf("NEW LISTS:\n\n");
		printf("List1:");
		printList(plist1);
		printf("List2:");
		printList(plist2);


		freeList(plist1); // frees all the nodes in the linked list starting from plist1
		freeList(plist2); // frees all the nodes in the linked list starting from plist2
		free(matrix->m); //frees lists of row node pointers 
		free(matrix);//frees matrix


        #ifdef _MSC_VER
	    printf( _CrtDumpMemoryLeaks() ? "Memory Leak\n" : "No Memory Leak\n");
	    #endif
	}

    system("pause");
	return 0;
}
/* =======================================================
   This function returns pointer to the node situated at (row, col)
     PRE:  matrix - - a pointer to the header structure of
	                a matrix,
           row - the number of linked lists
           col - the number of elements in each linked list
     POST: returns pointer to the NODE at location (row, col)
*/

NODE* fetch_node(MATRIX* matrix, int row, int col) // 0 based row and column
{
    /*
               0   1   2   3   4   5
    Row #0:   67  24  90  10  81  36
    Row #1:   49  38  87  76  14  27
    Row #2:   46  27  43   7  86  20
    Row #3:   39  38  59  96   8  56
    Row #4:   90  65  51  47  63  10
    Row #5:   93  41  76  83  25  47
    */

	//local definition
    int i;
    NODE* mynodeptr;
    
	//statements
	mynodeptr = *(matrix->m + row);
    
	i = 0;
	while (i < col)
    {
        mynodeptr = mynodeptr->link;
        i++;
    }
    return mynodeptr;
}// fetch_node

/* =======================================================
   This function splits the matrix in two list,
     PRE:  matrix - a pointer to the header structure of
	                a matrix,
           plist1 - a pointer to the pointer of list1.
           plist2 - a pointer to the pointer of list2.
     POST: plist1 - modified pointer to the pointer of list1
           plist2 - modified pointer to the pointer of list2
*/
void split( MATRIX *matrix, NODE **plist1, NODE **plist2 ) 
{
	//local definition
    int row;
    int col;
    NODE* list1;
    NODE* list2;
    NODE* pCurrent;
    NODE* pNext;

	//statements
    for(row=0; row<matrix->rows; row++)
    {
        for(col=row;col<(matrix->cols); col++)
        {
            pNext = fetch_node(matrix, row, col);

            if (row == 0 && col == 0)//creates the first node in the list
            {
                list1 = pNext;
            }
            else //creates the rest of the node
            {
                pCurrent->link = pNext;
            }
            pCurrent = pNext;
        }
    }
    pCurrent->link = NULL;

    for(row=1; row<matrix->rows; row++)
    {
        for(col=0;col<row; col++)
        {
            pNext = fetch_node(matrix, row, col);

            if (row == 1 && col == 0)//creates the first node in the list
            {
                list2 = pNext;
            }
            else
            {
                pCurrent->link = pNext;//creates the rest of the node
            }
            pCurrent = pNext;
        }
    }
    pCurrent->link = NULL;


    *plist1 = list1;
    *plist2 = list2;

    return;
}//split
/* =======================================================
   This function frees all the nodes in the linked list starting from plist
     PRE:  plist - a pointer to the list
     POST: returns nothing, frees up all the nodes to heap

*/
void freeList(NODE *plist)
{
    //local definition
	NODE *next;

    //statements
	while(plist != NULL)
    {
        next = plist->link;
        free(plist);
        plist = next;
    }

    return;
}//freelist


/* ********************************************************** */
/* INSTRUCTOR *********************************************** */
/* ********************************************************** */

/* =======================================================
   This function allocates a header structure for a MATRIX
   and a list of row NODE pointers
     PRE:  rows - the number of linked lists
	       cols - the number of elements in each linked list
     POST: returns a pointer to the structure, all fields
	       initialized, OR NULL if not enough memory
*/
MATRIX *createMatrix(int rows, int cols)
{
	MATRIX *matrix;

	matrix = (MATRIX *) malloc(sizeof(MATRIX));
	if( matrix )
	{
		matrix->rows = rows;
		matrix->cols = cols;
		matrix->m    = (NODE **) calloc( rows, sizeof(NODE *));
		if( !matrix->m ) // not enough memory
		{
			free(matrix);
			matrix = NULL;
		}
	}
	return matrix;
}

/* ======================================================
   This function builds a matrix of rows linked lists,
   each containing cols random numbers
     PRE: rows - the number of linked lists
	      cols - the number of elements in each linked list

     POST: returns a pointer to MATRIX header structure
*/
MATRIX* buildRandomMatrix( int rows, int cols )
{
//  Local Definitions
	MATRIX *matrix = NULL;
	int    r;

//  Statements
	srand( time(NULL) );

	if ( rows > 0 && rows == cols )
	{
		matrix = createMatrix (rows, cols);
		for( r = 0; r < rows; r++ )
			matrix->m[r] = buildRandomList(cols);
	}// if
	return matrix;
}


/* ======================================================
   This function prints a matrix of rows linked lists,
   each containing cols random numbers
     PRE:  matrix - a pointer to the header structure of
	                a matrix
     POST: matrix printed
*/
void printMatrix( MATRIX *matrix )
{
//  Local Definitions
	int r;

//  Statements
	for( r = 0; r < matrix->rows; r++ )
	{
		printf( "Row #%d: ", r + 1 );
		printList(matrix->m[r]);
	}
	printf("\n\n\n");

	return;
}

/* ======================================================
   This function builds a linked list of n random numbers
     PRE:  n - number of nodes
     POST: returns a pointer to the first node
*/
NODE *buildRandomList( int n )
{
//  Local Definitions
	NODE * pList;
	NODE * pNew;
    NODE * pPre;
	int    i;

//  Statements
	pList = NULL; //empty list
	if ( n > 0 )
	{
		// create the first node in the list
		pList = (NODE *) malloc(sizeof(NODE));
		if( pList == NULL )
		{
			printf( "Not enough memory\n" );
			exit(100);
		}
		pList->data = 1 + rand() % 99;
		// create the rest of the nodes
		pPre = pList;
		for( i = 1; i < n; i++ )
		{
			pNew = (NODE *) malloc(sizeof(NODE));
			if( pNew == NULL )
			{
				printf( "Not enough memory\n" );
				exit(100);
			}
			pNew->data = 1 + rand() % 99;
			pPre->link = pNew;
			pPre = pNew;
		}
		pPre->link = NULL; // set the last node's link to NULL
	}
	return pList;
}


/* ======================================================
   This function prints a linked list
     PRE:  pList - pointer to the first node in the list
     POST: list printed
*/
void printList( NODE *pList )
{
   NODE *pCurr;

   pCurr = pList;
   while( pCurr != NULL )
   {
      printf( "%4d", pCurr->data );
      pCurr = pCurr->link;
   }
   printf("\n");

   return;
}
/*
My Test Session : 1

ORIGINAL MATRIX:

Row #1:   29  84  30  65  68  86
Row #2:   23  86  97  31  54   6
Row #3:   66  46  60  10  80  58
Row #4:   70  13  30  43  60  44
Row #5:   17  96  15  93  91  34
Row #6:   10  92  16  65  89  41



NEW LISTS:

List1:  29  84  30  65  68  86  86  97  31  54   6  60  10  80  58  43  60  44  91  34  41
List2:  23  66  46  70  13  30  17  96  15  93  10  92  16  65  89
No Memory Leak
Press any key to continue . . .




My Test Session : 2

ORIGINAL MATRIX:

Row #1:   65  92
Row #2:   22  49



NEW LISTS:

List1:  65  92  49
List2:  22
No Memory Leak
Press any key to continue . . .
*/


