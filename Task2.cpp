// Danyal Asfar
// 552124
// section D
// BS-CS-15D

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

        int CountNodes(){
            int count = 0;

            node* currentNode = head;

            while (currentNode != nullptr){
                count++;
                currentNode = currentNode -> next;
            }

            return count;
        }
};

int main(){

    List linkedList;

    int n, data;
    cout << "Enter Number of Nodes:\n";
    cin >> n;

    while (n < 0){
        cout << "Invalid! Must be Non-Negative!!!\nTry Again:\n";
        cin >> n;
    }

    cout << endl;
    for (int count = 0; count < n; count++){
        cout << "Enter an Integer:\n";
        cin >> data;
        linkedList.AddData(data);
    }

    linkedList.PrintList();
    cout << "Count: " << linkedList.CountNodes();

    linkedList.ClearList();
    return 0;
}