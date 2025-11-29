#include "LinkedList.h"
#include <iostream>
using namespace std;
LinkedList::LinkedList() {

	head = nullptr;
	prev = nullptr;
	cursor = nullptr;
}
bool LinkedList::isEmpty() {
	return head == nullptr;
}
bool LinkedList::CursorIsEmpty() {
	return cursor == nullptr;
}
void LinkedList::ToFirst() {
	cursor = head;
}
void LinkedList::ToEnd() {
	ToFirst();
	if (!isEmpty()) {
		while (cursor->next != nullptr) {
			Advance();
		}
	}

}

bool LinkedList::AtFirst() {
	// if cursor is at head or list is empty and cursor is also empty
	return (cursor == head) || (isEmpty() && CursorIsEmpty());
}
bool LinkedList::AtEnd() {

	return (cursor->next == nullptr) || (isEmpty() && CursorIsEmpty());
}
void LinkedList::Advance() {

	if (!CursorIsEmpty()) {
		prev = cursor;
		cursor = cursor->next;
	}
}
int LinkedList::ListSize() {
	int count = 0;
	Node* temp = head;
	if (!isEmpty()) {
		while (temp != nullptr) {
			count++;
			temp = temp->next;
		}

	}
	return count;
}
void LinkedList::UpdateData(char newData) {
	if (!CursorIsEmpty()) {
		cursor->data = newData;
	}
}
void LinkedList::UpdateKey(int newKey) {
	if (!CursorIsEmpty()) {
		cursor->key = newKey;
	}
}

char LinkedList::GetData() {
	return cursor->data;
}
void LinkedList::GetData(char& data) {
	data = cursor->data;
}
int LinkedList::GetKey() {
	return cursor->key;
}
void LinkedList::GetKey(int& key) {
	key = cursor->key;
}
void LinkedList::InsertFirst(int key, char data) {
	Node* newNode = new Node;
	newNode->key = key;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
	cursor = head;
	prev = nullptr;
}
void LinkedList::InsertAfter(int key, char data) {
	Node* newNode = new Node;
	newNode->key = key;
	newNode->data = data;
	newNode->next = cursor->next;
	cursor->next = newNode;
	prev = cursor;
	cursor = newNode;

}
void LinkedList::InsertEnd(int key, char data) {
	if (isEmpty()) {
		InsertFirst(key, data);
	}
	else {
		ToEnd();
		InsertAfter(key, data);
	}

}

void LinkedList::InsertBefore(int key, char data) {
	Node* newNode = new Node;
	newNode->key = key;
	newNode->data = data;
	newNode->next = cursor;
	prev->next = newNode;
	cursor = newNode;
}

void LinkedList::DeleteNode() {
	Node* temp;
	temp = cursor;
	if (!CursorIsEmpty()) {

		if (AtFirst()) {
			cursor = cursor->next;
			head = cursor;
			delete temp;
		}
		else {
			cursor = cursor->next;
			prev->next = cursor;
			delete temp;
		}
	}
	
}

void LinkedList::DeleteFirst() {

	if (!isEmpty()) {
		ToFirst();
		DeleteNode();
	}

}
void LinkedList::DeleteEnd() {

	if (!isEmpty()) {
		ToEnd();
		DeleteNode();
	}


}
void LinkedList::MakeListEmpty() {

	ToFirst();
	
	while (!isEmpty()) {
		DeleteNode();
	}
}

bool LinkedList::Search(const int& k) {
	bool found = false;
	ToFirst();
	while ((!found) && (cursor != nullptr)) {
	
		if (k == cursor->key) {
			found = true;
			return found;
		}
		else
		{
			Advance();
		}
	}
	return found;
}
void LinkedList::Traverse() {

	if (!isEmpty()) {

		ToFirst();
		while (!CursorIsEmpty()) {
			cout << cursor->data << " - " << cursor->key << endl;
			Advance();
		}
	}
}

void LinkedList::OrderInsert(const char& d, const int& k) {
	ToFirst();
	while ((cursor!=nullptr)&& (k>cursor->key)) {
		Advance();
		if (prev == nullptr) {
			InsertFirst(k,d);
		}
		else {
			InsertBefore(k, d);
		}

	}
}