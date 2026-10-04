#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Heap{
    vector<int>vec;//COMPlETE BINARY TREE(max heap)
public:
    void push(int val){//O(logn)
        //STEP1
        vec.push_back(val);
        //STEP 2 
        //FIX HEAP
        int x=vec.size()-1;//x is child
        int parI=(x-1)/2;

        while(parI>=0 && vec[x]>vec[parI]){//FOR MAX HEAP vec[x]>vec[parI],,FOR MIN HEAP vec[x]<vec[parI]
            swap(vec[x],vec[parI]);
            x=parI;
            parI=(x-1)/2;
        }
        
    }
    
    void heapify(int i){//i=parI
        if(i>=vec.size()){
            return;
        }

        int maxIdx=i;
        int l=2*i+1;
        int r=2*i+2;

        if(l<vec.size() && vec[l]>vec[maxIdx]){
            maxIdx=l;
        }
        if(r<vec.size() && vec[r]>vec[maxIdx]){
            maxIdx=r;
        }

        swap(vec[i],vec[maxIdx]);
        if(maxIdx!=i){//swaping with child node
            heapify(maxIdx);
        }

    }
    void pop(){
        //step1 swap last element with 0
        swap(vec[0],vec[vec.size()-1]);
        //step2
        vec.pop_back();
        //step3
        heapify(0);//O(logn)
    }
    int top(){
        return vec[0];//HEIGEST PARIORITY ELEMENT
    }

    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    Heap h1;
    h1.push(20);
    h1.push(30);
    h1.push(89);
    
    // cout<<h1.top()<<" ";
    // h1.pop();
     
    // cout<<h1.top()<<" ";
    // h1.pop();

    while(!h1.empty()){
        cout<<h1.top()<<" ";
        h1.pop();
    }
    
    return 0 ;

}