// some generally usable tools 
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


#ifndef _UTIL_H__
#define _UTIL_H__

#include <stdio.h> 

// A sequence of bytes
typedef struct _bytes{
    void * addr; // the starting address of the sequence of bytes. 
    size_t  len;  // the number of bytes in the sequence. 
} Bytes;

// enum boolean {FALSE, TRUE};
// typedef enum boolean Boolean; 
typedef enum
{
    False,
    True
} Boolean;

// Use addr and len to make a Byte struct, without cloning the space at addr. 
Bytes make_bytes(void * addr, size_t len);

// Make a clone of a C string located at source (using the malloc function), return the starting address of the clone. 
char * clone_str( const char * source);

// return a clone of the Byte struct, a deep copy. 
Bytes clone_bytes(Bytes bt);

// print each byte as a character. The null character can be ignored without printing it.
void show_bytes_as_chars(Bytes bt);

// print each byte as an unsigned int. 
void show_bytes_as_nums(Bytes bt);  

// print some guiding message, pause the execution, until a user typed the newline one or two times. 
void pause(void);

#endif 