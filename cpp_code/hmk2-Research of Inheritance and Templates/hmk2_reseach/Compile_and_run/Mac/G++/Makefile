# a makefile for Mac OS

CXX = g++
Path = ../../../Code/
OPT = -std=c++11
OPT2 = -undefined dynamic_lookup

# $(OPT2) should appear at the end of a command. It is used to prevent some error of using gcc on Mac with M cpu.  

# ".PHONY all" means, even when the folder contains a file with name all, ignore the file, do not prevent the execution of the command "make all"

# "all" is the default target. So, when "make" is the command, it it the same as "make all"
# "all" can be replaced by "default".

.PHONY: all  

# all : testArrList.out testCommonList.out 

all :  testCommonList.out 

# testArrList.out:  test_arr_list.o
#	$(CXX) -o  testArrList.out test_arr_list.o $(OPT2)

testCommonList.out: test_common_list.o
	$(CXX) -o  testCommonList.out test_common_list.o $(OPT2)


# test_arr_list.o: $(Path)test_arr_list.cpp 
#	$(CXX) -c $(OPT) $(Path)test_arr_list.cpp

test_common_list.o : $(Path)test_common_list.cpp
	$(CXX) -c $(OPT) $(Path)test_common_list.cpp

 
# on windows, to know the options of the command "del", use "del /?"

.PHONY: cleanobj
cleanobj:
	rm  *.o
# /F means  Force deleting of read-only files.

.PHONY: cleanout
cleanout:
	rm  *.out

.PHONY: clean

clean:
	rm  *.o *.out



# https://michaelcurrin.github.io/dev-cheatsheets/cheatsheets/make/default-target.html
# https://www.jianshu.com/p/60b7bc6cf67d
# https://dev.to/mcaci/the-meaning-of-the-phony-target-inside-a-makefile-4fj8