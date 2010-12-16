# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin

#
# Generated - do not edit!
#
# NOCDDL
#
CND_BASEDIR=`pwd`
CND_BUILDDIR=build
CND_DISTDIR=dist
# Debug configuration
CND_PLATFORM_Debug=Cygwin_4.x_1-Windows
CND_ARTIFACT_DIR_Debug=dist/Debug/Cygwin_4.x_1-Windows
CND_ARTIFACT_NAME_Debug=pnprog_u10a
CND_ARTIFACT_PATH_Debug=dist/Debug/Cygwin_4.x_1-Windows/pnprog_u10a
CND_PACKAGE_DIR_Debug=dist/Debug/Cygwin_4.x_1-Windows/package
CND_PACKAGE_NAME_Debug=pnprogu10a.tar
CND_PACKAGE_PATH_Debug=dist/Debug/Cygwin_4.x_1-Windows/package/pnprogu10a.tar
# Release configuration
CND_PLATFORM_Release=
CND_ARTIFACT_DIR_Release=dist/Release/
CND_ARTIFACT_NAME_Release=pnprog_u10a
CND_ARTIFACT_PATH_Release=dist/Release//pnprog_u10a
CND_PACKAGE_DIR_Release=dist/Release//package
CND_PACKAGE_NAME_Release=pnprogu10a.tar
CND_PACKAGE_PATH_Release=dist/Release//package/pnprogu10a.tar


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=Cygwin_4.x_1-Windows
CND_CONF=Debug
CND_DISTDIR=dist


# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}






SRC=Reactor.cpp Handler.cpp ConnectHandler.cpp Socket.cpp AcceptHandler.cpp EchoHandler.cpp ReadHandler.cpp WriteHandler.cpp
OBJECTS=Reactor.o Handler.o ConnectHandler.o Socket.o AcceptHandler.o EchoHandler.o ReadHandler.o WriteHandler.o
# name your source files accordingly:
CHATSRC=ChatHandler.cpp AcceptChatHandler.cpp 
CHATOBJ=ChatHandler.o AcceptChatHandler.o 

TELNETSRC=TelnetConnectHandler.cpp reactortelnet.cpp SocketWriteHandler.cpp
TELNETOBJ=TelnetConnectHandler.o reactortelnet.o SocketWriteHandler.o

CPPFLAGS+=-g
# If there is a problem with boost, download it from http://www.boost.org/ 
# and uncomment the next line (don't forget to replace <path_to_boost_directory>)
#CPPFLAGS+=-g -I<path_to_boost_direcotry> #might be needed e.g. CPPFLAGS+=-g -Iboost_1_41_0

all: $(OBJECTS) reactorechoserv rtelnet
# all: $(OBJECTS) reactorechoserv rtelnet chatserver

reactorechoserv: reactorechoserv.o $(OBJECTS)
	g++ -o $@ $+ 

chatserver: chatserver.o $(OBJECTS) $(CHATOBJ)
	g++ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $+ 

rtelnet: $(TELNETOBJ) $(OBJECTS)
	g++ $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $+ 

clean:
	-rm $(OBJECTS) $(TELNETOBJ) $(CHATOBJ) rtelnet rtelnet.exe Makefile.bak chatserver chatserver.o chatserver.exe reactorechoserv reactorechoserv.o reactorechoserv.exe 2>/dev/null


depend: $(SRC) $(TELNETSRC)
# depend: $(SRC) $(TELNETSRC) $(CHATSRC) 
	-g++ -MM $(SRC)  $(TELNETSRC)  >./makedepends.incl  2>/dev/null
#	-g++ -MM $(SRC) $(TELNETSRC) $(CHATSRC)  >./makedepends.incl  2>/dev/null
	
-include ./makedepends.incl
# DO NOT DELETE
