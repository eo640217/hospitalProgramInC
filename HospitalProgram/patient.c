

#include "string.h"
#include "stdio.h"
#include "patient.h"

/********************************************************************/
void printPatient(PersonRec *person)

{printf("%s %s\t Department: %d Daily Cost %.2ld Number of days in hospital: %d Severity: %d\n", person->firstName,person->familyName,person->patient.department,person->patient.dailyCost,person->patient.numDaysInHospital,person->patient.severity);}

/********************************************************************/
void printPatients(PersonRec *person, int numRecords)
{// This fucntion prints all the patients
  printf("Patients: \n");
  for(int i= 0; i< numRecords; i++){ //loop through the struct
    if(person->emplyeeOrPatient == PATIENT_TYPE){ // if it is a patient type print the patient
      printPatient(person);
    }
    person++; //move onto the next patient
  }
}


/********************************************************************/
void printPatientSummary(PersonRec *person, int numRecords)
{
    int p1pat = 0;
    int p2pat = 0;
    int p3pat = 0;
    int p4pat = 0;
    int p5pat = 0;
    int p6pat = 0;
    // the values above will hold the amount of patients in each department
    int p1days = 0;
    int p2days = 0;
    int p3days = 0;
    int p4days = 0;
    int p5days = 0;
    int p6days = 0;
    // the values above will hold the amount of days spent per department
    float p1cost = 0;
    float p2cost = 0;
    float p3cost = 0;
    float p4cost = 0;
    float p5cost = 0;
    float p6cost = 0;
    // the values above will hold the total cost spent per department
    for(int i= 0; i< numRecords; i++){
      if(person->emplyeeOrPatient == PATIENT_TYPE){
             if (person->patient.department == 1){
               p1pat++;//add a new patient to their respective department
               p1cost +=person->patient.dailyCost*person->patient.numDaysInHospital;//add the total cost which consits of their total days sapent * their daily cost
               p1days += person->patient.numDaysInHospital; //add the patients total days to the department total
             }
             if (person->patient.department == 2){
               p2pat++;
               p2days += person->patient.numDaysInHospital;
               p2cost +=person->patient.dailyCost*person->patient.numDaysInHospital;
             }
             if (person->patient.department == 3){
               p3pat++;
               p3days += person->patient.numDaysInHospital;
               p3cost +=person->patient.dailyCost*person->patient.numDaysInHospital;
             }
             if (person->patient.department == 4){
               p4pat++;
               p4days += person->patient.numDaysInHospital;
               p4cost +=person->patient.dailyCost*person->patient.numDaysInHospital;
             }
             if (person->patient.department == 5){
               p5pat++;
               p5days += person->patient.numDaysInHospital;
               p5cost +=person->patient.dailyCost*person->patient.numDaysInHospital;
             }
             if (person->patient.department == 6){
               p6pat++;
               p6days += person->patient.numDaysInHospital;
               p6cost +=person->patient.dailyCost*person->patient.numDaysInHospital;
             }
      }
      person++;
    }

      printf("---\nSumary by Departments:\n");
      printf("Department[1] - patients: %i | cost-to-date: $%.2f | daily cost: $%.2f | cost per patient: $%.2f |\n",p1pat, p1cost, (p1cost/p1days), (p1cost/p1pat));
      printf("Department[2] - patients: %i | cost-to-date: $%.2f | daily cost: $%.2f | cost per patient: $%.2f |\n",p2pat, p2cost, (p2cost/p2days), (p2cost/p2pat));
      printf("Department[3] - patients: %i | cost-to-date: $%.2f | daily cost: $%.2f | cost per patient: $%.2f |\n",p3pat, p3cost, (p3cost/p3days), (p3cost/p3pat));
      printf("Department[4] - patients: %i | cost-to-date: $%.2f | daily cost: $%.2f | cost per patient: $%.2f |\n",p4pat, p4cost, (p4cost/p4days), (p4cost/p4pat));
      printf("Department[5] - patients: %i | cost-to-date: $%.2f | daily cost: $%.2f | cost per patient: $%.2f |\n",p5pat, p5cost, (p5cost/p5days), (p5cost/p5pat));
      printf("Department[6] - patients: %i | cost-to-date: $%.2f | daily cost: $%.2f | cost per patient: $%.2f |\n",p6pat, p6cost, (p6cost/p6days), (p6cost/p6pat));




    // add code

}


/********************************************************************/
void searchPatients(PersonRec *person, int numRecords)

{
  // add code
  printf("Please enter name: ");
  char patient[15] = "empty";
  scanf("%s",patient);


  printf("Employees:\n");
  for(int i= 0; i< numRecords; i++){
    if(person->emplyeeOrPatient == PATIENT_TYPE && !strncmp(person->familyName ,patient,4)){
      printPatient(person);
    }
    person++;
  }
}
