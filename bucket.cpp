//
// Created by mushf on 11/1/2022.
//
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main(){
    srand(time(NULL));
    int buc_size,data_rate,input_packet,token_size,pack_size;
    cout<<"Enter token size: ";
    cin>>token_size;
    cout<<"Enter bucket size: ";
    cin>>buc_size;
    cout<<"Enter output data rate: ";
    cin>>data_rate;
    cout<<"Enter no. of input data packet: ";
    cin>>input_packet;
    cout<<"Enter packet size: ";
    cin>>input_packet;

    int arr[input_packet];
    for(int i=0;i<input_packet;i++)
    {
        arr[i] = i+1;
    }
    for(auto a: arr){
        cout<<a<<" ";
    }
    cout<<endl;

    int m =0 ;
    vector<int>drop;
    while(m!=input_packet){
        if(token_size<=data_rate and ){
            int min_val = min(token_size,data_rate);
            token_size -= min_val;
            for(int i=m;i<m+min_val;i++){
                printf("%d is  sent\n",arr[i]);
            }
        }
        else if(token_size==0){
            drop.push_back(arr[m]);
            m++;
        }
        sleep(1);
    }

}//
// Created by mushf on 11/1/2022.
//
