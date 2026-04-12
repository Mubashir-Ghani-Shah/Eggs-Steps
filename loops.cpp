#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of times you want to print Hello World: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"Hello World"<<endl;
    }

    return 0;
}