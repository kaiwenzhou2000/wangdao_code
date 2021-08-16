//
// Created by kaiven on 2021/8/16.
//

#include "../public.h"

/*
 * 可以看出来，其实就是一个中序遍历
 * 在根节点(因为在最外面没有括号)和叶结点出不要添加括号
 * 在遍历子树之前需要添加括号，
 * 在遍历完成之后也要添加
 * */
void make_math(BiTree T, int deep){
    if (T == nullptr){
        return;
    }

    if (T->lchild == nullptr && T->rchild == nullptr){
        // 没有子树
        cout << T->data;
    } else{
        // 有子树，需要在之前就加上括号，且确保不是根节点
        if (deep!=1) cout << '(';
        make_math(T->lchild, deep+1);
        // 输出子树中的元素
        cout << T->data;
        make_math(T->rchild, deep+1);
        // 在子树遍历完成之后还要添加括号，且确保不是根节点
        if (deep!=1) cout << ')';
    }

}

int main(){
    BiTree T = get_tree();
    make_math(T, 1);
    return 0;
}