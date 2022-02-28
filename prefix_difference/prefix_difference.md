# 前缀和与差分

并非完整的模板，主要是一个数学上的公式。


## 前缀和
即当前的数是前面所有数的总和加上自己。
一维数组时，表示为```sum[i] += sum[i-1]```

```c++
#include <iostream>

using namespace std;

const int N = 1010;
int q[N][N];

int main(void){
    int n,m,k;
    
    cin >> n >> m >> k;
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            int number;
            cin >> number;
            q[i][j] = number;
        }
    }
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            // make_sum(i,j);
            q[i][j] += q[i-1][j] + q[i][j-1] - q[i-1][j-1];
        }
    }
    
    while(k--){
        int x1,x2,y1,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum;
        sum = q[x2][y2] - q[x1-1][y2] - q[x2][y1-1] + q[x1-1][y1-1];
        
        cout << sum << endl;
    }
    
    return 0;
}
```

## 差分
即，给定一个数组A，将A当做数组B的前缀和数组，求B。

**PS:** 计算差分的关键是，脑子中模拟出数组B，并将B由A求出（仅限一维数组时）。很多题目中，并不需要完整构造差分数组，而是利用前缀和与差分的关系，来进行额外的计算。

```c++
#include <iostream>

using namespace std;

const int N = 100010;

// q[N] 为 a[N]的前缀和数组
int q[N],a[N];


void add_c(int l, int r, int c){
    a[l] += c;
    a[r+1] -= c;
}

int main(void){
    int n,m;
    
    scanf("%d%d", &n,&m);
    
    for(int i = 1; i < n+1; i++){
        scanf("%d",&q[i]);
        add_c(i,i,q[i]);
    }
    
    while(m--){
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        add_c(l,r,c);
    }
    
    for(int i = 1; i< n+1; i++){
        a[i] += a[i-1];
        printf("%d ",a[i]);
    }
    
    return 0;
}
```
