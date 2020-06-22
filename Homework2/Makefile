hw2: main.o PbTreeNode.o PbBST.o analysis.o
	g++ main.o PbTreeNode.o PbBST.o analysis.o -o hw2

main.o: main.cpp
	g++ -c main.cpp

PbTreeNode.o: PbTreeNode.cpp PbTreeNode.h
	g++ -c PbTreeNode.cpp

PbBST.o: PbBST.cpp PbBST.h
	g++ -c PbBST.cpp

analysis.o: analysis.cpp analysis.h
	g++ -c analysis.cpp

clean:
	rm *.o hw2

