#include "LinkedList.h" // HandMade Array
using namespace algo;
template<class Type>
class StackList{
    private :
        // Permanent Value
        NodeSide<Type> *headStack;
        int size;
    public : 
        StackList(){
            headStack = nullptr;
            size = 0;
        }
        void DisplayRev(){
            NodeSide<Type> *temp = headStack;
            while(temp->next != nullptr){
                // cout << temp->data << " ";
                temp = temp->next;  
            }
            cout << "Data Reverse : ";
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << "\n";
            // delete temp;
        }
        void Display(){
            NodeSide<Type> *temp = headStack;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;  
            }
        }
        /**
         * Insert Into Head
        */
        void Push(Type data){
            NodeSide<Type> *temp = headStack;
            NodeSide<Type> *newNode = new NodeSide<Type>;
            //input data in newnode
            newNode->prev = nullptr;
            newNode->data = data;
            // Next is headStack, Because there is a chance that headStack can be null
            newNode->next = temp;
            if(temp != nullptr){
                temp->prev = newNode;
            }
            // Change Head Address
            headStack = newNode;
            size++;
        }
        Type peek(){
            assert(headStack != nullptr);
            return headStack->data;
        }
        void pop(){
            NodeSide<Type> *realData = headStack->next;
            NodeSide<Type> *temp = new NodeSide<Type>;

            temp = headStack;
            realData->prev = nullptr;

            delete temp;
            headStack = realData;
            size--;
        }
        bool Empty(){
            if(headStack != nullptr){
                return false;
            }else{
                return true;
            }
        }
        void Push2(Type data){
            NodeSide<Type> *newNode = new NodeSide<Type>;

            newNode->prev = nullptr;
            newNode->data = data;
            newNode->data = nullptr;

            NodeSide<Type> *temp = headStack;
            if(temp == nullptr){
                headStack = newNode;
                return;
            }
            temp->prev = newNode;
            newNode->next = temp;
            headStack = newNode;
            size++;
        }
        
};
template <class Type>
class QueueList{
    private:
        NodeSide<Type> *Queue;
        int size;
    public:
        QueueList(){
            Queue = nullptr;
            size = 0;
        }

        void Display(){
            while(Queue != nullptr){
                cout << Queue->data << " ";
                Queue = Queue->next;
            }
        }

        void EnQueue(Type data){
            NodeSide<Type> *temp = Queue;
            NodeSide<Type> *newNode = new NodeSide<Type>;
            newNode->prev = nullptr;
            newNode->next = nullptr;
            newNode->data = data;

            if(temp == nullptr){
                Queue = newNode;
                return;
            }
            while(temp->next != nullptr){
                 temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            size++;
        }
        void DeQueue(){
            NodeSide<Type> *temp = Queue;
            NodeSide<Type> *head = Queue->next;

            delete temp;

            Queue = head;
            size--;
        }
        Type Peek(){
            assert(Queue != nullptr);
            return Queue->data;
        }
};
template <class Type>
class QueueCircular{
    private: 
        NodeSide<Type> *front;
        int size;
    public:
        QueueCircular(){
            front = nullptr;
            size = 0;
        }
        void display(){
            NodeSide<Type> *temp = front;
            while(temp->next != front){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << temp->data;
        }
        void EnQueue(Type data){
            NodeSide<Type> *temp = front;
            if(temp == nullptr){
                NodeSide<Type> *newNode = new NodeSide<Type>;
                newNode->data = data;
                newNode->prev = newNode->next = newNode;
                front = newNode;
                return;
            }
            // Take The Last Data
            NodeSide<Type> *lastData = front->prev;

            // Create New Node An New Connection
            NodeSide<Type> *newNode = new NodeSide<Type>;
            newNode->data = data; // Input Data
            newNode->next = front; // Connecting next NewNode To Front Node
            front->prev = newNode; // Connect Front Prev to NewNode 
            newNode->prev = lastData; // Connect Prev NewNode to Last Data
            lastData->next = newNode; // Connect next Last Data to NewNode
        }
        void DeQueue(){
            NodeSide<Type> *temp = front;
            if(temp == nullptr){
                cout << "Data Empty\n";
                return;
            }
            NodeSide<Type> *newFront = front->next; // Take Next Node Data
            NodeSide<Type> *tail = temp->prev; // Take Prev Node Data
            
            newFront->prev = tail; // Connecting
            tail->next = newFront; // Connecting

            front = newFront; // Make newFornt As A NEw Header
            delete (temp); // Delete Node
        }
        NodeSide<Type> *SearchData(Type data){
            NodeSide<Type> *search = front;
            while(search->next != front){
                if(search->data == data){
                    return search;
                }
                search = search->next;
            }
            return search;
        }
        /**
         * \brief Insert Data After THe Seach Value
         * @param data Value That Y0u want to put
         * @param searchValue Value That you want to put after
        */
        void insertAfter(Type data, Type seachValue){
            NodeSide<Type> *searchData = SearchData(seachValue);
            if(searchData->data != seachValue){
                cout << "Data Value is Not Present\n";
                return;
            }
            NodeSide<Type> *newNode = new NodeSide<Type>;
            newNode->data = data;
            newNode->prev = nullptr;
            newNode->next = nullptr;

            // If Front Node is NULL
            if(front == nullptr){
                newNode->next = newNode;
                newNode->prev = newNode;
                front = newNode;
                return; 
            }
            newNode->next = searchData->next;
            newNode->prev = searchData;
            searchData->next = newNode;
        }
};