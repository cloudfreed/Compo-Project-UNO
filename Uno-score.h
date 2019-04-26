#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct player {
    int score;
    vector<string> card;
    vector<char> number;
    vector<char> colour; 
};


bool checkround(vector<player> &playerpool, int thisplayer){
    if(playerpool[thisplayer].card.size()==0){
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
        playerpool[thisplayer].score += score;
        cout << "Player "<< thisplayer << "'s score = " << score;
        if(playerpool[thisplayer].score>=500){
            return endgame(playerpool);
        }
    }
    }
}




bool endgame(vector<player> playerpool){
    char sortplayer[4]={0,0,0,0};
    for(int i=0;i<playerpool.size();i++){
        int c=playerpool[i].score;
        if(c>0){
            sortplayer[i]=playerpool[i].number.back();
            
        }
    }
    int N=4;
    for(int i=0;i<N;i++){
        if(sortplayer[i+1]>sortplayer[i]){
                char temp = sortplayer[i];
                sortplayer[i] = sortplayer[i+1];
                sortplayer[i+1] = temp;
            }
    }
    cout << " The winner is Player " << sortplayer[0];
    return true;
}

/*void findwinner(vector<player> playerpool){
    string sortplayer[4];
    for(int i=0;i<playerpool.size();i++){
        sortplayer[i] = playerpool[i].number.back();
        for(int j=i+1;j<playerpool.size();j++){
            if(playerpool[j].score > playerpool[i].score){
                sortplayer[i]=playerpool[j].number.back();
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
}*/





