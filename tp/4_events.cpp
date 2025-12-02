#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main(){
    vector<pair<int,int>> arr;
    vector<pair<int,int>> select;
    int n;
    int last_finish = INT_MIN;
    cout<<"number of events : ";
    cin>>n;

    cout<<"Enter events start and finsh with space :";
    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        arr.emplace_back(e,s);
    }

    sort(arr.begin(), arr.end());


    for(int i=0; i<n; i++){
        cout<<arr[i].second<<" "<<arr[i].first<<endl;
    }
    
    
    for(int i=0; i<n; i++){
        if(arr[i].second >= last_finish){
            select.emplace_back(arr[i].second, arr[i].first);
            last_finish = arr[i].first;
        }
    }
    
    for(int i=0; i<select.size(); i++){
        cout<<select[i].first<<" "<<select[i].second<<endl;
    }

}