
/*
worst case - O(n)
best case - Ω(1)
avg case - Θ(n)

*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int i=0;
    int count = 0;
    int amount;
    vector<int> notes = {2000,500,200,100,50,20,10,5,2,1};
    cout<<"Amount : ";
    cin>>amount;
    while(amount>0){
        count = amount/notes[i];
        amount = amount%notes[i];
        if(count != 0){
            cout<< notes[i] << " notes : "<<count<<endl;
        }
        i++;
    }
}