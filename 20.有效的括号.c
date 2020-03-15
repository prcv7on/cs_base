/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    if (s==NULL || s[0]=='\0') return true;
    size_t len=strlen(s);
    if (len & 1) return false;
    char* arr=(char*)malloc(len*sizeof(char));
    int i=0,k=0;
    // printf("k=%d\n",k);
    for (i=0;i<len;++i) {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            arr[k++]=s[i];
        else {
            if ((--k)<0) return false;
            else if (s[i]==')' && arr[k]!='(') return false;
            else if (s[i]==']' && arr[k]!='[') return false;
            else if (s[i]=='}' && arr[k]!='{') return false;
        }
    }
    //printf("k=%d\n",k);
    return k==0;
}


// @lc code=end


int main() {
    char* s="()[]{}"; //{[]}  //
    bool b1=isValid(s);
    printf("b1=%d\n",b1);

    return 0;
}



