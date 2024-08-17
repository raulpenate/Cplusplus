# using:
# make				# compile proyect
# make remove	#	remove all binaries and objects
# 
.PHONY = all clean ensamble remove

CC = g++
HEADERSDIR = ./Headers/include
SRCSDIR = ./Sources/src
MAINDIR = ./Sources

SRCS := $(wildcard ${SRCSDIR}/*.cpp)
OBJECTSRCS := ${SRCS:${SRCSDIR}/%.cpp=%.o}

all: ${OBJECTSRCS} main.o ensamble clean

ensamble: main.o
	@echo "Ensambling.."
	${CC} -o proyect.out *.o

%.o: ${SRCSDIR}/%.cpp
	@echo "Creating object..."
	${CC} -c -I ${HEADERSDIR} $<

main.o: ${MAINDIR}/main.cpp
	@echo "Compiling main.cpp.."
	${CC} -c -I ${HEADERSDIR} $<

clean:
	@echo "Cleaning compilation..."
	rm *.o

remove:
	rm -fv proyect.out
	rm -fv *.