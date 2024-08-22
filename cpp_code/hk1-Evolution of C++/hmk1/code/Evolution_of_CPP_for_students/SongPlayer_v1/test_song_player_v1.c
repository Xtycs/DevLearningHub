#include "song_player_v1.h"
#include "../Utility/util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int main(void)
{

    void *memClone = NULL;

    // Bytes bt1 ; // = {};

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

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    turn_on();

    printf(":) After turning on the device, there are %d songs in the it \n", how_many_songs());
    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    pause(); 

    add_song(s1);
    add_song(s2);
    add_song(s3);
    add_song(s4);
    add_song(s5);

    printf(":) After adding 5 songs,  there are %d songs in the it \n", how_many_songs());
    puts(":) Now, play all of them");
    pause();

    play_all_songs();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

    pause();
    puts(":) Please input a string, which is a substring of the title of a song to be found");
    {
        char name[80];
        fgets(name, 79, stdin);
        name[strlen(name) - 1] = '\0'; // replace \n with \0
        int idf;
        // scanf("%d",&id);
        idf = find_song_id(name);
        pause();
        if (idf != -1)
        {
            printf(":) The song is found, whose id is %d \n", idf);
        }
        else
            printf(":) The song is not found\n");
    }

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

    pause();

    puts(":) Now make a clone of the memory");
    pause();

    memClone = clone_device_memory();

    if(memClone != NULL){
        puts(":) A clone of the device memory is cloned sucessfully");
    }
    else
        puts(":) Making a clone of the device memory has failed ") ;

    pause();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

    puts(":) The song with ID 3 is :\n");
    play_song_by_id(3);

    {   
        Song *sp;
        Song *sc ; // a clone
        Boolean b = get_song_by_id(2, &sp);
        if(b == True){
            puts(":) The song with ID 2 is :\n");
            play_song(sp); 
            sc = clone_song(sp); 
            puts(":) The clone of the song with ID 2 is :\n");
            play_song(sc); 
            free(sc); // remember to free the space of the clone. 
        }
        else{
            printf(":) The song with id 2 is not found\n");
        }
    }

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

    pause(); 

    puts(":) Now, deleting the song with ID 3");
    delete_song(3);
    puts(":) After deleting the song 3, now the songs in the device are:");

    pause();

    play_all_songs();

    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

    puts(":) Replacing the memory with the clone");
    replace_device_memory(memClone);
    pause(); 

    puts(":) Now the songs in the device are: ");

    pause();

    play_all_songs();



    puts(":) ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

    pause(); 
    
    puts(":) Now turn off the device\n");

    /* responsible to clean the array of the clone array
     After calling replace_device_memory(memClone),
     the memory of the songs in the clone is shared by the storage of the device, 
     the these song's memory will be freed by the turn_off() function.
    */

    free(memClone); 

    turn_off();

    return 0;
}