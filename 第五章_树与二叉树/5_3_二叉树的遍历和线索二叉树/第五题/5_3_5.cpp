//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 * 使用非递归算法得到树的高度
 *  算法思想
 *      类似于后序遍历
 *      而栈的最高长度就是树的高度
 *
 * */
int get_tree_height(BiTree T){
    stack ss;
    ini_stack(ss);
    BiTNode* p = T;
    BiTNode* recent_visit = nullptr;
    int height = 0;
    while (!is_empty_stack(ss) || p){
        if (p){
            push(ss,p);
            p = p->lchild;
            if (ss.top + 1 > height){
                height = ss.top + 1;
            }
        } else{
            p = get_top(ss);
            if (p->rchild != nullptr && p->rchild != recent_visit){
                p = p->rchild;
            } else{
                pop(ss);
                recent_visit = p;
                p = nullptr;
            }
        }
    }
    return height;
}

/*
 * 王道书上使用的层序遍历的方法确定高度
 *
 * */
int get_tree_height_with_level(BiTree T){
    Quene q;
    ini_Quene(q);
    BiTNode* p = T;
    int height = 0;
    BiTNode* last = p;        // 该层最后一个节点
    enter_quene(q,p);
    while (!is_empty_quene(q)){
        p = exit_quene(q);
        if (p->lchild){
            enter_quene(q,p->lchild);
        }
        if (p->rchild){
            enter_quene(q,p->rchild);
        }
        if (p == last){
            height++;
            last = get_rear(q);          // 指向本层最后的元素
        }
    }
    return height;
}


int main(){
    BiTree T = get_tree();
    cout << endl;
    cout << "树的高度是(后序)：" << get_tree_height(T) << endl;
    cout << "树的高度是(层次)：" << get_tree_height_with_level(T) << endl;
    return 0;
}