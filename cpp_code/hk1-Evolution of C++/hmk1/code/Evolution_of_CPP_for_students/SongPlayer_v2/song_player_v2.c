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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song_player_v2.h"
#include "../Utility/util.h"


#define _LIMIT 200


// -----  Some general tools not related to a specific a player. -------

// no need to provide the definition of clone_song and play_song. Can use the definitions of these functions in song_player_v1.c. 
// When compile, link with the file song_player_v1.o
//Song * clone_song(Song s);

//play the song pointed to by the pointer sp.
// void play_song(const Song *sp);


// The memory of song player is implemented as a linked list. 

typedef struct songNode
{
    Song * song;
    struct songNode * next;
    struct songNode * prev;
} SongNode;

typedef struct _storage
{
    int songNum;    // number of songs, also the number of nodes in the list.
    SongNode *head; // address of the first node of the list.
    SongNode *tail; // address of the last node of the list.
    int limit; // max number of songs in the device. 
} Storage;

// The tool functions that can be used by different music players. 
// some functions have two versions; They are used to show that different music player can have different member functions. 

// the turn on functions need to publicly available. 
void turn_on_1(Music_player *self);
void turn_on_2(Music_player *self);



static void turn_off_1(Music_player * self);
static void turn_off_2(Music_player * self);

static Boolean play_song_by_id_1(Music_player * self, int id);
static Boolean play_song_by_id_2(Music_player * self, int id);
static void play_all_songs_1(Music_player * self);
static void play_all_songs_2(Music_player * self);
static int find_song_id(Music_player * self, const char *songTitle);
static int how_many_songs(Music_player * self);
static Boolean get_song_by_id(Music_player *self, int id, Song **spp);
static int add_song_to_storage(Storage * sp, Song f);
static Boolean delete_song(Music_player* self, int id);
static int add_song(Music_player * self, Song f);
static void *clone_device_memory(Music_player * self);
static void replace_device_memory(Music_player * self, void * backup);
static void empty_device_memory(Music_player* self);

//static const char * welcome_msg = NULL; 

static void turn_on_helper(Music_player *self){
    Storage *sp = (Storage *)malloc(sizeof(Storage));
    sp->head = sp->tail = NULL;
    sp->songNum = 0;
    sp->limit  = _LIMIT; 
    self->storage = sp;
    self->turn_on = turn_on_1; 
    self->turn_off = turn_off_1; 
    self->add_song = add_song; 
    self->clone_device_memory = clone_device_memory; 
    self->delete_song = delete_song;
    self->empty_device_memory = empty_device_memory; 
    self->find_song_id = find_song_id; 
    self->get_song_by_id = get_song_by_id; 
    self->how_many_songs = how_many_songs; 
    self->play_song_by_id = play_song_by_id_1; 
    self->play_all_songs = play_all_songs_1; 
    // self->play_song = play_song_1; 
    self->replace_device_memory = replace_device_memory; 
}

void turn_on_1(Music_player *self)
{
    // SongNode * head = malloc(sizeof(SongNode));
    puts(":) ~~~~~~~~ One device is turned on. Welcome, enjoy the Song Player made by HuaWei ! ~~~~~~~~~~~~~~~~~");
    turn_on_helper(self); 
}

void turn_on_2(Music_player *self){
    const char * welcome_msg =":) .......... One device is turned on...... turn on the player in my way like OpenAI ......";
    puts(welcome_msg); 
    turn_on_helper(self); 
    // same as turn_on_1, but some methods are different. 
    self->turn_on = turn_on_2; 
    self->turn_off = turn_off_2; 
    self->play_song_by_id  = play_song_by_id_2; 
    self->play_all_songs = play_all_songs_2;  
}


// empty all the space and say some goodby message that is different from turn_off_2.  if there is some clone made, empty the clone also.
static void turn_off_1(Music_player * self)
{
  /***    provide the missing clode  here    ~~~~~~~~~ <Task 27> ~~~~~~~~~  ***/
  empty_device_memory(self);
  puts("~~~~~~~~~~From Huawei:  Bye Bye ~~~~~~~~~~~~~");
}

// empty all the space and say some goodby message that is different from turn_off_1. 
static void turn_off_2(Music_player * self)
{   
    /***    provide the missing clode  here    ~~~~~~~~~ <Task 28> ~~~~~~~~~  ***/
    empty_device_memory(self);
    puts("~~~~~~~~~~From OpenAI:  Bye Bye ~~~~~~~~~~~~~");
}

//If the <id> is valid ( 1<=id <= NumberOfSongs), then play the song and return TRUE; 
//Otherwise, say some message that the id is invlid, and return FALSE
static Boolean play_song_by_id_1(Music_player * self, int id)
{
/***    provide the missing clode  here    ~~~~~~~~~ <Task 29> ~~~~~~~~~  ***/
    if (id >= 1 || id <= how_many_songs(self))
    {
        Song *sp = NULL;
        Boolean result = get_song_by_id(self, id, &sp);
        if (result == True)
        {
            printf("Playing song with id %d\n",id);
            play_song(sp);
            return True;
        }
        else
        {
            printf("The song with id %d does not exist.\n", id);
            return False;
        }
    }
    else
    {
        puts("Invalid id.");
        return False;
    }
}



static Boolean play_song_by_id_2(Music_player * self, int id){
    puts(":) ...... Play the song in my way ......");
    return play_song_by_id_1(self, id); 
}

static void play_all_songs_1(Music_player * self)
{
/***    provide the missing clode  here    ~~~~~~~~~ <Task 30>~~~~~~~~~  ***/
    for (int i = 1; i <= how_many_songs(self); i++)
    {
        play_song_by_id_1(self, i);
    }
    // Song **songs = (Song **)self->storage;
    // for (int i = 0; i < how_many_songs(self); i++)
    // {
    //     if (songs[i] != NULL)
    //     {
    //         play_song(songs[i]);
    //     }
    // }
}

    



static void play_all_songs_2(Music_player * self){
    puts("...... Play all the songs in my way ......");
    play_all_songs_1(self); 
}

// return the id of the first song whose title contails a substring <songTitle>
// When no such song is found, return -1. 
static int find_song_id(Music_player * self, const char *songTitle)
{
    /***    provide the missing clode  here    ~~~~~~~~~ <Task 31> ~~~~~~~~~  ***/
    if(songTitle == NULL || songTitle[0] == '\0' || songTitle[0] == '\n')
    {
        return -1;
    }


    for (int id = 1; id <= how_many_songs(self); id++)
    {
        Song *sp = NULL;
        if (get_song_by_id(self, id, &sp) == True)
        {
            if (strstr(sp->title, songTitle) != NULL)
            {
                return id;
            }
        }
        else
        {
            return -1;
        }
    }
}

static int how_many_songs(Music_player * self)
{   
    /***    provide the missing clode  here    ~~~~~~~~~ <Task 32> ~~~~~~~~~  ***/
    int count = 0;
    Storage *sp = (Storage *)self->storage;
    count = sp->songNum;
    return count;
}

// the song with <id> exists, create a clone of the song and save the address of the clone at * spp, and return TRUE. Otherwise, when the song with <id> does not exists, return FALSE, and no change is made to the space pointed to by spp. 
static Boolean get_song_by_id(Music_player *self, int id, Song **spp){
    /***    provide the missing clode  here    ~~~~~~~~~ <Task 33> ~~~~~~~~~  ***/
    Storage *sp = (Storage *)self->storage;
    if (id < 1 || id > how_many_songs(self))
    {
        return False;
    }
    else
    {
        SongNode *current = sp->head;
        for (int i = 1; i < id; i++)
        {
            current = current->next;
        }
        *spp = clone_song(current->song);
        return True;
    }
 }

// add a clone of a song f to the end of the list in the storage sp
// if successful, return the number of songs in sp after adding the clone of the song f. 
// otherwise, when fail, return -1. 
// Note, a songNode containing a clone of the Song f will be appended to the linked list of the storage sp. 
static int add_song_to_storage(Storage * sp, Song f){
    /***    provide the missing clode  here    ~~~~~~~~~ <Task 34> ~~~~~~~~~  ***/
    if (sp->songNum >= sp->limit)
    {
        return -1;
    }

    Song *clone = clone_song(&f);
    SongNode *newNode = (SongNode *)malloc(sizeof(SongNode));
    if(clone == NULL || newNode == NULL)
    {
        return -1;
    }
    

    newNode->song = clone;
    newNode->prev = sp->tail;
    newNode->next = NULL;

    if (sp->head == NULL)
    {
        sp->head = newNode;
    }
    else{
        sp->tail->next = newNode;
    }
    sp->tail = newNode;
    sp->songNum++;

    return sp->songNum;
}

// add a clone of a song f to the end of the list in the storage of of <self> 
// if successful, return the updated number of songs in sp after adding the clone of the song f. The id of a song is the sequential number of the song in the list, starting with 1. 
// otherwise, when fail, return -1. 
static int add_song(Music_player * self, Song f)
{
    /***    provide the missing clode  here    ~~~~~~~~~ <Task 35> ~~~~~~~~~  ***/
    Storage *sp = (Storage *)self->storage;
    return add_song_to_storage(sp, f);
    
}



// return a deep copy of the storage of of music_player. The whole linked list is cloned. 
static void * clone_device_memory(Music_player * self)
{
   /***    provide the missing clode  here    ~~~~~~~~~ <Task 36> ~~~~~~~~~  ***/
   Storage *original = (Storage *)self->storage;
   Storage *clone = (Storage *)malloc(sizeof(Storage));
   if(clone == NULL)
   {
       return NULL;
   }

   clone->songNum = original->songNum;
   clone->limit = original->limit;
   clone->head = NULL;
   clone->tail = NULL;

   SongNode *current = original->head;
   while (current != NULL)
   {
       Song *cloneSong = clone_song(current->song);
       SongNode *newNode = (SongNode *)malloc(sizeof(SongNode));
       if(cloneSong == NULL || newNode == NULL)
       {
        free(clone);
           return NULL;
       }
       

       newNode->song = cloneSong;
       if (clone->head == NULL)//first time come into the loop
       {
           clone->head = newNode;
           clone->tail = newNode;
           newNode->prev = NULL;
           newNode->next = NULL;
       }
       else
       {
           newNode->prev = clone->tail;
           newNode->next = NULL;
           clone->tail->next = newNode;
           clone->tail = newNode;
       }

       current = current->next;
   }
   return clone;//this clone is a backup of the storage of the music player
}



static void replace_device_memory(Music_player * self, void * backup)
{
    // empty the storage of the device    
    self->empty_device_memory(self); 
    self->storage = backup;  // directly plug-in the backup
}

// When the song with the id exists remove the song from the device (the space of the songNode, ) , return TRUE, otherwise 
static Boolean delete_song(Music_player* self, int id)
{
   /***    provide the missing clode  here   ~~~~~~~~~  <Task 37> ~~~~~~~~~ ***/
   if(id < 1 || id > how_many_songs(self))
   {
       return False;
   }


   Storage *sp = (Storage *)self->storage;
   SongNode *current = sp->head;
   for (int i = 1; i < id; i++)
   {
       current = current->next;
   }

   if (current->prev == NULL)
   {
       current->next->prev = NULL;
       sp->head = current->next;
       current->next = NULL;
   }
   else if (current->next == NULL)
   {
       current->prev->next = NULL;
       sp->tail = current->prev;
       current->prev = NULL;
   }
   else
   {
       current->prev->next = current->next;
       current->next->prev = current->prev;
       current->prev = NULL;
       current->next = NULL;
   }

   free_song(current->song);
   free(current);
   sp->songNum--;

   return True;
}

// Emtpy the device memory. Better show some message like how many songs are deleted. 
static void empty_device_memory(Music_player* self)
{
    /***    provide the missing clode  here    ~~~~~~~~~ <Task 38>~~~~~~~~~  ***/
    Storage *sp = (Storage *)self->storage;
    SongNode *current = sp->head;
    int count = 0;
    while (current != NULL)
    {
        SongNode *temp = current->next;
        free_song(current->song);
        free(current);
        current = temp;
        count++;
    }

    sp->head = NULL;
    sp->tail = NULL;
    sp->songNum = 0;
    printf("The device memory is emptied. %d songs are deleted.\n", count);
}

void free_song(Song* song) 
{
    free(song->title);  
    free(song->authors);
    free(song->actor);  
    free(song->media.addr);  
    free(song); 
}
