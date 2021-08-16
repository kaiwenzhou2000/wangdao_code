//
// Created by kaiven on 2021/8/16.
//

#include "../public.h"

// 线索化
ThreadNode *pre = nullptr;          // 表示当前节点的前驱
void visit(ThreadNode *p){
    p->rtag = 0;
    p->ltag = 0;
    // 没有左孩子（实现左边的指针）
    if (p->lchild == nullptr){
        p->lchild = pre;
        p->ltag = 1;
    }

    // pre节点右边的指针
    if (pre != nullptr && pre->rchild == nullptr){
        pre->rchild = p;
        pre->rtag = 1;
    }

    pre = p;        // 将pre指向当前节点
}

// 中序遍历+线索化
void InThread(ThreadTree &T){
    if (T == nullptr){
        return;
    }

    InThread(T->lchild);
    visit(T);
    InThread(T->rchild);
}


// 对于中序线索二叉树找到指定结点的前驱
ThreadNode* find_pre(ThreadNode *p){
    if (p->ltag == 1){
        // 表示左边被线索化
        return p->lchild;
    } else{
        // 表示没有被线索化
        // 他的前驱是左子树的最右边的节点
        ThreadNode *q = p->lchild;
        // 首先宝保证右边有节点，还要右边的节点不是线索化之后的节点
        while (q->rchild && q->rtag == 0){
            q = q->rchild;
        }
        return q;
    }
}

int main(){
    ThreadTree T = get_tree_with_thread();
    InThread(T);        // 线索化二叉树
    cout << find_pre(T->rchild)->data << endl;
    return 0;
}