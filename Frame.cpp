#include <bits/stdc++.h>
#include<unistd.h>

using namespace std;

int s_size,r,f_size,cnt=0;
string s="";
void sender();
void receive_ack(int,int);
void send_window(int,int);
void resend_window();

struct frame{
    int ack;
    char data;
}f[20];

bool allReceived(){
    cnt = 0;
    for(int i=0;i<s_size;i++){
        if(f[i].ack == 1){
            cnt++;
        }
    }
    if(cnt == s_size)
        return true;
    else
        return false;
}

void Initialize(){

    string input;
    cout<<"Enter a String: ";
    getline(cin,input);
    s_size = input.size();
    // initialize the frame
    for(int i=0;i<s_size;i++){
        f[i].data = input[i];
        f[i].ack = 1;
    }
}
void send_window(int st,int stp){

    if(stp>s_size)
        stp= s_size;
    if(st == stp )
        return;
    for(int i=st ; i<stp ;i++){
        printf("Sending data : frame %d(%c)\n",i,f[i].data);
        f[i].ack = 1;
    }
    sleep(1);
    //send data to receiver for acknowledgement
    receive_ack(st,stp);
}

void resend_window(){
    //check if all data is received or not
    if(allReceived())
    {
        return;
    }
    sleep(3);
    printf("\nResending Window\n");
    sleep(1);
    //sending window from lost acknowledgement frame
    send_window(r,r+f_size);
}

void receive_ack(int st,int stp){
    int x= 0;
    r = rand() % stp;
    r += st;
    if(r<s_size)
        f[r].ack = 0;
    for (int i = st; i < stp; i++) {
        //Receive data and send acknowledgement
        if(f[i].ack == 0){
            printf("\nFrame no. %d is not received\n",r);
            break;
        }
        printf("\nFrame no. %d is received\n",i);
        printf("\nData received: %c\n",f[i].data);
        s+=f[i].data;
        x++;
    }
    // when x==f_size that means all data received
    if(x==f_size){
        send_window(stp,stp+f_size);
    }
    // discarded data
//    for(int i=r+1;i<stp;i++){
//        printf("Frame no %d is discarded\n",i);
//    }
    //acknowledgement lost at some point, so resend the window
    resend_window();
}

int main(){
    /*time(NULL) return the number (after conversion) of seconds since about midnight 1970-01-01.
     * That number changes every second, so using that number to "select a book" pretty much guarantees a new sequence of "random" numbers every time your program runs.*/
    srand(time(NULL));
    Initialize();
    cout<<"\nEnter Window size: ";
    cin>>f_size;
    send_window(0,f_size);
    cout<<"Received Data: "<<s<<endl;
}
//
// Created by mushf on 10/12/2022.
//
