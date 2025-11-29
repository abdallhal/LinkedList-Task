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
	void ToEnd();	
	bool AtFirst();
	bool AtEnd();
	void Advance();
	int ListSize();
	void UpdateData(char newData);
	void UpdateKey(int newKey);


};

