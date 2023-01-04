#include <iostream>
using namespace std;

class Stack{
    //this node have a next and a pre pointer along with data;
    class node{
        public:
        int data;
        node* next; // next pointer points to the next node
        node* pre; // pre pointer points to the previous node
        node(int data, node* next, node* pre){
            this->next = next;
            this->data = data;
            this->pre = pre;
        }
        node(int data){
            this->data = data;
            this->next = NULL;
            this->pre = NULL;
        }
    };
    node* BOTTOM; // dummy node, BOTTOM->next = first node
    node* TOP; // points to latest node
    int SIZE;
    public:
    Stack(){
        BOTTOM = new node(-1);
        TOP = BOTTOM;
        SIZE = 0;
    }
    
    void push(int data){
        TOP->next = new node(data, NULL, TOP);
        TOP = TOP->next;
        SIZE++;
    }

    void pop(){
        if(SIZE == 0){
            return;
        }
        TOP = TOP->pre;
        delete TOP->next;
        TOP->next = NULL;
        SIZE--;
    }

    int top(){
        if(SIZE == 0){
            cout << "Index out of bound"<<endl;
            return -1;
        }
        return TOP->data;
    }

    bool empty(){
        if(SIZE){
            return 0;
        }else {
            return 1;
        }
    }
    void erase(){
        node* itr = BOTTOM->next;
        while(itr != NULL){
            node * t = itr->next;
            delete itr;
            itr = t;
        }
        BOTTOM->next = NULL;
        TOP = BOTTOM;
        SIZE = 0;
    }
    int size(){
        return SIZE;
    }
};

int main(){
    Stack s;
    for(int i = 0; i < 1000; i++){
        s.push(i);
    }
    // s.erase();
    for(int i = 0; !s.empty(); i++){
        cout << s.top() << " "<<endl;
        s.pop();
    }
}