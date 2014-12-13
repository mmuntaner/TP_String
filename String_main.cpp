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
  printf("Hello World !\n");
  printf("%d \n", test.length());
  printf("%d \n", test.max_size());
  printf("%d \n", test.capacity());
  printf("%d \n", test.empty());
  printf("%s \n", test.c_str());


  return 0;
}



// ===========================================================================
//                         Define Miscellaneous Functions
// ===========================================================================

