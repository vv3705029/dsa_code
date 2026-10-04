#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;class Job{
public:
   int idx;
   int deadline;
   int profit;
   Job(int idx,int deadline,int profit){
    this->idx=idx;
    this->deadline=deadline;
    this->profit=profit;
   }
};

int maxprofit(vector<pair<int,int>>pairs){
    int n=pairs.size();
    vector<Job>jobs;
    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);//idx deadline,profit
        //emplace_back
    }

    sort(jobs.begin(),jobs.end(),[](Job &a,Job &b){//lambda function
        return a.profit>b.profit;//decending order on the basis of profit
    });

    cout<<"Selecting job"<<jobs[0].idx<<endl;
    int profit=jobs[0].profit;
    int safedeadline=2;
    for(int i=1;i<n;i++){
        if(jobs[i].deadline>=safedeadline){
            cout<<"Selecting job"<<jobs[i].idx<<endl;
            profit+=jobs[i].profit;
            safedeadline++;
        }
    }
    
    cout<<profit;

}

int main(){
    int n =4;
    vector<pair<int,int>>pairs(n,make_pair(0,0));
    pairs[0]=make_pair(4,20);
    pairs[1]=make_pair(1,10);
    pairs[2]=make_pair(1,40);
    pairs[3]=make_pair(2,30);

    sort(pairs.begin(),pairs.end());

    for(int i=0;i<n;i++){
        cout<<pairs[i].first<<" "<<pairs[i].second<<endl;
    }

    maxprofit(pairs);
    return 0;
}