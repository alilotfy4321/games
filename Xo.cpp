#include<bits/stdc++.h>
using namespace std;

char Matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char player = 'X';
void printMatrix(){
	
	system("cls");//
	cout<<"\n";
	for(int i=0; i<3 ; i++){
	     for(int j=0; j<3 ; j++){
	     	cout<<"  "<<Matrix[i][j]<<"   ";
		 }	
		 cout<<"\n";
	}
}
void play(){
	
	char position;
	cout<<"\n";
	cout<<"choose your position to play - player ("<<player<<") : ";
	cin>>position;
	
		for(int i=0; i<3 ; i++){
	      for(int j=0; j<3 ; j++){
	      	if(Matrix[i][j]==position){
	      		Matrix[i][j]=player;
			  }
	     	
		 }	
		 
	}
	
	if(player=='X'){
		player='O';
	}else{
		player='X';
	}
	
}
char WhoWin(){
	int cx=0  , co=0 , counter=0;
	
	  //chack win in row by row
		for(int i=0; i<3 ; i++){
	      for(int j=0; j<3 ; j++){
	      	if(Matrix[i][j]!='X' && Matrix[i][j]!='O'){
	      		counter++; //check for ending game
			  }
	      	if(Matrix[i][j]=='X'){cx++;}else if(Matrix[i][j]=='O'){co++;}
			  
			  if(cx==3 || co==3){
			  	return cx>co?'X':'O';
			  }	     	
		   }
		   cx=0;
		   co=0;	 
		 
		 }
		 //chack win in column by column
		for(int i=0; i<3 ; i++){
	      for(int j=0; j<3 ; j++){
	      	if(Matrix[j][i]=='X'){cx++;}else if(Matrix[j][i]=='O'){co++;}
			  
			  if(cx==3 || co==3){
			  	return cx>co?'X':'O';
			  }	     	
		   }
		   cx=0;
		   co=0;	 
		 
		 }
		 
		 //check diameter
		 
		 if(Matrix[0][0]=='X' && Matrix[1][1]=='X' && Matrix[2][2]=='X' ) return 'X';
		 else if(Matrix[0][0]=='O' && Matrix[1][1]=='O' && Matrix[2][2]=='O' ) return 'O';
		 else if(Matrix[0][2]=='X' && Matrix[1][1]=='X' && Matrix[2][0]=='X' ) return 'X';
		 else if(Matrix[0][2]=='O' && Matrix[1][1]=='O' && Matrix[2][0]=='O' ) return 'O';
		 else{
		 	 if(counter==0) return 'z';//no one win Drow
		 }
       return '.'; //no one win still playing    
}

int main(){
	
while(WhoWin()=='.'){
	cout<<"\n";
	printMatrix();
	play();
}
printMatrix();

if(WhoWin()=='z'){
	cout<<" Drow => NO one win !\n";
}else {
	cout<<"\n Congratulatio ! The winner is  "<< WhoWin()<<" \n";
}
	system("pause");
	return 0;
}
