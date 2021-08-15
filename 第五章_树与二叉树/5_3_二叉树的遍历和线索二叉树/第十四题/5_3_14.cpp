//
// Created by kaiven on 2021/8/15.
//

#include "../public.h"

/*
 * 计算二叉树的宽度
 * 算法思想
 *      使用层序遍历，记录下最宽的那一层
 * */
int get_width(BiTree T){
    Quene q;
    ini_Quene(q);
    BiTNode *p = T;
    enter_quene(q,p);
    int width = 0;      // 记录最大宽度
    BiTNode *last = p;      // 指向当前层最后一个元素
    while (!is_empty_quene(q)){
        p = exit_quene(q);
        if (p->rchild){
            enter_quene(q,p->rchild);
        }
        if (p->lchild){
            enter_quene(q,p->lchild);
        }

        if (p == last){
            // 如果最后一个节点出栈说明此时栈中全部都是下一层的节点
            // 统计该层的节点个数，并记录最后一个节点的指针
            last = get_rear(q);
            // 长度，这里因为是循环队列，计算方式有点问题，大概是这个意思
            if (q.rear-q.head > width){
                width = q.rear-q.head;
            }
        }
    }
    return width;
}

int main(){
    BiTree T = get_tree();
    cout << "树的宽度是" << endl;
    cout << get_width(T) << endl;
    return 0;
}