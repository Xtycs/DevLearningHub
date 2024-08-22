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

#include "common_list.h"
// #include <iostream>

typedef MUST::CommonList<int> ListInt; // explicit instantiation of the class.
typedef MUST::Node<int> NodeInt;

// A user of the template class is responsible to define the static variable of the class.
//  error: specializing member 'MUST::CommonList<int>::debugMode' requires 'template<>' syntax
// bool ListInt::debugMode = false;

// inherited member is not allowedC/C++(298)
// template<> bool  ListInt::debugMode = false;

// here, no need to mention the template parameters of List.  Compiler can infer the details.
template <>
bool ListInt::List::debugMode =  false ; // true;
template <>
int ListInt::List::objCount = 0;
template <>
ListInt::List::EnvM *ListInt::List::em_ = nullptr;

// If we let int_envm return a pointer to EnvM, works, but could be dangerous, since its return value can expose the em_ to the world. 
// The following works, but maybe not that safe. 
// template<> ListInt::List::EnvM *   ListInt::List::em_ = ListInt::init_envm();

// a safer way. 
bool listint_init_envm_done = ListInt::do_init_envm();

// Not allowed to simply call a function in the global scope.
// ListInt::init_envm();

// In the global scope, maybe the only way to call a function is that it appears on the RHS of =, like:  
// int x = somefunction() ; 

// not allowed to call the function directly at the global scope. 
// MUST::CommonList<int>::init_envm();


// ------ the code to prepare the class ListDouble, a list of double ---------

/** Six statements are missing before using the class ListDouble 
 * Hint: just like the preparation code of ListInt
 * * provide the missing code  here    ~~~~~~~~~ <Task 17 > ~~~~~~~~~  ***/



class Student
{
private:
    std::string name;
    int id;

public:
    Student(std::string n = "", int id = 0) : name(n)
    {
        this->id = id;
    }
    friend std::ostream &operator<<(std::ostream &cot, const Student &stu);
};

std::ostream &operator<<(std::ostream &cot, const Student &stu)
{
    cot << "A student, Name: " << stu.name << " id: " << stu.id; // << std::endl;
    return cot;
}

// ------ the code to prepare the class ListStu, a list of Students ---------

/** Six statements are missing before using the class ListStu 
 * Hint: just like the preparation code of ListInt
 * * provide the missing code  here    ~~~~~~~~~ <Task 18 > ~~~~~~~~~  ***/



#define debug true

int main(void)
{
    using namespace MUST;
    using std::cout;
    using std::endl;
    if (debug)
        cout << ":) main is called \n";

    ListInt lis; // limit  is 200
    lis.set_info("<ListInt_1>");

    if (debug)
        cout << ":) one object of ListInt is made  \n";

    // randomly insert 10 integers in lis

    srand(time(0));
    for (int j = 0; j < 10; j++)
    {
        int n = rand();
        lis.insert_node(new Node<int>(n), lis.tail(), false);
    }
    std::cout << ":) --------- The list content is ----------------\n";
    std::cout << lis;

    ListInt lis2 = lis; // copy constructor.
    lis2.set_info("<ListInt_2>");

    std::cout << ":) --------- A copy of the list has the content  ----------------\n";
    std::cout << lis2;

    std::cout << ":) ------------- Testing the functions of Bag ----------------- \n";
    Bag<int> &br = lis;
    bool b1 = lis.put_in(100);
    bool b2 = lis.put_in(200);
    cout << ":)  putting in two items 100 and 200. The operation is  " << ((b1 && b2) ? "successful " : "failure ") << endl;

    int x;
    bool b3 = lis.take_out(x);
    cout << ":)  taking an item out is " << (b3 ? "successful " : "failure. ") << "the item is: " << x << endl;
    cout << ":) now the list has " << br.size() << " items. It content is: \n"
         << endl;
    lis.show();
    cout << ":) The 5th node contains the data : " << lis.data(lis.nth_node(5)) << endl;

    lis = lis2;
    cout << ":) After lis = lis2, the content of lis is \n" << lis << "\n";
    cout << ":) After lis = lis2, the content of lis2 is \n" << lis2 << "\n";

    ListDouble dls = ListDouble("<dls one>", 5);
    // dls.set_debug(true);
    dls.set_debug(false);

    for (int j = 0; j < 8; j++)
    {
        double x = rand() * 1.0;
        double y = rand() * 1.0;
        dls.insert_node(new Node<double>(x / y), dls.tail(), false);
    }

    std::cout << ":) ------------- dls, the double list, has the content :  " << endl;
    cout << dls;

    ListDouble dls2("<dls two>", 8);
    dls2 = dls;
    std::cout << ":) ------------- dls2, which is copied from dls, has the content :  " << endl;
    cout << dls;

    Student students[3] = {{"Alice", 1}, {"Bob", 2}, {"Charlie", 3}};

    ListStu stulis;
    stulis.set_info(" <Student list one>");
    for (int j = 0; j <= 2; j++)
    {
        stulis.insert_node(new Node<Student>(students[j]), stulis.tail(), false);
    }
    std::cout << ":) --------- Printing the list of students    ----------------\n";
    cout << stulis;

    std::cout << ":) -------------at the end of main(), testing the destructors ----------------- \n";

    return 0;
}
