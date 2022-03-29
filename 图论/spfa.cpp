#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n,m;
int dist[N];
int h[N], e[N], ne[N], w[N], idx;
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    // 初始化dist数组
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 定义队列，将起始点放入队列
    // st在这里的用处，表示点k是否在队列当中
    // 所以下面操作的时候，需要及时更新st[k]的状态
    queue<int> q;
    q.push(1);
    st[1] = true;

    // 当队列中还有点的时候，即还能更新dist数组时
    while(q.size())
    {
        // 去除并删除头结点
        auto t  = q.front();
        q.pop();

        // 因为t已不在队列中，所以需要将st[t]的状态更新
        st[t] = false;

        // 遍历t的所有邻边，更新dist数组，若相邻点不在队列中，则加入
        for(int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

}

int main(){
    scanf("%d%d", &n, &m);

    // 初始化邻接链表，用于存储图
    memset(h, -1, sizeof h);

    // 添加边和权重
    while(m--){
        int a,b,w;
        scanf("%d%d%d", &a, &b, &w);
        add(a,b,w);
    }

    spfa();

    if(dist[n] > 0x3f3f3f3f/2 ) puts("impossible");
    else printf("%d\n", dist[n]);

    return 0;
}

