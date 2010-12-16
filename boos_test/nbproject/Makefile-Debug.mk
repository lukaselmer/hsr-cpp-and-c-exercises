#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


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

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/reactortelnet.o \
	${OBJECTDIR}/Reactor.o \
	${OBJECTDIR}/Socket.o \
	${OBJECTDIR}/SocketWriteHandler.o \
	${OBJECTDIR}/reactorechoserv.o \
	${OBJECTDIR}/ReadHandler.o \
	${OBJECTDIR}/WriteHandler.o \
	${OBJECTDIR}/EchoHandler.o \
	${OBJECTDIR}/TelnetConnectHandler.o \
	${OBJECTDIR}/ConnectHandler.o \
	${OBJECTDIR}/Handler.o \
	${OBJECTDIR}/AcceptHandler.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/Cygwin_4.x_1-Windows/boos_test.exe

dist/Debug/Cygwin_4.x_1-Windows/boos_test.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/Cygwin_4.x_1-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/boos_test ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/reactortelnet.o: nbproject/Makefile-${CND_CONF}.mk reactortelnet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/reactortelnet.o reactortelnet.cpp

${OBJECTDIR}/Reactor.o: nbproject/Makefile-${CND_CONF}.mk Reactor.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Reactor.o Reactor.cpp

${OBJECTDIR}/Socket.o: nbproject/Makefile-${CND_CONF}.mk Socket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Socket.o Socket.cpp

${OBJECTDIR}/SocketWriteHandler.o: nbproject/Makefile-${CND_CONF}.mk SocketWriteHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/SocketWriteHandler.o SocketWriteHandler.cpp

${OBJECTDIR}/reactorechoserv.o: nbproject/Makefile-${CND_CONF}.mk reactorechoserv.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/reactorechoserv.o reactorechoserv.cpp

${OBJECTDIR}/ReadHandler.o: nbproject/Makefile-${CND_CONF}.mk ReadHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ReadHandler.o ReadHandler.cpp

${OBJECTDIR}/WriteHandler.o: nbproject/Makefile-${CND_CONF}.mk WriteHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/WriteHandler.o WriteHandler.cpp

${OBJECTDIR}/EchoHandler.o: nbproject/Makefile-${CND_CONF}.mk EchoHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/EchoHandler.o EchoHandler.cpp

${OBJECTDIR}/TelnetConnectHandler.o: nbproject/Makefile-${CND_CONF}.mk TelnetConnectHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/TelnetConnectHandler.o TelnetConnectHandler.cpp

${OBJECTDIR}/ConnectHandler.o: nbproject/Makefile-${CND_CONF}.mk ConnectHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/ConnectHandler.o ConnectHandler.cpp

${OBJECTDIR}/Handler.o: nbproject/Makefile-${CND_CONF}.mk Handler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Handler.o Handler.cpp

${OBJECTDIR}/AcceptHandler.o: nbproject/Makefile-${CND_CONF}.mk AcceptHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/AcceptHandler.o AcceptHandler.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/Cygwin_4.x_1-Windows/boos_test.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
