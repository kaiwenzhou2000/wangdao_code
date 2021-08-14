//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 *  查找x的所有祖先
 *  使用后序遍历，
 *  在栈中的都是祖先
 *  注意，这里不能用层序遍历，
 *  因为在这个节点上面的不一定都是祖先
 *
 * */
void find_ancestor(BiTree T, char ch){
    stack ss;
    ini_stack(ss);
    BiTNode *p = T;
    BiTNode *recent_visit = nullptr;
    while (!is_empty_stack(ss) || p){
        if (p){
            if (p->data == ch){
                // 找到节点
                cout << endl;
                cout << "祖先节点是："<< endl;
                for (int i = 0; i <= ss.top; ++i) {
                    cout << ss.data[i]->data << ' ';
                }
                cout << endl;
                return;
            }
            push(ss,p);
            p = p->lchild;
        } else{
            p = get_top(ss);
            if (p->rchild && p->rchild != recent_visit){
                p = p->rchild;
            } else{
                pop(ss);
                recent_visit = p;
                p = nullptr;
            }
        }
    }
}


int main(){
    BiTree T = get_tree();
    find_ancestor(T,'D');
    return 0;
}