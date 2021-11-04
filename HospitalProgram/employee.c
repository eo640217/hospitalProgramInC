#include "employee.h"
#include "stdio.h"

void printEmployee(PersonRec *person)

{
  printf("%s %s\t Department: %ld Salary: $%.2f Years of Service: %ld Salary-To-date: $%.2f\n",person->firstName,person->familyName,person->emp.department,person->emp.salary,person->emp.yearsService,(person->emp.salary * person->emp.yearsService));
}

void printEmployees(PersonRec *person, int numRecords)
{// This fucntion prints all the patients
  printf("Employees:\n");
  for(int i= 0; i< numRecords; i++){
    if(person->emplyeeOrPatient == EMPLOYEE_TYPE){
      printEmployee(person);
    }
    person++;
  }
}


void printEmployeesSummary(PersonRec *person, int numRecords)
{
  int numOfEmployees = 0; //var to store total number of employees
  float totalSalaries = 0; // var to hold total salaries
  float averageSalary = 0; // var to hold average salary

  int p1emp = 0;
  int p2emp = 0;
  int p3emp = 0;
  int p4emp = 0;
  int p5emp = 0;
  int p6emp = 0;
    // the values above will hold the amount of employees in each department
  float p1sal = 0;
  float p2sal = 0;
  float p3sal = 0;
  float p4sal = 0;
  float p5sal = 0;
  float p6sal = 0;
    // the values above will hold the total salaries per department
  for(int i= 0; i< numRecords; i++){
    if(person->emplyeeOrPatient == EMPLOYEE_TYPE){
      totalSalaries += person->emp.salary;
           if (person->emp.department == 1){
             p1emp++;//add a new employee to their respective department
             p1sal +=person->emp.salary; //add the employees total salary to the department total
           }
           if (person->emp.department == 2){
             p2emp++;
             p2sal +=person->emp.salary;
           }
           if (person->emp.department == 3){
             p3emp++;
             p3sal +=person->emp.salary;
           }
           if (person->emp.department == 4){
             p4emp++;
             p4sal +=person->emp.salary;
           }
           if (person->emp.department == 5){
             p5emp++;
             p5sal +=person->emp.salary;
           }
           if (person->emp.department == 6){
             p6emp++;
             p6sal +=person->emp.salary;
           }
    }
    person++;
  }

    numOfEmployees = p1emp + p2emp + p3emp + p4emp + p5emp + p6emp;
    averageSalary = (totalSalaries / numOfEmployees);
    printf("---\nTotal Number of employees:%i\nTotal Salary: $%.2f\nAverage Salary: $%.2f\n---\n",numOfEmployees,totalSalaries,averageSalary);
    printf("Position[1] - employees: %i Total Salary: $%.2f Avg Salary: $%.2f\n",p1emp, p1sal, (p1sal/p1emp));
    printf("Position[2] - employees: %i Total Salary: $%.2f Avg Salary: $%.2f\n",p2emp, p2sal, (p2sal/p2emp));
    printf("Position[3] - employees: %i Total Salary: $%.2f Avg Salary: $%.2f\n",p3emp, p3sal, (p3sal/p3emp));
    printf("Position[4] - employees: %i Total Salary: $%.2f Avg Salary: $%.2f\n",p4emp, p4sal, (p4sal/p4emp));
    printf("Position[5] - employees: %i Total Salary: $%.2f Avg Salary: $%.2f\n",p5emp, p5sal, (p5sal/p5emp));
    printf("Position[6] - employees: %i Total Salary: $%.2f Avg Salary: $%.2f\n",p6emp, p6sal, (p6sal/p6emp));


}
