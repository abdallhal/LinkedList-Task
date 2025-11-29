

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList L;

    cout << "InsertFirst:" << endl;
    L.InsertFirst(3, 'C');
    L.InsertFirst(2, 'B');
    L.InsertFirst(1, 'A');
    L.Traverse();
    cout << endl;

    cout << "InsertEnd:" << endl;
    L.InsertEnd(4, 'D');
    L.InsertEnd(5, 'E');
    L.Traverse();
    cout << endl;

    cout << "Search(3):" << endl;
    cout << (L.Search(3) ? "Found" : "Not Found") << endl << endl;

    cout << "Cursor Data:" << endl;
    L.ToFirst();
    cout << L.GetData() << endl;
    L.Advance();
    cout << L.GetData() << endl << endl;

    cout << "Update Cursor:" << endl;
    L.UpdateData('Z');
    L.UpdateKey(99);
    L.Traverse();
    cout << endl;

    cout << "InsertAfter:" << endl;
    L.ToFirst();
    L.InsertAfter(10, 'X');
    L.Traverse();
    cout << endl;

    cout << "InsertBefore:" << endl;
    L.ToEnd();
    L.InsertBefore(20, 'Y');
    L.Traverse();
    cout << endl;

    cout << "DeleteFirst:" << endl;
    L.DeleteFirst();
    L.Traverse();
    cout << endl;

    cout << "DeleteEnd:" << endl;
    L.DeleteEnd();
    L.Traverse();
    cout << endl;

    cout << "DeleteNode (second node):" << endl;
    L.ToFirst();
    L.Advance();
    L.DeleteNode();
    L.Traverse();
    cout << endl;

    cout << "OrderInsert:" << endl;
    L.OrderInsert('M', 15);
    L.OrderInsert('N', 7);
    L.Traverse();
    cout << endl;

    cout << "ListSize:" << endl;
    cout << L.ListSize() << endl << endl;

    cout << "MakeListEmpty:" << endl;
    L.MakeListEmpty();
    cout << (L.isEmpty() ? "Empty" : "Not Empty") << endl;
}

