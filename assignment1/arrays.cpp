#include <iostream>
using namespace std;

class array{
    int MaxLength = 10; // max size of our array 
    int in = 0; // index or size, this will point to the right side of last element or to 0 with the array is empty
    int *mainArray; // pointer for our array
    public:
    array(){
        mainArray = new int[10](); // first initialising it with size 10
    }
    
    int get(int index){
        if(index < MaxLength){
            cout << "Index out of bond"<<endl;
            return -1;
        }
        return mainArray[index];
    }
    
    int add(int data){
        // checking if our index has reached max length
        if(in < MaxLength){
            mainArray[in] = data;
            in++;
        }else{
            // now to increase the size we create a new array twice the size of old one
            int * arr = new int[2 * MaxLength];
            //now we copy the old element in new array
            for(int i = 0; i < MaxLength; i++){
                arr[i] = mainArray[i];
            }
            MaxLength *= 2;
            // deleting the old array from the memory
            delete mainArray;
            // pointing our main main pointer to the new array
            mainArray = arr;
            // adding the data
            mainArray[in] = data;
            in++;
        }
    }

    void insert(int index, int data){
        if(index < MaxLength){
            cout << "Index out of bound"<<endl;
        }
        else mainArray[index] = data;
    }
    void erase(int index){
        if(index > in){
            cout << "Index out of bond"<<endl;
            return;
        }
        // here we are swaping every element on the right side of the given index to their left position
        for(int i = index; i < in; i++){
            int t = mainArray[i];
            mainArray[i] = mainArray[i + 1];
            mainArray[i + 1] = t;
        }
        in--;
    }
    int size(){
        return in;
    }
    int clear(){
        // to clear every element we just put our pointer to the 0th index
        in = 0;
    }
    void printArray(){
        for(int i = 0; i < in; i++){
            cout << mainArray[i]<< " ";
        }
        cout << endl;
    }
};
int main(){
    array arr;
    for(int i = 0; i < 75; i++){
        arr.add(i);
    }
    cout << arr.size()<<endl;
    arr.erase(1);
    arr.printArray();
    arr.clear();
    arr.printArray();
}