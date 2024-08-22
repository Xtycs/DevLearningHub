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



#include "../Utility/util2.h"
#include "song_player_v3.h"
// Definition of static members
// should not mention static

typedef Music_player Mpr;


/***  Provide a  statement below to initialize the int static member playerNum of the Music_player class with the value 0   
 *                                  //*~~~~~~~~~ <Task 54> ~~~~~~~~~ ***/
int Mpr::playerNum = 0;
// <----  initialization of playerNum


// Hint, code should be quite simple. The clone should be created using the new operator.
Song *Mpr::clone_song(const Song &s)
{
    /***  provide the missing code  //*~~~~~~~~~ <Task 55> ~~~~~~~~~ ***/
    Song *clone_song = new Song(s);
    return clone_song;
}

void Mpr::play_song(const Song &s)
{
    /***  provide the missing code //*~~~~~~~~~ <Task 56> ~~~~~~~~~ ***/
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "Title:" << s.title << std::endl;
    std::cout << "Authors:" << s.authors << std::endl;
    std::cout << "Actor:" << s.actor << std::endl;
    std::cout << "Year:" << s.year << std::endl;
    s.media.show_as_chars();

    // Song *c = Mpr::clone_song(s);
    // std::cout << "Title:" << c->title << std::endl;
    // std::cout << "Authors:" << c->authors << std::endl;
    // std::cout << "Actor:" << c->actor << std::endl;
    // std::cout << "Year:" << c->year << std::endl;
    // c->media.show_as_chars();
    // delete c;
    std::cout << std::endl;
}



//If the parameter <limit> is a valid (>=1) then set it as the value of the member limit. Otherwise the value of the member limit is LIMIT. 
Mpr::Music_player(int limit)
{
    const char *welcome_msg = "\n:) ---- One player is turned on ----";
    std::cout << welcome_msg;
 
    /***  provide the missing code  //*~~~~~~~~~ <Task 57> ~~~~~~~~~ ***/
    if (limit >= 1)
    {
        this->limit = limit;
    }
    else
    {
        this->limit = LIMIT;//LIMIT is private static member of the class
    }

    playerNum++;
    storage.reserve(this->limit);

    //mistakes form:
    //storage = new Song[this->limit];
    //storage= vector<Song>();

    std::cout << "\n:) there are " << playerNum << " player objects existing.\n";
}


// The copy constructor. 
Mpr::Music_player(const Music_player &mp) 
          : limit(mp.limit)
{
    const char *welcome_msg = "\n:) ---- One player is turned on ----";

    /***  provide the missing code //*~~~~~~~~~ <Task 58>~~~~~~~~~  ***/
    std::cout << welcome_msg;


    //storage.reserve(this->limit);
    storage.resize(mp.how_many_songs());
    for (int i = 1; i <= mp.how_many_songs(); i++)
    {
        storage[i - 1] = mp.storage[i - 1];
    }
    playerNum++;

    std::cout << "\n:) there are " << playerNum << " player objects existing.\n";
}

Mpr::~Music_player()
{
    playerNum--;
    const char *bye_msg = "\n:) ---- One player is turned off  ----\n";
    std::cout << bye_msg << std::endl; 
    std::cout << ":) there are " << playerNum << " player objects remaining\n";
}


// If <id> is valid (1 < id <= number of songs in storage ), play the song with the id (at storage[id-1]) and return true, 
// Note, the id of the song should be printed. 
// Otherwise, return false. 
bool Mpr::play_song_by_id(int id) const
{
    /***  provide the missing code //*~~~~~~~~~ <Task 59> ~~~~~~~~~ ***/

    //if (id >= 1 && id <= storage.size())
    if(id >= 1 && id <= how_many_songs())
    {
        std::cout << "Playing song with id: " << id << std::endl;
        play_song(storage[id - 1]);
        return true;
    }
    else
    {
        std::cout << "Invalid song id" << std::endl;
        return false;
    }

}


// Play all songs in the Music_player object. The id should be shown. 
void Mpr::play_all_songs() const
{

    /***  A range-based for loop should be used. 
     *   provide the missing code //*~~~~~~~~~ <<Task 60>> ~~~~~~~~~ ***/
    for (int i = 1; i <= how_many_songs(); i++)
    {
        Song *c = Mpr::clone_song(storage[i - 1]);
        std::cout << "Playing song with id: " << i << std::endl;
        play_song(*c);
        delete c;
    }
}

// https://en.cppreference.com/w/cpp/string/basic_string/npos
// Find the first song whose title contains a substring <titleSubs> 
// If it is found, return its id (index + 1)
// otherwise return -1
// Hint: can use the find() function of the string class. 
int Mpr::find_song_id(const string &titleSubs) const
{
    /***  provide the missing code //*~~~~~~~~~ <Task 61> ~~~~~~~~~ ***/ 
    for(int i = 0; i < storage.size(); i++)
    {
        if(storage[i].title.find(titleSubs) != string::npos)
        {
            return i + 1;
        }
    }

    return -1;
}

int Mpr::how_many_songs() const {
    /***  provide the missing code  //*~~~~~~~~~ <Task 62> ~~~~~~~~~ ***/ 
    return storage.size();
}


// If the storage is not full, (limit is not reached), append a clone of the Song f into the storage (), and return the id of the added song (index + 1)
// Otherwise, return -1; 
int Mpr::add_song(const Song & f){
    /***  provide the missing code  //*~~~~~~~~~ <Task 63> ~~~~~~~~~  ***/
    if (storage.size() < limit)
    {
        Song *c = Mpr::clone_song(f);
        storage.push_back(*c);
        delete c;

        return storage.size();
        // storage[storage.size()] = *clone_song(f);
        // return storage.size();
    }
    else
    {
        return -1;
    }
}


// update backup as a clone of the storage of this object. When successful (the size of the clone is the same as the size of the storage), return true, otherwise, return false. 
// hint: should be quite simple. 
bool Mpr::clone_device_memory(vector<Song> & backup) const {
        /***  provide the missing code //*~~~~~~~~~ <Task 64> ~~~~~~~~~ ***/
    backup.clear();
    for (int i = 1; i <= how_many_songs(); i++)
    {
        backup.emplace_back(storage[i - 1]);
    }


    if (backup.size() == storage.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// replace the content of the storage with the content of <backup> 
// hint: can be quite simple. 
void Mpr::replace_device_memory(const vector<Song> & backup){
    /***  provide the missing code  //*~~~~~~~~~ <Task 65> ~~~~~~~~~  ***/
    storage.clear();
    for (int i = 1; i <= backup.size(); i++)
    {
        storage.emplace_back(backup[i - 1]);
    }

}

// https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
// If the song with id exists, delete from the storage and return true. 
// Othewise, return false. 
// hint: can use the erase() function of the vector class. 
bool Mpr::delete_song(int id){
    /***  provide the missing code  //*~~~~~~~~~ <Task 66> ~~~~~~~~~  ***/
    if (id >= 1 && id <= how_many_songs())
    {
        storage.erase(storage.begin() + id - 1);
        return true;
    }
    else
    {
        return false;
    }

}

//Empty the space of the storage.
// Hint: can be quite simple. 
bool Mpr::empty_device_memory(){
    /***  provide the missing code  //*~~~~~~~~~ <Task 67> ~~~~~~~~~  ***/
    storage.clear();
    if (storage.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

// Similar effect to the add_song function. 
Music_player & Mpr::operator+=(const Song& f){
     /***  provide the missing code  //*~~~~~~~~~ <Task 68> ~~~~~~~~~  ***/
     if (storage.size() < limit)
     {
         Song *c = Mpr::clone_song(f);
         storage.push_back(*c);
         delete c;
         return *this;
     }
     else
     {
        std::cout << "Failed to use += to add song" << std::endl;
        return *this;
     }
     
}




// If the id n is valid  (1 <= n <= number of songs in storage), return the song with the id. 
// Otherwise, throw n out   (throw is the the exception mechanism of C++)
Song & Mpr::operator[](int n) noexcept(false){
    /***  provide the missing code  //*~~~~~~~~~ <Task 69> ~~~~~~~~~  ***/
    if (n >= 1 && n <= how_many_songs())
    {
        return storage[n - 1];
    }
    else
    {
        throw n;
    }

}

/***  provide the missing definition of the function to overload the [] operator, the const version //*~~~~~~~~~ <Task 70> ~~~~~~~~~  ***/
const Song &Mpr::operator[](int n) const noexcept(false)
{
    if(n >= 1 && n <= how_many_songs())
    {
        return storage[n - 1];
    }
    else
    {
        throw n;
    }

}


/***  provide the missing definition to overloaded the << operator     //*~~~~~~~~~ <Task 71> ~~~~~~~~~  ***/
std::ostream &operator<<(std::ostream &os, const Music_player &player)//not a member function(attention)
{
    for (int i = 1; i <= player.how_many_songs(); i++)
    {
        Song *c = Mpr::clone_song(player.storage[i - 1]);

        os << "Playing song with id: " << i << std::endl;
        Mpr::play_song(*c);
        delete c;
    }
    return os;
}