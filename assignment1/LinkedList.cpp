#include<iostream>
using namespace std;

class LinkedList{
    // creating a node class 
    class node{
        public:
        int data; // value  
        node* next; // pointer to next node
        node(int data, node* next){
            this->next = next;
            this->data = data;
        }
        node(int data){
            this->data = data;
        }
    };

    node* head; // dummy pointer 
    node* curr; // current node or last node
    int SIZE;
    public:
    LinkedList(){
        head = new node(-1, NULL);
        curr = head;
        SIZE = 0;
    }
    int get(int index){
        // to get through the given index we start from i = 0 
        node* itr = head->next;
        int i = 0;
        while(itr != NULL && i != index){
            itr = itr->next;
            i++;
        }
        if(i != index){
            cout << "Index out of bond"<<endl;
            return -1;
        }
        return itr->data;
    }

    void add(int data){
        // adding the new data by adding a new node at the end of the last node
        curr->next = new node(data, NULL);
        //  making the new node as the last node
        curr = curr->next;
        SIZE++;
    }

    void insert(int index, int data){
        // for inserting data in the given index we iterate from the index i = 0 
        node* itr = head->next;
        int i = 0;
        while(itr != NULL && i != index){
            itr = itr->next;
            i++;
        }
        if(i != index){
            cout << "Index out of bond"<<endl;
            return;
        }
        // after reaching the disired node we change its data
        itr->data = data;
        return;
    }
    
    void erase(int index){
        // to erase a node we reach that index by interating from i = 0
        node* itr = head;
        int i = 0;
        while(itr->next != NULL && i != index){
            itr = itr->next;
            i++;
        }
        if(i != index){
            cout << "Index out of bond"<<endl;
            return;
        }

        node* t = itr->next->next;
        // deleting the node
        delete itr->next;
        itr->next = t;
        SIZE--;
    }

    int size(){
        return SIZE;
    }

    void clear(){
        // to clear the whole linked list we interate from i =0 to end and delete every node 
        node* itr = head->next;
        while(itr != NULL){
            //first store the next pointer so that we don't lose it
            node * t = itr->next;
            delete itr;
            itr = t;
        }
        curr = head;
        head->next = NULL;
        SIZE = 0;
    }

};
int main(){
    LinkedList l;
    for(int i = 0; i < 100; i++){
        l.add(i);
    }
    // l.insert(0, 1);
    l.erase(99);
    for(int i = 0; i < l.size(); i++){
        cout << l.get(i)<<endl;
    }
    l.clear();
    for(int i = 0; i < l.size(); i++){
        cout << l.get(i)<<endl;
    }
}