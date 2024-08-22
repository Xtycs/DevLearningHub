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

#ifndef _COMMON_LIST_H_
#define _COMMON_LIST_H_

#include "list.h"

// no way to express the idea that P is the pointer to a Node declared inside List ???
// List<int, struct Node{int, int, *Node} ;

// #define THE_LIST  MUST::List< Node<T>, T, Node<T> *, nullptr >

// works for Windows, but maybe is the reason for a  warning on Mac ,  warning: missing 'typename' prior to dependent type name  List<Node<T>, T, Node<T> *, nullptr> ...
// #define THE_LIST  List< Node<T>, T, Node<T> *, nullptr >

namespace MUST
{

    /**
     * @brief  A node of common list
     *
     * @tparam T   The type of a data item. It should support deep copying and can be deleted automatically (be a built-in type or has its own destructor or )
     */
    template <typename T>
    class Node
    {
    public:
        T data_;
        Node *next_;
        Node *prev_;

        // constructors
        Node()
        { // default constructor
            // does not care about the data_;
            next_ = prev_ = nullptr;
        }
        Node(T data)
        {
            next_ = prev_ = nullptr;
            data_ = data;
        }
        // No need to write the copy constructor
        // the implicit copy constructor can do deep copying of the <data_> field, while it makes no much sense to do deep copying of next_and prev_, that is too much work.
        // The implicit operator = will do just fine.
        // No need to write destructor, the type T is responsible to have its proper destructor.
    };

    template <typename T>
    class CommonList : public List<Node<T>, T, Node<T> *, nullptr>
    {

    protected:
        /** One line is missing
         * delare  THE_LIST an the alias of the specialization of List that is the base class of CommonList. 
         * * provide the missing code  here    ~~~~~~~~~ <Task 12 > ~~~~~~~~~  ***/
        

        // typedef does not work for templates with the compiler cl; g++  is fine
        // typedef List< Node<T>, T, Node<T> *, nullptr > THE_LIST;
        // using THE_LIST = List< Node<T>, T, Node<T> *, nullptr >;

        // warning: missing 'typename' prior to dependent type name List<Node<T>, T, Node<T> *, nullptr>::T;

        using ED = typename THE_LIST::EnvD;
        using EM = typename THE_LIST::EnvM;

        // the compiler knows that Node<T> is a dependent type. It does not need the typename description in side the < > after List.

        // -------------- The definitions of the methods of EnvM ----------------

        // error: unknown type name 'EnvD'
        // static Node<T> * & prev(Node<T> *ndp, EnvD &d, EnvM &m)

        static Node<T> *&prev_m(Node<T> *ndp, ED &d, EM &m)
        {
            return ndp->prev_;
        }

        static void clear_node_m(Node<T> *ndp, ED &d, EM &m)
        {
            delete ndp;
        }

        static void prepare_empty_list_m(ED **p, EM &m)
        {

            if (THE_LIST::debugMode)
            {
                std::cout << ":) The function : " << __func__ << " is called   \n";
            }

            // d = new ED; //new EnvD;
            ED &d = *(*p);
            d.head_ = d.tail_ = nullptr;
            // d->head_ = d->tail_ = nullptr;
            // d->size_ = 0;
            d.size_ = 0;
        }

        static inline Node<T> &node_m(Node<T> *ndp, ED &d, EM &m) { return *ndp; }

        static Node<T> *make_new_node_m(const T &data, ED &d, EM &m)
        {
            // error: use of class template 'Node' requires template arguments
            // return new Node(data);

            Node<T> *pt = new Node<T>(data);

            return pt;
        }

        // public:
        static typename THE_LIST::EnvM *init_envm()
        {
            // THE_LIST::EnvM * & e = THE_LIST::em_;
            if (THE_LIST::debugMode)
            {
                std::cout << ":) The function: " << __func__ << " is called \n";
            }

            // error: use of undeclared identifier 'e'
            // THE_LIST::EnvM * e;

            typename THE_LIST::EnvM *e;

            e = new EM;

            if (THE_LIST::debugMode)
            {
                std::cout << ":) space of em_ allocated  " << __func__ << " is called \n";
            }

            // ok
            // e->data = data_m;

            // try to use lambda expression here
            
            /**  One statement is missing
             * assign an lambda expression to e->data. 
             * The statment is like:   e->data = expr; 
             * where expr is an lambda expression. A common lambda expression can have the form: 
             * [] (parameter_list) -> return_type {function_body}
             * Hint: try to write the data_m function, and transform it into a lambda function 
             ** provide the missing code  here    ~~~~~~~~~ <Task 13 > ~~~~~~~~~  ***/

           

            // ok
            // e->next = next_m;

            /**  One statement is missing
             * Similarly, assignment to e->next with a lambda expression 
             * * provide the missing code  here    ~~~~~~~~~ <Task 14 > ~~~~~~~~~  ***/

           
            e->prev = prev_m;


            e->clear_node = clear_node_m;
            

            e->prepare_empty_list = prepare_empty_list_m;
            

            e->node = node_m;
            

            e->make_new_node = make_new_node_m;

            if (THE_LIST::debugMode)
            {
                std::cout << ":) make_new_node in em_ assigned  \n";
            }

            return e;
        }

    public:
        static bool do_init_envm(void)
        {
            THE_LIST::em_ = init_envm();
            return true;
        }

    public:
        // ~~~~~~~~~~~~~~~~~~~~~~ constructors and destructor

        CommonList(std::string info = "", int limit = ED::THE_LIMIT_) : THE_LIST()
        {
            if (this->debugMode)
                std::cout << ":) Default constructor of CommonList called \n";

            // error: use of undeclared identifier 'objCount'
            // if(objCount == 0 && THE_LIST::em_ == NULL)

            if (this->objCount == 0 || THE_LIST::em_ == nullptr)
                init_envm();

            // error, cannot access protected member THE_LIST::ed_
            // prepare_empty_list_m( & THE_LIST::ed_, *THE_LIST::em_ ) ;

            prepare_empty_list_m(&this->ed_, *THE_LIST::em_);

            // if(this->objCount == 0)
            THE_LIST::ed_->info_ = info;
            if (limit > 0)
                THE_LIST::ed_->limit_ = limit;
            else
                THE_LIST::ed_->limit_ = THE_LIST::ed_->THE_LIMIT_;
            this->objCount++;
        }

        // copy constructor:  Just call the base class's copy constructor, which can do most of the work.

        /** The definitin of the copy constructor of CommonList is missing
         * It simply does two things: 
         * 1) call the copy constructor of its base class THE_LIST
         * 2) increment objCount
         * * provide the missing code  here    ~~~~~~~~~ <Task 15 > ~~~~~~~~~  ***/
        


        // destructor
        // the destructor of base class will always be called.
        // Decrementing the objCount is done by the destructor of the base class.

        /** The definition of the destructor of CommonList is missing. 
         * Its body may contain just one statement, call the delete_list() function inherited from the base class. 
         * * provide the missing code  here    ~~~~~~~~~ <Task 16 > ~~~~~~~~~  ***/
        



        // ------------------- Define the pure virtual  methods and  some selected non-pure virtual methods inherited from List and Bag -----------------------


        // actually not much needed. List::show() is already good enough. Here the show() function is defined to demonstrate the dynamic inhertance behavior

        // with or without mentioning virtual, it is the same.
        // virtual void show()

        void show()
        {
            if (THE_LIST::debugMode)
            {
                std::cout << ":) ~~~~~~~~  Printing internal information of the list \n";
                THE_LIST::show_info(this->ed_);
            }
            std::cout << ":) it is a common list\n";
            THE_LIST::show();
        }

        // ---------------- friend functions --------------
        // no need to define the operator <<

    };  // end of the CommonList class

} // end of the MUST namespace. 

#endif