//
// Created by kaiven on 2021/6/23.
//

#include "2_2_14.h"

int main(){
    int s1[] = {-1, 0, 9};
    int s2[] = {-25, -10, 10, 11};
    int s3[] = {2, 9, 17, 30, 41};
    cout << "暴力法结果为" << find_min_D(s1, 3, s2, 3, s3, 4) << endl;
    cout << "王道解法" << findMinOfTrip(s1, 3, s2, 3, s3, 4) << endl;
    return 0;
}