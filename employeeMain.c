//Compile using the following command: gcc employeeMain.c employeeTable.c employeeOne.c 
//gcc employeeMain.c employeeTable.c employeeTwo.c 

#include <string.h> 
#include <stdlib.h> 
#include "employee.h" 

int main(void){ 

    //defined in employeeSearchOne.c 
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind); 
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind); 
    PtrToEmployee searchEmployeeByPhoneNumber(const Employee table[], int sizeTable, char * phoneNumberToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c 
    extern Employee EmployeeTable[];     
    extern const int EmployeeTableEntries;      

    PtrToEmployee matchPtr;  //Declaration 
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 1045); 

    //Example not found 
    if (matchPtr != NULL) 
        printf("Employee ID 1045 is in record %d\n", matchPtr - EmployeeTable); 
    
    else 
        printf("Employee ID is NOT found in the record\n"); 

    //Example found 
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat"); 

    if (matchPtr != NULL) 
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable); 

    else 
        printf("Employee Tony Bobcat is NOT found in the record\n"); 
    /////Part A//////////
    //Phone number match found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-555-1235");
    
    if (matchPtr != NULL)
        printf("Employee phone number 909-555-1235 was found in record %i\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number 909-555-1234 was NOT found in the record\n");

    //Phone number match NOT found
    matchPtr = searchEmployeeByPhoneNumber(EmployeeTable, EmployeeTableEntries, "909-123-1235");

    if (matchPtr != NULL)
        printf("Employee phone number 909-123-1235 was found in record %i\n", matchPtr - EmployeeTable);
    else
        printf("Employee phone number 909-123-1234 was NOT found in the record\n");

    //Salary match found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);

    if (matchPtr != NULL)
        printf("Employee salary of 4.50 was found in record %i\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary of 4.50 was NOT found in the record\n");
        
    //Salary match NOT found
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.05);

    if (matchPtr != NULL)
        printf("Employee salary of 4.05 was found in record %i\n", matchPtr - EmployeeTable);
    else
        printf("Employee salary of 4.05 was NOT found in the record\n");

    ///////////Part B////////

    return EXIT_SUCCESS; 
} 