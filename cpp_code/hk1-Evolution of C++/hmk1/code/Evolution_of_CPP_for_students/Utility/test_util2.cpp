#include "util2.h"
#include <iostream>
#include <cstring>

int main(void)
{
    {
        std::cout << ":) ------------------------------------------" << std::endl;
        util2::Bytes bt1;
        const char *word = "hello world";
        util2::Bytes bt2 = util2::Bytes((void *)word, strlen(word) + 1); // (void* ) needed.
        std::cout << "\n:)---------------  two Bytes object bt1 and bt2 are created ------------\n";
        std::cout << "\n:) ----------------calling bt1.show_as_chars() ------------------\n";
        bt1.show_as_chars();
        std::cout << "\n:) ----------------calling bt2.show_as_chars() ------------------\n";
        bt2.show_as_chars();
        std::cout << "\n:) ----------------calling bt2.show_as_nums()------------------\n";
        bt2.show_as_nums();
        util2::Bytes bt3 = util2::Bytes(bt2);
        std::cout << "\n:) ----------------bt3 is a clone of bt2 made by the copy constructor. Calling bt3.show_as_nums() and bt3.show_as_chars()------------------\n";
        bt3.show_as_nums();
        std::cout << std::endl;
        bt3.show_as_chars();
        std::cout << std::endl;

        std::cout << "\n:) ----------------bt4 is also a clone of bt2 made by the overloaded =. Calling bt4.show_as_nums() and bt4.show_as_chars()------------------\n";
        util2::Bytes bt4; 
        bt4 = bt2; 
        bt4.show_as_nums();
        std::cout << std::endl;
        bt4.show_as_chars();
        std::cout << std::endl;
        std::cout << ":) ------------------------------------------" << std::endl;
    }
    std::cout << ":)  Bye ...... " << std::endl;
    return 0;
}