#include<iostream>
#include<stdlib.h>
using namespace std;


bool game_over_by(char game[3][3],char c){
	//check horizontal
	if( (game[0][0]==c && game[0][1]==c && game[0][2]==c) || 
		(game[1][0]==c && game[1][1]==c && game[1][2]==c) ||
		(game[2][0]==c && game[2][1]==c && game[2][2]==c) ){
		return true;
	}

	//check vertical
	if( (game[0][0]==c && game[1][0]==c && game[2][0]==c) || 
		(game[0][1]==c && game[1][1]==c && game[2][1]==c) ||
		(game[0][2]==c && game[1][2]==c && game[2][2]==c) ){
		return true;
	}

	//check diagonally
	if( (game[0][0]==c && game[1][1]==c && game[2][2]==c )|| 
		(game[0][2]==c && game[1][1]==c && game[2][0]==c) ){
		return true;
	}

	return false;
}
void show_rules(){
	
	cout<<endl;
	cout<<"===================================================";
	cout<<endl;
	cout<<"you need to enter any number between 1 to 9 provided it should not be filled"<<endl;
	cout<<"x indicates that it is filled by you in game"<<endl;
	cout<<"0 indicates that it is filled by computer in game"<<endl;
	cout<<"For more... Read on Wikkipedia"<<endl;
	cout<<endl;
	cout<<"===================================================";
	cout<<endl;
}
void display(char game[3][3]){
	cout<<endl;
	cout<<"===================================================";
	cout<<endl;
	cout<<"\t\t\t"<<game[0][0]<<" | "<<game[0][1]<<" | "<<game[0][2]<<endl;
	cout<<"\t\t\t---------"<<endl;
	cout<<"\t\t\t"<<game[1][0]<<" | "<<game[1][1]<<" | "<<game[1][2]<<endl;
	cout<<"\t\t\t---------"<<endl;
	cout<<"\t\t\t"<<game[2][0]<<" | "<<game[2][1]<<" | "<<game[2][2]<<endl;
	cout<<endl;
	cout<<"===================================================";
	cout<<endl;
}
int run(){

	char game[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			game[i][j]=i*3+j+1+'0';
		}
	}

	//result 0 --> draw, 1 --> user won, -1 computer won
	int result=0;
	bool game_over=false;
	int cell,i,j;
	string input;
	bool condition2;
	for(int k=1;k<=9;k++){

		//by user
		if(k%2==1){
			display(game);
			cout<<"Its your turn"<<endl;
			cout<<"To fill the cell enter appropriate digit"<<endl;
			
			condition2=true;
			while(condition2==true){
				cin>>input;
				cell=int(input[0]-'0');
				if(cell>=1 && cell<=9){
					cell-=1;
					i=cell/3;
					j=cell%3;
					if(game[i][j]!='x' && game[i][j]!='0'){
						game[i][j]='x';
						display(game);
						condition2=false;
					}
					else{
						cout<<"please fill the empty cell"<<endl;
					}
				}
			}

			if(game_over_by(game,'x')){
				result=1;
				game_over=true;
			}
		}
		//by computer

		else{
			condition2=true;
			while(condition2==true){
				cell=rand()%9;
				i=cell/3;
				j=cell%3;

				if(game[i][j]!='x' && game[i][j]!='0'){
					game[i][j]='0';
					condition2=false;
				}
			}

			if(game_over_by(game,'0')){
				game_over=true;
				result=-1;
				break;
			}
		}

		if(game_over==true){
			break;
		}

	}

	display(game);
	return result;
}

int main(){

	int choice;
	int result;
	
	bool condition=true;
	while(condition==true){
		cout<<"Enter 1 to see rulls of the game"<<endl;
		cout<<"Enter 2 to play"<<endl;
		cout<<"Enter 3 to Exit"<<endl;
		cout<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				show_rules();
				break;
			case 2:
				result=run();
				if(result==1){
					cout<<"congratulation! you won the match!"<<endl;
				}
				else if(result==-1){
					cout<<"ops! you lost the game!"<<endl;
				}
				else{
					cout<<"game draw!"<<endl;
				}
				break;
			case 3:
				cout<<"Thank you for play the game"<<endl;
				condition=false;
				break;
		}
	}
return 0;
}