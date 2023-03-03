#include <iostream>
#include <fstream>
#include <string>
//writing a function
//creates leaderboad.txt if doesnt exist
//if exists, read player names
//put them in an array of size 10
//of the current game score is higher than the lowest score (bottom), remove it and put in new score
//contents of the array overwrite the file
using namespace std;
void DisplayLeaderboard(string, int,string,string [], int[]);
void sort(int [],int,int,string [],string);
void displayarrays(string [], int []);
void updatetextfile(string,int [],string []);
void startgame();
string buffer = "Maham";
int main()
{
    startgame();
    return 0;
}
void startgame()
{
    //funtion will take parameter of score (current game)
    string leaderboard = "/Users/mahamimran/leaderboard.txt";
    ifstream fin;
    ofstream fout;
    int score[10];
    string name[10];
    
    //INITIALISING ARRAYS
    for(int i=0;i<10;i++){score[i]=-1;}
    for(int i=0;i<10;i++){name[i]="empty";}
    
    //CREATES FILE IF IT DOES NOT ALREADY EXIST, INITIALISING IT
    fout.open(leaderboard,ios::app);
    {
        updatetextfile(leaderboard,score,name);
    }
    fout.close();
    
    string playername = "";
    int newplayerscore = 0;
    
    while(newplayerscore!=-1)
    {
        cout<<"Enter your name: ";
        cin>>playername;
        cout<<"Enter score: ";
        cin>>newplayerscore;
        DisplayLeaderboard(playername, newplayerscore,leaderboard,name,score);
    }
    
}
void updatetextfile(string leaderboard,int score[],string name[])
{
    ofstream fout;
    fout.open(leaderboard,ios::out);
    if(!fout.eof())
    {
        for(int i=0;i<10;i++)
        {
           
                string tempscore = to_string(score[i]);
                string line = tempscore + name[i];
                fout<<line<<endl;
        }
        fout.close();
    }
}
void DisplayLeaderboard(string playername, int newplayerscore,string leaderboard,string name[], int score[])
{
    ifstream fin;
    ofstream fout;
    
        //PUTTING CONTENTS OF FILE INTO ARRAY
        fin.open(leaderboard);
        if(fin.is_open())
        {
            string line = "";
            int index = 0;
            while(!(fin.eof()) && index<10)
            {
                    getline(fin,line);
                    string temp = line.substr(0,2);
                    score[index]=stoi(temp);
                    temp = line.substr(2,15);
                    //NAME SHOULD NOT EXCEED 15 LETTERS
                    name[index]=temp;
                    index++;
            }
        }
        //SORTING ARRAY ACCORDING TO SCORE
        for(int index2=0; index2<10;index2++)
        {sort(score,index2,newplayerscore,name,playername);}
        fin.close();
    
    
        //DISPLAYING ARRAYS
        displayarrays(name,score);
        
        //UPDATING THE .TXT FILE SORTED
        updatetextfile(leaderboard,score,name);
   
    
}
void sort(int score[],int index2,int newplayerscore,string name[],string playername)
{
     //ARRAY UPDATED IN MIDDLE
    if(newplayerscore>=score[index2] && newplayerscore<score[index2-1] && index2!=0)
         {
             for(int i=9;i>index2;i--)
             {
                 score[i]=score[i-1];
                 name[i]=name[i-1];
             }
             score[index2]=newplayerscore;
             name[index2]=playername;
             index2++;
         }
    //HIGH SCORE
    else if(index2 == 0 && newplayerscore>score[0])
    {
        for(int i=9;i>0;i--)
        {
            score[i]=score[i-1];
            name[i]=name[i-1];
        }
        score[0]=newplayerscore;
        name[0]=playername;
        index2++;
    }
     
}
void displayarrays(string name[], int score[])
{
    for(int i=0;i<10;i++)
    {
        cout<<score[i]<<"  "<<name[i]<<endl;
    }
}
