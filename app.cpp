#include<iostream>
using namespace std;

class Node
{
    public:

    string Names;
    Node *next;

    Node(string val)
    {
        Names = val;
        next = nullptr;
    }
};

class app
{
    public:
    app();
    ~app();
    bool init();
    void menu();
    void DisplayBooks();
    void readBook(string bookName);
    string searchBook(Node *head, int index);
    


    private:
    int choice;
    int BookChoice;
    Node *head;
    string bookname;
};
