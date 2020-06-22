q2: main.o PbTreeNode.o AVLTree.o analysis.o
	g++ main.o PbTreeNode.o AVLTree.o analysis.o -o q2

main.o: main.cpp
	g++ -c main.cpp

PbTreeNode.o: PbTreeNode.cpp PbTreeNode.h
	g++ -c PbTreeNode.cpp

AVLTree.o: AVLTree.cpp AVLTree.h
	g++ -c AVLTree.cpp

analysis.o: analysis.cpp analysis.h
	g++ -c analysis.cpp

clean:
	rm *.o q2

