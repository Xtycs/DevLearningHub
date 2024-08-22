# make file for using cl on Windows. 

CXX = cl
Path = ../../../Code/
#Path = ..\..\..\Code\
#OPTC = -std=c++11

# replace -c of g++
OPTC = /c 

# https://learn.microsoft.com/en-us/cpp/build/reference/std-specify-language-standard-version?view=msvc-170
# no option for c++11, only has /std:c11
# So, c++11 is suppoted by cl by default. no need to mention it. 
# OPTV = /std=c++17

# replace -o of g++ 
OPTO = /Fe

# C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.37.32822\include\ostream(293): warning C4530: C++ exception handler used, but unwind semantics are not enabled. Specify /EHsc
# C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.37.32822\include\ostream(278): note: while compiling class template member function 'std::basic_ostream<char,std::char_traits<char>> &std::basic_ostream<char,std::char_traits<char>>::operator <<(int)'

# cl /help
# /EHs enable C++ EH (no SEH exceptions)  
# /EHa enable C++ EH (w/ SEH exceptions)
# /EHc extern "C" defaults to nothrow

OPTW = /EHsc



# ".PHONY all" means, even when the folder contains a file with name all, ignore the file, do not prevent the execution of the command "make all"

# "all" is the default target. So, when "make" is the command, it it the same as "make all"
# "all" can be replaced by "default".

.PHONY: all  

# all: testCommonList.exe   testArrList.exe

all: testCommonList.exe

# testArrList.exe:  test_arr_list.obj
#	$(CXX) $(OPTO)testArrList.exe test_arr_list.obj

testCommonList.exe: test_common_list.obj
	$(CXX) $(OPTO)testCommonList.exe test_common_list.obj


# test_arr_list.obj: $(Path)test_arr_list.cpp 
#	$(CXX) $(OPTW) $(OPTC)  $(Path)test_arr_list.cpp

test_common_list.obj : $(Path)test_common_list.cpp
	$(CXX) $(OPTW) $(OPTC)  $(Path)test_common_list.cpp

 

 
# on windows, to know the options of the command "del", use "del /?"

.PHONY: cleanobj
cleanobj:
	del /F *.obj
# /F means  Force deleting of read-only files.

.PHONY: cleanexe
cleanexe:
	del /F *.exe

.PHONY: clean

clean:
	del /F *.obj *.exe



# https://michaelcurrin.github.io/dev-cheatsheets/cheatsheets/make/default-target.html
# https://www.jianshu.com/p/60b7bc6cf67d
# https://dev.to/mcaci/the-meaning-of-the-phony-target-inside-a-makefile-4fj8