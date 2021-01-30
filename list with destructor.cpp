#include <iostream>

class list_element
{
public:
    list_element(int n=0, list_element* ptr=0):d(n),next(ptr){}
    int d;
    list_element* next;
};

class list
{
public:
    list():head(0), cursor(0){}
    list(const list& lst);
    ~list();
    void prepend(int n); //insert at front value n
    int get_element(){return cursor->d;}
    void advance(){cursor=cursor->next;}
    void print();
private:
    list_element* head;
    list_element* cursor;
};

void list::prepend(int n)
{
    if (head == 0) //empty list case
        cursor = head = new list_element(n,head);
    else //add to front-chain
        head = new list_element(n, head);
}

void list::print()
{
    list_element* h = head;
    while (h!=0)
    {
        std::cout << h->d << ", ";
        h = h->next;
    }
    std::cout << "###" << std::endl;
}

list::list(const list& lst) //deep copy constructor
{
    if (lst.head == 0)
    {
        head = 0; cursor = 0;
    }
    else
    {
        cursor = lst.head;
        list_element* h = new list_element();
        list_element* previous;
        head = h;
        h->d = lst.head->d;
        previous = h;

        for (cursor = lst.head; cursor !=0;) //copy
        {
            h = new list_element();
            h->d = cursor->d;
            previous->next = h;
            cursor = cursor->next;
            previous = h;
        }
        cursor = head;
    }
}

list::~list() //destructor
{
    std::cout << "destructor called" << std::endl; //just for demonstration-debug
    for (cursor = head; cursor != 0;)
    {
        cursor = head->next;
        delete head;
        head = cursor;
    }
}

int main()
{
    list a,b,d,e;
    int data[10] = {3,4,6,7,-3,5};
    //list d(data, 6);
    for (int i=0; i<6; ++i)
        d.prepend(data[i]);
    //list e(data, 10);
    for (int i=0; i<10; ++i)
        e.prepend(data[i]);
    a.prepend(9); a.prepend(8);
    std::cout << " list a " << std::endl;
    a.print();
    for (int i=0; i<40; ++i)
        b.prepend(i*i);
    std::cout << " list b " << std::endl;
    b.print(); std::cout << std::endl;
    list c(b);
    c.print(); std::cout << std::endl;
    d.print(); std::cout << std::endl;
    e.print(); std::cout << std::endl;
    return 0;
}
