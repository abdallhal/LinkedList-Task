#pragma once
class LinkedList
{
	class Node
	{
	public:
		int key;
		char data;
		Node* next;
		Node(){
			key = 0;
			data = 'a';
			
		}
	};

	Node* head;
	Node* cursor;
	Node* prev;
public:
	LinkedList();
	bool isEmpty();
	bool CursorIsEmpty();
	void ToFirst();
	bool AtFirst();


};

