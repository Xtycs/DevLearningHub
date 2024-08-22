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


// Class-like C style interface: functions are listed as members  (function-pointers) in a struct .

/*
Concept of a song player is the same as described in song_player_v1.h
*/

#ifndef _SP_V2_H_
#define _SP_V2_H_

#include <stdio.h>
#include "../Utility/util.h"

/**
 A struct describe a song.
 */
typedef struct song
{
    char *title;   // name of the song
    char *authors; // the name of the authors who wrote the song (or a piece of music)
    char *actor;   // the name of the singer(s), or the person played the music.
    int year;      // year of publication
    Bytes media;   // the music file, could be .mp3 .wav ..., or a sequence of characters.  The play_song function should deal with the <media> properly.
} Song;

typedef struct music_player Music_player;

// -----  Some general tools not related to a specific a player. -------

// make a clone of a Song. The space of the clone is allocated on the Heap.
Song *clone_song(const Song *s);

// play the song pointed to by the pointer sp.
void play_song(const Song *sp);
void free_song(Song *s);

// ------------------- code for a music player ------------------

struct music_player
{
    void *storage; // songs are stored here in someway.

    /*!!!!!!!
        In all the following functions, the parameter, Music_player * self, means that the corresponding argument is the address of the struct on which the function is called.
        For example:
        x.how_many_songs(&x);
    */

    // Prepare the device before using it. Its storage can be initialized.
    void (*turn_on)(Music_player *self);

    // Call the function at the end of using the device. This function can do something like freeing the allocated space, close some file stream, etc.
    void (*turn_off)(Music_player *self);

    // Play the song that has the id in the device
    // If the song with the <id> is not found, or something wrong, return FALSE, Otherwise, return TRUE;
    Boolean (*play_song_by_id)(Music_player *self, int id);

    // Play all songs in the device.
    void (*play_all_songs)(Music_player *self);

    /*   Find a song whose title contains a substring <songTitle>.
  - If it found, its id in the device is returned
  - If it is not found, then -1 is returned, which cannot be a valid id.
  - If songTitle describes an empty string, or just a newline,  the song title should be ignored; thus, -1 is returned.
  */
    int (*find_song_id)(Music_player *self, const char *songTitle);

    /*
   - Whe id is valid (1 <= id <= number_of_songs), make a clone of the song with id, and save the address of the clone at the space pointed to by spp, and return TRUE.
   - When id is invalid, nothing is saved at the space pointed to by spp, and return FALSE.
   */
    Boolean (*get_song_by_id)(Music_player *self, int id, Song **spp);

    // return the number of songs recorded in the device.
    int (*how_many_songs)(Music_player *self);

    // add a song into the data bases of the player. Return an unique id (non-negative) of that song in the device.
    // return -1 if adding the song is not successful.
    //
    /*** Declartion statement of function pointer member add_song
     *    provide the missing clode  here    ~~~~~~~~~ <Task 22> ~~~~~~~~~  ***/
    int (*add_song)(Music_player *self, const Song s);

    // return a clone of the memory (all song records of the device)
       /*** Declartion statement of function pointer member clone_device_memory
     *    provide the missing clode  here   ~~~~~~~~~  <Task 23> ~~~~~~~~~  ***/
    void * (*clone_device_memory)(Music_player *self);

    // replace the memory of the device.
    /* the memory of the device is emptied, and a clone of backup becomes the memory of the device */
    /*** Declartion statement of function pointer member replace_device_memory
     *    provide the missing clode  here   ~~~~~~~~~  <Task 24> ~~~~~~~~~  ***/
    void (*replace_device_memory)(Music_player *self, void *backup);

    // Give an id of a song, remove the song from the device's memory. All the space of the song is freeed. 
    // return TRUE if operation is successful, otherwise ( when no song with id exists), return FALSE;
      /*** Declartion statement of function pointer member delete_song
     *    provide the missing clode  here    ~~~~~~~~~ <Task 25> ~~~~~~~~~  ***/
    void (*delete_song)(Music_player *self, int id);

    // Remove (release the storage space) of all songs in the device ( call the function when the device will be turned off)
    /*** Declartion statement of function pointer member delete_song
     *    provide the missing clode  here     ~~~~~~~~~ <Task 26> ~~~~~~~~~  ***/
    void (*empty_device_memory)(Music_player *self);
};

#endif
