#include<iostream>
#include<string>
#include<math.h>
std::string parse(int mode,int num);
int main(){
    for(int i=0;i<99;i++){
        std::cout<<parse(932,i)<<std::endl;
    }
    return 0;
}
std::string parse(int mode,int num){
    if(num==0)
        return "0";
    std::string ans="";
    while(num){
        ans=(char)(num%mode+'0')+ans;
        num/=mode;
    }
    return ans;
}