
/*
File name is linked_list_hospital.c
 Purpose: file contains functions for manipulating singly linked list

 Revisions
 Doron Nussbaum 2021





 Copyright 2021 Doron Nussbaum

 */

/******************************************************************/
// INCLUDE

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list_hospital.h"
#include "patient.h"


/************************************************************************/
// Define

/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
patient - the patient record

input/output
head - head of linked list

return
A pointer to the node that was allocated.

NULL - if the operation was not successful

*/

ListNode *insertToList(ListNode **head, PatientInfo *patient)

{
    // allocating memory
    ListNode *p = NULL;
    p = (ListNode*)malloc(sizeof(ListNode)*sizeof(PatientInfo));

    // check if allocation was successful, if an error occured return NULL.
    if (p == NULL) {
      printf("error: could not allocate memory for the array \n");
      return NULL;
    }


    //if it is the first node in the list. Set as Head.
    if (*head == NULL){
        p->patient = *patient;
        p->next = NULL;
        *head = p;
        return p;
        }
    //set the last node in the list as the patient.
      p->patient = *patient;
      p->next = *head;
      *head = p;
      return p;




}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node

Input
input
patient - the patient record


return
A pointer to the node that was allocated.

NULL - if the operation was not successful

*/


ListNode *insertAfter(ListNode *node, PatientInfo *patient)
{
  //allocating memory and then checking if allocation was successful, if an error occured return NULL.
  ListNode *p = NULL;
  p = (ListNode*)malloc(sizeof(ListNode)*sizeof(PatientInfo));
  if (p == NULL){printf("Could Not allocate memory\n"); return NULL;}

  // setting the next node after 'node' given to patient.
  p->patient = *patient;
  ListNode temp = *node->next; // this is to keep track of the next node. we will set the next of our new patient to this node.
  node->next = p;
  p->next = &temp;
  return p;
}




/************************************************************************/
/*
Purpose: search for the first patient with the matching priority
Input
head - the head of the list
priority - first priority of the patient

output
patient - the patient record

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


ListNode * searchFirstPatientByPriority(ListNode *head, unsigned char priority, PatientInfo *patient)
{
  ListNode *p = head;
  while(p!=NULL){
    //return patient if we find one that matches the priority while traversing the list.
    if (p->patient.priorityLevel == priority){
      *patient = p->patient;
      return p;
    }
    p = p->next;
  }
  //return NULL if nothing was found
  return NULL;
}


/************************************************************************/
/*
Purpose: search for the first patient with the matching criteria.  The criteria is determined
by the comparison function
Input
head - the head of the list
findPatient -  a function pointer that returns a 0 if the patient's record matches that criteria

output
patient - the patient record

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


ListNode * searchNextPatient(ListNode *head, int (*findPatient)(PatientInfo *), PatientInfo *patient)
{
  ListNode *p = head;
  while(p!=NULL){
    //return zero if findPatient returns zero.
    if(!findPatient(&p->patient)){return 0;}
    p = p->next;
  }

  return p;
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
patient - the patient record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(ListNode **head, PatientInfo *patient)

{
  ListNode *p = *head;
  if(patient == &p->patient){
    //this means the head is the patient
    head = &p->next;
    free(p);
    return 0;
  }

  ListNode *prev = p;
  while(p!=NULL){
    //traverse the list. if we find the patient, set the previous node to its next node. Then free its memory.
    if(&p->patient == patient){
      prev->next = p->next;
      free(p);
      return 0;
    };
    prev = p;
    p = p->next;
  }
  //the patient did not exist, return 1;
  return 1;
}


/***************************************************************/

/*
Purpose: Retrieve the first node that matches the priority.  When found the node is deleted and the patient
information is provided.

Input
head - the head of the list

output
head - the head of the list
patient - the patient record


return

0 if node was deleted
1 if node was not found or list is empty

*/


int retrieveNextPatientByPriority(ListNode **head, unsigned char priority, PatientInfo *patient)

{

    //creating variable and allocating memory for Node
      ListNode *p = *head;

      // check if list is empty
      if (p == NULL){return 1 ;}

      while(p!=NULL){
        //if patient with priorityLevel is found, delete.
        if (p->patient.priorityLevel == priority){
          *patient = p->patient;
          deleteFromList(head, &p->patient);
          return 0;
        }
        p = p->next;
      }

      return 1;


}

/***************************************************************/

/*
Purpose: Retrieve the patient with the highest criteria to be treated.  The maximum criteria is determined by
a comparePatients function.  Once the patient is found it is deleted from the list and its information is
returned.

Input
head - the head of the list
comparePatients - this function takes two paitent records and compares them.
				It returns, -1, 0 or 1 if p1 < p2, p1 == p2, or p1 > p2, respectively.

output
head - the head of the list
patient - the patient record


return
0 if  patient was found and the node was deleted
1 if no paitent was found or the list is empty


Algorithm:
The function first finds the patient with the hights criteria by comparing all the patients records and
finding the first patient with the maximum criteria to be treated.  It then deletes the patient and returns
its information.
*/


int retrieveNextPatientByCriteria(ListNode **head, int (*comparePatients)(PatientInfo *p1, PatientInfo *p2, int currentTime), int currentTime, PatientInfo *patient)

{

  //creating variable and allocating memory for Node
    ListNode *p = *head;

    // check if list is empty
    if (p == NULL){return 1 ;}
    ListNode *highest = *head;  // this will hold the patient with the highest priority Level


    while(p!=NULL){
      //compare patients. if the patient in traversal has a higher priority, set to highest.
      if (comparePatients(&p->patient, &highest->patient, currentTime)){highest = p;}
      p = p->next;
    }
    // once traversal is finished return and delete from list.
    *patient = highest->patient;
    p = *head;
    deleteFromList(&p, &highest->patient);
}



/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(ListNode **head)
{
  ListNode *p = *head;
  if(p!=NULL){
    deleteList(&p->next); // recursively call untill we reach the last node
    free(p); // begin freeing memory as the stack calls pop.
   }
   return;
}



/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
myPrint - a function pointer for print the patient information.
*/


void printList(ListNode *head, void (*myPrint)(PatientInfo *patient))
{
  ListNode *p = head;
  while(p!=NULL){
    printPatient(&p->patient);
    p = p->next;
  }
}


/************************************************************************/
/*
Purpose: counts the number of patients that are waiting to be treted
input
head - the head of the list

return
the number of registered patients

*/


int numPatientsInEmergency(ListNode *head)
{
  ListNode *p = head;
  int counter = 0;
  while(p!=NULL){
    counter++;
    p = p->next;
  }
  return counter;




}

/************************************************************************/
/*
Purpose: counts the number of patients with a matching priority
input
head - the head of the list


return
the number of patients with a matching priority


*/


int countPatients(ListNode *head, unsigned char priority)
{
  int counter = 0; // to track total number of patients
  ListNode *p = head;
  while(p!=NULL){
  if(p->patient.priorityLevel == priority){counter++;}
    p = p->next;
  }
  return counter; // return num of patients

}

/************************************************************************/
/*

Purpose: store all the patients records in the file by printing out the information i.e., in ASCII readable format.


input
filename - the name of the file to be used for storing the data
head - the head of the  list

Algorithm:
use the '$' character as a delimeter between the fields
For example:
Miya                 $Bronson                 $ 9700    $ 20  $ 2 $ Broken Bone
*/

// Backup Functions
int createAsciiBackup(char *fileName, ListNode *head)

{
	// add code

	// open the file

	// store each patient records in the file

	// close the file

    return(0);
}

/************************************************************************/
/*

Purpose: store all the patients records in the file in their binary format.


input
filename - the name of the file to be used for storing the data
head - the head of the  list



*/

int createBinaryBackup(char *fileName, ListNode *head)
{
	// add code

	// open the file

	// store each patient records in the file

	// close the file

    return(0);
}

////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// BONUS SECTION



/************************************************************************/
/*

Purpose: removes all Patients with priority less than or equal to the given priority
(remove all patients with priorityLevel <= priority).


input
head - the head of the  list

Ouput
head - the head of the list where all patients with priorityLevel < priority are removed

*/

int releasePatients(ListNode **head, unsigned char priority)

{
  // check if list is empty.
    ListNode *p = *head;
    if (p == NULL){return 1 ;}


    while(p!=NULL){
      //delete each patient with specified priority
      if (p->patient.priorityLevel == priority){
        deleteFromList(head, &p->patient);
      }
      p = p->next;
    }
	return(0);

}

/************************************************************************/
/*
Purpose: prints all the patients' records in the list in reverse order using recursion

input
head - the head of the list
*/


void printListReverse(ListNode *head, void (*myPrint)(PatientInfo *patient))
{
  ListNode *p = head;
  if(p!=NULL){
    printListReverse(p->next,printPatient);//reach end of list through recursive calls.
    printPatient(&p->patient);//print patients as stack calls pop.
   }
   return;
}

/*****************************************************************************/

/************************************************************************/
/*
Purpose: Reverse the list such that the last node in the list becomes the first node and the first node in the list becomes the last node.

Restrictions:
1.	This operation must be achieved using recursive calls
2.	No memory is to be allocated or released at any time during the execution of the function



input
head - the head of the list


Returns:
the head of the new list
*/

ListNode *reverse(ListNode *head)

{
  //if head is null, return. if the node after head is null, return list.
  if(head == NULL){return NULL;}
  if(head->next == NULL){return head;}

  ListNode* newList = reverse(head->next);//recursively call till we reach the end. the last node becomes the head and nodes
  head->next->next = head;// the next two lines reverse the list because they set their next nodes as the nodes that occured before theirs. This is how the reversal is done.
  head->next = NULL;
  return newList;


}
