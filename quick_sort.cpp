#include <bits/stdc++.h>
using namespace std;
using vi=vector<int>;

int partition(vi& a, int p, int q)
{
    int j=p;
    for(int i=p; i<q; i++)
    {
        if(a[i]<a[q])
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[q]);
    return j;
}
void quick_sort(vi& a, int p, int q)
{
    if(p<q)
    {
        int id=partition(a, p, q);
        quick_sort(a, p, id-1);
        quick_sort(a, id+1, q);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];
    quick_sort(a, 0, n-1);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
