CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
LDFLAGS = -lboost_date_time

OBJS = ActivityRm.o Bandit.o Entrance.o FAstation.o Fighter.o Gameplay.o main.o validation.o Garden.o Space.o Street.o

SRCS = ActivityRm.cpp Bandit.cpp Entrance.cpp FAstation.cpp Fighter.cpp Gameplay.cpp main.cpp validation.cpp Garden.cpp Space.cpp Street.cpp

HEADERS = ActivityRm.hpp Bandit.hpp Entrance.hpp FAstation.hpp Fighter.hpp Gameplay.hpp validation.hpp Garden.hpp Space.hpp Street.hpp

escapeu: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o escapeu

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm *.o escapeu
