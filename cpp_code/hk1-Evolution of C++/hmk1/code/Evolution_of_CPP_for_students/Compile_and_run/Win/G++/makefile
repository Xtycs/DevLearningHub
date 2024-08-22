# has to use gcc, not g++, to compile util.c, if functions defined util.c will be used as some C function in a .cpp file. 

util.o:  ../../../Utility/util.c
	gcc -c ../../../Utility/util.c

test_util.o: ../../../Utility/test_util.c
	gcc -c ../../../Utility/test_util.c 

test_util.exe: util.o test_util.o
	gcc -o test_util.exe util.o test_util.o 
	
song_player_v1.o: ../../../SongPlayer_v1/song_player_v1.c
	gcc -c ../../../SongPlayer_v1/song_player_v1.c

test_song_player_v1.o : ../../../SongPlayer_v1/test_song_player_v1.c
	gcc -c ../../../SongPlayer_v1/test_song_player_v1.c

test_v1.exe: util.o song_player_v1.o test_song_player_v1.o
	gcc -o test_v1.exe util.o song_player_v1.o test_song_player_v1.o


song_player_v2.o: ../../../SongPlayer_v2/song_player_v2.c 
	gcc -c ../../../SongPlayer_v2/song_player_v2.c

test_song_player_v2.o : ../../../SongPlayer_v2/test_song_player_v2.c
	gcc -c ../../../SongPlayer_v2/test_song_player_v2.c

test_v2.exe: util.o song_player_v2.o test_song_player_v2.o song_player_v1.o
	gcc -o test_v2.exe util.o song_player_v2.o test_song_player_v2.o song_player_v1.o

util2.o:  ../../../Utility/util2.cpp
	g++ -c ../../../Utility/util2.cpp

test_util2.o: ../../../Utility/test_util2.cpp
	g++ -c ../../../Utility/test_util2.cpp

test_util2.exe: util2.o util.o test_util2.o
	g++ -o  test_util2.exe util.o util2.o test_util2.o

song_player_v3.o: ../../../SongPlayer_v3/song_player_v3.cpp 
	g++ -c ../../../SongPlayer_v3/song_player_v3.cpp 

test_song_player_v3.o: ../../../SongPlayer_v3/test_song_player_v3.cpp
	g++ -c ../../../SongPlayer_v3/test_song_player_v3.cpp

test_v3.exe: song_player_v3.o test_song_player_v3.o util.o util2.o 
	g++ -o test_v3.exe song_player_v3.o test_song_player_v3.o util.o util2.o

all: test_util.exe  test_util2.exe test_v1.exe test_v2.exe test_v3.exe

clean: 
	del *.exe *.o