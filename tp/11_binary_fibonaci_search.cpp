#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key, int &comp){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid = s +(e-s)/2;

        comp++;
        if(arr[mid] == key){
            return mid;
        }

        comp++;
        if(arr[mid] > key){
            e = mid -1;
        }

        else{
            s = mid + 1;
        }
    }
    return -1;
}

int fiboSearch(int arr[], int n, int key, int &comp){
    comp = 0;
    int fib2 = 0, fib1 = 1;
    int fib = fib1 + fib2;

    while(fib < n){
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while(fib > 1){
        int i = min(offset + fib2, n-1);
        comp++;

        if(arr[i] == key){
            return i;
        }
        else if(a[i] < key){
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else{
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib -fib1;
        }
    }
    if(fib1 && offset + 1<n){
        comp++;
        if(arr[offset+1] == key){
            return offset+1;
        }
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
        cout<<"1. binary search\n";
        cout<<"2. fibonacci search\n";
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
            int idx = binarySearch(arr,n,key,comp);
            cout<<"binary search : "<<idx;
            cout<<"Comparision : "<<comp;
        }
        
        else if(choice == 2){
            int idx = fiboSearch(arr,n,key,comp);
            cout<<"fibonacci search : "<<idx;
            cout<<"Comparision : "<<comp;
        }
        
        else if(choice == 3){
            int comp1, comp2;
            int idx1 = binarySearch(arr,n,key, comp1);
            cout<<"binary Comparision : "<<comp1;
            int idx2 = fiboSearch(arr,n,key, comp2);
            cout<<"fibonacci Comparision : "<<comp2;
        }
    }
    return 0;
}