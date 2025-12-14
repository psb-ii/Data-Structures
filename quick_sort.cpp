#include<iostream>
#include<vector>
using namespace std;

// gives partition index ( where on the either side of it will have opposite nature )
int getPartitionIndex(vector<int>&v,int low,int high){
    int pivot = low;
    int i = low;
    int j = high;
    while(i<j){
        while(v[i] <= v[pivot] && i <= high - 1)  
            i++;
        while(v[j] > v[pivot] && j >= low + 1)
            j--;
        if(i<j)
            swap(v[i],v[j]);
    }
    swap(v[pivot],v[j]);
    return j;
}

void quickSort(vector<int>&v,int low, int high){
    if(low<high){
        int partition_ind = getPartitionIndex(v,low,high);
        quickSort(v,low,partition_ind-1);
        quickSort(v,partition_ind+1,high);
    }
}

int main(){
    int n;
    cout << "Enter the size of the array"<<endl;
    cin >> n;
    vector<int>v;
    for(int i=0;i<n;i=i+1){
        int k;
        cin >> k;
        v.push_back(k);
    }
    quickSort(v,0,n-1); // always keep it n - 1
    for(int i=0;i<n;i=i+1){
        cout <<v[i]<<" ";
    }
}