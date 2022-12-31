#include<iostream>
using namespace std;

class LinkedList{
    class node{
        public:
        int data;
        node* next;
        node(int data, node* next){
            this->next = next;
            this->data = data;
        }
        node(int data){
            this->data = data;
        }
    };

    node* head; // 
    node* curr;
    int SIZE;
    public:
    LinkedList(){
        head = new node(-1, NULL);
        curr = head;
        SIZE = 0;
    }
    int get(int index){
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
        curr->next = new node(data, NULL);
        curr = curr->next;
        SIZE++;
    }

    void insert(int index, int data){
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
        itr->data = data;
        return;
    }
    
    void erase(int index){
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
        delete itr->next;
        itr->next = t;
        SIZE--;
    }

    int size(){
        return SIZE;
    }

    void clear(){
        node* itr = head->next;
        while(itr != NULL){
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