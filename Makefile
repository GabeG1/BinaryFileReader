 #                                                                              
 #Filename        Makefile
 #Date            4/28/19                                                        
 #Author          Gabriel Goldstein                                             
 #Email           gjg180000@utdallas.edu                                        
 #Course          CS 3377.502 Spring 2019                                       
 #Version         1.0                                                           
 #Copyright 2019, All Rights Reserved                                           
 #                                                                             
 #Description                                                                   
 #            Build Program6 executable with CDK   

CXX = g++
CXXFLAGS =
CPPFLAGS = -Wno-write-strings -Wall -Werror -std=c++11 -I/people/cs/s/sxp127930/include
#libraries
LDFLAGS = -L/people/cs/s/sxp127930/lib
LDLIBS = -lcdk -lcurses 

#Use implicit rules to get object files
OBJS = program6.o

.PHONY: all clean

all: program6

#Clean up directory
clean:
	rm -f $(OBJS) program6 *~ \#* 

#Make executable
program6: $(OBJS)
	$(CXX) -o program6 $(OBJS) $(LDFLAGS) $(LDLIBS)
