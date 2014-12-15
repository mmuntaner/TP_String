//****************************************************************************
//
//                                  String.cpp
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "String.h"



//############################################################################
//                                                                           #
//                                 Class String                              #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================

String::String(const char* s)
{
  // Function that allows to know the length of s.
  int i=0;
  while(s[i]!='\0')
    {
       i++;
    }

  // Function that copies the character sequence pointed by s.
  s_data = new char[i];
  for (int j=0; j<=i; j++)
    {
      s_data[j]=s[j];
    }
  
  s_length=i;
  s_capacity=i+1;
}

String::String (const String& str)
{
  int i;
  s_capacity = str.s_capacity;
  s_length = str.s_length;
  s_data = new char [s_length];

  // This loop is similar to memcpy
  for(i=0;i<s_length;i++)
    {
      s_data[i]=str.s_data[i];
    }
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
String::~String(void)
{
  delete [] s_data;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================

// Returns whether the string is empty (i.e. whether its length is 0).
bool String::empty(void) const
{
  return (s_length==0);
}

// Returns a reference to the character at position pos in the string.
char& String::at (unsigned int pos)
{
  if (pos<=s_length)
    {
      return s_data[pos-1];	
    }
  
  else 
    {
     printf("out of range\n");
     exit(EXIT_FAILURE);
    }
}

// Erases the content of the table and set "s_length" to 0
void String::clear()
{
  delete [] s_data;
  s_capacity=0;
  s_length=0;
  s_data=NULL;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================



// ===========================================================================
//                               Non inline accessors
// ===========================================================================
