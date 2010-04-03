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
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/Rational/Rational.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/MinGW-Windows/librational.a

dist/Debug/MinGW-Windows/librational.a: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/MinGW-Windows
	${RM} dist/Debug/MinGW-Windows/librational.a
	${AR} rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/librational.a ${OBJECTFILES} 
	$(RANLIB) dist/Debug/MinGW-Windows/librational.a

${OBJECTDIR}/_ext/E_/dev/cpp_projects/Rational/Rational.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/Rational/Rational.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/Rational
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/Rational/Rational.o /E/dev/cpp_projects/Rational/Rational.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/MinGW-Windows/librational.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
