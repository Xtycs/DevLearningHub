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

#ifndef LIST_H
#define LIST_H

#include "bag.h"
#include <string>
#include <iostream>
#include <ctime>   // for time()
#include <cstdlib> // for rand() and srand(), and exit()

namespace MUST
{

    template <typename N, typename T, typename P, P nullP_>
    class List;

    // Declare that there is a operator<< in the MUST name space. So that, later the List can declare this function  as a friend.
    template <typename N, typename T, typename P, P nullP_>
    std::ostream &operator<<(std::ostream &cot, MUST::List<N, T, P, nullP_> &lis);

    /**
     * @brief A general purpose template for a doubly-linked list
     *
     * @tparam N   The type of the list node. Such a data type should be able to provide three pieces of information: a data item, with type D, and two "pointers" to the node (prev and next) with type P.  It should has a proper copy constructor.
     *
     * @tparam T The type of the data item. T should support deep copying, and << for printing.
     *
     * @tparam P  The "pointer" to a node.
     *
     * @tparam nullP_   a value of type P that represents some invalid "address" of a node.  It is  a special pointer, like NULL for a pointer, or an invalid index in an array.
     *
     * @note  This is an eager base class, providing helpful code for derived class as much as possible.
     */
    template <typename N, typename T, typename P, P nullP_>
    class List : public Bag<T>
    {

    protected:
        /**
         * @brief  The environment, the data part.
         *
         */
        struct EnvD
        {
            enum
            {
                THE_LIMIT_ = 200
            };


            // Naming style:  data member names has a trailing _

            // Data members
            P head_;   // "Pointer" the first node
            P tail_;   // "Pointer" of the last node
            int size_; // Number of nodes
            // const int limit_;
            int limit_; // actual limit of nodes in the list,
          
          // something about the list, like an name of the object.
            std::string info_;

            // Environment of Data. The data the every list will have. 
            EnvD(EnvD *p = nullptr, int limit = THE_LIMIT_) //; // default constructor
            {
                if (debugMode)
                {
                    std::cout << ":) default constructor of EnvD is called, with p = " << p << " limit = " << limit << "\n";
                }
                if (p == nullptr)
                {
                    head_ = tail_ = nullP_;
                    size_ = 0;
                    // limit_ = 0;
                    limit_ = (limit <= 0 ? THE_LIMIT_ : limit);
                    info_ = "";
                }
                else // meaningless to copy head and tail and size. only coy the limit and info
                {
                    //  head_ = p->head_;
                    head_ = tail_ = nullP_;
                    // size_ = p->size_;
                    size_ = 0;
                    limit_ = (p->limit_ <= 0 ? THE_LIMIT_ : p->limit_);
                    info_ = p->info_;
                }
            }
        };

        using ED = typename List::EnvD;   // ED is an alias 

        // Environment of methods. Pointers to functions that different list can implement differently. 
        struct EnvM
        {   
            // obtain the data of a node pointed by ndp. 
            T &(*data)(P ndp, const EnvD &d, EnvM &m);
         
            // obtain the pointer of the next node of a node pointed by ndp. 
            P &(*next)(P ndp, EnvD &d, EnvM &m);
            
             // obtain the pointer of the previous node of a node pointed by ndp. 
            P &(*prev)(P ndp, EnvD &d, EnvM &m);

            // Something work to clear the space of a node pointed to by ndp. The members space inside the node, and possibly the space of the node, are  "released" in some way. 
            void (*clear_node)(P ndp, EnvD &d, EnvM &m);

            // Prepare the space of an empty list, and initialize the data members as much as possible.
            // Note: d is double pointer parameter, so that possibly a pointer to EnvD can be changed, like the ed_ member of List. 
            void (*prepare_empty_list)(EnvD **d, EnvM &m);

            // From a node pointer ndp, get the node
            N &(*node)(P ndp, EnvD &d, EnvM &m);

           // Prepare a new node and put the data in it.
            P(*make_new_node)
            (const T &data, EnvD &d, EnvM &m);

        };


        // 'static' is not permitted on a declaration of a type
        // static struct EnvM

        static bool debugMode; // default value should be false ???

        static int objCount; // should be 0 at the beginning.
                             // Have to define the static member outside the class somewhere at the global scope. The declaration of a static member inside the class is not a definition.

    protected:
         
        EnvD *ed_;    // pointer to some data environment. Each object has its own data 
        static EnvM *em_; // Pointer to the methods environment. It is static, no need to be recorded in each object.

        /*  Doing this, then the default constructor is meaningless or improper, since it make no sense to let the base class find a way to initialize ed and em
        EnvD ed;
        EnvM em
        */

        /*  Also, doing this, then the default constructor is meaningless or improper, since it make no sense to let the base class find a way to initialize ed and em
        EnvD & ed;
        EnvM & em
        */

        // static member variable can be difined and initialized in class either as a const expression or an inline one.  Then, there is no need to define the variable ouside the class.
        //  inline variables are only available with -std=c++17 or -std=gnu++17
        // static inline bool debugMode {false};

        //Print some information,  usually for debug purpuse. 
        static void show_info(EnvD *d)
        {
            if (debugMode)
            {
                std::cout << ":) the function " << __func__ << " is called \n";
                std::cout << ":) the parameter d has value " << d << " \n";
            }

            std::cout << "head: " << d->head_ << " tail: " << d->tail_ << " size: " << d->size_ << "info: " << d->info_ << "\n";
        }

    public:
        static inline void set_debug(bool v) { 
            debugMode = v; 
        }

    public:
        // ~~~~~~~~~~~~~~~~~~~~~ Constructors and destructors ~~~~~~~~~~~~~~~~~~~~~~~~
        
        // Constructors
        // default constructor
        List(EnvD *ed = nullptr /* EnvM *em = nullptr */)
        {
            if (debugMode)
            {
                std::cout << ":) default constructor of List is called \n";
            }
            if (ed == nullptr)
                // ed_ = nullptr ; // it will make the program crash
                ed_ = new EnvD;
            else
                ed_ = new EnvD(*ed);

            // no, em_ should be initialized ouside an object
            //  em_ = new EnvM(*em);
            
            // objCount++;  // let the derived class take care about the objCount.

            // The user of List, or the derived classes are responsible to initialize em_ before any constructor of List is called.
            if (em_ == nullptr)
            {
                std::cout << "!!! the em_ is not prepared yet. exit the program. \n";
                exit(1);
            }

            if (debugMode)
                std::cout << ":) Default constructor of List called \n";
        }

        List(const List &lis) // copy constructor
        {
            if (em_ == nullptr)
            {
                std::cout << "!!! the em_ is not prepared yet. exit the program. \n";
                exit(1);
            }

            // ed_ = new EnvD(*(lis.ed_));  // big bug

            ed_ = new EnvD(lis.ed_, lis.ed_->limit_);

            if (debugMode)
            {
                std::cout << ":) Copy constructor of List called \n";
                std::cout << ":) ed_ is at: " << (void *)ed_ << "\n";
                std::cout << ":) this->ed_ is at: " << (void *)this->ed_ << "\n";
            }

            if (debugMode)
                std::cout << ":) before prepare_empty_list, ed_ is " << ed_ << "\n";

            // prepare_empty_list should also initialize ed_ and the data in ed_ properly. 
            em_->prepare_empty_list(&ed_, *em_);
   
            if (debugMode)
                std::cout << ":) after prepare_empty_list, ed_ is " << ed_ << "\n";

            // everything is prepared, then copy the content from lis. 
            copy_list(lis);
        }

        /* Such a destructor shows that
        1) the class better to have derived classes. 
        2) the class is an abstract class 
        3) unlike other pure virtual function, a definition of the destructor is needed is required by this class.

        */
        virtual ~List() = 0; 

        // ---------------  The simple  get and set functions etc. --------------
        // These are public functions that users can call directly.

        // has to declared these methods as const, otherwise, a call like
        // lis.data(), for a const object lis, it is an error.

        inline P head() const
        {
            if (debugMode)
            {
                std::cout << ":) head() is called \n"
                          << "now the ed_ is at " << ed_ << "; head value is " << ed_->head_ << "\n";
            }
            return ed_->head_;
        }
        inline P tail() const
        {
            return ed_->tail_;
        }

        /***   The definition of the function limit() is missing. It simply returns the value of limit_ 
         * provide the missing code  here    ~~~~~~~~~ <Task 3 > ~~~~~~~~~  ***/
  

        /*   size() is a virtual funciton of the Bag class. its code is at another place in this class. 
        inline int size() {
            return ed_->size_;}
        */

        T &data(P ndp) const
        {
            if(debugMode)
                std::cout << ":)  the function " << __func__ << " is called in List\n";
            return em_->data(ndp, *ed_, *em_);
        }
        P &next(P ndp) const
        {
            return em_->next(ndp, *ed_, *em_);
        }
        P &prev(P ndp) const
        {
            return em_->prev(ndp, *ed_, *em_);
        }

        P make_new_node(T v) const
        {
            /*   The body of the function make_new_node() is missing
            **   provide the missing code  here    ~~~~~~~~~ <Task 4> ~~~~~~~~~  ***/


        }

        inline void set_info(std::string s)
        {
            ed_->info_ = s;
        }

        // // ---------- The 6 non-trivial public functions defined by the List class ------------------------------

        // return the position of the nth node, when 0 <= n < size_. When n is out of range, return nullP_.
        P nth_node(int n) const;

        // no need to be virtual. 
        // virtual List &operator=(const List &lis);
        List &operator=(const List &lis);

        /**
         * @brief Insert a node into a list at a certain location.
         *
         * @param newNd : an "pointer" to node that is already created.
         * @param anchor : describes a node in the list
         * @param atPrev : If true, the new Node should be added as the previous node of <anchor>, otherwise, when <atPrev> is false, <newNd> should be added as the next node of <anchor>
         * @return P : When success, return newNd. When fail (like the when the list is full) return nullP_.
         * @note The fields of <head_> <tail_> <size_> should be updated accordingly.
         */
        P insert_node(P newNd, P anchor, bool atPrev);

        /**
         * @brief Remove a node from the list.
         *
         *
         * @param ndp    the node to be deleted.
         * @note  Assuming that ndp is a valid node pointer, i.e., it describes an actual node belonging to the list.
         * @note the fields of <head_> <tail_> <size_> should be updated accordingly.
         * @note The tasks of releasing the space of the node is done by another function, clear_node. 
         */
        void delete_node(P ndp);

        // copy the content of a source list into this list.
        void copy_list(const List &lis);

        // Remove each node from the list, and release the space of each node (can use the function clear_node)
        void delete_list();

        // ----------------------  define the virtual methods inherited from Bag ------------------
        // When it is clear enough to implement the virtual functions of the base class Bag,
        // do it to ease the work the derived classes.
        // all the pure virtual function of Bag are implemented.

        // insert v into a new node appended to the tail of the list
        bool put_in(const T &v)
        {
            if (ed_->size_ >= ed_->limit_)
                return false;
            P ndp = em_->make_new_node(v, *ed_, *em_);
            insert_node(ndp, ed_->tail_, false);
            return true;
        }

        /*   size() is a funciton of bag
       inline int size() {
           return ed_->size_;}
       */

        // compiler will tell which function pure virtual function is not implemented
        // unimplemented pure virtual method 'size' in 'CommonList'

        int size() const
        {
            return ed_->size_;
        }

        // Requirement from Bag: take out one value from (and remove it from) the storage and save it at v. Which value is removed is not specified.
        // The way of List: take out a node randomly chosen from the list
        bool take_out(T &v)
        {
            /** The body of the take_out() function is missing 
             * if the size of the list is 0, return false; 
             * otherwise, get a random number n in the range [0, size-1], find the node at position n (the nth) in the list, save the data of the node in v, and delete the node, and return false. 
             * 
             * *   provide the missing code  here    ~~~~~~~~~ <Task 5> ~~~~~~~~~  ***/
            


        }

        // error: call to function 'operator<<' that is neither visible in the template definition nor found by argument-dependent lookup
        virtual void show()
        {
            std::cout << ":) A list " << ed_->info_ << ";"
                      << " Number of items is :" << size() << "; limit is : " << limit() << "\n";
            int j = 0;
            P current = head();
            while (j < size())
            {
                std::cout << j << ") " << data(current) << std::endl;
                current = next(current);
                j++;
            }
        }
        // ----------------------  friend functions ------------------

         
        /*  One line is missing here. It says that, there is a function that is a friend of this class List. That function is an instance of the template function operator<<, while the the template argument is same as what are used to instantiate the template class List. 
        **   provide the missing code  here    ~~~~~~~~~ <Task 6> ~~~~~~~~~  ***/
        


    }; // ~~~~~~~~~~~~~~ end of the class declaration ~~~~~~~~~~~~~`

}

// ~~~~~~~~~~~~~~~~~~~~~  Definitions of the functions ouside the class ~~~~~~~~~~~~~~~~~~~~
// put the definitions of the template class methods in this .h file, not in a separate .cpp file.

// the destructor. Remember to decrement the objCount. 
template <typename N, typename T, typename P, P nullP_>
MUST::List<N, T, P, nullP_>::~List() // tricky to have the correct header of the destructor
{
    delete_list();
    std::string info = ed_->info_;
    delete ed_; // remove the space of the data part.
    objCount--;
    /* Maybe no need to delete the envM pointer.
    if(objCount == 0)
        delete em_;
    */
    std::cout << " The list: " << info << " is deleted. The number of remaining object of this list class is: " << objCount << "\n";
}

// -----------------   Define the 6 non-trivial public functions outside the class declaration

template <typename N, typename T, typename P, P nullP_>
P MUST::List<N, T, P, nullP_>::nth_node(int n) const
{
    /** The body the function nth_node() is missing
     * if n is out of the range [0, size_ -1], return the invalid address nullP_
     * Otherwise, find the nth node, in the list, and return its "address"
     **   provide the missing code  here    ~~~~~~~~~ <Task 7> ~~~~~~~~~  ***/
    
}

template <typename N, typename T, typename P, P nullP_>
MUST::List<N, T, P, nullP_> & MUST::List<N, T, P, nullP_>::operator=(const List &lis)
{

    if (this == &lis)
        return *this;
    delete_list();
   
    
    /**  one line of code is missing 
     * Call the prepare_empty_list function, where the arguments is related to ed_ and em_. 
     **   provide the missing code  here    ~~~~~~~~~~~ <Task 8> ~~~~~~~~~~~  ***/
   
    
    copy_list(lis);
    return *this;
}

// Assuming newNd (the new node) is properly prepared.
template <typename N, typename T, typename P, P nullP_>
P MUST::List<N, T, P, nullP_>::insert_node(P newNd, P anchor, bool atPrev)
{   
    if (debugMode)
    {   
        std::cout << "List::insert_node() is called; size_ = " << ed_->size_ << "; limit_ = " << ed_->limit_ << "; head_ = " << ed_->head_ << "; tail_ = " << ed_->tail_ << std::endl;
    }

    if (newNd == nullP_ || ed_->size_ == ed_->limit_) // insertion not successful.
        return nullP_;
    // special cases:
    if (ed_->head_ == nullP_ || ed_->tail_ == nullP_ || ed_->size_ == 0) // when the list is empty.
    {
        ed_->head_ = ed_->tail_ = newNd;
        prev(newNd) = next(newNd) = nullP_;
        ed_->size_ = 1;
        return newNd;
    }
    if (anchor == nullP_)
    {
        return nullP_; // now it is  some error.
    }
    if (atPrev == true)
    {
        // step 1: update newNd
        prev(newNd) = prev(anchor);
        next(newNd) = anchor;
        // step 2: update the neighbor of anchor, only when the neighbor is not nullP
        if (prev(anchor) != nullP_) // only when anchor is not the head
            next(prev(anchor)) = newNd;
        // step 3: update anchor
        prev(anchor) = newNd;
        ed_->size_++;
        // step 4: update head if needed.
        if (ed_->head_ == anchor)
            ed_->head_ = newNd;
    }
    else
    { // insert node after <anchor>

    /** the code of the else part is missing 
     * step 1: update newNd
     * step 2: update the neighbor of anchor, only when the neighbor is not nullP
     * step 3: update anchor
     * step 4: update the size_
     * step 5: update tail if needed.
     **   provide the missing code  here    ~~~~~~~~~ <Task 9> ~~~~~~~~~  ***/
       
    }
    return newNd;
}

template <typename N, typename T, typename P, P nullP_>
void MUST::List<N, T, P, nullP_>::delete_node(P ndp)
{
    if (this->debugMode)
    {
        std::cout << ":)  the function " << __func__ << " is called \n";
    }
    if (ndp == nullP_)
        return;
    // the special case:
    if (ed_->size_ == 1)
    {
        ed_->head_ = ed_->tail_ = nullP_;
        goto END;
    }

    /** The code before END is missing
     * step 1: if the previous node of ndp exists, update its next link. 
     * step 2: if the next node of the ndp exists, update its previous link. 
     * step 3: update the head if it is ndp. 
     * step 4: update the tail if it is ndp. 
     ** provide the missing code  here    ~~~~~~~~~ <Task 10> ~~~~~~~~~  ***/

    


END:
    // clear the space of the node
    em_->clear_node(ndp, *ed_, *em_); // update or process the node ofndp now.
    ed_->size_--;

    if (this->debugMode)
    {
        std::cout << ":)  the function " << __func__ << " is called and finished. \n";
    }
}

/**
 * @brief A function to delete the space of a list
 */
template <typename N, typename T, typename P, P nullP_>
void MUST::List<N, T, P, nullP_>::delete_list()
{
    /**     the body of delete_list() is missing 
     *  Repeat, delete the nodes one by one (call the delete_node() function), until the list is empty
     * provide the missing code  here    ~~~~~~~~~ <Task 11 > ~~~~~~~~~  ***/
    

    
}

template <typename N, typename T, typename P, P nullP_>
void MUST::List<N, T, P, nullP_>::copy_list(const List &lis)
{
  
    int j = 0;

    // P current = head(); // bug fixed
    P current = lis.head();

    //  while (j < size_ && current != nullP_)
    if (debugMode)
    {
        std::cout << "List::copy_list() is called when size_ = " << ed_->size_ << "; limit_ = " << ed_->limit_ << "\n";
    }

    while (ed_->size_ < ed_->limit_ && ed_->size_ < lis.ed_->size_ && current != nullP_)
    {
        // head, size, and tail will be updated by insert_node.
        // insert_node(new N(*current), tail_, false);

        if (debugMode)
        {
            std::cout << "Begin of the iteration:  size_ : " << ed_->size_ << "; current : " << current << std::endl;
        }

        insert_node(make_new_node(lis.data(current)), ed_->tail_, false);
        /* bug !!! current = next(current); */
        current = lis.next(current);

        if (debugMode)
        {
            std::cout << "End of the iteration: size_ : " << ed_->size_ << "; current : " << current << std::endl;
        }
    }
    if (ed_->size_ != lis.ed_->size_) // lis.size())
    {
        std::cout << ":(  !!!! copy_list() in list.h is wrong, size is do not match \n";
    }
    if (&ed_->head_ == &lis.ed_->head_ || &ed_->tail_ == &lis.ed_->tail_ || &ed_->size_ == &lis.ed_->size_)
    {
        std::cout << ":(  !!!! copy_list() in list.h is wrong,  two object sharing space \n";
    }
}

// error: out-of-line definition of 'operator<<' does not match any declaration in namespace 'MUST'

template <typename N, typename T, typename P, P nullP_>
std::ostream &MUST::operator<<(std::ostream &cot, MUST::List<N, T, P, nullP_> &lis)
{
    lis.show();
    return cot;
}

#endif // LIST_H
