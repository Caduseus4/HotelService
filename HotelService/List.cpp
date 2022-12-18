#include <iostream>
#ifndef LIST_CPP
#define LIST_CPP


#include "Node.cpp"
using namespace std;

class List {
	Node* root;
public:
	List() : root(NULL) { }

	Node* begin() const { return root; }
	Node* end() const { return NULL; }
	bool isEmpty() const { return begin() == end(); }

	//listeye ürün eklemek için kullanýlan fonksiyon çift parametreli
	void pushBack(const string& value, const double& value2) {

		if (isEmpty()) // liste boþ mu diye kontrol eden blok
		{
			root = new Node(value,value2);
		}
		else 
		{
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(value,value2);
		}

	}

	//listeye ürün eklemek için kullanýlan fonksiyon tek parametreli
	void pushBack(const string& value) {

		if (isEmpty())// liste boþ mu diye kontrol eden blok
		{
			root = new Node(value); 
		}
		else {
			Node* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new Node(value);
		}

	}

	
	// listeyi yazdiran fonksiyon
	void printlist() {

		Node* tmp = begin();
		while (tmp != end()) {
			cout << tmp->data << " Fiyati:" << tmp->fiyat << endl;
			tmp = tmp->next;
		}

	}

	~List(){}

};
#endif 