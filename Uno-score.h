#include<iostream>
#include<vector>
#include<string>
#include "UnoMain.cpp"


void sumscore(vector<player> playerpool){
    for(int j=0; j<playerpool.size(); j++){
        int sum=0, score=0;
        for(int i=0; i<playerpool[j].card.size(); i++){
            string x = playerpool[j].card[i].substr(2);
            if(x == "0") sum = 0;
            if(x == "1") sum = 1;
            if(x == "2") sum = 2; 
            if(x == "3") sum = 3; 
            if(x == "4") sum = 4; 
            if(x == "5") sum = 5; 
            if(x == "6") sum = 6;
            if(x == "7") sum = 7; 
            if(x == "8") sum = 8; 
            if(x == "9") sum = 9;
            if(x == "Skip") sum = 20;
            if(x == "Rev") sum = 20;
            if(x == "+2") sum = 20;
            if(x == "Wild") sum = 50;
            if(x == "Wild4") sum = 50;
            score += sum;
        }
        playerpool[j].score += score;
        cout << "Player "<< j+1 << "'s score = " << score;
        cout << "Player "<< j+1 << "'s total score = " << playerpool[j].score;

    }
}

bool checkwinner(vector<player> playerpool){
    for(int i=0;i<playerpool.size();i++){
        int c=playerpool[i].score;
        if(c>=500){
            return true;
        }else{
            return false;
        }
    }
}



void findwinner(vector<player> playerpool){
    string sortplayer[4];
    for(int i=0;i<playerpool.size();i++){
        sortplayer[i] = playerpool[i].name;
        for(int j=i+1;j<playerpool.size();j++){
            if(playerpool[j].score > playerpool[i].score){
                sortplayer[i]=playerpool[j].name;
            }
        }
    }
    cout << " The winner is " << sortplayer[0] << "\n";
    int N = sizeof(sortplayer)/sizeof(sortplayer[0]);
    if(N==4){
        cout << " The second place is " << sortplayer[1] << "\n";
        cout << " The third place is " << sortplayer[2] << "\n";
        cout << " The fourth plae is " << sortplayer[3] << "\n";
    }else{
        if(N==3){
            cout << " The second place is " << sortplayer[1] << "\n";
            cout << " The third place is " << sortplayer[2] << "\n";
        }else{
            cout << " The second place is " << sortplayer[1] << "\n";
        }
    }
}



