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

// common C style interface: functions are listed in a .h file. 

/*
Concept of a song player (we may call it the device):
- It has a memory storage (like a tape or memory disk) that contain song records. 
- Each song has a different ID (an integer) in the device.
    * It is possible that the ID of of song may change, as long as at each moment its id is unique, it is fine.
- A song (the song record) can be added into the device, then an ID is assiciated to the song. 
- A song, described by its ID, can be deleted from the device using its ID. Then the ID is released and can be associated to some other song. 
- The ID of a song can be found using its title, 
- The information (authors, title, year) of a song (described by its ID) can be shown.
- A song, described by its ID, can be played.
- All the songs' IDs and associated information (authors, title, year) can be shown together. 
- The storage of device the can be cloned (like duplicating its tape)
- The storage of the device can be replaced by another storage (like changing its tape).
- The storage of the device can be fully deleted (like emptying the tape)
*/

#ifndef _SP_V1_H_
#define _SP_V1_H_

#include <stdio.h>
#include "../Utility/util.h"

/**
 A struct describe a song. 
 */
typedef struct song{
    char * title;    // name of the song
    char * authors;  // the name of the authors who wrote the song (or a piece of music) 
    char * actor; // the name of the singer(s), or the person played the music.
    int year;  // year of publication 
    Bytes media;   // the music file, could be .mp3 .wav ..., or a sequence of characters.  The play_song function should deal with the <media> properly. 
} Song;




// -----  Some general tools not related to a specific a player. -------

// make a clone of a Song. The space of the clone is allocated on the Heap.
Song *clone_song(const Song *s);

// play the song pointed to by the pointer sp. 
void play_song(const Song* sp); 


// --------- some functions related to one music player -----------------

// Prepare the device before using it. It can 
void turn_on(); 

// Call the function at the end of using the device. This function can do something like freeing the allocated space, close some file stream, etc.  
void turn_off(); 

// Play the song that has the id in the device
// If the song with the <id> is not found, or something wrong, return FALSE, 
// Otherwise, show the title, authors, actors, and year information. print the media as a sequence of characters. Return TRUE; 
Boolean play_song_by_id(int id);




// Play the songs one by one. Note the id of each song should be shown. 
void play_all_songs(void); 

/*   Find a (first) song whose title contains a substring <songTitle>. 
- If it found, its id in the device is returned
- If it is not found, then -1 is returned, which cannot be a valid id. 
- If songTitle describes an empty string, or start with a null character, or just a newline,  the song title should be ignored; thus, -1 is returned.  
*/
int find_song_id(const char * songTitle); 

/*
- Whe id is valid (1 <= id <= someLimit), make a clone of the song with id, and save the address of the clone at the space pointed to by spp, and return TRUE.
- When id is invalid, nothing is saved at the space pointed to by spp, and return FALSE. 
*/
Boolean get_song_by_id(int id, Song ** spp);

// return the number of songs records in the device.  
int how_many_songs(void); 

 // add a song into the memory of the player. Return an unique id (non-negative) of that song in the device.
 // return -1 if adding the song is not successful (when space is full). 
int add_song(Song  f) ; 

// return a clone of the memory (all song records of the device)
void * clone_device_memory(void) ;

// replace the memory of the device. 
/* the current memory of the device is emptied, and a clone of backup becomes the memory of the device */
void replace_device_memory(void * backup);

// Give an id of a song, remove the song from the device's memory.
// return TRUE if operation is successful, 
// otherwise, if the id is invalid, or no song with the id exists, return FALSE; 
Boolean delete_song(int id) ;   

void empty_device_memory(void); // remove (release the storage space) of all songs in the device (  the function should also be called when the device will not be used)

#endif
