# To choose the .exe file name, use the option /Fe followed immediatly the file name, with no separating space. 
# -o is deprecated. 

# cl /filename.exe  is ok 
# but,  cl /Fe"filename" is visually better. 

# Can use /Fo to seleted the name of the generated .obj file 

util.obj:  ../../../Utility/util.c
	cl /c ../../../Utility/util.c

test_util.obj: ../../../Utility/test_util.c
	cl -c ../../../Utility/test_util.c 

test_util.exe: util.obj test_util.obj
	cl /Fe"test_util.exe" util.obj test_util.obj 

song_player_v1.obj: ../../../SongPlayer_v1/song_player_v1.c
	cl /c ../../../SongPlayer_v1/song_player_v1.c

test_song_player_v1.obj : ../../../SongPlayer_v1/test_song_player_v1.c
	cl /c ../../../SongPlayer_v1/test_song_player_v1.c

test_v1.exe: util.obj song_player_v1.obj test_song_player_v1.obj
	cl /Fe"test_v1.exe" util.obj song_player_v1.obj test_song_player_v1.obj


song_player_v2.obj: ../../../SongPlayer_v2/song_player_v2.c 
	cl -c ../../../SongPlayer_v2/song_player_v2.c

test_song_player_v2.obj : ../../../SongPlayer_v2/test_song_player_v2.c
	cl -c ../../../SongPlayer_v2/test_song_player_v2.c

test_v2.exe: util.obj song_player_v2.obj test_song_player_v2.obj song_player_v1.obj
	cl /Fe"test_v2.exe" util.obj song_player_v2.obj test_song_player_v2.obj song_player_v1.obj

util2.obj:  ../../../Utility/util2.cpp
	cl -c ../../../Utility/util2.cpp

test_util2.obj: ../../../Utility/test_util2.cpp
	cl -c ../../../Utility/test_util2.cpp

test_util2.exe: util2.obj util.obj test_util2.obj
	cl /Fe"test_util2.exe" util.obj util2.obj test_util2.obj


song_player_v3.obj: ../../../SongPlayer_v3/song_player_v3.cpp 
	cl -c ../../../SongPlayer_v3/song_player_v3.cpp 

test_song_player_v3.obj: ../../../SongPlayer_v3/test_song_player_v3.cpp
	cl -c ../../../SongPlayer_v3/test_song_player_v3.cpp

test_v3.exe: song_player_v3.obj test_song_player_v3.obj util.obj util2.obj 
	cl /Fe"test_v3.exe" song_player_v3.obj test_song_player_v3.obj util.obj util2.obj

all: test_util.exe  test_util2.exe test_v1.exe test_v2.exe test_v3.exe

clean: 
	del *.exe *.obj