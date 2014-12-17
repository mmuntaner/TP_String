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
  String test("koukou komen sa va :)");

Test_class_string(test);
printf("Testing the method clear\n");
test.clear();
Test_class_string(test);
  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================
void Test_class_string(String S)
{
   printf("String to test : %s \n", S.c_str());
  printf("lenght of the string : %d \n", S.length());
  printf("size of the string :%d \n", S.size());
  printf("max_capacity of the string : %d \n", S.max_size());
  printf("capacity of the string :%d \n", S.capacity());
  printf("does the string is empty ? (y=1, n=0) :%d \n", S.empty());
  printf("character at the position 5 in the string :%c \n", S.at(5));
  printf("character at the position 7 in the string using operator []:%c \n", S[10]);
 
}


