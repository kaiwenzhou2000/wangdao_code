//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 * 判断是不是完全二叉树
 *  算法思想
 *      可以采用层次遍历思想，但是要把空节点也进入队列
 *      当空节点后面是非空节点的时候可以判定一定不是完全二叉树
 *
 * */
bool is_full_BiTree(BiTree T){
    BiTNode* a[maxN];
    int a_index = 0;
    Quene q;
    ini_Quene(q);
    BiTNode* p = T;
    enter_quene(q, p);
    a[a_index++] = p;

    // 获得带空节点的层次遍历的数组a
    while (!is_empty_quene(q)){
        p = exit_quene(q);
        if (p == nullptr){
            continue;
        }
        enter_quene(q,p->lchild);
        a[a_index++] = p->lchild;
        enter_quene(q,p->rchild);
        a[a_index++] = p->rchild;
    }

    // 判断空节点的后面的节点是不是非空节点
    for (int i = 0; i < a_index - 1; ++i) {
        if (a[i] == nullptr && a[i+1] != nullptr){
            return false;
        }
    }
    return true;
}

int main(){
    BiTree T = get_tree();
    cout << is_full_BiTree(T) << endl;
    return 0;
}