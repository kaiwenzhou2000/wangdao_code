//
// Created by kaiven on 2021/8/19.
//

#ifndef WANGDAO_CODE_PUBLIC_H
#define WANGDAO_CODE_PUBLIC_H

#include "iostream"
#include "cstdlib"

using namespace std;

typedef struct CSNode{
    int data;
    struct CSNode *firstchild, *nextsibling;        // 左孩子，右兄弟
}CSNode,*CSTree;

CSTree get_CSTree(){
    CSTree T = (CSNode*) malloc(sizeof(CSNode));
    T->data = 1;
    // 左孩子
    T->firstchild = (CSNode*) malloc(sizeof(CSNode));
    T->firstchild->data = 1;
    T->firstchild->firstchild = nullptr;
    T->firstchild->nextsibling = nullptr;

    // 右孩子
    T->nextsibling = (CSNode*) malloc(sizeof(CSNode));
    T->nextsibling->data = 1;
    T->nextsibling->firstchild = nullptr;
    T->nextsibling->nextsibling = nullptr;
    return T;
}

#endif //WANGDAO_CODE_PUBLIC_H
