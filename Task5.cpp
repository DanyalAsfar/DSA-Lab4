#include <iostream>
using namespace std;

struct node{
    int data;
    node* next = nullptr;
};

class List{
    public:
        node* head = nullptr;
        node* tail = nullptr;

        // adds a node to the end (tail) of the list
        void AddData(int addData){
            node* newNode = new node;
            newNode -> data = addData;

            // if tail is empty, then list is empty
            if (tail == nullptr){
                head = newNode;
            }
            else{
                tail -> next = newNode;
            }

            // tail points to the newest node added to the end of the list
            tail = newNode;
        }

        void PrintList(){
            
            if (head==nullptr){
                cout << "List is Empty!!!\n";
            }
            else{
                node* currentNode = head;
                cout << endl;

                // go till end of list reached
                while (currentNode != nullptr){
                    cout << currentNode -> data << endl;
                    currentNode = currentNode -> next;
                }

            }
        }

        void ClearList(){
            node* currentNode = head;
            node* nextNode;
            while (currentNode != nullptr){
                nextNode = currentNode -> next;
                delete currentNode;
                currentNode = nextNode;
            }

            head = nullptr;
            tail = nullptr;
        }

        void InsertAtBeginning(int addData){
            node* newNode = new node;
            newNode -> data = addData;
            newNode -> next = head;

            if (head == nullptr)
                tail = newNode;
            head = newNode;
        }

        void DeleteNode(int delData){
            node* currentNode;
            node* prevNode;

            currentNode = head;
            prevNode = nullptr;

            while (currentNode != nullptr && currentNode -> data != delData){
                prevNode = currentNode;
                currentNode = currentNode -> next;
            }

            if (currentNode == nullptr)
                cout << "\nValue not in Linked List!!!";
            else{

                if (tail == currentNode)
                        tail = prevNode;
                if (head == currentNode)
                    head = currentNode -> next;
                else{
                    prevNode -> next = currentNode -> next;
                }
                delete currentNode;

                cout << "\nDeletion Successful!!!\n";
            }
        }
};

int main(){

    List linkedList;
    linkedList.AddData(10);
    linkedList.AddData(20);
    linkedList.AddData(20);
    linkedList.AddData(30);

    cout << "Test 1:\nLinked List:\n";
    linkedList.PrintList();
    linkedList.DeleteNode(10);
    cout << "Linked List:\n";
    linkedList.PrintList();

    linkedList.InsertAtBeginning(10);
    cout << "Test 2:\nLinked List:\n";
    linkedList.PrintList();
    linkedList.DeleteNode(20);
    cout << "Linked List:\n";
    linkedList.PrintList();

    cout << "Test 3:\nLinked List:\n";
    linkedList.PrintList();
    linkedList.DeleteNode(30);
    cout << "Linked List:\n";
    linkedList.PrintList();


    return 0;
}