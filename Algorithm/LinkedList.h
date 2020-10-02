#include <iostream>
#include <cassert>
using namespace std;
/**
 * \brief Node Start From Zero - infinite
*/
template <typename T>
struct Node{
    T data;
    Node *next;
};
template <typename T>
struct NodeSide{
    NodeSide *prev;
    T data;
    NodeSide *next;
};
namespace algo{
    template <class Type>
    class DoublelinkedList{
        protected:
            // Main Data
            NodeSide<Type> *DataNode;

        public:
            DoublelinkedList(){
                DataNode = nullptr;
            }
            /**
             * \brief Show Data
            */
            void Display(){
                NodeSide<Type> *temp = DataNode;
                cout << "Data :";
                while(temp != nullptr){
                    cout << temp->data << " ";
                    temp = temp->next;
                }
            }
            /**
             * \brief Inserting Data in head Node
             * @param data Insert Value
            */
            void insertAtHead(Type data){
                // Create A new Node
                NodeSide<Type> *newHead = new NodeSide<Type>;
                // Put The Data
                newHead->data = data;
                // newHead prev and next
                newHead->prev = NULL;
                newHead->next = DataNode;
                
                if(DataNode != NULL){
                    DataNode->prev = newHead;
                }
                // Replace Head Address
                DataNode = newHead;
            }
            /**
             * \brief Insert Data in Node Tail
             * @param data Insert Value
            */
            void append(Type data){
                NodeSide<Type> *newNode = new NodeSide<Type>;

                NodeSide<Type> *lastNode = DataNode;
                newNode->data = data;
                newNode->next = nullptr;

                //Find next NULL next Node
                while(lastNode->next != nullptr){
                    lastNode = lastNode->next;
                }

                newNode->prev = lastNode;
                lastNode->next = newNode;
            }
            /**
             * \brief Delete THe Most Last Node
            */
            void pop(){
                // Create Temp Variable
                NodeSide<Type> *temp = new NodeSide<Type>;
                // Copy Data
                temp = DataNode;
                // Change into Next Node
                DataNode = DataNode->next;
                // Make Prev Node NULL
                DataNode->prev = nullptr;
                //Remove The Old Node
                delete temp;
            }
            /**
             * \brief Sorting Data for Linked List Data Structure 
            */
            void Merge(){
                NodeSide<Type> *head = DataNode;
                NodeSide<Type> *aside;
                NodeSide<Type> *back;

                SplitLink(head, &aside, &back);

                Merge(&aside);
                Merge(&back);

                DataNode = Sorting(aside, back);
            }
            /**
             * \brief Split Into 2 of Linked List, split until cannot be split anymore
             * @param Ref Reference of the Real Node
             * @param aside Returning Linked list front to mid List
             * @param back Returning Linked List mid to behind List  
            */
            void SplitLink(NodeSide<Type> *Ref, NodeSide<Type> &aside,
                            NodeSide<Type> &back)
            {
                if(Ref == nullptr){
                    cout << "Data is Empty \n";
                    return;
                }
                NodeSide<Type> *behind;
                NodeSide<Type> *front;
                front = Ref;
                behind = Ref->next;

                while(behind != nullptr){
                    behind = behind->next; // Just For Checking
                    if(behind != nullptr){
                        front = front->next;
                        behind = behind->next; // Just For Checking
                    }
                }
                // Divided into 2 linked list
                aside = Ref; // Take The First Data
                back = front->next; // Make next front Node as a new Reference
                front->next = nullptr; // Cut The Connection
            }
            /**
             * \brief Sort The Data for Data Structure Linked List
             * @param a head Node
             * @param b tail Node
             * \return New Node After Sorting
            */
            NodeSide<Type> *Sorting(NodeSide<Type> *a, NodeSide<Type> *b){
                NodeSide<Type> *first = nullptr;
                    if(a == nullptr){
                        return (b);
                    }else if(b == nullptr){
                        return (a);
                    }

                    if(a->data <= b->data){
                        first = a;
                        first->next = Sorting(a, b);
                    }else{
                        first = b;
                        first->next = Sorting(a, b);
                    }

                return first;
            }
            /**
             * \brief Search Data In the Linked List
             * @param temp Node Reference
             * @param Data Value That You want to find
            */
            NodeSide<Type> *SeqSearch(NodeSide<Type> *temp, Type Data){
                while(temp != nullptr){
                    if(temp->data == Data){
                        return temp;
                    }else{
                        temp = temp->next;
                    }
                }
                return temp;
            }
            /**
             * \brief Insert Data After The Value
             * @param data Value that you want to insert
             * @param searchValue After Value
            */
            void insertAfter(Type data, Type searchValue){
                NodeSide<Type> *newNode = new NodeSide<Type>;
                NodeSide<Type> *search = SeqSearch(DataNode, searchValue);
                if(search->data != 
                searchValue){
                    cout << "Value didn't exist\n";
                    return;
                }
                // Put Data In NewNode
                newNode->prev = nullptr;
                newNode->data = data;
                newNode->next = nullptr;

                newNode->next = search->next;
                newNode->prev = search;
                search->next = newNode;
            }
    };
    template <class T>
    /**
     * \brief Class For Creating LinkedList and
     * A few Function adding value to the linked list
    **/
    class linkedList{
        private:
            Node<T> *head;

        public:
            linkedList(){
                head = nullptr;
            }
            void display(){
                Node<T> *temp = head;
                cout << "Data : ";
                while(temp != nullptr){
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                delete temp;
            }
            // Reverse Pointer Address
            void Reversing(){
                Node<T> *data = head;
                Reverse(data); // Calling Reverse Function 
            }
            // Reversing Data
            void Reverse(Node<T> *data){
                if(data->next == nullptr){
                    head = data;
                    return;
                }
                Reverse(data->next);
                Node<T> *reverseNode = data->next;
                reverseNode->next = data;
                data->next = nullptr;
            }
            void push(T data){
                //First, Create a New Node
                Node<T> *newNode = new Node<T>;

                //Second, put the data into new Node
                newNode->data = data;

                //Third, Make next New Node As Head 
                newNode->next = head;

                //Fourth, Turn new Node as Head
                head = newNode;

            }
            Node<T> *SeqSearch(Node<T> *node, T value){
                while(node != nullptr){
                    if(node->data == value){
                        return node;
                    }else{
                        node = node->next;
                    }
                }
                return node;
            }
            /**
             * \brief Inserting New data into linked list After the Node
             * @param dataAfter Node of The Previous data
             * @param data New Node Data
             * \return Nothing
            **/
            void insertAfter(T data, T dataAfter){
                //Prologue Search Node Value
                Node<T> *prevNode = SeqSearch(head, dataAfter);
                if(prevNode->data != dataAfter){
                    cout << "Wrong Data Value\n";
                    return; // break The Function 
                }
                //1. create a new Node
                Node<T> *newNode = new Node<T>;

                //2. put data in the new Node
                newNode->data = data;

                //3. fill the the next newNode with next prevNode data,
                //   Leaving The next prevNode Empty  
                newNode->next = prevNode->next;

                //4. make empty next prevNode connect with newNode
                prevNode->next = newNode;
            }
            T firstData(Node<T> *dataNode){
                assert(dataNode != nullptr); // is it Not NULL ?
                return dataNode->data;
            }
            /**
             * \brief copy into new Linked List with
             * different pointer
             * 
            */
            Node<T>* copyLinked(){
                //Deklarasi Variable
                Node<T> *temp = head;
                Node<T> *newNode = new Node<T>;

                // Copy The First Data
                newNode->data = *new T(temp->data); // Make it A different Pointer
                newNode->next = NULL;

                //Record THe First Data, This Variable That Should Be Return
                Node<T> *const first = newNode;

                temp = temp->next;
                while(temp != nullptr){
                    // Create Variable Every Loop
                    newNode = newNode->next = new Node<T>;

                    //Insert into separate pointer variable
                    newNode->data = *new T(temp->data);

                    //Make Sure Bext is NULL
                    newNode->next = NULL;

                    //Go to next Node
                    temp = temp->next;
                }
                return first;
            }
            void append(T data){
                //1. Create New Node
                Node<T> *newNode = new Node<int>;

                //2. Connect last Node with Main Node
                Node<T> *last = head;

                //2. Put Data
                newNode->data = data;

                //3. Make Sure next Data is Null 
                newNode->next = NULL;

                if(head == nullptr){
                    head = newNode;
                    return;
                }

                while(last->next != NULL){
                    last = last->next;
                }

                last->next = newNode;
            }
            /**
             * \brief Deleting Node From The Linked List;
             * @param delValue Data to Delete
             * \return Nothing
            */
            void deleteNode(T delValue){
                
                Node<T> *temp = head, *prev;    
                
                //if The value is the first Node
                if(temp != NULL && temp->data == delValue){
                    temp = temp->next;
                    free(temp);
                    return;
                }

                while(temp != NULL && temp->data != delValue){
                    prev = temp; 
                    temp = temp->next; 
                }
                if(temp == NULL) return;

                // Unlink delValue From Data Recorded
                prev->next = temp->next;

                free(temp);
            }
            /**
             * \brief Start From 0, and this function is
             * Turning Value into normal Condition
            */
            void delNodePosition(int position){
                Node<T> *copy = copyLinked();

                //Checking initial Value
                if(copy == NULL){
                    return; 
                }
                Node<T> *temp = copy;
                
                //if The Position is 0
                if(position == 0){
                    copy = temp->next;
                    free(temp);
                    return;
                }
                // If Position is More than 1
                for(int i = 0; temp!=NULL && i < position - 1; i++){
                    temp = temp->next;
                }

                if(temp == NULL || temp->next == NULL){
                    return;
                }

                // Take The Value From the temp->next
                // and Put into a new Variable
                Node<T> *nextNode = temp->next->next;
                
                //Free Memory
                free(temp->next);

                //Unlink The Value With The new Variable nextNode
                temp->next = nextNode;

                head = copy;
            }
    };
}