#include<iostream>
using namespace std;

void shellSort(int arr[], int n){
    for(int gap = n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int temp = arr[i];

            int j = i;
            while(j >= gap){
                if(arr[j-gap] > temp){
                    arr[j] = arr[j-gap];
                    j -= gap;
                }
            }
            arr[j] = temp;
        }
    }
}

// --------------radix sort------------------------

int getMax(int arr[], int n){
    int mx = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > mx) mx = arr[i];
    }

    return mx;
}

int countingSort(int arr[], int n, int exp){
    int output[n+1];
    int count[10] = {0};

    for(int i=0; i<n; i++){
        count[(arr[i]/exp)%10]++;
    }

    for(int i=1; i<10; i++){
        count += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n){
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countingSort(arr, exp, stats);
}

int main(){
    
    return 0;
}