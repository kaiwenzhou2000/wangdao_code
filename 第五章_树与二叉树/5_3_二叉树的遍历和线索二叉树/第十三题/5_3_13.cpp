//
// Created by kaiven on 2021/8/14.
//

#include "../public.h"

/*
 * 寻找公共的祖先节点
 *  p 表示第一个节点
 *  q 表示第二个节点
 *  t 表示公共的祖先
 *
 *  将两个人祖先全部记录下来，然后找到公共的
 * */
BiTNode* find_common_ancestor(BiTree T, BiTNode *p, BiTNode *q){
    BiTNode* ancestor_p[maxN];
    int ancestor_p_index = 0;
    BiTNode* ancestor_q[maxN];
    int ancestor_q_index = 0;
    find_ancestor(T, p->data, ancestor_p, ancestor_p_index);
    find_ancestor(T, q->data, ancestor_q, ancestor_q_index);

    // 寻找两个人的公共节点
    for (int i = ancestor_p_index; i >= 0; --i) {
        for (int j = ancestor_q_index; j >= 0; --j) {
            if (ancestor_q[j] == ancestor_p[i]){
                return ancestor_p[j];
            }
        }
    }
}


int main(){
    BiTree T = get_tree();
    BiTNode *r = find_common_ancestor(T, T->rchild->rchild, T->lchild->rchild);
    cout << "公共祖先是" << endl;
    cout << r->data << endl;
    return 0;
}