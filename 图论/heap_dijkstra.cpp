#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>


using namespace std;

typedef pair<int,int> PII;


const int N = 1e6 + 10;

int n,m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];


void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}


int heap_dijkstra(){
    // 初始化dist数组
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    // 初始化heap并且将点1加入heap
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0,1});
    
    // 当heap中还有点的时候
    while(heap.size()){
        // 取出堆顶元素，并删除
        auto t = heap.top();
        heap.pop();
        
        // 得到堆顶pair的节点位置
        int ver = t.second;
        
        // 如果节点ver已经是最短路径，则直接跳过，进入下一个
        if(st[ver]) continue;
        st[ver] = true;
        
        // 如果节点ver的最短距离加上到i的权重大于原先的距离，则更新
        for(int i  = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j],j});
            }
        }
    }
    
    // 若是点n的距离没有被更新，则不存在通路
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main(){
    scanf("%d%d", &n, &m);
    
    memset(h, -1, sizeof h);
    
    while(m--){
        int a,b,c;
        scanf("%d%d%d", &a,&b,&c);
        add(a,b,c);
    }
    
    int t = heap_dijkstra();
    
    printf("%d", t);
    
    return 0;
}
