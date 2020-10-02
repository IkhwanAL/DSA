#include <iostream>
using namespace std;
#define MAX 6
template <class CC>
class Dequeue{
    private:
        CC arr[MAX] = {0};
        int size;
        int front;
        int rear;
    public:
        Dequeue(int size){
            front = -1;
            rear = 0;
            this->size = size;
        }
        bool isFull(){
            if((front == 0 && rear == size - 1) || front == rear + 1){
                return true;
            }else{
                return false;
            }
        }
        bool isEmpty(){
            if(front == -1){
                return true;
            }else{
                return false;
            }
        }
        void display(){
            for(int i = 0; i < MAX; i++){
                cout << arr[i] << " ";
            }
        }
        void insertFront(CC data){
            if(isFull()){
                cout << "Data Overflow\n";
                return;
            }
            if(front == -1){
                front = 0;
                rear = 0;
            }else if(front == 0){
                front = size - 1;
            }else{
                front = front - 1;
            }
            arr[front] = data;
        }
        void deleteFront(){
            if(isEmpty()){
                cout << "Data Underflow\n";
                return;
            }
            if(front == rear){
                front = -1;
                rear = -1;
            }else if(front == size - 1){
                front = 0;
            }else{
                front = front + 1;
            }
            arr[front] = 0;
        }
        void insertRear(CC data){
            if(isFull()){
                cout << "Data OVerflow\n";
                return;
            }
            if(front == -1){
                front = 0;
                rear = 0;
            }else if(rear == size - 1){ // if rear reach end
                rear = 0;
            }else{
                rear = rear + 1;
            }
            arr[rear] = data;
        }
        void deleteRear(){
            if(isEmpty()){
                cout << "Data Undeflow\n";
                return;
            }
            if(front == rear){
                front = -1;
                rear = -1;
            }else if(rear == 0){
                rear = size - 1;
            }else{
                rear = rear - 1;
            }
            arr[rear] = 0;
        }
        
};