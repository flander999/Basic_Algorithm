# Prim算法和Kruskal算法 求最小生成树

## Prim

### 基本逻辑

```
   初始化所有点到当前最小生成树集合的距离为正无穷

   for i: 1 ~ n
    t <--- 不在集合中的距离集合最近的点
    若t距离最小生成树是正无穷，则当前点集不存在最小生成树
    若当前点不是初始点(根节点),则将t到集合的距离，即权重加入到最终结果res中

    根据t到集合的距离，更新其他点到集合的距离。即是点已在集合中，因为不会再次访问，所以距离更新了也没有关系。

  最后输出最终结果res
```
总体来说，prim算法应用了贪心的思想，每一步把距离集合最近的点加入集合，以此来最终形成最小生成树。在这个基础的模板之上，也可以通过增加额外的数据结构来记录最小生成树，提取最小生成树边全，或者进一步做连通块问题等等。

### 实际代码

```c++
    int prime()
    {
      //初始化dist数组
      memset(dist, 0x3f, sizeof dist);

      //最小生成树的权重总和
      int res = 0;

      for(int i = 0; i < n; i++)
      {
          int t = -1;

          //找到最小生成树外距离最近的一个点
          for(int j = 1; j <= n; j++)
          {
              if (!st[j] && (t == -1 || dist[t] > dist[j]))
              {
                  t = j;
              }
          }

          st[t] = true;

          //只要存在非头结点并且距离为无穷，意味着点t与最小生成树不连通，不存在最小生成树，返回INF
          if (i && dist[t] == INF) return INF;

          //只要不是第一个点，即头结点，就将权重加到最终结果当中
          if(i) res += dist[t];

          //更新距离
          for(int j = 1; j <=n; j++)
          {
              dist[j] = min(dist[j], g[t][j]);
          }

      }

      return res;
    }
```




## Kruskal算法

### 基本思想

```
   将所有边按权重大小进行排序 O(mlogm)
   枚举每条边ab，权重为w: 1~m
    若ab不连通，就将ab这条边加入边集合中，并且计算权重总和
```
总体来说，Kruskal算法的第二步的迭代，就是应用了并查集的思想，将时间复杂度降到了线性。

### 实际代码

```c++
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int M = 2e5+10, N = 1e5+10, INF = 0x3f3f3f3f;

int n,m;
int p[N];

struct Edge{
    int a,b,w;

    //重载<，让结构体可以根据权重w进行排序。
    bool operator< (const Edge &W) const
    {
        return w < W.w;
    }
}Edges[M];

//只要a的父节点不是他自己，就意味着他不是该连通块的根节点，就继续往上搜。
int find(int a)
{
    if(p[a] != a) p[a] = find(p[a]);

    return p[a];
}

int Kruskal()
{
    //将所有边按权重大小排序，从小到大
    sort(Edges, Edges+m);

    for(int i = 1; i <= n; i++) p[i] = i;

    //res为最终最小生成树的权重和, cnt为加入最小生成树的点的数量
    int res = 0, cnt = 0;

    // 因为已经进过排序，所以每次取出的必然是当前所有还未加入最小生成树的边的权重中最小的那一个。
    // 遍历每一条边
    for(int i  = 0; i < m; i++)
    {
        int a = Edges[i].a, b = Edges[i].b, w = Edges[i].w;

        //判断a和b是否有共同的根节点，即他们是否在同一个连通块内。
        a = find(a), b = find(b);

        //如果不连通，则把权重加进去
        if(a != b)
        {
            res += w;

            // 将两个点相连
            p[a] = b;
            cnt++;
        }
    }

    //若cnt小于总点数，意味着有点直到最后都不在最小生成树内，即未连通，所以不存在最小生成树
    if(cnt < n-1) return INF;

    return res;
}


int main(){
    scanf("%d%d", &n, &m);


    for(int i = 0; i< m; i++)
    {
        int a,b,w;
        scanf("%d%d%d", &a, &b, &w);
        Edges[i] = {a,b,w};
    }

    int res = Kruskal();

    if(res == INF) puts("impossible");
    else printf("%d", res);

    return 0;
}
```
