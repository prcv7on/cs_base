/*
 * @lc app=leetcode.cn id=860 lang=c
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool lemonadeChange(int* bills, int bsz){
    int cnt5=0;
    int cnt10=0;
    for (int i=0;i<bsz;++i) {
        if (bills[i]==5) ++cnt5;
        else if (bills[i]==10) {
            if (cnt5 !=0) {
                --cnt5;
                ++cnt10;
            }
            else return false;
        }
        else {
            if (cnt5 !=0 && cnt10 != 0) {
                --cnt5;
                --cnt10;
            }
            else if (cnt5>=3) cnt5 -= 3;
            else return false;
        }
    }
    return true;
}


// @lc code=end

int main(void) {
    int arr[]={5,5,5,10,20};
    bool b1=lemonadeChange(arr,5);
    printf("b1=%d\n",b1);

    return 0;
}