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


#include "util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main(void){
    puts(":) ------------------------------------------" );
    Bytes bt1 = {NULL, 0} ; // remember to initialize the fields of bt1
    const char * word = "hello world";
    Bytes bt2 = make_bytes(clone_str(word),  strlen(word) + 1); // (void* ) not needed. 
    puts("\n:)---------------  two Bytes object bt1 and bt2 are created ------------\n");
    puts( "\n:) ----------------show bt1 (the empty one) as chars ------------------\n" ); 
    show_bytes_as_chars(bt1); 
    puts( "\n:) ----------------show bt2 as chars-----------------\n" ); 
    show_bytes_as_chars(bt2); 
    puts( "\n:) ----------------show bt2 as numbers------------------\n" ); 
    show_bytes_as_nums(bt2); 
    { 
        Bytes bt3 = clone_bytes(bt2); 
        puts( "\n:) ----------------bt3 is a clone of bt2. show bt3 as numbers and chars-----------------\n");
        show_bytes_as_nums(bt3);
        puts("");
        show_bytes_as_chars(bt3); 
        puts(""); 
        puts(":) ------------------------------------"); 
        free(bt3.addr);
        puts("The space of bt3 is freed");
    } 
    free(bt1.addr); 
    puts("The space of bt1 is freed");
    free(bt2.addr);
    puts("The space of bt2 is freed");
    puts("\n:)  Bye ");
    return 0; 
}