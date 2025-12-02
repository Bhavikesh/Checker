#include<iostream>
#include<algorithm>
using namespace std;

void addPoly(){
    int d1, d2;
    cout<<"Enter degree of first polynomial : ";
    cin>>d1;

    int pol1[100] = {0};
    cout<<"Enter coefficients from highest degree to constant term:\n";
    for(int i=d1; i>=0; i--){
        cout<<"Coeffient of x^"<<i<<" : ";
        cin>>pol1[i];
    }
    
    
    cout<<"Enter degree of second polynomial : ";
    cin>>d2;

    int pol2[100] = {0};
    cout<<"Enter coefficients from highest degree to constant term:\n";
    for(int i=d2; i>=0; i--){
        cout<<"Coeffient of x^"<<i<<" : ";
        cin>>pol2[i];
    }

    int maxDeg = max(d1,d2);
    int sum[100]= {0};

    for(int i=0; i<=maxDeg; i++){
        sum[i] = pol1[i] + pol2[i];
    }


    int prod[100] = {0};
    for(int i=0; i<=d1; i++){
        for(int j=0; j<=d2; j++){
            prod[i+j] += (pol1[i] * pol2[j]);
        }
    }

    cout<<"\nSum\n";
    for(int i=maxDeg; i>=0; i--){
        if(sum[i]!=0){
            cout<<sum[i]<<"x^"<<i<<" + ";
        }
    }
    cout<<"0\n";
    
    cout<<"\nProduct\n";
    for(int i=d1+d2; i>=0; i--){
        if(prod[i] != 0){
            cout<<prod[i]<<"x^"<<i<<" + ";
        }
    }   
    cout<<"0\n";

}

int main(){
    addPoly();
    return 0;
}