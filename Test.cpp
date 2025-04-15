#include<iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int element;
        cin>>element;
        v.push_back(element);
    }
    std::sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
