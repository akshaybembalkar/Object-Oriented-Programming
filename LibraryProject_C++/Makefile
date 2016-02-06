CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -W -Werror -pedantic

main: main.o searchEngine.o Media.o Book.o Periodic.o Video.o Film.o
	$(CXX) -o main main.o searchEngine.o Media.o Book.o Periodic.o Video.o Film.o

main.o: main.cpp 

searchEngine.o: searchEngine.cpp searchEngine.h

Media.o: Media.cpp Media.h

Book.o: Book.cpp Book.h

Periodic.o: Periodic.cpp Periodic.h

Video.o: Video.cpp Video.h

Film.o: Film.cpp Film.h

clean:
	rm -f *.o main
