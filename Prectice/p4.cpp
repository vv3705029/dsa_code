#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<limits>
#include<queue>
using namespace std;
//  bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int>s;
//         for(int i=0;i<nums.size();i++){
//             if(s.count(nums[i])){
//                 s[nums[i]]++;
//             }else{
//                 s[nums[i]]=1;
//             }
//         }
//         for(pair<int,int>temp:s){
//             if(temp.second>=2){
//                 return true;
//                 break;
//             }
//         }
//         return false;
//     }
int main(){
   //  vector<vector<int>>ans;
   //  int row=4;
   //  int col=3;
   //  for(int i=0;i<row;i++){
   //     vector<int>temp;
   //     for(int j=0;j<col;j++){
   //        temp.push_back(j);
   //     }
   //     ans.push_back(temp);
   //  }
   //  // sort(ans.begin()ans.end());
   //   for(int i=0;i<row;i++){
   //     for(int j=0;j<col;j++){
   //         cout<<ans[i][j]<<" ";
   //     }
   //     cout<<endl;
   //  }
   //  cout<<ans[0].size();
    // int n = 5;
    // int result = 1 << n;  // 2^n using left shift
    // std::cout << "2^" << n << " = " << result << std::endl;
    
    // vector<int>nums={1,2,3,1};
    // cout<< containsDuplicate(nums);

    // string v="vikas";
    // cout<<v.substr(0,2)<<endl;
    //  cout<<v.substr(2,1)<<endl;
    // cout<<INT16_MAX;
        vector<int>stones{2,7,4,1,8,1};
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x!=y){
             pq.push(y-x);
            }
        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    return 0;
}