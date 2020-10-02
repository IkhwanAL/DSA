#include "StackLinked.h"
#include "Dequeu.h"
#include "cstring"
bool Pairing(char peek, char close){
    if(peek == '{' && close == '}') return true;
    else if(peek == '[' && close == ']') return true;
    else if(peek == '(' && close == ')') return true;
    else return false;
}
bool checkParentesis(char *data){
    StackList<char> pt;
    for(int i = 0; i < strlen(data); i++){
        if(data[i] == '{' || data[i] == '[' || data[i] == '('){
            pt.Push(data[i]);
        }else if(data[i] == '}' || data[i] == ']' || data[i] == ')'){
            if(pt.Empty() || !Pairing(pt.peek(), data[i])){
                return false;
            }else{
                pt.pop();
            }
        }
    }
    return pt.Empty() ? true : false;
}
main(){
    // QueueCircular<int> QC;
    // QC.EnQueue(10);
    // QC.EnQueue(20);
    // QC.EnQueue(30);
    // QC.EnQueue(30);
    // QC.insertAfter(50, 20);
    // QC.display();
    
    // Dequeue<int> dq(6);
    // dq.insertFront(10);
    // dq.insertFront(11);
    // dq.insertRear(12);
    // dq.insertFront(15);
    // dq.insertFront(20);
    // dq.insertRear(1);
    // dq.deleteFront();
    // dq.deleteRear();
    // dq.display();

    //Check Balanced Parenthesis
    char test[10] = "{[]}";
    if(checkParentesis(test)){
        cout << "Balanced";
    }else{
        cout << "No Balance";
    }
}