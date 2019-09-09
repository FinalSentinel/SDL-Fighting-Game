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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW64-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Audio.o \
	${OBJECTDIR}/AudioMenu.o \
	${OBJECTDIR}/BattleMenu.o \
	${OBJECTDIR}/Box.o \
	${OBJECTDIR}/Character.o \
	${OBJECTDIR}/CommandMenu.o \
	${OBJECTDIR}/ControlsMenu.o \
	${OBJECTDIR}/Entity.o \
	${OBJECTDIR}/Frame.o \
	${OBJECTDIR}/GalleryMenu.o \
	${OBJECTDIR}/GameEngine.o \
	${OBJECTDIR}/GameState.o \
	${OBJECTDIR}/MainMenu.o \
	${OBJECTDIR}/MenuState.o \
	${OBJECTDIR}/OptionsMenu.o \
	${OBJECTDIR}/Player.o \
	${OBJECTDIR}/SFX.o \
	${OBJECTDIR}/Song.o \
	${OBJECTDIR}/StoryMenu.o \
	${OBJECTDIR}/Texture.o \
	${OBJECTDIR}/TitleState.o \
	${OBJECTDIR}/VersusMenu.o \
	${OBJECTDIR}/VersusState.o \
	${OBJECTDIR}/VideoMenu.o \
	${OBJECTDIR}/Window.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-L/C/SDL64/lib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fg_test.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fg_test.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/fg_test ${OBJECTFILES} ${LDLIBSOPTIONS} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

${OBJECTDIR}/Audio.o: Audio.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Audio.o Audio.cpp

${OBJECTDIR}/AudioMenu.o: AudioMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AudioMenu.o AudioMenu.cpp

${OBJECTDIR}/BattleMenu.o: BattleMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/BattleMenu.o BattleMenu.cpp

${OBJECTDIR}/Box.o: Box.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Box.o Box.cpp

${OBJECTDIR}/Character.o: Character.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Character.o Character.cpp

${OBJECTDIR}/CommandMenu.o: CommandMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CommandMenu.o CommandMenu.cpp

${OBJECTDIR}/ControlsMenu.o: ControlsMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControlsMenu.o ControlsMenu.cpp

${OBJECTDIR}/Entity.o: Entity.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Entity.o Entity.cpp

${OBJECTDIR}/Frame.o: Frame.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Frame.o Frame.cpp

${OBJECTDIR}/GalleryMenu.o: GalleryMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GalleryMenu.o GalleryMenu.cpp

${OBJECTDIR}/GameEngine.o: GameEngine.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameEngine.o GameEngine.cpp

${OBJECTDIR}/GameState.o: GameState.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/GameState.o GameState.cpp

${OBJECTDIR}/MainMenu.o: MainMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MainMenu.o MainMenu.cpp

${OBJECTDIR}/MenuState.o: MenuState.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/MenuState.o MenuState.cpp

${OBJECTDIR}/OptionsMenu.o: OptionsMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/OptionsMenu.o OptionsMenu.cpp

${OBJECTDIR}/Player.o: Player.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Player.o Player.cpp

${OBJECTDIR}/SFX.o: SFX.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/SFX.o SFX.cpp

${OBJECTDIR}/Song.o: Song.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Song.o Song.cpp

${OBJECTDIR}/StoryMenu.o: StoryMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/StoryMenu.o StoryMenu.cpp

${OBJECTDIR}/Texture.o: Texture.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Texture.o Texture.cpp

${OBJECTDIR}/TitleState.o: TitleState.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TitleState.o TitleState.cpp

${OBJECTDIR}/VersusMenu.o: VersusMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VersusMenu.o VersusMenu.cpp

${OBJECTDIR}/VersusState.o: VersusState.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VersusState.o VersusState.cpp

${OBJECTDIR}/VideoMenu.o: VideoMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/VideoMenu.o VideoMenu.cpp

${OBJECTDIR}/Window.o: Window.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Window.o Window.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/C/SDL64/include -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
