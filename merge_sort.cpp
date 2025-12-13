#include<iostream>
#include<vector>
using namespace std;
void merge(int low,int mid,int high,vector<int>&v){
    int left = low, right = mid + 1;
    vector<int>temp;
    while(left <= mid && right <= high){
        if(v[left] <= v[right]){
            temp.push_back(v[left]);
            left +=1;
        }
        else{
            temp.push_back(v[right]);
            right +=1;
        }
    }
    while(left <= mid){
        temp.push_back(v[left]);
        left +=1;
    }
    while(right <= high){
        temp.push_back(v[right]);
        right +=1;
    }
    for(int i=low;i<=high;i=i+1){
        v[i] = temp[i-low];
    }
}
void mergeSort(int low,int high,vector<int>&v){
    if(low >= high)
        return;
    int mid = (low + high)/2;
    mergeSort(low,mid,v);
    mergeSort(mid+1,high,v);
    merge(low,mid,high,v);
}
void sortTheArray(vector<int>&v){
    mergeSort(0,v.size()-1,v);
}
void printTheGivenArray(vector<int>&v){
    for(int i=0;i<v.size();i=i+1){
        cout << v[i] <<" ";
    }
    cout <<endl;
}
int main(){
    int n;
    vector<int>v;
    cout <<"Enter the size of the array:";
    cout <<"\n";
    cin >> n;
    for(int i=0;i<n;i=i+1){
        int k;
        cin >> k;
        v.push_back(k);
    }
    sortTheArray(v);
    printTheGivenArray(v);
}   