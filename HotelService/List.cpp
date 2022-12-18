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

	//listeye ürün eklemek için kullanýlan fonksiyon çift parametreli
	void pushBack(const string& value, const double& value2, char* kontrolTarihi) {

		if (isEmpty()) // liste boþ mu diye kontrol eden blok
		{
			root = new Node(value, kontrolTarihi,value2);
		}
		else 
		{
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(value, kontrolTarihi,value2);
		}

	}

	//listeye ürün eklemek için kullanýlan fonksiyon tek parametreli
	void pushBack(const string& value, char* kontrolTarihi) {

		if (isEmpty())// liste boþ mu diye kontrol eden blok
		{
			root = new Node(value,kontrolTarihi); 
		}
		else {
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(value,kontrolTarihi);
		}

	}


	~List(){}

};
#endif 