hw4: main.o FlightNetwork.o LinkedList.o Queue.o
	g++ main.o FlightNetwork.o LinkedList.o Queue.o -o hw4

main.o: main.cpp
	g++ -c main.cpp

FlightNetwork.o: FlightNetwork.cpp FlightNetwork.h
	g++ -c FlightNetwork.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

clean:
	rm *.o hw4

