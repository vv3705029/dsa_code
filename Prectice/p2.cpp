#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
int main(){
    // vector<int> num1({ 1, 2 });
    // vector<int> num2({ 3, 4 });
    // vector<int> num;
    // int i = 0;
    // int j = 0;
    // cout<<num1[1];
    // while (i <= nums1.size() - 1 && j <= nums2.size() - 1)
    // {
    //     if (nums1[i] < nums2[j])
    //     {
    //         num.push_back(nums1[i++]);
    //     }
    //     else
    //     {
    //         num.push_back(nums2[j++]);
    //     }
    // }
    // while (i <= nums1.size() - 1)
    // {
    //     num.push_back(nums1[i++]);
    // }
    // while (j <= nums2.size() - 1)
    // {
    //     num.push_back(nums2[j++]);
    // }
    // int index = num.size();
    // if (index % 2 == 0)
    // {
    //     double sum = (num[(index / 2) - 1] + num[index / 2]) / 2;
    //     return sum;
    // }
    // else
    // {
    //     return num[(index / 2)];
    // }

    // cout<<(1<<2)<<"\n";
    // cout<<(11&1)<<endl;
    // 
    // int x=5;
    // int y=6;
    // int z=x&y;
    // int a=z&7;
    // cout<<a;

    // int left=5;
    // int right=7;
    // while(right>left){
    //     cout<<right<<endl;
    //     right=right&(right-1);
    //     cout<<right<<endl;
    // }

    // cout<<(7&6)<<endl;
    // cout<<(6&5)<<endl;

    // int x=0;
    // for(int i=1;i<=3;i++){
    //     x+=i;
    // }
    // cout<<x;

    // char x='a';
    // char y='a';
    // int n=0;
    // if(x==y){
    //   n++;
    // }

    // int x=pow(-1,2);
    // cout<<x;

    // string s="452";
    // cout<<(s[0]-'0')*4;


    // vector<int>dp(26,0);
    // string str="jsbdkjsdfhjkjsfkjhafkjsfjdszzzz";
    // for(int i=0;i<str.size();i++){
        
    //     dp[str[i]-'a']++;
    // }
    // for(int i=0;i<dp.size();i++){
    //     cout<<i<<":"<<dp[i]<<"\n";
    // }

    // string s="123";
    // int temp=0;
    // for(int i=0;i<s.size();i++){
    //     temp=temp*10+s[i]-'0';
    // }

        string num="6913259244";
        long long temp=0;
        for(int i=0;i<num.size();i++){
            temp=temp*10+(num[i]-'0');
            cout<<temp<<" ";
        }
        cout<<temp;
    
    return 0;
}