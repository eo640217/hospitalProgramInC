#include "stdio.h"
#include "stdlib.h"
#include "struct.h"
#include "string.h"
#include "populateRecords.h"
#include "patient.h"
#include "employee.h"


#define NUM_RECORDS 20
int menu();//menu to display options
int exitMenu();//menu to confirm exit of program
int validateInput(char*);//function to validate the users input. if is an int, it will pass
void sizeOfStructures(PersonRec *person);//function to print of the size of structues used

int main(int argc, char *argv[])
{
  struct person *person = NULL;
  int numRecords = 0;         // number of records to be created

  int data;
  if (argc == 2){
    if(validateInput(argv[1]) || argv[1][0] == '-'){ //check if inpt is valid
      sscanf(argv[1], "%d", &data); //saving argument into variable data as an int.
      numRecords = data; //once verification is passed, set the amout of records to the argument
    }
    else{
      printf("Invalide Input\n");
      return 0;}
  }
  else {printf("\nSorry Not enough Arguments. There should be exactly two arguments.\nThe Second argument should declare the amount of person records you would like to create.\nIt must also be an Integer.\n"); return 0;}

//-------------
    // Allocate memory for the array empArr (which is an array of pointers)
  person = (struct person *) malloc(sizeof(struct person) * numRecords);
    // check if allocation was successful
  if (person == NULL) {
    printf("error: could not allocate memory for the array \n");
    return(1);
  }
//---------------

  // populating the array person with data of patients and employees
  populateRecords(person, numRecords);
    // menu
    int num;
    while(1){
      num = menu();//set the var num to the returned value from menu()
      switch (num){
        case 0:
          if (!exitMenu()){printf("\n---BYE!---\n");return 0;}
          else{break;}
        case 1:
          printf("1 ---------PRINT EMPLOYEES---------------------\n");
          printEmployees(person,numRecords);
          break;
        case 2:
          printf("2 ---------SEARCH PATIENTS---------------------\n");
          searchPatients(person, numRecords);
          break;
        case 3:
          printf("3 ---------EMPLOYEE SUMMARY--------------------\n");
          printEmployeesSummary(person,numRecords);
          break;
        case 4:
          printf("4 --------SUMMARY BY DEPARTMENT--------------------\n");
          printPatientSummary(person, numRecords);
          break;
        case 5:
          printf("5 ---------SIZE OF STRUCTURES-----------------\n");
          sizeOfStructures(person);
          break;
        break;
      }
    }
    return 0;
}

int menu(){
  int num = -1;
  printf("Please Select one of the following numbers: \n");
  printf("-------------------------------------------\n");
  printf("1.\tPrint all employees\n");
  printf("2.\tSearch for all patients by Family Name\n");
  printf("3.\tSummary of Employees data\n");
  printf("4.\tSummary of Patients data\n");
  printf("5.\tsize of structures (patientRec,PatientRec,EmployeeRec)\n");
  printf("0.\tQuit\n");
  printf("Enter a value from 0 to 5:");
  while(1){
    scanf("%d", &num);
    if (num <= 5 && num >=0 ) {break;}
    else{printf("Sorry that entry is invalid. Please select a number between 0 and 5:");}
  }
  return num;
}
int exitMenu(){
  char value;
  int returnValue;
  printf("----\nYou are about to exit the program!\nPress 0 to Confirm Exit.\n1 to Continue Program.\nHow would you like to proceed? (0 or 1) :");
  while(1){
    scanf("%c", &value); //get user input
    if (validateInput(&value)) {//check users input is valid
      sscanf(&value, "%d", &returnValue);//saving user input to as int ot returnValue variable
      if(returnValue==0 ||returnValue==1 ){break;}
      else{printf("Sorry that entry is invalid. Please select either 0 or 1: ");}
    }
  }
  return returnValue;
}
int validateInput(char* input){
  char* p = input;
  while (*p != '\0')
  {
    if (*p<'0' || *p>'9'){return 0;}
    p++;
  }
  // printf("value is %s", p);
  return 1;
}
void sizeOfStructures(PersonRec *person){
  printf("Size of Structures:\n---\n");
  printf("Size of PersonRec = %ld\n",sizeof(struct person));
  printf("Size of PatientRec = %ld\n",sizeof(person->emp));
  printf("Size of EmployeeRec = %ld\n",sizeof(person->patient));
};
