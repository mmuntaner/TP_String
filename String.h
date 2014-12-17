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
   inline String& operator=( const char* s);
   inline String& operator= (const String& str);
   friend inline String operator+ (const String& lhs, const String& rhs);
   friend inline String operator+ (const String& lhs, char rhs);
   friend inline String operator+ (char lhs, const String& rhs);
   friend inline String operator+ (const char* lhs,const String& rhs);
   friend inline String operator+ (const String& lhs, const char* rhs);
  

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
  
      return s_capacity*sizeof(char);
  
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
{ if(n>MAX_CAPACITY)
{
printf("Your string is too long, not enough capacity !\n");
exit(EXIT_FAILURE);
}
 else if (n > s_capacity)
{
  char* news_data = new char [n];
  for(int i=0;i<s_capacity;i++)
    {
     news_data[i]=s_data[i];
    }
     delete [] s_data;
     s_data=news_data;
     s_capacity = n;
  }
}
		
// Resizes the string to a length of n characters.
inline void String::resize (unsigned int n)
{   
  this->reserve(n);
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
      s_length=n;
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

//Assigns a new value ('c') to the string, replacing its current contents.
 inline String& String::operator=(char c)
 {
  s_length=1;
  s_capacity=1;
  delete [] s_data;
  char* s_data = new char[1];
  s_data[0]=c;
  return *this; 
 }


   inline String operator+ (const String& lhs,const char* rhs )
 {

  unsigned int i=0;
  while(rhs[i]!='\0')
 {
 i++;
 }
 char* data = new char[i+lhs.s_length];
 unsigned int j;
 for (j=0; j<lhs.s_length;j++)
 {
 data [j]=lhs.s_data[j];
 }

 for (j=lhs.s_length; j<(i+lhs.s_length);j++)
 {
 data [j]=rhs[j-lhs.s_length];
 }
 data[i+lhs.s_length]='\0';
 String string_ret(data);

 delete []data;
 return string_ret;


 }


//Returns a newly constructed string object with its value 
//being the concatenation of the characters at the right of the operator
inline String operator+ (const char* lhs,const String& rhs)
{
   unsigned int i=0;
  while(lhs[i]!='\0')
 {
 i++;
 }
 char* data = new char[i+rhs.s_length];
 unsigned int j;
 for (j=0; j<i;j++)
 {
 data[j]=lhs[j];
 }
 for (j=i; j<(i+rhs.s_length);j++)
 {
 data[j]=rhs.s_data[j-i];
 }
 data[i+rhs.s_length]='\0';
 String string_ret(data);
 delete []data;
 return string_ret;
  
}

       
 
//Assigns a new value ("foo") to the string, replacing its current contents.
String& String::operator=( const char* s )
{
  int j=0;
  while(s[j]!='\0')
    {
      j++;
    }
  s_length = j;
  if (s_data)
  {
    delete[] s_data;
  }
  s_data = new char[ s_length + 1 ];
  for( int i = 0; i < s_length; i++ )
  {
  s_data[i] = s[i];
  }

  s_data[s_length] = '\0';
  return *this;
}


//Returns a newly constructed string object with its value 
//being the concatenation of the characters in lhs followed by those of rhs.
inline String operator+ (const String& lhs, const String& rhs)
{
  unsigned int n = lhs.s_length;
  unsigned int m = n + rhs.s_length;
  String newstring(lhs);
  newstring.resize(m);
  unsigned int j;
  for (j=n; j<(m);j++)
    {
      newstring.s_data[j]=rhs.s_data[j-n];
    }
  newstring.s_data[m]='\0';
  return newstring;
  
}

// This operator compare if the String are the same, if they arent, it
// copy str
inline String& String::operator= (const String& str)
{
  int cmp=0;
  int i;
  if (s_length==str.s_length)
    {
      for(i=0;i<s_length;i++)
	{
	  if (s_data[i]==str.s_data[i])
	    {
	      cmp=1;
	    }
	}
    }
  if(cmp)
    {
      return *this;
    }
  delete [] s_data;
  s_length=str.s_length;
  s_capacity=str.s_capacity;
  s_data=new char [s_capacity];
  // This loop is similar to memcpy
  for(i=0;i<s_length;i++)
    {
      s_data[i]=str.s_data[i];
    }
  return *this;
}


// This operator have two declaration, the first is used when the String is at 
// the left of the operator. It return a concatenate String from anothe String
// and a char
  inline String operator+ (const String& lhs, char rhs)
  {
    int i;
    char * cstr= new char [lhs.s_length+2];
    for(i=0;i<lhs.s_length;i++)
      {
	cstr[i]=lhs.s_data[i];
      }
    cstr[i]=rhs;
    cstr[i+1]='\0';
    String result(cstr);
    return result;
  }

// This one is used when the String is at the right of the operator
inline String operator+ (char lhs, const String& rhs)
{
  int i;
  char * cstr= new char [rhs.s_length+2];
  for(i=1;i<rhs.s_length+1;i++)
    {
      cstr[i]=rhs.s_data[i-1];
    }
  cstr[0]=lhs;
  cstr[i]='\0';
  String result(cstr);
  return result;
}








// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

