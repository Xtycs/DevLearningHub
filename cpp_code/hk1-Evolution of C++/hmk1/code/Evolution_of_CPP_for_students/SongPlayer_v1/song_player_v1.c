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


#include "song_player_v1.h"
#include "../Utility/util.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

#define SIZE_LIMIT 200

// ................ functions not bound to a music player .....................

void play_song(const Song* sp){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 8> ~~~~~~~~~  ***/
    printf("Title: %s\n", sp->title);
    printf("Authors: %s\n", sp->authors);
    printf("Actor: %s\n", sp->actor);
    printf("Year: %d\n", sp->year);
    printf("Media: %s\n", sp->media.addr);
}

Song * clone_song(const Song * s){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 9> ~~~~~~~~~  ***/
    Song *clone = (Song *)malloc(sizeof(Song));
    if (clone == NULL)
    {
        printf("Memmory allocation faild");
        exit(1);
    }
    clone->title = clone_str(s->title);//can't only use s->title,or thy share the same memory
    clone->authors = clone_str(s->authors);
    clone->actor = clone_str(s->actor);
    clone->year = s->year;
    clone->media = make_bytes(clone_str(s->media.addr), s->media.len);
    return clone;
}

// .................. Code related to one music player ....................

// An array of pointers to Song records, where each Song record is allocated on the Heap. 
static  Song * songBase[SIZE_LIMIT] = {NULL}; 


// The number of songs existing in the songBase. When a song is added into the songBase, songNum should + 1. When a song is deleted, songNum should - 1. 
static  int songNum = 0;



// The preparation task. May just print a welcome message 
void turn_on(){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 10> ~~~~~~~~~  ***/
    printf("Welcome use the song player made by Tingyang Xie\n");

}


// Empty the meory of the device and say good by
void turn_off(void){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 11> ~~~~~~~~~  ***/
    empty_device_memory();
    printf("Goodbye\n");

}


//An id starts with 1, not 0.  A song with n is at songBase[n-1]
// A song with id n exists if songBase[n-1] != NULL. 
Boolean play_song_by_id(int id){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 12> ~~~~~~~~~  ***/
    if (id < 1 || id > SIZE_LIMIT || songBase[id - 1] == NULL)
    {
        printf("The song is not found\n");
        return False;
    }
    else
    {
        printf("Playing song with id %d\n",id);
        play_song(songBase[id - 1]);
        return True;
    }
}

// Play all songs in songBase. Ignore a songBase[x] if sonbBase[x] is NULL, i.e. the song with id x+1 does not exists
void play_all_songs(void){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 13> ~~~~~~~~~  ***/
    for (int i = 0; i < SIZE_LIMIT;i++)
    {
        if (songBase[i] != NULL)
        {
            printf("<<$$&&&<<Playing song with id %d >>&&&$$>>\n", i + 1);
            play_song(songBase[i]);
        }
        // else
        // {
        //     break;
        // }
    }
} 

// Hint:: can use the strstr library function
/*   Find a (first) song whose title contains a substring <songTitle>. 
- If it found, its id in the device is returned
- If it is not found, then -1 is returned, which cannot be a valid id. 
- If songTitle describes an empty string, or start with a null character, or just a newline,  the song title should be ignored; thus, -1 is returned.  
*/
int find_song_id(const char * songTitle){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 14> ~~~~~~~~~  ***/
    if (songTitle == NULL || songTitle[0] == '\0' || songTitle[0] == '\n')
    {
        return -1;
    }
    for (int i = 0; i < SIZE_LIMIT; i++)
    {
        if (songBase[i] != NULL && strstr(songBase[i]->title, songTitle) != NULL)
        {
            return i + 1;
        }
    }
    return -1;
}

// Note: a clond of song (when it is found) and made and the address of clone is saved at *spp. 
/*
- Whe id is valid (1 <= id <= someLimit), make a clone of the song with id, and save the address of the clone at the space pointed to by spp, and return TRUE.
- When id is invalid, nothing is saved at the space pointed to by spp, and return FALSE. 
*/
Boolean get_song_by_id(int id, Song ** spp){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 15> ~~~~~~~~~  ***/
    if (id < 1 || id > SIZE_LIMIT || songBase[id - 1] == NULL)
    {
        return False;
    }
    else
    {
        *spp = clone_song(songBase[id - 1]);
        return True;
    }
}

// return the current number of songs in songBase. 
int how_many_songs(void){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 16> ~~~~~~~~~  ***/
    int count = 0;
    for (int i = 0; i < SIZE_LIMIT; i++)
    {
        if (songBase[i] != NULL)
        {
            count++;
        }
    }
    return count;
}

// return the addrss of a clone of songBase. Note, each song should be cloned and put in the allocated array. 
void * clone_device_memory(void) {
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 17> ~~~~~~~~~  ***/
    Song **clone = (Song **)malloc(SIZE_LIMIT * sizeof(Song));//every element int the array is a pointer to a song
    if (clone == NULL)
    {
        printf("Memmory allocation faild");
        exit(1);
    }
    for (int i = 0; i < SIZE_LIMIT; i++)
    {
        if (songBase[i] != NULL)
        {
            clone[i] = clone_song(songBase[i]);
        }
        else
        {
            clone[i] = NULL;
        }
    }
    return clone;
}

// add a clone of the song f into the songBases of the player. Return an unique id of that song in the device (if index is n, id is n+1)
// return -1 if songBase is full and has no space to add a song. 
int add_song(Song  f){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 18> ~~~~~~~~~  ***/
    for (int i = 0; i < SIZE_LIMIT; i++)
    {
        if (songBase[i] == NULL)
        {
            songBase[i] = clone_song(&f);//don't use &f, it will cause the songBase[i] and f share the same memory
            songNum++;
            return i + 1;
        }
    }
    return -1;
}

// empty the mory of songBase, and replace its content with that of the the back up. 
// remember to update songNum
// Maybe no need to make clone of each song in backup, as long as no trouble is made, and finally all allocated space will be freed, it is fine. 
void replace_device_memory(void * backup){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 19> ~~~~~~~~~  ***/
    empty_device_memory();
    songNum = 0;
    if (backup != NULL)
    {
        for (int i = 0; i < SIZE_LIMIT; i++)
        {
            if(((Song**)backup)[i] != NULL)
            {
                songBase[i] = clone_song(((Song**)backup)[i]);//change it from void* to Song**, more flexible
                songNum++;
            }
            else
            {
                songBase[i] = NULL;
            }
        }
    }
}

// If a song with a give id is found, remove the song from the device (the space allocated in the song should be freed).
// Note that the space of <title>, <authors>, <actors>, addr in media, are all allocated on the Heap. So does the space of a song recorded in songBase.  
Boolean delete_song(int id)
{
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 20> ~~~~~~~~~  ***/
    if (id < 1 || id > SIZE_LIMIT || songBase[id - 1] == NULL)
    {
        return False;
    }
    else
    {
        free(songBase[id - 1]->title);
        free(songBase[id - 1]->authors);
        free(songBase[id - 1]->actor);
        free(songBase[id - 1]->media.addr);
        free(songBase[id - 1]);
        songBase[id - 1] = NULL;
        songNum--;
        return True;
    }
}


void empty_device_memory(void){
    /***   provide the missing clode  here    ~~~~~~~~~ <Task 21> ~~~~~~~~~  ***/
    for (int i = 0; i < SIZE_LIMIT; i++)
    {
        if (songBase[i] != NULL)
        {
            free(songBase[i]->title);
            free(songBase[i]->authors);
            free(songBase[i]->actor);
            free(songBase[i]->media.addr);
            free(songBase[i]);//songBase[i] is a pointer to a song which is allocated on the heap
            printf("The song with id %d is deleted\n", i + 1);
        }
    }
    songNum = 0;
}