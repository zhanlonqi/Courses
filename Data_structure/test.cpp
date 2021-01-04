#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int get_cost(int highways[][4],int num,int num_highways,int num_cities);
int main(){
    string num_cities_str="",num_highways_str="";
    int num_cities=0,num_highways=0;
    int i=0,count=0;
    cin>>num_cities_str;
    num_cities=atoi(num_cities_str.c_str());
    cin>>num_highways_str;
    num_highways=atoi(num_highways_str.c_str());
    int highways[num_highways][4];
    for(int i=0;i<num_highways;i++){
        for(int j=0;j<4;j++){
            string temp="";
            cin>>temp;
            highways[i][j]=atoi(temp.c_str());
        }
    }
    
    int max_cost=0;
    vector<int> ans;
    for(int i=0;i<num_cities;i++){
        int cost=get_cost(highways,i,num_highways,num_cities);
        if(cost>max_cost){
            max_cost=cost;
            ans.clear();
            ans.push_back(i+1);
        }
        else if(cost==max_cost){
            ans.push_back(i+1);
        }
    }
    if(max_cost!=0)
    for(int i=0;i<ans.size();i++){
        std::cout<<ans.at(i)<<(i==(ans.size()-1)?" ":"");
    }
    else{
        std::cout<<0<<std::endl;
    }
}

int get_cost(int highways[][4],int num,int num_highways,int num_cities){
    int cost=0;
    bool included[num_cities]={0};
    included[num]=true;
    for(int i=0;i<num_highways;i++){
        if(highways[i][3]==1&&highways[i][0]!=num+1&&highways[i][1]!=num+1){
            included[highways[i][0]-1]=true;
            included[highways[i][1]-1]=true;
        }
    }
    int cities_disconnected=0;
    for(int i=0;i<num_cities;i++){
        if(!included[i]){
            cities_disconnected++;
        }
    }
    for(int i=0;i<cities_disconnected;i++){
        int min_cost=-1,min_index=-1;
        for(int j=0;j<num_highways;j++){
            if(highways[j][3]==0&&(!included[highways[j][0]-1]||!included[highways[j][1]-1])){
                if(min_index==-1||highways[j][2]<min_cost){
                    min_index=j;
                    min_cost=highways[j][2];
                }
            }
        }
        if(min_index!=-1){
            included[highways[min_index][0]-1]=true;
            included[highways[min_index][1]-1]=true;
            cost+=min_cost;
        }
        else{
            return INT32_MAX;
        }
    }
    return cost;
}

