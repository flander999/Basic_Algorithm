#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n,m;
int dist[N];
int h[N], e[N], ne[N], w[N], idx;
int cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{

    // 定义队列，将起始点放入队列
    // 不再需要初始化是因为并不再关心最短路径
    queue<int> q;

    // 可能存在不以1位起点的负权回路，所以在一开始就需要把所有的点加入队列进行更新
    for(int i = 1; i <= n; i++){
        q.push(i);
        st[i] = true;
    }

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
                cnt[j] = cnt[t] + 1;

                if(cnt[j] >= n) return true;

                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;

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

    bool isvalid = spfa();

    if(isvalid ) puts("Yes");
    else puts("No");

    return 0;
}
