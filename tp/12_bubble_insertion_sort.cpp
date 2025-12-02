#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n, int &comp, int &swap){
    comp = swap = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            comp++;
            if(arr[j] < arr[j+1]){
                swap++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void insertSort(int arr[], int n, int &comp, int &swap){
    for(int i=0; i<n; i++){
        int temp = arr[i];
        int j = i-1;

        comp++;
        for(; j>=0; j--){
            if(arr[j] > temp){
                swap++;
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main(){
    
    return 0;
}