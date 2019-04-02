#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>  

using namespace std;

vector<string> deck,P1,P2,P3,P4;
int nplayer=4;
int randomnumber = 2000;
struct player {
    int score;
    vector<string> card;
};
vector<player> playerpool;
//player playerpool;

void createdeck(vector<string> &);
void showdeck(vector<string>);
void random(vector<string> &);
void cardmanager(int,vector<string> &);
int gameplay(vector<player> &,vector<string> &,int);

int main()
{
    int firstplayer;
    deck.clear();
    createdeck(deck);
    showdeck(deck);
    srand (time(NULL));
    random(deck);
    showdeck(deck);
    cout << "How many player do you want to play with?\nInput = ";
    cin >> nplayer;
    cardmanager(nplayer,deck);
    for(int i=0;i<=nplayer;i++){
        cout << "Card of player " <<i <<" = ";
        for(int j= 0;j<playerpool[i].card.size();j++){
            cout << playerpool[i].card[j] << "\t";
        }
        cout <<endl;
    }
    firstplayer = rand()%(nplayer+1);
    cout << "first player is = player [" <<firstplayer <<"]"<<endl;
    gameplay(playerpool,deck,firstplayer);

    return 0;
}

void createdeck(vector<string> &deck){
    for(int i=0;i<4;i++){
        
        if(i==0){deck.push_back("R:0");}
        if(i==1){deck.push_back("Y:0");}
        if(i==2){deck.push_back("G:0");}
        if(i==3){deck.push_back("B:0");}
        
        if(i<2){
                
                deck.push_back("R:Skip");
                deck.push_back("Y:Skip");
                deck.push_back("G:Skip");
                deck.push_back("B:Skip");

                deck.push_back("R:Rev");
                deck.push_back("Y:Rev");
                deck.push_back("G:Rev");
                deck.push_back("B:Rev");

                deck.push_back("R:+2");
                deck.push_back("Y:+2");
                deck.push_back("G:+2");
                deck.push_back("B:+2");
        }

        deck.push_back("S:Wild");
        deck.push_back("S:Wild4");

        for(int j=0;j<2;j++){

            for(int k=1;k<10;k++){
                
                if(i==0){deck.push_back("R:"+to_string(k));}
                if(i==1){deck.push_back("Y:"+to_string(k));}
                if(i==2){deck.push_back("G:"+to_string(k));}
                if(i==3){deck.push_back("B:"+to_string(k));}
                
            }
                
        }
    }    
}

void showdeck(vector<string> deck){
    for(int i=0 ;i<deck.size();i++){
        cout << deck[i] <<endl;
    }
    cout << "Number of card is = " << deck.size() <<endl;
}

void random(vector<string> &d){
    int count=0;
    string temp;
    while(count <= randomnumber){
        temp = d.back();
        d.pop_back();
        d.insert(d.begin()+(rand()%107), temp);
        count++;
    }
}

void cardmanager(int n,vector<string> &d){
    player playertemp;
    for(int i=0;i<=n;i++){
        for(int j=0;j<7;j++){
            playertemp.card.push_back(d.back());
            d.pop_back();
        }
        playerpool.push_back(playertemp);
        playertemp.card.clear();
    }
}

int gameplay(vector<player> &pool,vector<string> &d,int n){
    bool reverse=0;
    //0=clockwise
    //1=antiClockwise
    vector<string> table;
    table.push_back(d.back());
    d.pop_back;
    int thisplayer=n;
    int ccard;

    while(true){
        while(reverse){
            cout << "Last Card on the table is = " <<table.back();
            cout << "Player " << thisplayer <<" turn!!!";
            cout << "Choose your card number";
            cin >> ccard;

        }
        while(reverse){
            
        }
    }



}