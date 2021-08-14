//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 * 实现树的从下到上，从右到左遍历
 *  思想
 *      先使用层序遍历
 *      将遍历之后的结果放入栈中，在一个一个的弹出
 *
 * */
void show_reverse_level_tree(BiTree T){
    Quene q;
    stack ss;
    ini_stack(ss);
    ini_Quene(q);
    BiTNode *p = T;
    // 将根元素先进入队列
    enter_quene(q, p);
    while (!is_empty_quene(q)){
        p = exit_quene(q);
        // 放入栈中
        push(ss,p);
        // 如果有左右孩子，就入队列,先左，后右
        if (p->lchild){
            enter_quene(q, p->lchild);
        }
        if (p->rchild){
            enter_quene(q, p->rchild);
        }
    }

    while (!is_empty_stack(ss)){
        pop(ss);
    }
}

int main(){
    BiTree T = get_tree();
    show_reverse_level_tree(T);
    return 0;
}