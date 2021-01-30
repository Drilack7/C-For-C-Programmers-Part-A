#include <iostream>

struct slistelem {char data; slistelem* next;}

class slist
{
public:
    slist():h(0){} //empty list
    ~slist() //destructor
    {
        std::cout << "destructor called" << std::endl; //just for demonstration-debug
        release(); //march through list with deletes
    }

private:
    slistelem* h; //list head
}

void slist::prepend (char* c)
{
    slistelem* temp = new slistelem; //possibility for bad_alloc exception thrown
    temp->next = h; //single link
    temp->data = c;
    h = temp; //update h
}
