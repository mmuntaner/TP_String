//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __STRING_H__
#define __STRING_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>
#include <cstring>


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

    // =======================================================================
    //                                Destructor
    // =======================================================================
     virtual ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
	inline size_t length(void) const;
	inline const unsigned int max_size(void) const;
  inline unsigned int capacity(void) const;
	inline char* c_str(void) const;


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
		inline void reserve(unsigned int n=0);
		inline void resize (unsigned int n);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    bool empty(void) const;
    char& at (unsigned int pos);
        
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

    String(const String &model)
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
	inline size_t String::length(void) const
	{
	  return s_length*sizeof(char);
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
            printf("Vous avez rentré une chaine de caractère trop grande \n");
            exit(EXIT_FAILURE);
        }
    }


	inline char* String::c_str(void) const
	{
    return s_data;
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

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

