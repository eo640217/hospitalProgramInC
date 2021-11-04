# hospitalProgramInC
# Name: Emmanuel Olufelo -- 2021-11-03;
# Purpose of software: 
Program for manipulating records of patients and employees in a hospital. The program will allow hospital administrators to query he data and to obtain some summary information. The data of patients and employees is initialized using the function populateRecords().
The data is stored in an array , and the size of the array is given using the define NUM_RECORDS.
Header files contain all the prototypes and the body for the functions are all in the .c files.
# To compile program & run (ubuntu): 
  1. gcc -Wall employee.c patient.c populateRecords.c struct.h hospital.c -o hospitalProgram into the command line.
  2. ./hospitalProgram {numberOfRecords}  //where numberOfRecords is the number of records you want to create.
# No issues to take note of so far.
