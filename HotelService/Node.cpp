#pragma warning(disable : 4996)
#include <iostream>
#ifndef NODE_CPP
#define NODE_CPP
#include <ctime>

using namespace std;

class Node {
public:
	string data;

	double fiyat;
	Node* next;
	char* kontrolTarihi;
	int islemiYapanId;
	
	//Node classinin constructor'i
	Node(const string& data = "", char* kontrolTarihi = 0, int islemiYapanId = 0, const double& fiyat = 0, Node* next = NULL ) :kontrolTarihi(kontrolTarihi), data(data),
		islemiYapanId(islemiYapanId), next(next), fiyat(fiyat) {	}



	//~Node() {}

};
#endif