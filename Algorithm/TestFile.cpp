#include "StackLinked.h"
#include "Dequeu.h"
main(){
    // QueueCircular<int> QC;
    // QC.EnQueue(10);
    // QC.EnQueue(20);
    // QC.EnQueue(30);
    // QC.EnQueue(30);
    // QC.insertAfter(50, 20);
    // QC.display();
    Dequeue<int> dq(6);
    dq.insertFront(10);
    dq.insertFront(11);
    dq.insertRear(12);
    dq.display();
}