CXX = g++
Path = ../../../Code/
OPT = -std=c++11

# ".PHONY all" means, even when the folder contains a file with name all, ignore the file, do not prevent the execution of the command "make all"

# "all" is the default target. So, when "make" is the command, it it the same as "make all"
# "all" can be replaced by "default".

.PHONY: all  


# all : testArrList.exe testCommmonList.exe 

all :  testCommmonList.exe 

# testArrList.exe:  test_arr_list.o
#	$(CXX) -o testArrList.exe test_arr_list.o

testCommmonList.exe: test_common_list.o
	$(CXX) -o testCommmonList.exe test_common_list.o

# test_arr_list.o: $(Path)test_arr_list.cpp 
#	$(CXX) -c $(Path)test_arr_list.cpp

test_common_list.o : $(Path)test_common_list.cpp
	$(CXX) -c $(Path)test_common_list.cpp



 
# on windows, to know the options of the command "del", use "del /?"

.PHONY: cleanobj
cleanobj:
	del /F *.o
# /F means  Force deleting of read-only files.

.PHONY: cleanexe
cleanexe:
	del /F *.exe

.PHONY: clean

clean:
	del /F *.o *.exe



# https://michaelcurrin.github.io/dev-cheatsheets/cheatsheets/make/default-target.html
# https://www.jianshu.com/p/60b7bc6cf67d
# https://dev.to/mcaci/the-meaning-of-the-phony-target-inside-a-makefile-4fj8