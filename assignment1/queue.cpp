#include <iostream>
using namespace std;

class Queue{
    class node{
        public:
        int data;
        node* next;
        node(int data){
            this->data = data;
            this->next = NULL;
        }
        node(int data, node* next){
            this->data = data;
            this->next = next;
        }
    };
    node* FRONT;
    node* LAST;
    int SIZE;
    public:
    Queue(){
        FRONT = new node(-1, NULL);
        LAST = FRONT;
        SIZE = 0;
    }

    int push(int data){
        LAST->next = new node(data, NULL);
        LAST = LAST->next;
        SIZE++;
    }

    int front(){
        if(SIZE == 0){
            cout << "stack is empty"<<endl;
            return -1;
        }
        return FRONT->next->data;
    }

    void pop(){
        if(SIZE == 0){
            return;
        }
        node* t = FRONT->next->next;
        delete FRONT->next;
        FRONT->next = t;
        SIZE--;
    }

    bool empty(){
        if(SIZE){
            return 0; 
        }else return 1;
    }

    int size(){
        return SIZE;
    }
};
int main(){
    Queue q;
    for(int i = 0; i < 1000; i++){
        q.push(i);
    }
    for(int i = 0; !q.empty(); i++){
        cout << q.front()<<endl;
        q.pop();
    }
}