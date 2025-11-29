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
bool LinkedList::AtFirst() {
	// if cursor is at head or list is empty and cursor is also empty
	return (cursor == head)||(isEmpty()&&CursorIsEmpty());	
}