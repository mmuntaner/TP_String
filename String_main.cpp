//****************************************************************************
//
//                                String_main.cpp
//
//****************************************************************************
// String_main is used for test 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <stdio.h>


// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "String.h"


// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================
void Test_class_string(String S);


// ===========================================================================
//                                   The Main
// ===========================================================================




int main(int argc, char* argv[])
{

String test("Test for the string ");
String test2("Stringtest2");
String test3("Stringtest3");

//Definition of the string to test
Test_class_string(test);


printf("\nTesting operators\n");

//Testing the operator =(String)
test=test2;
printf("New string : %s \n", test.c_str());

//Testing the operator =(char c)
test='c';
printf("New string : %s \n", test.c_str());

//Testing the operator =(char *)
test="newchar*";
printf("New string : %s \n", test.c_str());

//Testing the operator +(String)
test=test2+test3;
printf("New string : %s \n", test.c_str());

//Testing the operator +(String)
test=test3+test2;
printf("New string : %s \n", test.c_str());

//Testing the operator +(char c)
test=test2+'c';
printf("New string : %s \n", test.c_str());

//Testing the operator +(char c)
test='c'+test2;
printf("New string : %s \n", test.c_str());

//Testing the operator +(char *)
test="newchar*"+test2;
printf("New string : %s \n", test.c_str());

//Testing the operator +(char *)
 test=test2+"newchar*";
 printf("New string : %s \n", test.c_str());




printf("\nTesting the method clear\n");
test.clear();
//verification that the string is clear
Test_class_string(test);


  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================
void Test_class_string(String S)
{
   printf("String to test : %s \n", S.c_str());
  printf("Lenght of the string : %d \n", S.length());
  printf("Size of the string :%d \n", S.size());
  printf("Max_capacity of the string : %d \n", S.max_size());
  printf("Capacity of the string :%d \n", S.capacity());
  printf("Does the string is empty ? (y=1, n=0) :%d \n", S.empty());
  printf("Character at the position 5 in the string :%c \n", S.at(5));
  printf("Character at the position 7 in the string using operator []:%c \n", S[10]);
 
}


