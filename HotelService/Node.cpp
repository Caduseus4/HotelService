#include <iostream>
#ifndef NODE_CPP
#define NODE_CPP

using namespace std;

class Node {
public:
	string data;
	double fiyat;
	Node* next;

	Node(const string& data = "", const double& fiyat = 0, Node* next = NULL) : data(data), next(next), fiyat(fiyat) {	}

	//~Node() {}

};
#endif