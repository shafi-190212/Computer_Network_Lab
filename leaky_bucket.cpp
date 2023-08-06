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
    int sent=0,remain=0;
    printf("Time\tReceived\tSent\tRemaining\tDropped\n");
    for(int t=0;t<input_packet;t++){
        int dropped=0;
        if(arr[t]>data_rate){
            sent = data_rate;
            remain += (arr[t]-sent);
        }
        else{
            if(remain>0){
                sent = data_rate;
                remain -=sent;
                remain+= arr[t];
            }
            else{
                sent = arr[t];
            }

        }
        if(remain>buc_size){
            dropped = remain-buc_size;
            remain -= dropped;
        }
        if(remain<0) remain = 0;
        printf("%2d \t %5d\t \t%3d \t %5d \t \t %5d\n",t+1,arr[t],sent,remain,dropped);
        sleep(1);
    }

}