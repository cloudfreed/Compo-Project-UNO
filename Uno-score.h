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

void totalscore(vector<player> playerpool){
    for(int j=0; j<playerpool.size(); j++){
        for(int i=0; i<playerpool[j].card.size(); i++){
            
        }
        
    }
    
}



