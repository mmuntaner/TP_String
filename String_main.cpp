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


// ===========================================================================
//                                   The Main
// ===========================================================================
int main(int argc, char* argv[])
{
  String test("Test string!");
  String test2("Another test string!");
  printf("%d \n", test.length());
  printf("%d \n", test.size());
  printf("%d \n", test.max_size());
  printf("%d \n", test.capacity());
  printf("%d \n", test.empty());
  printf("%s \n", test.c_str());
  printf("%d \n", test2.length());
  printf("%d \n", test2.size());
  printf("%d \n", test2.max_size());
  printf("%d \n", test2.capacity());
  printf("%d \n", test2.empty());
  printf("%s \n", test2.c_str());
  test2 = test;
  printf("%d \n", test2.length());
  printf("%d \n", test2.size());
  printf("%d \n", test2.max_size());
  printf("%d \n", test2.capacity());
  printf("%d \n", test2.empty());
  printf("%s \n", test2.c_str());

  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

