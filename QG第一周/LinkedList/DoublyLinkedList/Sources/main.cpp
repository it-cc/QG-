#include "DoublyLinkedList.hpp"

int main()
{
    MyLinkedList<int> list;
    list.addLast(1);
    list.addLast(2);
    list.addLast(3);
    list.addFirst(0);
    list.add(2, 100);

    list.display();
    // size = 5
    // 0 <-> 1 <-> 100 <-> 2 <-> 3 <-> null
	

	return 0;
}