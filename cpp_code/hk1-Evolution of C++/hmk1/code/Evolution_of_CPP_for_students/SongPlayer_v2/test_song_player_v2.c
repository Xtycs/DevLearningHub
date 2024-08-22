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

#include "song_player_v2.h"
#include "../Utility/util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for free()

// just need the two turn_on functions. 

extern void turn_on_1(Music_player * self); 

extern void turn_on_2(Music_player * self); 

int main(void)
{

    void *storageClone = NULL;

    Music_player p1, p2; 

    const char *t1 = "Empty your mind. Be formless. Shapeless. Like water. You put water into a cup, it becomes the cup. You put water into a bottle, it becomes the bottle. You put it in a teapot, it becomes the teapot. Water can flow, or it can crash. Be water, my friend.\n";

    Song s1 = {clone_str("Be water my friend"),
               clone_str("Bruce Lee"),
               clone_str("Lee Fans"),
               1970,
               make_bytes(clone_str(t1), strlen(t1) + 1)};

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
               make_bytes(clone_str(t2), strlen(t2) + 1)};

    const char *t3 = "Every night in my dreams\n"
                     "I see you, I feel you\n"
                     "That is how I know you go on\n";

    Song s3 = {clone_str("My Heart Will Go On"),
               clone_str("James Horner, Will Jennings"),
               clone_str("Celine Dion"),
               1998,
               make_bytes(clone_str(t3), strlen(t3) + 1)};

    const char *t4 = "Girl, close your eyes. \n"
                     "Let that rhythm get into you.\n"
                     "Don\'t try to fight it. \n"
                     "There ain\'t nothin' that you can do. \n"
                     "Relax your mind.\n";

    Song s4 = {clone_str("Rock with your"),
               clone_str("Rod Temperton, Quincy Jones"),
               clone_str("Michael Jackson"),
               1979,
               make_bytes(clone_str(t4), strlen(t4) + 1)};

    const char *t5 = " Twinkle twinkle little star.\n How I wonder what you are.\n above the world so high.\n Like a diamond in the sky.\n Twinkle twinkle little star.\n How I wonder what you are.\n";

    Song s5 = {clone_str("Twinkle twinkle little star"),
               clone_str("Jane Taylor, Wolfgang Amadeus Mozart"),
               clone_str("A boy"),
               1806,
               make_bytes(clone_str(t5), strlen(t5) + 1)};

    // ready to use the song player.

    p1.turn_on = turn_on_1;  
    p2.turn_on = turn_on_2; 
    
    p1.turn_on(&p1); 
    p2.turn_on(&p2); 

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    printf(":) After turning on the two player, there are %d songs in Player 1, and %d songs in Player 2. \n", p1.how_many_songs(&p1), p2.how_many_songs(&p2));

    pause(); 
    // add two songs into p1
    p1.add_song(&p1, s1);
    p1.add_song(&p1, s2);
    puts(":) Two songs are added into player 1 ");

    // add three songs into p2
    p2.add_song(&p2,s3);
    p2.add_song(&p2, s4);
    p2.add_song(&p2, s5);
    puts(":) Two songs are added into player 2 ");
    pause();

    printf(":) After adding some songs, Player 1 has   %d songs, and Player 2 has %d songs  \n", p1.how_many_songs(&p1), p2.how_many_songs(&p2));
    pause();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Now, play all the songs in Player 1:");
    pause();

    p1.play_all_songs(&p1);

    pause();
    puts(":) Now, play all the songs in Player 2:");
    pause();
    p2.play_all_songs(&p2);

    pause(); 

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Please input a string, which is a substring of the title of a song to be found in Player 1");
    {
        char name[80];
        fgets(name, 79, stdin);
        name[strlen(name) - 1] = '\0'; // replace \n with \0
        int idf;
        // scanf("%d",&id);
        idf = p1.find_song_id(&p1, name);
        pause();
        if (idf != -1)
        {
            printf(":) The song is found, whose id is %d \n", idf);
        }
        else
            printf(":) The song is not found\n");
    }

    
    pause();
    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Now make a clone of Player 2");
    pause();

    storageClone = p2.clone_device_memory(&p2);

    if(storageClone != NULL){
        puts(":) A clone of the device memory is cloned sucessfully");
    }
    else
        puts(":) Making a clone of the device memory has failed ") ;

    pause();
    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) The song with ID 3 in Player 2 is :\n");
    p2.play_song_by_id(&p2, 3);
    pause();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
       {   
        Song *sp;
        Song *sc ; // a clone of the song to be found
        Boolean b = p2.get_song_by_id(&p2, 2, &sp);
        if(b == True){
            puts(":) The song with ID 2 in Player 2 is :\n");
            play_song(sp); 
            sc = clone_song(sp); 
            puts(":) The clone of the song with ID 2 is :\n");
            play_song(sc); 
            free(sc); // remember to free the space of the clone. 
        }
        else{
            printf(":) The song with id 2 is not found in player 2\n");
        }
    }
    pause();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Now, deleting the song with ID 3 from player 2");
    pause();
    p2.delete_song(&p2, 3);
    puts(":) After deleting the song 3, now the songs in Player 2 are:");
    pause();
    p2.play_all_songs(&p2);

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Replacing the memory of P1 by the earlier clone of P2");
    pause(); 
    p1.replace_device_memory(&p1, storageClone);
    puts(":) Now the songs in Player 1 are: ");

    pause();

    p1.play_all_songs(&p1);

    pause(); 
    
    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Now turn off the player P2\n");
    p1.turn_off(&p1); 
    pause();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    puts(":) Now turn off the player P2\n");
    p2.turn_off(&p2); 

    return 0;
}