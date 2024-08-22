/********************** 
* Homework done by 
* Student1: 
* Student2: 
* Student3:
*********************** 
*/

/************************************************ 
 * CS111 2024
 * Project Designed by the teacher: Zhiyao Liang
 * zyliang@must.edu.mo
 * **********************************************
*/



#ifndef _BAG_H_
#define _BAG_H_


/***   some code saying that, there is a namespace MUST, and there is a template class Bag in the namespace. 
 * provide the missing clode  here    ~~~~~~~~~ <Task 1> ~~~~~~~~~  ***/


template <typename T > class MUST::Bag{
    public: 
        // add a (deep clone of ) value of type T into the storage in some way. 
        virtual bool put_in(const T& v) = 0 ; 

        // take out one value from (and remove it from) the storage and save it at v. Which value is removed is not specified. 
        virtual bool take_out(T& v) = 0 ;   

        // return a number that is related to the number of elements in the storage. It can be interpreted in different ways. Maybe the number of unique elements, or total number of elements.  
        virtual int size() const = 0 ; 

        virtual ~Bag() = 0;

        virtual void show() = 0;  // print the content of the storage.  
};


/*** 
 * Definition of the destructor of Bag. Its body may do nothing. 
 * provide the missing code  here    ~~~~~~~~~ <Task 2> ~~~~~~~~~  ***/



#endif
