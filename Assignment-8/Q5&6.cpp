#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
public:
    vector<int> a;

    void insert(int v) {
        a.push_back(v);
        int i = a.size() - 1;
        while(i && a[(i-1)/2] < a[i]) {
            swap(a[i], a[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapify(int n, int i) {
        int mx = i, l = 2*i+1, r = 2*i+2;
        if(l<n && a[l]>a[mx]) mx = l;
        if(r<n && a[r]>a[mx]) mx = r;
        if(mx!=i){ swap(a[i], a[mx]); heapify(n,mx); }
    }

    void heapsort() {
        int n = a.size();
        for(int i=n/2-1;i>=0;i--) heapify(n,i);
        for(int i=n-1;i>=0;i--) {
            swap(a[0], a[i]);
            heapify(i,0);
        }
    }

    int top() {
        return a[0];
    }

    void pop() {
        a[0] = a.back();
        a.pop_back();
        heapify(a.size(),0);
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(40);
    h.insert(30);
    h.insert(5);
    h.insert(1);
    h.insert(50);
    h.heapsort();
    for(int x:h.a) cout<<x<<" ";
    cout<<"\n";
    MaxHeap pq;
    pq.insert(30);
    pq.insert(20);
    pq.insert(40);
    pq.insert(10);
    cout<<pq.top()<<"\n";
    pq.pop();
    cout<<pq.top()<<"\n";
}
