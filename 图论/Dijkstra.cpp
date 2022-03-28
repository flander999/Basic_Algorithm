#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int n,m;
int dist[N], g[N][N];
bool st[N];


int dijkstra(){

    // 初始化dist数组，保证开始前所有路径均为正无穷
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 循环n遍，每一遍保证确定一个点的最短距离
    for(int i = 1; i <= n; i++){
        int t = -1;

        // 找到当前不在S中的距离最近的点t
        for(int j = 1; j <= n; j++){
            if(!st[j] && (t==-1 || dist[t] > dist[j])){
                t = j;
            }
        }

        // 将t设置为true，表示已经得到更新
        st[t] = true;

        // 利用t点的最短距离，更新其他点的最短距离
        for(int j = 1; j <= n; j++){
            dist[j] = min(dist[j], dist[t]+g[t][j]);
        }
    }

    //如果n点的距离仍大于最大点数，则从1到n没有通路
    if(dist[n] > 0x3f3f3f/2) return -1;

    return dist[n];
}

int main(void){
    scanf("%d%d", &n,&m);

    memset(g, 0x3f, sizeof g);


    //构建图
    while(m--){
        int a,b,c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c); // a,b之间可能存在多条边，权重不一样。此题只需要保存最小权重即可
    }

    int t = dijkstra();

    printf("%d\n", t);

    return 0;

}

