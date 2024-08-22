/********************** 
* Homework done by 
* Student1:Tingyang Xie(解汀阳)  Class:CS111 D2  Student ID:1230019461
*********************** 
*/


/************************************************ 
 * CS111/EIE111 2024
 * Project Designed by the teacher: Zhiyao Liang
 * zyliang@must.edu.mo
 * **********************************************
*/

#ifndef _UTIL2_H__
#define _UTIL2_H__

#include <cstddef> // for size_t

/*
// also fine: 
namespace util2 {
    class Bytes{ ...};
}

*/

namespace util2
{
    class Bytes;
}

class util2::Bytes//  <--- the class Bytes is defined in the namespace util2(similar to the definition of member functions of a class outside the class)
{
private:
    // The address of the first byte. the space must be allocated on the heap using the new operator
    void * addr_; 
    int id;   // if id is 3, the the object thes 3rd Bytes object created. 
    static int numOfBytesCreated; 
    // the number of bytes in the allocated space starting at addr. 
    std::size_t len_;  // don't forget std

public:
    // <addr_> becomes the starting address of a clone of the space located at the addr_field of another Bytes object, 
     /***    Declaration statement of the copy constructor of Bytes 
      * provide the missing clode  here    ~~~~~~~~~ <Task 39> ~~~~~~~~~  ***/
    Bytes(const Bytes & bt); //under the namespace,so no need to use util2::Bytes &bt
    
    
    // <addr> becomes the starting address of a clone of the space located at <_addr>,
    Bytes(void * _addr = nullptr, size_t _len = 0); 
    
    // print the bytes at addr one by one as characters. 
    void show_as_chars() const;

    // print the bytes at addr one by one as unsigned integers. 
    void show_as_nums() const;

    // delete the space at addr, and let this object be a clone (with deep copy) of Bytes object bt; 
    util2::Bytes & operator=(const Bytes & bt); 

    // destructor, delete the space at <addr_>  
    /***    Declaration statement of the destructor of Bytes 
      * provide the missing clode  here    ~~~~~~~~~ <Task 40> ~~~~~~~~~  ***/
    ~Bytes();
};

#endif