#include<iostream>
#include<vector>
//symbolic constants micro
#define X 25
#define ll long long
using namespace std;
int main(){
    /*const int num=25;
    int num1=24;
    num1=87;
    long long x;
    cout<<X;*/

    /*cout<<(10/3)<<endl;
    cout<<(10/3.0)<<endl;
    cout<<'A'+1<<endl;
    cout<<'a'+1<<endl;
    cout<<int('A'+1.5)<<endl;
    cout<<char('A'+8.5)<<endl;
    cout<<float('A'+8.5)<<endl;
    cout<<bool(3)+1;*/
     
     //arothmatic unary oprater a++ a--
    //  int a=3;
    //  a++;
    //  cout<<a<<endl;;
    //  a--;
    //  cout<<a;
    // cout<<int('0');
    vector<vector<int>>ans;
    vector<int>num={1,2,3};
    ans.push_back({});
    for(int i=0;i<3;i++){
        vector<int>t;
        t.push_back(num[i]);
        ans.push_back(t);
    }
    for(int i=0;i<3;i++){
        vector<int>x;
        if(i==2){
           x.push_back(num[i-1]);
           x.push_back(num[i]);
        }else{
            x.push_back(num[i]);
            x.push_back(num[i+1]);
        }
        ans.push_back(x);
        x.clear();
    }
    ans.push_back(num);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

