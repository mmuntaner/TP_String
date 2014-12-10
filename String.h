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
    String(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================
     virtual ~String(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
	inline unsigned int length(void) const;
	inline const unsigned int max_size(void) const;
    inline unsigned int capacity(void) const;

	

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================

    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
        bool Empty(void) const;
    // =======================================================================
    //                             Public Attributes
    // =======================================================================

  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*String(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
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
	inline unsigned int String::length(void) const
	{
	  return s_length;
	}

	inline const unsigned int String::max_size(void) const
	{
	  return MAX_CAPACITY;
	}

    // Capacity : Returns the size of the storage space currently allocated 
    // for the string,expressed in terms of bytes.

    inline unsigned int String::capacity(void) const
    {
      if (s_capacity<MAX_CAPACITY) {
                                     return s_capacity;
        }
      else {
            printf("Vous avez rentré une chaine de caractère trop grande \n");
            exit(EXIT_FAILURE);
        }
    }

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __STRING_H__

