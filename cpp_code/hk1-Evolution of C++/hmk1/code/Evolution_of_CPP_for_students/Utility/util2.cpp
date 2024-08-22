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

#include <iostream>
#include <cstring> // for std::memcpy
// #include "util.h"
#include "util2.h"

// https://isocpp.org/wiki/faq/mixing-c-and-cpp
//  C++ cannot call C code directly.

int util2::Bytes::numOfBytesCreated = 0;

#define DEBUG true
// #define DEBUG false

extern "C"
{
    /*  also ok to put the declarations one by one
    typedef struct _bytes
    {
        void *addr; // the starting address of the sequence of bytes.
        size_t len; // the number of bytes in the sequence.
    } Bytes;

    Bytes make_bytes(void *addr, size_t len);

    // print each byte as a character
    void show_bytes_as_chars(Bytes bt);

    // print each byte as an unsigned int.
    void show_bytes_as_nums(Bytes bt);

    */

// easier, just inlcude the util.h
#include "util.h"

};

// This statement will cause trouble ? 
// using util2::Bytes;

/* provide the missing code  here, the function header of the copy constructor of Bytes    ~~~~~~~~~ <Task 41> ~~~~~~~~~  ***/    
util2::Bytes::Bytes(const Bytes & bt) // <--- function header is missing 
{
    /***  Provide the missing code in the body of the copy constructor of Bytes    ~~~~~~~~~ <Task 42> ~~~~~~~~~ ***/
    //util2::Bytes *new_bytes = new util2::Bytes(bt.addr_, bt.len_);
    addr_ = new char[bt.len_];
    if(addr_==nullptr)
        throw std::bad_alloc();
    std::memmove(addr_, bt.addr_, bt.len_);

    len_ = bt.len_;
    id = ++numOfBytesCreated;

    if (DEBUG)
    {
        std::cout << "A Byte object with id " << id << " is created \n";
    }
}

// Note: remember to make a clone of the space at <addr>, and save starting address of the clone at <addr_>
util2::Bytes::Bytes(void *addr, std::size_t len)
{
  /***  Provide the missing code in the body of this constructor of Bytes    ~~~~~~~~~ <Task 43> ~~~~~~~~~ ***/
  addr_ = new char[len];
  std::memmove(addr_, addr, len);

  len_ = len;
  id = ++numOfBytesCreated;

  if (DEBUG)
  {
      std::cout << "A Byte object with id " << id << " is created \n";
    }
}

namespace util2
{
    //Note, the show_bytes_as_chars() function provided in util.h should be used. 
    void util2::Bytes::show_as_chars() const
    {
       /***  Provide the missing code in the body of this function    ~~~~~~~~~ <Task 44> ~~~~~~~~~ ***/
       if(addr_ != nullptr && len_ > 0)
       show_bytes_as_chars(make_bytes(addr_, len_));
    }

    // Note, the show_bytes_as_nums() function provided in util.h should be used. 
    // the ending const is needed.
    void Bytes::show_as_nums() const
    {
       /***  Provide the missing code in the body of this function    ~~~~~~~~~ <Task 45> ~~~~~~~~~ ***/
       if(addr_ != nullptr && len_ > 0)
       show_bytes_as_nums(make_bytes(addr_, len_));
    }

    Bytes::~Bytes()// <----  provide the missing function header of the destructor ~~~~~~~~~ <Task 46> ~~~~~~~~~
    {
         /***  Provide the missing code in the body of this function    ~~~~~~~~~ <Task 47> ~~~~~~~~~ ***/
         delete[] static_cast<char *>(addr_);
         addr_ = nullptr;
         len_ = 0;

         if (DEBUG)
         {
             std::cout << ":) ... A Byte object with id " << id << " is deleted ... \n";
        }
    }


    // Let the data of this Bytes object be the clone of the bt. Remeber to delete the existing space of the this object before making the clone. Return the reference to this object. 
    util2::Bytes & Bytes::operator=(const util2::Bytes &bt)
    {
        /***  Provide the missing code in the body of this function    ~~~~~~~~~ <Task 48> ~~~~~~~~~ ***/
        if (this != &bt)
        {
            delete[] static_cast<char *>(addr_);

            addr_ = new char[bt.len_];
            std::memmove(addr_, bt.addr_, bt.len_);
            //id = ++numOfBytesCreated;//we initialize bt4 first, so we don't need to increase the number of Bytes created.
            len_ = bt.len_;
            id = ++numOfBytesCreated;
        }

        return *this;
    }
}
