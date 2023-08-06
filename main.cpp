//
// Created by mushf on 11/1/2022.
//
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main(){
    srand(time(NULL));
    int buc_size,data_rate,input_packet,token_size;
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
        arr[i] = (4+(rand()%5));
    }
    for(auto a: arr){
        cout<<a<<" ";
    }
    cout<<endl;
    int remain=0,token =token_size;
    vector<int> dropped;
    printf("Time\tReceived\tSent\tRemaining\n");
    int t;
    for(t=0;t<input_packet;t++){
        int sent=0;
        if(remain!=0){
            sent = min(remain,data_rate);
            remain -= min(remain,data_rate);
            token --;
        }
        if(arr[t]>(buc_size-remain) or token <(token-remain)){
            dropped.push_back(arr[t]);
        }
        else{
            if(arr[t]<data_rate and token>=arr[t]){
                sent = arr[t];
                token --;
            }
            else if(token>=data_rate){
                sent = data_rate;
                remain += (arr[t]-data_rate);
                token --;
            }
            else{
                dropped.push_back(arr[t]);
            }
        }
        printf("%2d \t %5d\t \t%3d \t %5d\n",t+1,arr[t],sent,remain);
        if(token<token_size)
            token++;
        sleep(1);
    }
    for(auto x: dropped){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<token<<endl;



}