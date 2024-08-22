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

#include "song_player_v3.h"         /*  ??? <-----    proide a missing line here   //*~~~~~~~~~ <Task 72> ~~~~~~~~~ */
#include <cstdio> 
#include <cstring> 
typedef Music_player Mpr; 

extern "C"{
    #include "../Utility/util.h"
};

int main(void)
{
    Mpr p1, p2; 
    using std::cout; 
    using std::cin;
    using std::endl; 

    const char *t1 = "Empty your mind. Be formless. Shapeless. Like water. You put water into a cup, it becomes the cup. You put water into a bottle, it becomes the bottle. You put it in a teapot, it becomes the teapot. Water can flow, or it can crash. Be water, my friend.\n";

    Song s1 = {clone_str("Be water my friend"),
               clone_str("Bruce Lee"),
               clone_str("Lee Fans"),
               1970,
               util2::Bytes(clone_str(t1), strlen(t1) + 1)};

    const char *t2 = "Wise men say\n"
                     "Only fools, only fools rush in\n"
                     "Oh, but I, but I, I can\'t help falling in love with you\n"
                     "Shall I stay?\n"
                     "Would it be, would it be a sin\?\n"
                     "If I can\'t help falling in love with you\n";

    Song s2 = {clone_str("Can\'t Help Falling in Love"),
               clone_str("Hugo Peretti, Luigi Creatore, and George David Weiss "),
               clone_str("Elvis Presley"),
               1961,
               util2::Bytes(clone_str(t2), strlen(t2) + 1)};

    const char *t3 = "Every night in my dreams\n"
                     "I see you, I feel you\n"
                     "That is how I know you go on\n";

    Song s3 = {clone_str("My Heart Will Go On"),
               clone_str("James Horner, Will Jennings"),
               clone_str("Celine Dion"),
               1998,
               util2::Bytes(clone_str(t3), strlen(t3) + 1)};

    const char *t4 = "Girl, close your eyes. \n"
                     "Let that rhythm get into you.\n"
                     "Don\'t try to fight it. \n"
                     "There ain\'t nothin' that you can do. \n"
                     "Relax your mind.\n";

    Song s4 = {clone_str("Rock with your"),
               clone_str("Rod Temperton, Quincy Jones"),
               clone_str("Michael Jackson"),
               1979,
               util2::Bytes(clone_str(t4), strlen(t4) + 1)};

    const char *t5 = " Twinkle twinkle little star.\n How I wonder what you are.\n above the world so high.\n Like a diamond in the sky.\n Twinkle twinkle little star.\n How I wonder what you are.\n";

    Song s5 = {clone_str("Twinkle twinkle little star"),
               clone_str("Jane Taylor, Wolfgang Amadeus Mozart"),
               clone_str("A boy"),
               1806,
               util2::Bytes(clone_str(t5), strlen(t5) + 1)
               };

    // ready to use the song player.

    //p1.turn_on = turn_on_1;  
    //p2.turn_on = turn_on_2; 
    
    //p1.turn_on(&p1); 
    //p2.turn_on(&p2); 

    cout<< ":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<< endl;
    cout << ":) After turning on the two player, there are " << p1.how_many_songs() << " songs in Player 1, and " << p2.how_many_songs() << " songs in Player 2. \n"; 
    pause(); 
    // add two songs into p1
    p1.add_song(s1);
    p1.add_song(s2);
    cout << ":) Two songs are added into player 1 \n";

    // add three songs into p2
    ((p2 += s3) += s4) += s5; 
    //p2.add_song(s4);
    //p2.add_song(s5);
    puts(":) Three songs are added into player 2 using operator+= ");
    pause();

    cout <<":) After adding some songs, Player 1 has " <<  p1.how_many_songs() <<  " songs, and Player 2 has "<<  p2.how_many_songs() << " songs  \n";
    pause();

   cout <<":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << ":) Now, play all the songs in Player 1:" << endl; 
    pause();

    p1.play_all_songs();

    pause();
    cout << ":) Now, play all the songs in Player 2:" << endl ;
    pause();
    p2.play_all_songs();

    pause(); 

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Please input a string, which is a substring of the title of a song to be found in Player 1");
    {
        char name[80] = {0};
        std::cin.getline(name, 80-1); 
        //fgets(name, 79, stdin);
        //name[strlen(name) - 1] = '\0'; // replace \n with \0
        int idf;
        // scanf("%d",&id);
        idf = p1.find_song_id(name);
        pause();
        if (idf != -1)
        {
            printf(":) The song is found, whose id is %d \n", idf);
        }
        else
            printf(":) The song is not found\n");
    }

    
    pause();
    cout << ":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << ":) Now make a clone of Player 2" << endl;
    pause();

    vector<Song> storageClone;
    bool result = p2.clone_device_memory(storageClone);

    if(result != false){
        puts(":) A clone of the device memory is cloned sucessfully");
    }
    else
        puts(":) Making a clone of the device memory has failed ") ;

    pause();
    cout << ":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl; 
    puts(":) The song with ID 3 in Player 2 is :\n");
    p2.play_song_by_id(3);
    pause();

    cout << ":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
       {   
        Song s;
        Song * sc ; // a clone of the song to be found
        try{
            s = p2[2]; 
        //if(b == TRUE){
            puts(":) The song with ID 2 in Player 2 is (testing operator [] ):\n");
            Mpr::play_song(s); 
            sc = Mpr::clone_song(s); 
            puts(":) The clone of the song with ID 2 is :\n");
            Mpr::play_song(*sc); 
            delete(sc); // remember to  delete the space of the clone. 
        }
        catch(int n){
            std::cout<<"The id " << n << " is invalid\n";
        }
    }
    pause();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Now, deleting the song with ID 3 from player 2");
    pause();
    p2.delete_song( 3);
    puts(":) After deleting the song 3, now the songs in Player 2 are (testing the operator<<):");
    pause();
    std::cout << p2;

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Replacing the memory of P1 by the earlier clone of P2");
    pause(); 
    p1.replace_device_memory(storageClone);
    puts(":) Now the songs in Player 1 are: ");

    pause();

    p1.play_all_songs();

    pause(); 
    {
        /* ??? */ 
        try{   // provide the missing code on the LHS of {   //*~~~~~~~~~ <Task 73> ~~~~~~~~~
        const Mpr p3 = p1;
        cout <<" P3 is a copy of p1. The song with id 1 in p3 is " << endl ; 
        Mpr::play_song(p3[1]);  // test the const version of operator[]; 
        cout << "  The song with id -1 in p3 is (testing const [])" << endl; 
        Mpr::play_song(p3[-1]); 
        }
        
        /* ??? */ //! need to deal with the error
        catch(const int& InvalidId )
        { // provide the missing code on the LHS of {   //*~~~~~~~~~ <Task 74> ~~~~~~~~~
            int n = -1;
            cout << "The id " << n << " is invalid " << endl;
        }
    }
    cout << ":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl; 
    cout << ":) Now the players p1 and p2 are ready to turn off " << endl; 
    return 0;
}