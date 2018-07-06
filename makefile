#Makefile for Kyle Garland
#This makefile was created with the help of the rooker lecture under the makefile module
#and also from the TA's makefile example.
#References were also pulled from https://www.gnu.org/software/make/manual/make.pdf
#and also from ftp://ftp.gnu.org/old-gnu/Manuals/make-3.79.1/html_chapter/make_2.html
#This is the makefile for Lab1 - created on 4/8/2018

#changes made
#executable file
EXEC = Final162

#Zip file
ZIP = ${EXEC}_Garland_Kyle

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#Valgrind commands for debugging and memory leaks
VALG = --leak-check=full
VALG += --tool=memcheck
VALG += --show-leak-kinds=all
VALG += --track-origins=yes

#source files
SRCS = main.cpp
SRCS += planetUnity.cpp
SRCS += ThePurge.cpp
SRCS += Space.cpp
SRCS += Player.cpp
SRCS += planetGazorpazorp.cpp
SRCS += Microverse.cpp
SRCS += asteroidField.cpp
SRCS += TheCitadel.cpp
SRCS += Util.cpp

#header files
HEADERS = Util.hpp
HEADERS += planetUnity.hpp
HEADERS += ThePurge.hpp
HEADERS += Space.hpp
HEADERS += Player.hpp
HEADERS += planetGazorpazorp.hpp
HEADERS += Microverse.hpp
HEADERS += asteroidField.hpp
HEADERS += TheCitadel.hpp

#objects
OBJS = $(SRCS:.cpp=.o)

#target: dependencies
#     rule to build

${EXEC}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o $@

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

debug:
	valgrind $(VALG) ./$(EXEC)

#zip file
zip:
	zip -D $(ZIP) Final162_Garland_Kyle *.cpp *.hpp *.pdf *makefile

#clean
clean:
	rm ${OBJS} ${EXEC}

