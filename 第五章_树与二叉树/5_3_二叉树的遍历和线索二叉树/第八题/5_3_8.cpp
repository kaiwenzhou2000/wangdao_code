//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 * 确定拥有两分支节点的数量
 *  算法思想
 *      还是按照层次遍历的方法，判断有没有两个节点
 * */
int counter_node(BiTree T){
    int cnt = 0;
    Quene q;
    ini_Quene(q);
    BiTNode* p = T;
    enter_quene(q,p);
    int child = 0;
    while (!is_empty_quene(q)){
        child = 0;
        p = exit_quene(q);
        if (p->lchild != nullptr){
            enter_quene(q,p->lchild);
            child++;
        }
        if (p->lchild != nullptr){
            enter_quene(q,p->rchild);
            child++;
        }

        // 要是有两个孩子的话，cnt++
        if (child == 2){
            cnt++;
        }
    }
    return cnt;
}


/*
 * 采用递归的方式
 * 算法思想
 *      在每个准备要开始遍历的节点之前，判断存不存在两个孩子
 *      这里用全局变量cnt来记录个数
 * */
int cnt = 0;
void counter_node_without_quene(BiTNode *p){
    if (p == nullptr){
        return;
    }
    if (p->lchild && p->rchild){
        cnt++;
    }
    counter_node_without_quene(p->lchild);
    counter_node_without_quene(p->rchild);

}

int main(){
    BiTree T = get_tree();
    cout << counter_node(T) << endl;
    counter_node_without_quene(T);
    cout << cnt << endl;
    return 0;
}