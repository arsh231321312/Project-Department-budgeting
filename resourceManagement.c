#include <stdlib.h>

#include "resourceManagement.h"

int const STRING_LENGTH = 31;
/*
gcc -Wall -g -c queue.c
gcc -Wall -g -c priorityQueueDepartment.c
gcc -Wall -g -c resourceManagement.c
gcc -Wall -g -c driver.c
gcc -Wall -g -o driver driver.o queue.o priorityQueueDepartment.o resourceManagement.o
./driver

*/
pqType createPQType( Department *d, double totalSpent );
double minDouble( double x, double y );

/* printNames
 * input: none
 * output: none
 *
 * Prints names of the students who worked on this solution
 * REMINDER: You may only work with one other cs2124 student
 */
void printNames( )
{
    /* TODO : Fill in you and your partner's names (or N/A if you worked individually) */
    printf("\nThis solution was completed by:\n");
    printf("<Arshdeep Sandhu>\n");
    printf("<student name #2 (if no partner write \"N/A\")> N/A\n\n");
}

/* TODO:
 * ResourceManagement
 * input: char* fileNames[], double budget
 * output: none
 *
 * Simulates the algorithm from the pdf to determine what items are purchased
 * for the given budget and department item lists.
 * Print a summary of what each department received and did not receive.
 */

/*
typedef struct Department
{
    char* name;                 //name of this department
	double totalSpent;          //total spent on this department so far
	
	Queue* itemsDesired;        //Queue of items desired by this department
	Queue* itemsReceived;       //Queue of items received by this department
	Queue* itemsRemoved;        //Queue of items not received by this department
}  Department;

*/
void ResourceManagement( char* fileNames[], int testDataSize, double budget )
{
    /* Create a department for each file listed in fileNames */
		
		
		
		PriorityQueue *priority=createPQ();
		//char name1[50];
		
		int i;
		for(i=0;i<testDataSize;i++){
		Department* file1=(Department*)malloc(sizeof(Department));
		FILE *f = fopen( fileNames[i], "r" );
		if( f==NULL )
		{
			printf("ERROR - Invalid file %s\n", fileNames[i]);
			exit(-1);
		}else
		{
			char buffer[STRING_LENGTH];
			char buffer2[STRING_LENGTH];
			char buffer3[STRING_LENGTH];
			char* name1=(char*)malloc(sizeof(char)*50);
			fscanf(f, "%s", name1);
			
			fgets(buffer,STRING_LENGTH,f); //takes newline
			file1->name=name1;
			
			fgets(buffer,STRING_LENGTH, f);
			
			file1->itemsDesired= createQueue();        //Queue of items desired by this department
			file1->itemsReceived= createQueue();        //Queue of items received by this department
			file1->itemsRemoved= createQueue();      //items over budget
			//fgets(buffer,STRING_LENGTH, f);
			
			//while(fgets(buffer3,STRING_LENGTH, f) != NULL)
			while(fscanf(f,"%s",buffer3)==1)
			{
				//printf("buffer3-%s",buffer3);
				fgets(buffer2,STRING_LENGTH,f);
				queueType itemInfo = (queueType)malloc(sizeof(struct Item));
				//buffer[strlen(buffer)- 1] = '\0';
				//printf("%s ",  buffer3);
				
				itemInfo->name= strdup(buffer3);
				//printf("%s",itemInfo->name);
				fscanf(f,"%lf",&itemInfo->price);
				//printf("%lf",itemInfo->price);
				//itemInfo->price=100;
				//fscanf(f,"%s",buffer);
				fgets(buffer2,STRING_LENGTH, f);
				//printf("here %lf",  itemInfo->price);
				
				enqueue(file1->itemsDesired, itemInfo);

				fgets(buffer2,STRING_LENGTH, f);

				//fgets(buffer,STRING_LENGTH, f);
				
			}
		}
		fclose(f);
		
		pqType pqDep1=createPQType( file1,0);
		
		insertPQ(priority,pqDep1);  //possibly &
	}
	printf("ITEMS PURCHASED\n----------------------------\n");
  //------------------------------------------------------------------------------------------------------------------------------
    /* Simulate the algorithm for picking the items to purchase */
	// printf("\nnot same\n %s", file1.name);
   	char string2[50]="1.00";
				//strcpy(string2, "1.00");
	char string3[50]= "testName";
	char string1[30];
	double tempBudget = budget;
	pqType tempPQ;
	queueType testQ;
	int flag=0;
	int flag2=0;
	char string10[50];
	
	while(tempBudget>0){
		
		queueType tempQueue=(queueType)(sizeof(queueType));
		flag=0;
		
		//=(pqType)malloc(sizeof(queueType));
		tempPQ = removePQ(priority);
		//printf("%s", tempPQ.info->itemsDesired->qFront->qt->name);		 

		
		
			// tempPQ = removePQ(priority);
			// tempPQ = removePQ(priority);
			
			
			//printf("%s %s %lf",tempPQ.info->name,tempPQ.info->itemsDesired->qFront->qt->name, tempPQ.info->itemsDesired->qFront->qt->price);
			if(tempPQ.info->itemsDesired->qFront == NULL){
				// tempPQ.info->totalSpent+=tempQueue->price;
				// tempPQ.priority+=tempQueue->price;
				// tempBudget-=tempQueue->price;
				// enqueue(tempPQ.info->itemsReceived,tempQueue);  //might need to add to if^
				// if(flag==0){
				// insertPQ(priority,tempPQ);
				// flag=1;
				
				// }
					
					queueType scholarship = (queueType)malloc(sizeof(struct Item));
					scholarship->name="scholarship";
					//printf("here");
					if(tempBudget<1000){
						scholarship->price=tempBudget;
						tempBudget=0;
					}else{
						scholarship->price=1000;
						tempBudget-=1000;
					}
					tempPQ.priority+=scholarship->price;
					
					sprintf(string1,"$%.2lf",scholarship->price);
					
					printf("Department of %-31s -%-31s-%21s\n",tempPQ.info->name,scholarship->name,string1);
					enqueue(tempPQ.info->itemsReceived,scholarship);
					if(flag==0){
						
					insertPQ(priority,tempPQ);
					flag=1;
					}
					//printf("%s",tempPQ.info->itemsReceived->qFront->qt->name);
					
			}else{
				
				tempQueue= dequeue(tempPQ.info->itemsDesired);
				if(tempQueue->price>tempBudget||tempPQ.info->itemsDesired->qFront == NULL){
					flag2=1;
				}
				//printf("here2\n");
				while(tempQueue->price>tempBudget ){
					
					enqueue(tempPQ.info->itemsRemoved,tempQueue);
					
					
					//if( tempPQ.info->itemsDesired->qFront == NULL){
					if( tempPQ.info->itemsDesired->qFront == NULL ){
						
						queueType scholarship = (queueType)malloc(sizeof(struct Item));
						
						scholarship->name="scholarship";
						
						if(tempBudget<1000){
							scholarship->price=tempBudget;
							tempBudget=0;
						}else{
							scholarship->price=1000;
							tempBudget-=1000;
						}
						tempPQ.priority+=scholarship->price;
						sprintf(string1,"$%.2lf",scholarship->price);

						printf("Department of %-31s -%-31s-%21s\n",tempPQ.info->name,scholarship->name,string1);

						enqueue(tempPQ.info->itemsReceived,scholarship);
						//tempQueue=dequeue(tempPQ.info->itemsDesired);
						//enqueue(tempPQ.info->itemsRemoved,tempQueue);
						if(flag==0){
							
						insertPQ(priority,tempPQ);
						flag=1;
						}	
						
						
					//	enqueue(tempPQ.info->itemsRemoved,tempQueue);
						break;
					}
					
				//	printf("%s", tempPQ.info->itemsDesired);					
					 tempQueue= dequeue(tempPQ.info->itemsDesired);
					 
					
				}
				//if(tempQueue->price!=1999.99 && tempQueue->price!=.02 && tempPQ.info->itemsDesired->qFront == NULL && (flag2==0 || tempQueue->price>tempBudget)){
				//if(tempQueue->price!=1999.99 && tempQueue->price!=.02 && tempPQ.info->itemsDesired->qFront == NULL && (flag2==0 || tempQueue->price>tempBudget)){
				
				if(tempPQ.info->itemsDesired->qFront == NULL && (flag2==0 || tempQueue->price>tempBudget)){
				//if(tempPQ.info->itemsDesired->qFront==NULL && flag2==0){
					if(flag==0){
					flag=1;	
					insertPQ(priority,tempPQ);
					}
				//	printf("here\n\n\n");
					
					continue;	
				}
				flag2=0;
				
			//	printf("%lf\n", tempQueue->price);
				//sprintf(string2,"$%.2lf",tempQueue->price);
			//	strcpy(string2, "2.00");


				//double test = tempQueue->price;
				sprintf(string2, "$%.2lf", tempQueue->price);
				sprintf(string3, "%s", tempQueue->name);
				printf("Department of %-31s -%-31s-%21s\n",tempPQ.info->name,string3, string2);
 
				tempPQ.info->totalSpent+=tempQueue->price;
				tempPQ.priority+=tempQueue->price;
				tempBudget-=tempQueue->price;
				enqueue(tempPQ.info->itemsReceived,tempQueue);  //might need to add to if^
				if(flag==0){
					
				insertPQ(priority,tempPQ);
				flag=1;
				} //wejfeofijfjeoifjewosfjesw
			}
			
			//while()
			// printf("\nsame\n");
		
		
	}	
	int j;
	
	printf("\n");
	
	
	
	for(j=0;j<testDataSize;j++){
	tempPQ= removePQ(priority);
	
	while(tempPQ.info->itemsDesired->qFront!=NULL){
		queueType please= dequeue(tempPQ.info->itemsDesired);

		enqueue(tempPQ.info->itemsRemoved,please);
	//	free(please);
		
	}
	// if(isEmptyPQ(priority))
	// 	break;
		

		printf("Department of %s\n",tempPQ.info->name);
		printf("Total Spent       = $%.2lf\n",tempPQ.priority);
		printf("Percent of Budget = %.2lf%%\n",tempPQ.priority/budget*100);
		printf("----------------------------\nITEMS RECEIVED\n");
		if(tempPQ.info->itemsReceived->qFront!=NULL){
			
			
			testQ=dequeue(tempPQ.info->itemsReceived);
			
			sprintf(string10,"$%.2lf",testQ->price);
	
			printf("%-31s-%21s\n",testQ->name,string10);
			
			free(testQ);
				while(testQ!=NULL){
				if(tempPQ.info->itemsReceived->qFront!=NULL){
					sprintf(string10,"$%.2lf",tempPQ.info->itemsReceived->qFront->qt->price);
					printf("%-31s-%21s\n",tempPQ.info->itemsReceived->qFront->qt->name,string10);
				//if(tempPQ.info->itemsRemoved->qFront!=NULL){
					testQ=dequeue(tempPQ.info->itemsReceived);
					
					free(testQ);
				}else
					break;
			}
			
		}
		printf("\n\nITEMS NOT RECEIVED\n");
		if(tempPQ.info->itemsRemoved->qFront!=NULL){
			 testQ=dequeue(tempPQ.info->itemsRemoved);
		
			 sprintf(string10,"$%.2lf",testQ->price);
			 printf("%-31s-%21s\n",testQ->name,string10);
			 free(testQ->name);
			 free(testQ);
				while(testQ!=NULL){
				if(tempPQ.info->itemsRemoved->qFront!=NULL){
					sprintf(string10,"$%.2lf",tempPQ.info->itemsRemoved->qFront->qt->price);
					printf("%-31s-%21s\n",tempPQ.info->itemsRemoved->qFront->qt->name,string10);
				//if(tempPQ.info->itemsRemoved->qFront!=NULL){
					testQ=dequeue(tempPQ.info->itemsRemoved);
					free(testQ->name);
					free(testQ);
				}else
					break;
			}
			
		}
		
		printf("\n\n");
		free(tempPQ.info->itemsDesired);
		free(tempPQ.info->itemsRemoved);
		free(tempPQ.info->itemsReceived);
		free(tempPQ.info->name);
		free(tempPQ.info);
	}
	freePQ(priority);

	// printf("\n\n\nhere\n");
	// if(tempPQ.info->itemsDesired->qFront!=NULL)
	// printf("%s",tempPQ.info->itemsDesired->qFront->qt->name);
	
}

	
	
	/*
	gcc -Wall -g -c queue.c
gcc -Wall -g -c priorityQueueDepartment.c
gcc -Wall -g -c resourceManagement.c
gcc -Wall -g -c driver.c
gcc -Wall -g -o driver driver.o queue.o priorityQueueDepartment.o resourceManagement.o
driver

*/
	

	// if(tempPQ.info->itemsReceived->qFront ==NULL){
	// $1000.	printf("null");
	// }else
	// printf("%s %s %s",tempPQ.info->itemsReceived->qFront->qt->name,tempPQ.info->itemsReceived->qFront->pNext->qt->name,tempPQ.info->itemsReceived->qFront->pNext->pNext->qt->name);

	 //Print the information for each department (including which items were received and which were not) 



/* createPQType
 * input: Department *d, double totalSpent
 * output: pqType
 *
 * Creates and returns a pqType struct (i.e the type in the priority queue)
 * from the given department and totalSpent. 
 */
pqType createPQType( Department *d, double totalSpent ){
	pqType pt;
	pt.info = d;
	pt.priority = totalSpent;

	return pt;
}

/* minDouble
 * input: double x, double y 
 * output: the smaller of x and y
 */
double minDouble( double x, double y ){
	if( x<=y )
		return x;
	return y;
}
