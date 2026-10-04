#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool copmare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int maxchainlength(vector<pair<int,int>>pairs){
    int n=pairs.size();
    int count=1;
    int currend=pairs[0].second;
    for(int i=1;i<n;i++){
        if(pairs[i].first>=currend){//non-ovelaping
            count++;
            currend=pairs[i].second;

        }
    }
    return count;
}
int main(){
    vector<pair<int,int>>pairs={make_pair(5,24),make_pair(39,60),make_pair(5,28),make_pair(27,40),make_pair(50,90)};
    sort(pairs.begin(),pairs.end(),copmare);//if true no swap otherwise swap
     cout<<"max chainlength:"<<maxchainlength(pairs);
    return 0;
}