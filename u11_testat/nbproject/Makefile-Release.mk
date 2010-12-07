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
CND_PLATFORM=Cygwin_4.x-Windows
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/UploadFile.o \
	${OBJECTDIR}/SocketIO.o \
	${OBJECTDIR}/FileUploader.o \
	${OBJECTDIR}/ServerSocket.o \
	${OBJECTDIR}/htechoserv.o


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
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/Cygwin_4.x-Windows/u11_testat.exe

dist/Release/Cygwin_4.x-Windows/u11_testat.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Release/Cygwin_4.x-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/u11_testat ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/UploadFile.o: nbproject/Makefile-${CND_CONF}.mk UploadFile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/UploadFile.o UploadFile.cpp

${OBJECTDIR}/SocketIO.o: nbproject/Makefile-${CND_CONF}.mk SocketIO.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/SocketIO.o SocketIO.cpp

${OBJECTDIR}/FileUploader.o: nbproject/Makefile-${CND_CONF}.mk FileUploader.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/FileUploader.o FileUploader.cpp

${OBJECTDIR}/ServerSocket.o: nbproject/Makefile-${CND_CONF}.mk ServerSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/ServerSocket.o ServerSocket.cpp

${OBJECTDIR}/htechoserv.o: nbproject/Makefile-${CND_CONF}.mk htechoserv.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/htechoserv.o htechoserv.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/Cygwin_4.x-Windows/u11_testat.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
