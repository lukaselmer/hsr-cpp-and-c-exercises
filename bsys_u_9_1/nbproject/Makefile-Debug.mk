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
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/bsys_u_9_1/wprog1.o

# C Compiler Flags
CFLAGS=-mwindows -std=c99

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/MinGW-Windows/bsys_u_9_1.exe

dist/Debug/MinGW-Windows/bsys_u_9_1.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/MinGW-Windows
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/bsys_u_9_1 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/E_/dev/cpp_projects/bsys_u_9_1/wprog1.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/bsys_u_9_1/wprog1.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/bsys_u_9_1
	${RM} $@.d
	$(COMPILE.c) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/bsys_u_9_1/wprog1.o /E/dev/cpp_projects/bsys_u_9_1/wprog1.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/MinGW-Windows/bsys_u_9_1.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
