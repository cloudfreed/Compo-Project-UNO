#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<bits/stdc++.h>
#include<time.h>
#include<stdlib.h>  
#include<cstring>
#include<iomanip>
#include"Uno-score.h"

using namespace std;

vector<string> deck,P1,P2,P3,P4;
int nplayer=4;
int randomnumber = 100;
bool reverse1=1;
//0=antiClockwise
//1=clockwise

struct player {
    int score;
    vector<string> card;
    vector<char> number;
    vector<char> colour; 
};
vector<player> playerpool;
//player playerpool;

void createdeck(vector<string> &);
void showdeck(vector<string>);
void random(vector<string> &);
void cardmanager(int,vector<string> &);
void gameplay(vector<player> &,vector<string> &,int);
void checktable(vector<string> &);
void showdecksize(vector<string> &);
void showcardonhand(vector<player> &,int);
bool checkwrong(string,string);

void specialcard(string ,player &,int &,vector<string> &,vector<string> &);
string Choosecolour();
void DoubleDraw(player &,vector<string> &,int &);
void Wild(vector<string> &t);
void Wild4(player &play,vector<string> &d,vector<string> &t,int &);

int main()
{
    int firstplayer;
    deck.clear();
    createdeck(deck);
    //showdeck(deck);
    srand (time(NULL));
    random(deck);
    //showdeck(deck);
    cout << "How many player do you want to play with?\nInput = ";
    cin >> nplayer;
    cardmanager(nplayer,deck);
    showcardonhand(playerpool,nplayer);
    showdecksize(deck);
    firstplayer = rand()%(nplayer+1);
    cout << "First player is = player [" <<firstplayer <<"]"<<endl;
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
    showdecksize(deck);
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

void gameplay(vector<player> &pool,vector<string> &d,int n){
    
    vector<string> table;
    table.push_back(d.back());
    d.pop_back();
    int thisplayer=n;
    int ccard;
    bool exitt=1;
    bool x=true;
    int nextplayer;

    while(exitt){
            checktable(table);
            cout << "Player " << thisplayer <<" turn!!!"<<endl;
            do {
                cout << "Choose your card [Number] or [0] to Draw = ";
                cin >> ccard;
                if(ccard==0){
                    pool[thisplayer].card.push_back(d.back());
                    d.pop_back();
                    x = false;
                }
                else{
                x = checkwrong(pool[thisplayer].card[ccard-1],table.back());
                if(x) cout << "Wrong Card!!!";
                }
            }
            while(x);
            if (ccard!=0) {
                if(reverse1){
                    if(thisplayer+1>=nplayer+1){
                        nextplayer = 0;
                    }
                    else nextplayer = thisplayer+1;
                }
                if(!reverse1){
                    if(thisplayer-1<=0){
                        nextplayer = nplayer;
                    }
                    else nextplayer = thisplayer-1;
                    
                }
                table.push_back(pool[thisplayer].card[ccard-1]);
                specialcard(pool[thisplayer].card[ccard-1],pool[nextplayer],thisplayer,d,table);
                pool[thisplayer].card.erase(pool[thisplayer].card.begin()+(ccard-1));
                //exitt = checkwinround();
            }
            
            //pool[thisplayer].card.shrink_to_fit();
            checktable(table);
            showdecksize(d);
            showcardonhand(playerpool,nplayer);
            if(reverse1){
                thisplayer+=1;
                if(thisplayer>nplayer) thisplayer=0;
            }
            if(!reverse1){
                thisplayer-=1;
                if(thisplayer<0) thisplayer=(nplayer);
            }
    }



}

void checktable(vector<string> &t){
    cout << "Last Card on the table is = " <<t.back() <<endl;
}

void showdecksize(vector<string> &d){
    cout << "Number of card left in the deck is = " << d.size() <<endl;
}

void showcardonhand(vector<player> &playerpool,int nplayer){
     for(int i=0;i<=nplayer;i++){
        cout << "Card of player " <<i <<" = ";
        for(int j= 0;j<playerpool[i].card.size();j++){
            cout << setw(10) <<playerpool[i].card[j] <<"[" <<j+1<<"]";
        }
        cout <<endl;
    }
}

bool checkwrong(string p,string t){
    //char textP[p.size()+1];
    //char textT[t.size()+1];
    //strcpy(textP,p.c_str());
    //strcpy(textT,t.c_str());
    //char format[] = "%[^:]:%s";
    //char type1[2],type2[2];
    //char value1[6],value2[6];
    
    //sscanf(textP,format,type1,value1);
    //sscanf(textT,format,type2,value2);
    
    //P is player card
    //T is Table card

    //cout << p << endl;
    //cout << t << endl;
    //cout << textP << "  " << type1 << "  " << value1 << endl;
    //cout << textT << "  " << type2 << "  " << value2 << endl;

    char typeP,typeT;
    string valueP,valueT;

    typeP = p[0];
    typeT = t[0];

    valueP = p.substr(2);
    valueT = t.substr(2);

    if (typeP == 'S') return false;
    if(typeP!=typeT && valueP!=valueT){
        return true;}
    else {
        return false;}
}

void specialcard(string card,player &play,int &player,vector<string> &d,vector<string> &t){
    if (card == "R:Skip"||card == "Y:Skip"||card == "G:Skip"||card == "B:Skip"){
        if (reverse1){
            player+=1;
            if (player >= nplayer+1){
                player = 0;
            }
        if (!reverse1){
            player -= 1;
            if (player <= 0){
                player = nplayer;
            }
        }
        } 
    }else if (card == "R:Rev"||card == "Y:Rev"||card == "G:Rev"||card == "B:Rev"){
        reverse1 = !reverse1;
    }else if (card == "R:+2"||card == "Y:+2"||card == "G:+2"||card == "B:+2"){
        DoubleDraw(play,d,player);
    }else if (card == "S:Wild"){
        Wild(t);
    }else if (card == "S:Wild4"){
        Wild4(play,d,t,player);
    }
}

string Choosecolour(){
    string colour;
    do{
        cout<<"Choose your colour. (R/Y/G/B) :";
        cin>>colour;
    }while (colour != "R" && colour != "Y" && colour != "G" && colour != "B");
    return colour;
}

void DoubleDraw(player &play,vector<string> &d,int &player){
    for(int j=0;j<2;j++){
        play.card.push_back(d.back());
        d.pop_back();
    }
    if (reverse1){
            player+=1;
            if (player >= nplayer+1){
                player = 0;
            }
        if (!reverse1){
            player -= 1;
            if (player <= 0){
                player = nplayer;
            }
        }
        } 
}

void Wild(vector<string> &t){
    string c;
    c = Choosecolour();
    string colour = t[t.size() - 2];
    string back = colour.substr(2);
    string newCard = c+':'+back;
    t.push_back(newCard);
}

void Wild4(player &play,vector<string> &d,vector<string> &t,int &player){
    for(int j=0;j<4;j++){
        play.card.push_back(d.back());
        d.pop_back();
    }
    if (reverse1){
            player+=1;
            if (player >= nplayer+1){
                player = 0;
            }
        if (!reverse1){
            player -= 1;
            if (player <= 0){
                player = nplayer;
            }
        }
        } 
    string c;
    c = Choosecolour();
    string colour = t[t.size() - 2];
    string back = colour.substr(2);
    string newCard = c+':'+back;
    t.push_back(newCard);
}
