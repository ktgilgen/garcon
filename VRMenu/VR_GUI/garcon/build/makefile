# Linux
CC=g++

# COMPILER flags
CXXFLAGS= -g -std=c++0x

OBJ= main_v1.o AppInfo.o AppManager.o

../bin/garcon: $(OBJ)
	$(CC) $(OBJ) -o ../bin/garcon
	-rm *.o

main_v1.o: ../src/main_v1.cpp ../src/AppInfo.h ../src/AppManager.h
	$(CC) $(CXXFLAGS)  -c ../src/main_v1.cpp

AppInfo.o: ../src/AppInfo.h ../src/AppInfo.cpp
	$(CC) $(CXXFLAGS) -c ../src/AppInfo.cpp

AppManager.o: ../src/AppManager.h ../src/AppManager.cpp ../src/AppInfo.h
	$(CC) $(CXXFLAGS) -c ../src/AppManager.cpp


clean: 
	-rm *.o
