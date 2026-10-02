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

        void CreateThreeNodes(){

            int addData;

            for (int count = 1; count < 4; count++){
                cout << "Enter an Integer\n";
                cin >> addData;
                AddData(addData);
            }
        }

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
};

int main(){

    List linkedList;

    linkedList.PrintList();
    linkedList.CreateThreeNodes();
    linkedList.PrintList();

    linkedList.ClearList();
    return 0;
}