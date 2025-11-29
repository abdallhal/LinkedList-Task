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
