//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"


/*
 * 递归删除一棵树
 * 删除一棵树的话使用后序遍历，因为删除的时候只能从叶节点开始删除
 *
 * */
void del_tree(BiTNode *root){
    if (root == nullptr){
        return;
    }

    del_tree(root->lchild);
    del_tree(root->rchild);
    cout << root->data << ' ';
    free(root);
}


/*
 * 删除树指定元素的子树
 *  这种方法是可以正常删除元素的，但是删除之后，
 *  有些节点的孩子指针会遗失
 *
 * */
void del_sub_tree(BiTNode *p, char ch){
    if(p == nullptr){
        return;
    }
    del_sub_tree(p->lchild, ch);
    del_sub_tree(p->rchild, ch);
    if (ch == p->data){
        del_tree(p);
    }
}

/*
 * 王道书上使用层次遍历的方法来删除节点
 *
 * */
void del_sub_tree_with_quene(BiTree &T, char ch){
    Quene q;
    ini_Quene(q);
    BiTNode *p = T;
    enter_quene(q,p);
    while (!is_empty_quene(q)){
        p = exit_quene(q);
        if (p->lchild){
            if (p->lchild->data == ch){
                // 左孩子是要删除的节点
                del_tree(p->lchild);
                p->lchild = nullptr;
            } else{
                enter_quene(q,p->lchild);
            }
        }
        if (p->rchild){
            if (p->rchild->data == ch){
                // 右孩子是要被删除的节点
                del_tree(p->rchild);
                p->lchild = nullptr;
            } else{
                enter_quene(q,p->rchild);
            }
        }
    }
}



int main(){
    BiTree T = get_tree();
    show_pre_tree(T);
    cout << endl;
    cout << "删除的元素是" << endl;
    del_sub_tree_with_quene(T, 'B');
    cout << endl;
    cout << "删除之后的树" << endl;
    show_pre_tree(T);
    return 0;
}