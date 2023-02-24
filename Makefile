GPPWARN = -Wall -Wextra -Wpedantic -Wshadow -Wold-style-cast -Werror
GPPOPTS = ${GPPWARN}
COMPILEGPP = clang++ -g -O2 ${GPPOPTS}
EXECBIN = blackjack

MODULES = Card Deck GenericPlayer Hand Game \
		  House Player System main
CPPSOURCE = ${wildcard ${MODULES:=.cpp}}
OBJECTS = ${CPPSOURCE:.cpp=.o}

all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${COMPILEGPP} -o $@ ${OBJECTS}

%.o : %.cpp
	${COMPILEGPP} -c $<

clean :
	- rm ${OBJECTS}

spotless : clean
	- rm ${EXECBIN}

format:
	clang-format -i *.cpp *.hpp

scan-build: spotless
	scan-build make

again:
	make spotless all
