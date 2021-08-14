//
// Created by kaiven on 2021/8/13.
//

#include "../public.h"

/*
 * 非递归后序输出十字链表的树
 *  算法思想：
 *      首先一直往左边走，并全部入栈
 *      如果遇到叶子节点，说明没有其没有左边的孩子了，
 *      这时候需要看看这个节点的右边是否有元素，
 *      如果有元素，且这个元素还没有访问过，则在沿着这个元素的左边入栈（这里一定要保证元素没有访问过，否则会造成死循环）
 *      如果没有元素则说明可以出栈
 *
 *
 * */
void show_post_tree_with_stack(BiTree T){
    stack ss;
    ini_stack(ss);
    // 设置一个最经访问的指针，放置重复访问
    BiTNode *recent_visit = nullptr;
    BiTNode *p = T;
    // 后面的条件保证第一次能够进入循环
    while (!is_empty_stack(ss) || p){
        if (p){
            // 一直往左边走，并全部入栈
            push(ss, p);
            p = p->lchild;
        } else{
            // 如果遇到叶子节点，说明没有其没有左边的孩子了，
            // 这时候需要看看这个节点的右边是否有元素，
            // 如果有元素，且这个元素还没有访问过，则在沿着这个元素的左边入栈（这里一定要保证元素没有访问过，否则会造成死循环）
            // 如果没有元素则说明可以出栈
            p = get_top(ss);
            if (p->rchild && p->rchild != recent_visit){
                // 存在右边的孩子，且没访问过
                p = p->rchild;
            } else{
                // 已经访问过，或者没有右边的孩子
                pop(ss);
                recent_visit = p;               // 记录
                p = nullptr;                    // 将p置为null，让它不能往左边走
            }
        }
    }

}

int main(){
    BiTree T = get_tree();
    // 递归显示的树
    show_post_tree(T);
    cout << endl;
    // 通过非递归的方式输出
    show_post_tree_with_stack(T);
    return 0;
}