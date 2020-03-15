/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    size_t len=strlen(s);
    if (len<2) return true;
    char* str=(char*)malloc(len*sizeof(char));
    int i=0,j=0;
    for (i=0;i<len;++i) {
        if (s[i]>='A' && s[i]<='Z')
            str[j++]=tolower(s[i]);
        else if (s[i]>='a' && s[i]<='z')
            str[j++]=s[i];
        else if (s[i]>='0' && s[i]<='9')
            str[j++]=s[i];
    }
    // printf("str=%s\n",str);
    // printf("j=%d\n",j);

    for (i=0;i<(j/2);++i) {
        if (str[i] != str[j-i-1]) {
            return false;
        }
    }
    return true;
}


// @lc code=end



int main() {
    // int a='a'-'A';
    // printf("a=%lu\n",strlen(a));//32

    //char*s ="abc121cba";
    char* s="A man, a plan, a canal: Panama";
    bool b1=isPalindrome(s);
    printf("b1=%d\n",b1);


    return 0;
}


