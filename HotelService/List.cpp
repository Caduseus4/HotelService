#pragma warning(disable : 4996)
#include <iostream>
#ifndef LIST_CPP
#define LIST_CPP
#include "Node.cpp"
#include <ctime>
using namespace std;

class List {
	Node* root;
public:
	List() : root(NULL) { }

	Node* begin() const { return root; }
	Node* end() const { return NULL; }
	bool isEmpty() const { return begin() == end(); }

	//listeye ürün eklemek için kullanýlan fonksiyon 4 parametreli
	void pushBack(const string& value, char* kontrolTarihi, int islemiYapanId, const double& value2) {

		if (isEmpty()) // liste boþ mu diye kontrol eden blok
		{
			root = new Node(value, kontrolTarihi, islemiYapanId, value2);
		}
		else 
		{
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(value, kontrolTarihi,islemiYapanId,value2);
		}

	}

	//listeye ürün eklemek için kullanýlan fonksiyon 3 parametreli
	void pushBack(const string& value, char* kontrolTarihi,int islemiYapanId) {

		if (isEmpty())// liste boþ mu diye kontrol eden blok
		{
			root = new Node(value,kontrolTarihi, islemiYapanId);
		}
		else {
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(value,kontrolTarihi, islemiYapanId);
		}

	}


	//destructor
	~List(){}

};
#endif 