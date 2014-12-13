//****************************************************************************
//
//
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

// Constructor used to initialize a string test
String::String(void)
{
  s_capacity=12;
  s_length=6;
  char* s_data = new char[s_capacity];
  for (int i=0; i<=s_length;i+=3)
    {
			s_data[i]='c';
			s_data[i+1]='o';
			s_data[i+2]='u';
    }
}

String::String(const char* s)
{

  //Function that allows to know the length of s.
  int i=0;
  while(s[i]!='\0')
	{
		i++;
	 }
   
  //Function that copies the character sequence pointed by s.
  s_data = new char[i];
	for (int j=0; j<=i; j++)
	{
		s_data[j]=s[j];
	}
  
  s_length=i;
  s_capacity=i;
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

 //Returns whether the string is empty (i.e. whether its length is 0).
 bool String::empty(void) const
 {
  return (s_length==0);
 }
//Returns a reference to the character at position pos in the string.
char& String::at (unsigned int pos)
{
  if (pos<=s_length)
	{
		return s_data[pos-1];	
	}

	else 
  {
    printf("La position que vous avez demandée n'existe pas. \n");
    exit(EXIT_FAILURE);
  }
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================
 


// ===========================================================================
//                               Non inline accessors
// ===========================================================================
