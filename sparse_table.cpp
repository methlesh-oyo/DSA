// solution to https://www.codechef.com/problems/MSTICK
#include <bits/stdc++.h>
#define N 10001
using namespace std;
using vi=vector<int>;
const int MAXN = (1 << 20);
const int MAXLOG = 20;

struct sparse_table
{
    int dpmi[MAXN][MAXLOG], dpmx[MAXN][MAXLOG];;
    int prec_lg2[MAXN], n;

    sparse_table(){ 
        memset(dpmi, 0, sizeof(dpmi)); 
        memset(dpmx, 0, sizeof(dpmx)); 
        memset(prec_lg2, 0, sizeof(prec_lg2)); 
        n = 0;
    }

    void init(vi &a){
        n = a.size();
        for(int i = 2; i < 2 * n; i++)
            prec_lg2[i] = prec_lg2[i >> 1] + 1;
        for(int i = 0; i < n; i++){
            dpmi[i][0] = a[i];
            dpmx[i][0] = a[i];
        }
        for(int j = 1; (1 << j) <= n; j++){
            for(int i = 0; i < n; i++){
                dpmi[i][j] = min(dpmi[i][j - 1], dpmi[i + (1 << (j - 1))][j - 1]);
                dpmx[i][j] = max(dpmx[i][j - 1], dpmx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int min_query(int l, int r) 
    {
        int k = prec_lg2[r - l + 1];
        return min(dpmi[l][k], dpmi[r - (1 << k) + 1][k]);
    }
    int max_query(int l, int r) 
    {
        int k = prec_lg2[r - l + 1];
        return max(dpmx[l][k], dpmx[r - (1 << k) + 1][k]);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    sparse_table st;
    st.init(a);
    int x, y, cnt=0, mi, mx, m1, m2;
    cout<<setprecision(1)<<fixed;
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        assert(x<=y);
        mi=st.min_query(x, y);
        mx=st.max_query(x, y);
        double t=mi+0.0;
        m1=m2=0;
        if(x>0)
            m1=st.max_query(0, x-1);
        if(y<n-1)
            m2=st.max_query(y+1, n-1);
        m1=max(m1, m2);
        t+=max((mx-mi)/2.0, m1+0.0);
        // cout<<t<<"\n";
        cout<<t<<"\n";
    }
    return 0;
}
