#include <iostream>
#include <cassert>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node* next;
	Node* prev;

	Node() :data(), next(), prev() {}
	Node(const T& _data) :data(_data), next(), prev() {}
};


template<class T>
class DoubleLinkedList
{
	Node<T>* head;
	Node<T>* tail;
public:

	DoubleLinkedList() :head(), tail() {}

	void push_front(T data)
	{
		push_front(new Node<T>(data));
	}
	void push_front(Node<T>* node)
	{
		if (head == NULL)
		{
			head = node;
			tail = node;
			return;
		}
		node->next = head;
		head->prev = node;
		head = node;
	}

	void push_back(T data)
	{
		push_back(new Node<T>(data));
	}
	void push_back(Node<T>* node)
	{
		if (head == NULL)
		{
			head = node;
			tail = node;
			return;
		}

		node->prev = tail;
		tail->next = node;

		tail = node;
	}

	void insert_before(Node<T>* node, T data)
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* temp = node;

		if (node == head)
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
			return;
		}
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
	}
	void insert_before(Node<T>* node, Node<T>* data)
	{
		Node<T>* temp = node;

		if (node == head)
		{
			data->next = head;
			head->prev = data;
			head = data;
			return;
		}
		data->next = temp;
		data->prev = temp->prev;
		temp->prev->next = data;
		temp->prev = data;
	}

	void insert_after(Node<T>* node, T data)
	{
		Node<T>* newNode = new Node<T>(data);
		Node<T>* temp = node;

		if (node == tail)
		{
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
			return;
		}
		newNode->prev = temp;
		newNode->next = temp->next;
		temp->next = newNode;
		temp->next->prev = newNode;
	}
	void insert_after(Node<T>* node, Node<T>* data)
	{
		Node<T>* temp = node;

		if (node == tail)
		{
			data->prev = tail;
			tail->next = data;
			tail = data;
			return;
		}
		data->prev = temp;
		data->next = temp->next;
		temp->next = data;
		temp->next->prev = data;
	}

	void pop_front()
	{
		if (head == NULL)
			return;
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}

		head = head->next;
		delete head->prev;
		head->prev = NULL;
	}
	void pop_back()
	{
		if (head == NULL)
			return;
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			tail = NULL;
			return;
		}


		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;

	}

	Node<T>* search(T data)
	{
		Node<T>* temp = head;
		while (temp->next != NULL)
		{
			if (temp->data == data)
			{
				return temp;
			}
			temp = temp->next;
		}

		if (temp->data == data)
		{
			return temp;
		}

		return NULL;
	}

	void displayFront()
	{
		Node<T>* temp = head;
		cout << "[";
		while (temp->next != NULL)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << "]" << endl;
	}
	void displayBack()
	{
		Node<T>* temp = tail;
		cout << "[";
		while (temp->prev != NULL)
		{
			cout << temp->data << ", ";
			temp = temp->prev;
		}
		cout << temp->data << "]" << endl;
	}


};


void main() {

	string vusal = "Vusal";
	string hesen = "Reshad";
	string huseyn = "Huseyn";
	string nezrin = "Orxan";
	string rovshen = "Ruslan";
	string ramazan = "Ibrahim";

	Node<string>* akif = new Node<string>("Akif");
	Node<string>* kamran = new Node<string>("Kamran");
	DoubleLinkedList<string> list;
	//list.push_back(name_1);
	//list.push_back(name_2);
	//list.push_back(name_3);
	list.push_front(vusal);
	//list.push_front(name_5);
	list.push_front(nezrin);
	//list.push_front(huseyn);
	list.push_back(akif);
	list.push_front(hesen);


	list.displayFront();
	//list.displayBack();
	//list.insert_before(akif, huseyn );
	list.insert_after(akif, huseyn );
	list.displayFront();
}