//****************************************************************************
//
//                                  String.h
//
//****************************************************************************



#ifndef __STRING_H__
#define __STRING_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>


// ===========================================================================
//                                Project Files
// ===========================================================================




// ===========================================================================
//                              Class declarations
// ===========================================================================




class String
{
 public :
  
  // =======================================================================
  //                                 Enums
  // =======================================================================
  
  // =======================================================================
  //                               Constructors
  // =======================================================================
  String(const char* s);
  String (const String& str);
  
  // =======================================================================
  //                                Destructor
  // =======================================================================
  virtual ~String(void);
  
  // =======================================================================
  //                            Accessors: getters
  // =======================================================================
  // In the specification length return a size_t value but we prefer return
  // an unsigned int to fit our decision of not including cstring 
  inline unsigned int length(void) const;
  inline unsigned int size(void) const;
  inline const unsigned int max_size(void) const;
  inline unsigned int capacity(void) const;
  inline const char* c_str(void) const;  
  
  // =======================================================================
  //                            Accessors: setters
  // =======================================================================
  inline void reserve(unsigned int n=0);
  inline void resize (unsigned int n);

  // =======================================================================
  //                                Operators
  // =======================================================================
   inline char& operator[](unsigned int pos);
   inline String& operator=(char c);
   inline String operator+ (const char* lhs);
  // =======================================================================
  //                              Public Methods
  // =======================================================================
  bool empty(void) const;
  char& at (unsigned int pos);
  void clear();  

  // =======================================================================
  //                             Public Attributes
  // =======================================================================
  
 protected :
  
  // =======================================================================
  //                            Forbidden Constructors
  // =======================================================================
  // Avoid use of the default constructor
  String(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };
    
  // =======================================================================
  //                              Protected Methods
  // =======================================================================
  
  // =======================================================================
  //                             Protected Attributes
  // =======================================================================    
  // "data" is a pointer on the tab wich contain each char of the string
  char* s_data;
  
  // "length" is the size of the string in bytes, "capacity" is the actual  
  // size of the tab in bytes
  unsigned int s_length, s_capacity;
  
  // "MAX_CAPACITY" is the maximal capacity of a string
  static const unsigned int MAX_CAPACITY=100;
  
};

// ===========================================================================
//                              Getters' definitions
// ===========================================================================
inline unsigned int String::length(void) const
{
  return s_length*sizeof(char);
}

// "size()" is exactly the same as "length()"
inline unsigned int String::size(void) const
{
  return length();
}

inline const unsigned int String::max_size(void) const
{
  return MAX_CAPACITY;
}

// Capacity : Returns the size of the storage space currently allocated 
// for the string,expressed in terms of bytes.
inline unsigned int String::capacity(void) const
{
  if (s_capacity<MAX_CAPACITY) 
    {
      return s_capacity*sizeof(char);
    }
  else {
    printf("The string is too long! \n");
    exit(EXIT_FAILURE);
  }
}

// "c_str" return a pointer on a c string version of s_data 
// In the main, user have to delete the tab pointed by cstr
inline const char* String::c_str(void) const
{
  unsigned int i;
  char* cstr = new char [1+s_length];
  for(i=0 ; i<s_length ; i++)
    {
      cstr[i] = s_data[i];
    }
  cstr[s_length] = '\0';
  return cstr;
}

// ===========================================================================
//                              Setters' definitions
// ===========================================================================
// Requests that the string capacity be adapted to a planned change in size to a length of up to n characters.
inline void String::reserve(unsigned int n)
{
  if (n > s_capacity){
    s_capacity = n;
  }
}
		
// Resizes the string to a length of n characters.
inline void String::resize (unsigned int n)
{   
  if (n<s_length)	
    {
      char* news_data = new char[n];     	
      for (int i=0; i<n; i++) 
	{ 
	  news_data[i]= s_data[i];
	}
      delete [] s_data;
      s_data=news_data;
      s_length=n;
    } 
  
  if (n>s_length)
    {
      this->reserve(n);
      char* news_data = new char[n]; 
      for (int i=0; i<s_length; i++) 
	{ 
    	  news_data[i]=s_data[i];
	}
      for (int i=s_length; i<n; i++) 
	{ 
    	  news_data[i]=' ';
	}
      delete [] s_data;
      s_data=news_data;
    }
} 

// ===========================================================================
//                             Operators' definitions
// ===========================================================================
//Returns a reference to the character at position pos in the string.
inline char & String::operator[]( unsigned int pos )
{
//if the position asked is outside the lenght of the string
if (pos<0 || pos>s_length) 
{
printf("out of range\n");
exit(EXIT_FAILURE);
}
else
{ 
  return this->s_data[pos-1];
}

}

//Assigns a new value to the string, replacing its current contents.
 inline String& String::operator=(char c)
 {
  s_length=1;
  s_capacity=1;
  delete [] s_data;
  char* s_data = new char[1];
  s_data[0]=c;
  return *this; 
 }

 inline String String::operator+ (const char* lhs)
 {
   unsigned int i=0;
   while(lhs[i]!='\0')
   {
      i++;
   }
   char* data = new char[i+s_length]; 
   unsigned int j;
   for (j=0; j<s_length;j++)
     {
       data [j]=s_data[j];
     }
   
    for (j=s_length; j<(i+s_length);j++)
     {
       data [j]=lhs[j-s_length];
     }
   data[i+s_length]='\0';
   printf(" \n");
   String string_ret(data);
   printf("%d \n", string_ret.length());
   delete []data;
   return string_ret;
       
 }
// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

