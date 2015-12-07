#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct person{
                    char name[10];
                    float height;
                    struct person* next;
                    }PERSON;
PERSON* getData(FILE*);
PERSON* position(PERSON* head, PERSON* adding);
char menu(void);
void print(PERSON*);
float calcAvg(PERSON*);
PERSON* removeNode(PERSON*);
PERSON* addNode(PERSON* parentNode);  // Returns pointer to the node added
PERSON* modify(PERSON* HEAD);
int count(PERSON* HEAD);
PERSON* calcShortestPerson(PERSON* head);
void outputToFile(PERSON* head);

int main (void)
{
	char ch; FILE* fp;
	PERSON* head = NULL;
	PERSON* tail = NULL;
	PERSON* walker;
	float average;

	if(!(fp = fopen("result.txt", "r")))//open the file in read mode
	{
		printf("NO SUCH FILE"); system("pause"); exit(100);
	}

	/*The current list is entered from the file*/
	/*The list is in descending order by heights*/
	head=getData(fp);
	print(head);

	while ((ch=menu()) != 'E')
	{
		switch (ch)
		{
		case 'P':  print(head); break;
		case 'A':
			printf("\nWrite function to add a single person");
			printf(" from the keyboard");
			addNode(head);//add new item
			break;
		case 'D':
			printf("\nWrite function to delete a single person");
			printf(" from the list\n");
			head = removeNode(head);//remove item
			break;
		case 'V': 
			printf("\nWrite function to compute and output the");
			printf(" average height");
			average = calcAvg(head);//calculated average
			printf("%.2f", average);
			break;
		case 'S':
			printf("\nWrite function to output the name of the");
			printf(" shortest person");
			printf("\nShortest person is: %s\n", calcShortestPerson(head)->name); //prints shortest person's name
			break;
		case 'F':
			printf("\nWrite function to output the linked list");
			printf(" to a file");
			outputToFile(head); break;// prints the linked list
			break;
		case 'E':  printf("\nExit the program\n");
			break;
		case 'M': head = modify(head);
		default:
			printf("\n Invalid.  Enter choice again");
			break;
		}/*switch*/
	}/*while*/
	
	return 0;

}
/*=============================================================================================*/
PERSON* removeNode(PERSON* head)
{
	//local declarations
	char temp[10];
	PERSON* walker = head; PERSON* prev = NULL;

	if(!head)
	{
		printf("Empty list"); return head;
	}

	//input name to be deleted
	printf("Enter name");
	scanf ("%s", temp);
	//find person
	while(walker && strcmp(temp, walker->name)!= 0)
	{
		prev = walker;
		walker = walker->next;
	}
	//remove person (carefully)
	if(walker == NULL)
	{
		printf("NO SUCH PERSON");
	}
	else
	{
		if (prev)
		{
		prev->next = walker->next;
		// free(walker->name);
		free(walker); //if there was any field
		//dynamically allocated then I would need to free it firs
		//
		}
		else
		{
		prev = head;
		head = head->next;
		free(prev);
		}
	}
	return head;
}
/*=============================================================================================*/
PERSON* getData(FILE* fp)
{
	//Pre: file pointer
	//Post: pointer to the first node
	char hold[81];
	PERSON* head = NULL;
	PERSON* tail = NULL;
	PERSON* newNode;


	int firstnode = 1;
	while (fgets(hold, 80, fp))
	{
		newNode = (PERSON*)malloc(sizeof(PERSON));
		sscanf(hold, "%s %f", newNode->name, &newNode->height);
		newNode->next = NULL;
		if (firstnode == 1)
		{
			head = newNode;
			tail = newNode;
			firstnode = 0;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	return head;
}
/*=============================================================================================*/
PERSON* position(PERSON* head, PERSON* adding)
{
	//Pre: pointer to first node and pointer to node we are adding
	//Post: pointer to first node
	PERSON* current = head;
	PERSON* previous = NULL;
	if(head == NULL)
	{
		head = adding;
	}
	else
	{
		while( current != NULL && current->height > adding->height)
		{
			previous = current;
			current = current->next;
		}
		if(previous != NULL)
		{
			adding->next = previous->next;
			previous->next = adding;
		}
		else
		{
			adding->next = head;
			head = adding;
		}
	}
	return head;
}
/*===================================================================================================*/
char menu(void)
{  /*Pre:  Nothing
	Post:  char representing user's choice*/
	char choice;
	printf("\n\nEnter 'P' to print the entire list");
	printf("\n      'A' to add a person to the list");
	printf("\n      'D' to delete a person from the list");
	printf("\n      'V' to output the average height");
	printf("\n      'S' to print the name of the shortest person");
	printf("\n      'F' to output to a file.\n");
	printf("\n      'E' to exit the program.\n");

	scanf(" %c",&choice);
	return toupper(choice);
}
/*============================================================================================*/
void print(PERSON* head)
{
	PERSON* walker = head;

	while (walker)
	{
		printf("\n %s\t%.1f", walker->name, walker->height);
		walker = walker->next;
	}
	return;
}
/*======================================================================================*/
float calcAvg(PERSON* head)
{
	float sum = 0;
	int count = 0;
	PERSON* walker = head;

	while(walker)
	{
		sum += walker->height;
		count++;
		walker = walker->next;
	}
	return sum/count;
}
/*==================================================================*/
PERSON* modify(PERSON* head)
{
    //local declaration
    char temp[10];
    PERSON* walker = head;
    PERSON* prev = NULL;
    float tempHt;
    PERSON* adding = head;

    if(!head)
    {
        printf("Empty List");
        return head;
    }
    //ask user who
    printf("Enter name");
    scanf("%s", temp);
    //find the person
    while(walker && strcmp(temp, walker->name)!=0)
    {
        prev = walker;
		walker = walker->next;
    }
    if(walker==NULL)
    {
        printf("No such person");
        return head;
    }
    //ask for new height
    printf("Enter new height");
    scanf("%f", &tempHt);
    //make the new mode
    adding = (PERSON*)malloc(sizeof(PERSON));
    adding->height = tempHt;
    strcpy(adding->name, temp);
    adding->next = NULL;
    //delete the old one
    if(prev)
        prev->next = walker->next;
    else
        head = walker->next;
    free(walker);

    //position the new one
    head = position(head, adding);
    return head;
}

/*====================================================================*/
int count(PERSON* head)
{
   int num = 0; PERSON* walker = head;
	while(walker)
	{
		walker = walker->next;
		num++;
	}
	return num;
}
/*==================================================================*/
PERSON* addNode(PERSON* head)
{
	PERSON* newNode;
	char name[100];
	float height;
	PERSON* lastnode = head;

	while (lastnode->next != NULL)
	{
		lastnode = lastnode->next;
	}

	

	newNode = (PERSON*)calloc(1, sizeof(PERSON));
	newNode->next = NULL;
	printf("\nName of the new person? : ");
	scanf("%s", newNode->name);
	printf("\nAnd the height? : ");
	scanf("%f", &(newNode->height));
	lastnode->next = newNode;

	return newNode;
}
/*====================================================================*/
PERSON* calcShortestPerson(PERSON* head)
{
	PERSON* current = head;

	PERSON* shortestPersonPointer = NULL;
	int shortestHeight = 200;
	while(current != NULL) 
	{
		if (current->height < shortestHeight)
		{
			shortestHeight = current->height;
			shortestPersonPointer = current;
		}
		current = current->next;
	}
	return shortestPersonPointer;
}
/*=================================================================*/
void outputToFile(PERSON* head)
{
	PERSON* person = head;
	FILE* fp;
	fp = fopen("output.txt", "w");
	
	while(person != NULL)
	{
		fprintf(fp, "%s %.2f", person->name, person->height);
		fprintf(fp, "\n");
		person = person->next;

	}


	
	
	return;	


}
	
/*===============================================*/
/* my test session:

 Kanmani        63.0
 Billy  70.0
 Christina      67.0

Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
f

Write function to output the linked list to a file

Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
p

 Kanmani        63.0
 Billy  70.0
 Christina      67.0

Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
a

Write function to add a single person from the keyboard
Name of the new person? : aaa

And the height? : 90


Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
p

 Kanmani        63.0
 Billy  70.0
 Christina      67.0
 aaa    90.0

Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
d

Write function to delete a single person from the list
Enter nameaaa


Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
p

 Kanmani        63.0
 Billy  70.0
 Christina      67.0

Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
v

Write function to compute and output the average height66.67

Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
s

Write function to output the name of the shortest person
Shortest person is: Kanmani


Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
f

Write function to output the linked list to a file

Enter 'P' to print the entire list
      'A' to add a person to the list
      'D' to delete a person from the list
      'V' to output the average height
      'S' to print the name of the shortest person
      'F' to output to a file.

      'E' to exit the program.
*/


