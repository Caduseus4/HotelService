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
	void pushBack(const string& deger, char* kontrolTarihi, int islemiYapanId, const double& deger2) {

		if (isEmpty()) // liste bos mu diye kontrol eden blok
		{
			root = new Node(deger, kontrolTarihi, islemiYapanId, deger2);
		}
		else 
		{
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(deger, kontrolTarihi,islemiYapanId,deger2);
		}

	}

	//listeye ürün eklemek için kullanilan fonksiyon 3 parametreli
	void pushBack(const string& deger, char* kontrolTarihi,int islemiYapanId) {

		if (isEmpty())// liste boþ mu diye kontrol eden blok
		{
			root = new Node(deger,kontrolTarihi, islemiYapanId);
		}
		else {
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(deger,kontrolTarihi, islemiYapanId);
		}

	}


	//destructor
	~List(){}

};
#endif 