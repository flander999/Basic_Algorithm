#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;

int n,m,k;
int dist[N], backup[N];

struct Edge{
    int a,b,w;
}edges[M];


void bellman_ford()
{
    // 初始化dist数组
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    //迭代k次，每次拷贝一下前一次迭代更新的dist数组
    for(int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);

        // 循环每条边，比较当前点的最短距离和前一个点的最短距离加权重，更新
        for(int j = 0; j < m; j++)
        {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], backup[e.a]+e.w);
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    // 使用结构体存储边的两点和权重，不需要考虑顺序
    for(int i = 0; i < m; i++){
        int a,b,w;
        scanf("%d%d%d", &a,&b,&w);
        edges[i] = {a,b,w};
    }

    bellman_ford();

    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d\n", dist[n]);


    return 0;
}

