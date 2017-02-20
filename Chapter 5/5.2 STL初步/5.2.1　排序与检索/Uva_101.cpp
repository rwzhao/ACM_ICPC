#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 30;
int n;
//每个pile[i]是一个vector
vector<int> pile[maxn];

//找木块a所在的pile和height，以引用的形式返回调用者
void find_block(int a, int& p, int& h)
{
    for(p = 0; p < n; p ++)
    {
        for(h = 0; h < pile[p].size(); h ++)
        {
            if(pile[p][h] == a)
                return;
        }
    }
}

//把第p堆高度为h的木块上方的所有木块移回原位
void clear_above(int p, int h)
{
    for(int i = h + 1; i < pile[p].size(); i ++)
    {
        int b = pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].push_back(h + 1);
}

//将第p堆高度为h及其上方的木块整体移动到p2堆的顶部
void pile_onto(int p, int h, int p2)
{
    for(int i = h; i < pile[p].size(); i ++)
    {
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}

void print()
{
    for(int i = 0; i < n; i ++)
    {
        printf("%d:", i);
        for(int j = 0; j < pile[i].size(); j ++)
            printf(" %d", pile[i][j]);
        printf("\n");
    }
}
