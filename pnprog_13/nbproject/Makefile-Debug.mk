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
	${OBJECTDIR}/UDPSocket.o \
	${OBJECTDIR}/udpchatserver.o \
	${OBJECTDIR}/Datagram.o \
	${OBJECTDIR}/udpchatclient.o \
	${OBJECTDIR}/udpdemo.o


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
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/Cygwin_4.x_1-Windows/pnprog_13.exe

dist/Debug/Cygwin_4.x_1-Windows/pnprog_13.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/Cygwin_4.x_1-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/pnprog_13 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/UDPSocket.o: nbproject/Makefile-${CND_CONF}.mk UDPSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/UDPSocket.o UDPSocket.cpp

${OBJECTDIR}/udpchatserver.o: nbproject/Makefile-${CND_CONF}.mk udpchatserver.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/udpchatserver.o udpchatserver.cpp

${OBJECTDIR}/Datagram.o: nbproject/Makefile-${CND_CONF}.mk Datagram.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Datagram.o Datagram.cpp

${OBJECTDIR}/udpchatclient.o: nbproject/Makefile-${CND_CONF}.mk udpchatclient.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/udpchatclient.o udpchatclient.cpp

${OBJECTDIR}/udpdemo.o: nbproject/Makefile-${CND_CONF}.mk udpdemo.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/udpdemo.o udpdemo.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/Cygwin_4.x_1-Windows/pnprog_13.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
