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
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Square.o \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Shape.o \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Rectangle.o \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/GardenPlan.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Ellipse.o \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Circle.o \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Triangle.o \
	${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Diamond.o

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
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/MinGW-Windows/gardenplan.exe

dist/Debug/MinGW-Windows/gardenplan.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/MinGW-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gardenplan ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Square.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/Square.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Square.o /E/dev/cpp_projects/GardenPlan/Square.cpp

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Shape.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/Shape.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Shape.o /E/dev/cpp_projects/GardenPlan/Shape.cpp

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Rectangle.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/Rectangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Rectangle.o /E/dev/cpp_projects/GardenPlan/Rectangle.cpp

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/GardenPlan.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/GardenPlan.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/GardenPlan.o /E/dev/cpp_projects/GardenPlan/GardenPlan.cpp

${OBJECTDIR}/main.o: nbproject/Makefile-${CND_CONF}.mk main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Ellipse.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/Ellipse.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Ellipse.o /E/dev/cpp_projects/GardenPlan/Ellipse.cpp

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Circle.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/Circle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Circle.o /E/dev/cpp_projects/GardenPlan/Circle.cpp

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Triangle.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/Triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Triangle.o /E/dev/cpp_projects/GardenPlan/Triangle.cpp

${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Diamond.o: nbproject/Makefile-${CND_CONF}.mk /E/dev/cpp_projects/GardenPlan/Diamond.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/E_/dev/cpp_projects/GardenPlan/Diamond.o /E/dev/cpp_projects/GardenPlan/Diamond.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/MinGW-Windows/gardenplan.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
