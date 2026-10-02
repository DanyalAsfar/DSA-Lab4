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

        int CountNodes(){
            int count = 0;

            node* currentNode = head;

            while (currentNode != nullptr){
                count++;
                currentNode = currentNode -> next;
            }

            return count;
        }

        void SearchNode(int searchData){
            node* currentNode = head;
            int position = 1;

            while (currentNode != nullptr && currentNode -> data != searchData){
                position++;
                currentNode = currentNode -> next;
            }

            if (currentNode == nullptr)
                cout << "Value Not Found";
            else
                cout << "Value Found at Position: " << position;
        }

        void PrintSecondNode(){
            node* currentNode = head;
            int position = 1;

            while (currentNode != nullptr){
                if (position == 2){
                    cout << currentNode -> data;
                    return;
                }
                position++;
                currentNode = currentNode -> next;
            }

            cout << "Fewer than two nodes exist!!!\n";
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
    int option = -1;

    while (option != 9){
        cout << "\n\n1. Add Data to Linked List\n2. Print Linked List\n3. Count Nodes in Linked List\n4. Search for a Node in Linked List\n"
            << "5. Print Second Node in Linked List\n6. Insert Node at Beginning of Linked List\n7. Delete Node from Linked List\n"
            << "8. Clear Linked List\n9. Exit Program\n";
        cout << "Select an Option:\n";
        cin >> option;

        switch (option){
            case 1:
                int data;
                cout << "Enter an Integer:\n";
                cin >> data;
                linkedList.AddData(data);
                break;

            case 2:
                linkedList.PrintList();
                break;

            case 3:
                cout << "Number of Nodes in List: " << linkedList.CountNodes() << endl;
                break;

            case 4:
                int searchData;
                cout << "Enter an Integer to Search for in Linked List:\n";
                cin >> searchData;
                linkedList.SearchNode(searchData);
                break;

            case 5:
                linkedList.PrintSecondNode();
                break;

            case 6:
                int addData;
                cout << "Enter an Integer to Add to Beginning of Linked List:\n";
                cin >> addData;
                linkedList.InsertAtBeginning(addData);
                break;

            case 7:
                int delData;
                cout << "Enter an Integer to Delete from Linked List:\n";
                cin >> delData;
                linkedList.DeleteNode(delData);
                break;

            // intentional fall through to case 8 to clear list before exiting
            case 9:
                cout << "\nExiting Program!!!\n";

            case 8:
                linkedList.ClearList();
                cout << "\nLinked List Cleared!!!\n";
                break;

            default:
                cout << "\nInvalid Option!!!\n";
        }
    }
    return 0;
}