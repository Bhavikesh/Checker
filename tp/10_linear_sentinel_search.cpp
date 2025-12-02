#include<iostream>
using namespace std;

int linear(int arr[], int n, int key, int &comp){
    comp = 0;
    for(int i=0; i<n; i++){
        comp++;
        if(arr[i] == key){
            return i;
        }
    }

    return -1;
}


int sentinel(int arr[], int n, int key, int &comp){
    comp = 0;
    int last = arr[n-1];
    arr[n-1] = key;

    int i=0;
    while(true){
        comp++;
        if(arr[i] == key){
            return i;
        }
        i++;
    }

    arr[n-1] = last;
    if(i<n-1 || last == key){
        return i;
    }

    return -1;
}

int main(){
    int arr[100], n, key, comp, choice;

    cout<<"Enter number of element : ";
    cin>>n;
    cout<<"Enter elements : \n";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    while(1){
        cout<<"\nMenu\n";
        cout<<"1. linear search\n";
        cout<<"2. sentinel search\n";
        cout<<"3. compare search\n";
        cout<<"0. exit\n";
        cout<<"Enter choice : ";
        cin>>choice;

        if(choice == 0){
            break;
        }

        cout<<"Enter key : ";
        cin>>key;
        else if(choice == 1){
            int idx = linear(arr,n,key,comp);
            cout<<"Linear search : "<<idx;
            cout<<"Comparision : "<<comp;
        }
        
        else if(choice == 2){
            int idx = sentinel(arr,n,key,comp);
            cout<<"Sentinel search : "<<idx;
            cout<<"Comparision : "<<comp;
        }
        
        else if(choice == 3){
            int comp1, comp2;
            int idx1 = linear(arr,n,key, comp1);
            cout<<"Linear Comparision : "<<comp1;
            int idx2 = sentinel(arr,n,key, comp2);
            cout<<"Sentinel Comparision : "<<comp2;
        }


    }
    return 0;
}