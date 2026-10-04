#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;
void prindItinerary(unordered_map<string,string>tick){
    //Starting Point
    unordered_set<string>to;
    for(pair<string,string>ticket:tick){//<from,to>
           to.insert(ticket.second);
    }
    string start="";
    for(pair<string,string>ticket:tick){//<from,to>
       if(to.find(ticket.first)==to.end()){
         start=ticket.first;
         break;
        }
    }
    //Plain
    cout<<start<<"->";
    while(tick.count(start)){
        cout<<tick[start]<<"->";
        start=tick[start];
    }
}
int main(){
    unordered_map<string,string>tick;
    tick["Chennai"]="Bengaluru";
    tick["Mumbai"]="Delhi";
    tick["Goa"]="Chennai";
    tick["Delhi"]="Goa";
    prindItinerary(tick);
    return 0;
}
