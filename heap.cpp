#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using vi=vector<int>;
void max_heapify(vi& a, int id, int n)
{
    int l=2*id, r=2*id+1, mid=id, max_elem=a[id-1];
    if(l<=n)
    {
        if(max_elem<a[l-1])
        {
            max_elem=a[l-1];
            mid=l;
        }
    }
    if(r<=n)
    {
        if(max_elem<a[r-1])
        {
            max_elem=a[r-1];
            mid=r;
        }
    }
    if(mid!=id)
    {
        swap(a[id-1], a[mid-1]);
        max_heapify(a, mid, n);
    }
}
void build_max_heap(vi& a, int n)
{
    for(int i=n/2; i>0; i--)
    {
        max_heapify(a, i, n);
    }
}
int main()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    build_max_heap(a, n);
    for(int i=n; i>1; i--)
    {
        swap(a[i-1], a[0]);
        max_heapify(a, 1, i-1);
    }
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
