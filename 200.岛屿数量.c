/*
 * @lc app=leetcode.cn id=200 lang=c
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <stdio.h>
#include <stdlib.h>

void dfs(char** a,int r, int c,int i,int j) {
    if (i<0 || i==r || j<0 || j==c || a[i][j]=='0' ) return;
    a[i][j]='0';
    dfs(a,r,c,i+1,j);
    dfs(a,r,c,i-1,j);
    dfs(a,r,c,i,j+1);
    dfs(a,r,c,i,j-1);
}

int numIslands(char** a, int r, int* pc) {
    int cnt=0;
    for (int i=0;i<r;++i) {
        for (int j=0;j<(*pc);++j) {
            if (a[i][j]=='1') {
                ++cnt;
                dfs(a,r,*pc,i,j);
            }
        }
    }
    return cnt;
}


// @lc code=end

int main(void) {
    char a1[]={'1','1','0','0','0'};
    char a2[]={'1','1','0','0','0'};
    char a3[]={'0','0','1','0','0'};
    char a4[]={'0','0','0','1','1'};
    char* arr[4]={a1,a2,a3,a4};
    int row=4;
    int col=5;
    int num=numIslands(arr,row,&col);
    printf("num=%d\n",num);
    //printf("arr[][]=%d\n",arr[2][1]);



}