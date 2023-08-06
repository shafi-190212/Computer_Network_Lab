//
// Created by mushf on 11/1/2022.
//
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main(){
    srand(time(NULL));
    int buc_size,data_rate,input_packet;
    cout<<"Enter bucket size: ";
    cin>>buc_size;
    cout<<"Enter output data rate: ";
    cin>>data_rate;
    cout<<"Enter no. of input data packet: ";
    cin>>input_packet;
    int arr[input_packet];
    for(int i=0;i<input_packet;i++)
    {
        arr[i] = (1+(rand()%buc_size));
    }
    for(auto a: arr){
        cout<<a<<" ";
    }
    cout<<endl;
    int remain=0;
    printf("Time\tReceived\tSent\tRemaining\tDropped\n");
    for(int t=0;t<input_packet;t++){
        int dropped=0,sent=0;
        if(arr[t]>(buc_size-remain)){
            dropped = arr[t];
            if(remain!=0){
                sent = min(remain,data_rate);
                remain -= min(remain,data_rate);
            }

        }
        else{
            if(arr[t]<data_rate){
                sent = arr[t];
            }
            else{
                sent = data_rate;
                remain += (arr[t]-data_rate);
            }

        }
        printf("%2d \t %5d\t \t%3d \t %5d \t \t %5d\n",t+1,arr[t],sent,remain,dropped);
        sleep(1);
    }

}