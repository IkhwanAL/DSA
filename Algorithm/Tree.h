#include "LinkedList.h"

template <typename T>
void inOrder(NodeSide<T> *Root){
    if(Root == nullptr) return;
    inOrder(Root->prev);
    cout << Root->data << " -> ";
    inOrder(Root->next);
}
template <typename T>
void preOrder(NodeSide<T> *Root){
    if(Root == nullptr) return;
    cout << Root->data << " -> ";
    preOrder(Root->prev);
    preOrder(Root->next);
}
template <typename T>
void postOrder(NodeSide<T> *Root){
    if(Root == nullptr) return;
    postOrder(Root->prev);
    postOrder(Root->next);
    cout << Root->data << " -> ";
}
template <typename CC>
NodeSide<CC> *ConvertArrToTree(CC *arr, NodeSide<CC> *Node, int i, int size){
    if(i < size){
        NodeSide<CC> *temp = new NodeSide<CC>(arr[i]);
        Node = temp;

        Node->prev = ConvertArrToTree(arr, Node->prev, 2*i + 1, size);
        Node->next = ConvertArrToTree(arr, Node->next, 2*i + 2, size);
    }
    return Node;
}
void TreeSituation(int size){
    int leaf = size + 1;
    int nodes = 2*size+1;
    int internal = (size - 1) / 2;
    int leaf1 = (size + 1) / 2;
    int nodes1 = 2*leaf - 1;
    int internal1 = leaf - 1;

    cout << leaf << endl;
    cout << nodes << endl;
    cout << internal << endl;
    cout << leaf1 << endl;
    cout << nodes1 << endl;
    cout << internal1 << endl;
}
/**
 * \brief Full Binary Tree either have two nodes or None
 * @param Node for the input
 * \return true / false
*/
template <typename CC>
bool isItFullBinaryTree(NodeSide<CC> *Node){
    if(Node == nullptr){
        return true;
    }else if(Node->prev == nullptr && Node->next == nullptr){
        return true;
    }
    if((Node->prev) && (Node->next)){
        return (isItFullBinaryTree(Node->prev) && isItFullBinaryTree(Node->next));
    }
    return false;
}
template <typename CC>
int depth(NodeSide<CC> *Node){
    int d = 0;
    while(Node != nullptr){
        d++;
        Node = Node->next;
    }
    return d;
}
template <typename CC>
bool perfectBinaryTree(NodeSide<CC> *Node, int depth, int level = 0){
    if(Node == nullptr){
        return true;
    }else if(Node->prev == nullptr && Node->next == nullptr){
        return depth == level + 1;
    }

    return perfectBinaryTree(Node->prev, depth, level + 1) &&
        perfectBinaryTree(Node->next, depth, level + 1);
}
template <typename CC>
bool isItPerfectBinaryTree(NodeSide<CC> *Node){
    int d = depth(Node);
    return perfectBinaryTree(Node, d);
}
template <typename CC>
int TotalNodes(NodeSide<CC> *Node){
    if(Node == nullptr) return (0);
    else return (1 + TotalNodes(Node->prev) + TotalNodes(Node->next));
}
template <typename CC>
bool isItCompleteBinaryTree(NodeSide<CC> *Node){
    int total = TotalNodes(Node);
    int index = 0;
    return completeBinaryTree(Node, index, total);
}
template <typename CC>
bool completeBinaryTree(NodeSide<CC> *Node, int index, int total){
    if(Node == nullptr){
        return true;
    }else if(index >= total){
        return false;
    }

    return (completeBinaryTree(Node->prev, 2*index + 1, total)
            && completeBinaryTree(Node->next, 2*index + 2, total));
}
template <typename CC>
bool isItBalancedBinaryTree(NodeSide<CC> *Node){
    int ln, rn;

    if(Node == nullptr){
        return true;
    }

    ln = height(Node->prev);
    rn = height(Node->next);

    if(abs(ln - rn) <= 1 && isItBalancedBinaryTree(Node->prev) && isItBalancedBinaryTree(Node->next)){
        return true;
    }
    return false;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

template <typename CC>
int height(NodeSide<CC> *Node){
    if(Node == nullptr)return (0);
    else return 1+max(height(Node->prev), height(Node->next));
}