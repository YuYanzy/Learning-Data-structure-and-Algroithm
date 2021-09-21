#include<iostream>

using  namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void merge_sort(int q[], int l, int r){

    if(l >= r) return ;

    int mid = l + r >> 1;

    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1, tmp[r - l + 1];
    while(i <= mid && j <= r){
     if(q[i] <= q[j]) tmp[k++] = q[i++]; 
     else tmp[k++] = q[j++];
    }
    while(i <= mid) tmp[k++] = q[i++];
    while(j <= r  ) tmp[k++] = q[j++];
    
    for(int i = l, k = 0; i <= r; i++, k++) q[i] = tmp[k];  
}

int main(){

    cin >> n;
    
    for( int i = 0; i < n; i++) cin >> q[i];

    merge_sort(q , 0, n-1);

    for(int i = 0; i < n ; i++) cout << q[i] << " ";
    cout << endl;

    return 0;
}