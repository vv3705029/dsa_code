#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Car{
public:
   int idx;
   int distsq;
   Car(int idx,int distsq){
        this->idx=idx;
        this->distsq=distsq;
   }

   bool operator < (const Car &obj)const{
       return this->distsq > obj.distsq;//min heap
   }
};
void Nearbycar(vector<pair<int,int>>&pos,int k){
    //idx,distane ka squre
    vector<Car>cars;
    for(int i=0;i<pos.size();i++){
        int distsq=pos[i].first*pos[i].first+pos[i].second*pos[i].second;
        cars.push_back(Car(i,distsq));
    }
    
    priority_queue<Car>pq(cars.begin(),cars.end());
    
    for(int i=0;i<k;i++){
        cout<<"car : "<<pq.top().idx<<endl;
        pq.pop();//O(logn)
    }

}
int main(){
    vector<pair<int,int>>pos;
    pos.push_back(make_pair(3,3));
    pos.push_back(make_pair(5,-1));
    pos.push_back(make_pair(-2,4));

    int k=2;
    Nearbycar(pos,k);

    for(int i=0;i<pos.size();i++){
        cout<<pos[i].first<<" ";
    }
    return 0;
}