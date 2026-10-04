#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
void print(vector<int>vec){
     for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
     }
     cout<<endl;
}
int areahistogram(vector<int>height){
    int n=height.size();
    vector<int>nsl={0,0,0,0,0,0};
    vector<int>nsr={0,0,0,0,0,0};
    stack<int>s;
    // next smaller left
    nsl[0]=-1;
    s.push(0);
    for(int i=1;i<n;i++){
        int curr=height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i]=-1;
        }else{
            nsl[i]=s.top();
        }
        s.push(i);

    }
     print(nsl);
 
    while(!s.empty()){
         s.pop();
    }
    
    // // //next smaller right
    s.push(n-1);
    nsr[n-1]=n;
    for(int i=n-2;i>=0;i--){
        int curr=height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=n;//-1
        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }
    print(nsr);

    // //area 
    int maxarea=0;
    for(int i=0;i<n;i++){
        int ht=height[i];
        int width=nsr[i]-nsl[i]-1;
        int area=ht*width;
        maxarea=max(area,maxarea);
    }
    cout<<"Max area of histogram:"<<maxarea;
}

int main(){
    vector<int>height={2,1,5,6,2,3};
    areahistogram(height);
    return 0;
}