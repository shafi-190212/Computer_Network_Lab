//
// Created by mushf on 11/1/2022.
//
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main(){
    srand(time(NULL));
    int buc_size,token_size,data_rate,input_packet;
    cout<<"Enter token size: ";
    cin>>token_size;
    cout<<"Enter bucket size: ";
    cin>>buc_size;
    cout<<"Enter output data rate: ";
    cin>>data_rate;
    cout<<"Enter no. of input data packet: ";
    cin>>input_packet;
    int arr[input_packet];
    for(int i=0;i<input_packet;i++)
    {
        arr[i] = i+1;
    }
    for(auto a: arr){
        cout<<a<<" ";
    }
    if(token_size==0){
        cout<<"No token Available";
    }
    else{
        vector<int>dropped;
        int i=0,m=input_packet;
        while(m!=0 and i<=input_packet){
            int min_value = min(token_size,data_rate);
            token_size -= min_value;
            if(token_size==0){
                dropped.push_back(arr[i]);
                i++;
            }
            for(int k=i;k<min_value;k++){
                printf("%d no. packet is sent to receiver\n",arr[k]);
                m--;
            }
            i+=min_value;
            if((rand()%2)==0){
                token_size++;
            }
        }
    }

}