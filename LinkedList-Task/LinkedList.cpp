#include "LinkedList.h"
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
	Node* newNode= new Node;
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