// #include "../ReverseWord.h"
#include "cstring"
#include "string"
#include "Tree.h"
#include "array"
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

    /**
     * Check Balanced Parenthesis 
    */
    // char test[10] = "{[]}";
    // if(checkParentesis(test)){
    //     cout << "Balanced";
    // }else{
    //     cout << "No Balance";
    // }

    /**
     * Reverse Word
    */
    // string say = "Test";
    // string newWord = reverseWord(say);
    // cout << newWord;

    /**
     * 
    */
    NodeSide<int> *tr = new NodeSide<int>;
    tr->data = 12;
    tr->prev = new NodeSide<int>(11);
    tr->next = new NodeSide<int>(12);
    tr->prev->prev = new NodeSide<int>(22);
    tr->prev->next = new NodeSide<int>(88);
    tr->next->prev = new NodeSide<int>(10);
    tr->next->next = new NodeSide<int>(1);

    inOrder(tr);
    printf("\n");
    preOrder(tr);
    printf("\n");
    postOrder(tr);
    printf("\n");
    
    int arr[11] = {1,2,3,4,5,6,7,22,9,11,12};
    int t = sizeof(arr)/sizeof(arr[0]);
    
    NodeSide<int> *Tree;
    Tree = ConvertArrToTree(arr, Tree, 0, t);
    preOrder(Tree);
    printf("\n");

    //Example For Perfect Binary Tree
    NodeSide<int> *PR;
    PR = new NodeSide<int>(1);
    PR->prev = new NodeSide<int>(2);
    PR->next = new NodeSide<int>(3);
    PR->prev->prev = new NodeSide<int>(4);
    PR->prev->next = new NodeSide<int>(5);
    PR->next->prev = new NodeSide<int>(6);
    PR->next->next = new NodeSide<int>(7);
    preOrder(PR);
    printf("\n");
    if(isItCompleteBinaryTree(PR)) cout << "Yes";
    else cout << "No";
    printf("\n");
    int *height = 0;
    if(isItBalancedBinaryTree(PR)) cout << "Yes";
    else cout << "NO";
}