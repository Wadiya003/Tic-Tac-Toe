#include <iostream>
#include<ctime>
#include<random>
using namespace std;

char box[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
//Function to draw the tic tac toe structure using cout statements
void Draw(){
  cout<<"    "<<"  |  "<<"  |  "<<endl;
  cout<<"    "<<box[0]<<" |  "<<box[1]<<" |  "<<box[2]<<endl;
  cout<<"------------------"<<endl;
   cout<<"    "<<"  |  "<<"  |  "<<endl;
  cout<<"    "<<box[3]<<" |  "<<box[4]<<" |  "<<box[5]<<endl;
   cout<<"------------------"<<endl;
   cout<<"    "<<"  |  "<<"  |  "<<endl;
  cout<<"    "<<box[6]<<" |  "<<box[7]<<" |  "<<box[8]<<endl;
   
}
//Function to keep the count of filled places 
int Count(char symbol){
  int total=0;
  for(int i=0; i < 9; i++){
    if(box[i]==symbol)total+=1;
  } return total;
}
//Function to get the player X's choice and fill it in the box if its a valid position
void GetX(){ 

int choice;
while(true){
  cout<<"Enter Your Position(1-9)"<<endl;
  cin>>choice;
  choice--;
  if(box[choice]!=' '){
    cout<<"Choose an Empty Position !"<<endl;
  }
  else if (choice<0 || choice>8){
    cout<<"Choose from Position from (1-9)"<<endl;
  }
  else {
    box[choice]='X';
    break;
  }
}
}
//Function to get the player O's choice and fill it in the box if its a valid position
void GetO(){
int choice;
while(true){
  cout<<"Enter Your Position(1-9)"<<endl;
  cin>>choice;
  choice--;
  if(box[choice]!=' '){
    cout<<"Choose an Empty Position !"<<endl;
  }
  else if (choice<0 || choice>8){
    cout<<"Choose from Position from (1-9)"<<endl;
  }
  else {
    box[choice]='O';
  }
}
}
//Function to get the computer's choice using random library and srand stuffs .
void GetC(){
  srand(time(NULL));
  int choice;
  do{
  choice=rand()%10;
  }while(box[choice]!=' ');
  box[choice]='O';
}

//Function to check if we have got any winner or not by checking each and every possible cases
char check(){
  if(box[0]==box[1]&& box[1]==box[2]&& box[0]!=' ')
  return box[0];
  if(box[3]==box[4]&& box[4]==box[5]&& box[3]!=' ')
  return box[3];
  if(box[6]==box[7]&& box[7]==box[8]&& box[6]!=' ')
  return box[6];
  if(box[0]==box[3] && box[3]==box[6] && box[0]!=' ')
  return box[0];
  if(box[1]==box[4] && box[4]==box[7] && box[1]!=' ')
  return box[1];
  if(box[2]==box[5] && box[5]==box[8] && box[2]!=' ')
  return box[2];
 if(box[0]==box[4] && box[4]==box[8] && box[0]!=' ')
  return box[0];
  if(box[2]==box[4] && box[4]==box[6] && box[2]!=' ')
  return box[2];
  if(Count('X') + Count('O')<9)
 return 'C'; //if Its c that means we have got no winner yet and the game should continue (Not gonna use it anywhere but since we gotta return a char )
  else return 'D'; //when the game is a draw
}

//function for the mode when player play against computer
void compplay(){
string name;
cout<<"Enter your Name"<< endl;
cin>> name;
while(1){ //an infinite loop (will only break of we get any break inside the loop) 
system("cls");
Draw();
if(Count('X')==Count('O')){
  cout<<name<<"'s Turn"<<endl;
  GetX(); //getting the choice of player X
}
else GetC(); //getting computers choice
char WINNER= check();
Draw(); 
if(WINNER=='X'){ //checking for the winner adn printing the result
cout<<"-------------"<<name<<" WON-------------"<<endl;
break;
}
else if(WINNER=='O'){
cout<<"-------------"<<name<<" LOST-------------"<<endl;
break;
}
else if(WINNER=='D'){
  cout<<"---------------TIE---------------"<<endl;
  break;
}}}
//Mode when player plays against another player
void plaplay(){
string PlayerX; 
string PlayerO;
cout<<"Enter X-Player name "<< endl;
cin>> PlayerX;
cout<<"Enter O-Player name "<< endl;
cin>> PlayerO;
while(1){ //an infinite loop (will only break of we get any break inside the loop)
  system("cls");
  Draw();
  if(Count('X')==Count('O')){
cout<<PlayerX<<"'s Turn"<<endl;
GetX(); //getting the choice of player X
  }
  else cout<<PlayerO<<"'s Turn"<< endl;
  GetO();//getting computers choice
  char WINNER=check();
  Draw();
if(WINNER=='X'){//checking for the winner adn printing the result
cout<<"-------------"<<PlayerX<<" WON-------------"<<endl;
break;
}
else if(WINNER=='O'){
cout<<"-------------"<<PlayerO<<" LOST-------------"<<endl;
break;
}
else if(WINNER=='D'){
  cout<<"---------------TIE---------------"<<endl;
  break;
}}}






int main() {
  //MENU DRIVEN PROGRAM 
  
  int ch ;
  while(1){
    cout<<"Choose a Mode"<<endl;
    cout<<"1.Player vs Computer"<<endl;
    cout<< "2.Player vs Player"<<endl;
    cin>>ch;
    switch(ch){
      case 1 :  compplay(); check();break;
      case 2 :  plaplay();  check();break;
      default : cout<<"Wrong Option chosen ,Try again!"<<endl; break;
    }
  } return 0;
} 