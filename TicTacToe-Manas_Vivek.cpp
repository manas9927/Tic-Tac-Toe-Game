/* A TIC-TAC-TOE GAME PLAY AND ENJOY */
#include<iostream>

using namespace std;
char  block[10]={'0','1','2','3','4','5','6','7','8','9'};		//Gloabal Array containing block data

class gamescr			//Parent class for game screen design
{
	public:
		void screen()
		{
			system("cls");			//Function to clear up the screen After every chance
			cout<<"\n\n\t\t\t==============================";	
			  cout<<"\n\t\t\t||  WELCOME TO TIC-TAC-TOE  ||";
			  cout<<"\n\t\t\t||   DON'T JUST PLAY, WIN   ||";
			  cout<<"\n\t\t\t==============================\n\n";
			cout<<"\n\n\t\t\tPlayer-1 -> X \t Player-2 -> O ";
			cout <<"\n\t\t\t\t     |     |     ";
			cout <<"\n\t\t\t\t  "<<block[1]<<"  |  " <<block[2]<<"  |  "<<block[3];
			cout <<"\n\t\t\t\t_____|_____|_____";
			cout <<"\n\t\t\t\t     |     |     ";
			cout <<"\n\t\t\t\t  "<<block[4]<<"  |  " <<block[5]<<"  |  "<<block[6];
			cout <<"\n\t\t\t\t_____|_____|_____";
			cout <<"\n\t\t\t\t     |     |     ";
			cout <<"\n\t\t\t\t  "<<block[7]<<"  |  " <<block[8]<<"  |  "<<block[9];
			cout <<"\n\t\t\t\t     |     |     ";
		}
};
class gamebeg:public gamescr		//Child class having function to retun game status
{
	public:
		int stat()
		{
			if (block[1]==block[2] && block[2]==block[3])
			{
				return 1;
			}
			else if (block[4]==block[5] && block[5]==block[6])
			{
				return 1;
			}
			else if (block[7]==block[8] && block[8]==block[9])
			{
				return 1;
			}
			else if (block[1]==block[4] && block[4]==block[7])
			{
				return 1;
			}
			else if (block[2]==block[5] && block[5]==block[8])
			{
				return 1;
			}
			else if (block[3]==block[6] && block[6]==block[9])
			{
				return 1;
			}
			else if (block[1]==block[5] && block[5]==block[9])
			{
				return 1;
			}
			else if (block[3]==block[5] && block[5]==block[7])
			{
				return 1;
			}
			else if (block[1]!='1' && block[2]!='2' && block[3]!='3' && block[4]!='4' && block[5]!='5' && block[6]!='6' && block[7]!='7' && block[8]!='8' && block[9]!='9')
			{
				return 0;
			}
			else
			return 2;
		}
};
int main()
{
	int player=1 ,step ,i;			//initializing player with 1 for begining
	char occupied;					//This charecter occupies the block after the player has used it
	gamebeg g1;						//Child class function
	do
	{
		g1.screen();				//calling screen function for the layout
		player=(player%2)?1:2;		//Conditional operator for player switching, initialized as 1
		cout<<"\n\t\t\tPlayer "<<player<<", do enter your step here->  ";//Entering chance choice for Player
		cin>>step;
		occupied=(player==1)?'X':'O';		//Occupied is X for player 1 & O for Player 2
		if(step==1 && block[1]=='1')		//Whenever the input step is equal to the index of array,
		{									//the block gets occupied and no further be edited.
			block[1]=occupied;
		}
		else if(step==2 && block[2]=='2')
		{
			block[2] = occupied;
		}
		else if(step==3 && block[3]=='3')
		{
			block[3]=occupied;
		}
		else if (step==4 && block[4]=='4')
		{
			block[4]=occupied;
		}
		else if (step==5 && block[5]=='5')
		{
			block[5]=occupied;
		}
		else if (step==6 && block[6]=='6')
		{
			block[6]=occupied;
		}
		else if (step==7 && block[7]=='7')
		{
			block[7]=occupied;
		}
		else if (step==8 && block[8]=='8')
		{
			block[8]=occupied;
		}
		else if (step==9 && block[9]=='9')
		{
			block[9]=occupied;
		}
		else
		{
			cout<<"\n\t\t\tInvalid move ";			//When the user tries to enter on the pre-occupied block

			player--;						//Returns to the Currently plating player
			cin.ignore();					//For discarding the charecter
			cin.get();						//For returning the Charecter
		}
		i=g1.stat();						//storing the status of the game to i
		player++;							//Next player
	}while(i==2);							//i=2 when the no one has won and all the blocks are not occupied
	g1.screen();								
	if(i==1)								//i=1 when one player has won the game
	{
		cout<<"\n\n\t\t\t__________________________________";
		  cout<<"\n\t\t\t|| WINNER WINNER CHICKEN DINNER ||";
		  cout<<"\n\t\t\t----------------------------------";
		cout<<"\n\n\t\t\t\aPlayer "<<--player<<" has won the game \n\n";		//Declaring the winner
	}
	else
	{
		cout<<"\n\t   ____      _      __  __   _____     ____    ____       _     __        __";
		cout<<"\n\t  / ___|    / )    |  )/  | | ____|   |  _ )  |  _ )     / )    ) )      / /";
		cout<<"\n\t | |  _    / _ )   | |)/| | |  _|     | | | | | |_) |   / _ )    ) ) /) / / ";
		cout<<"\n\t | |_| |  / ___ )  | |  | | | |___    | |_| | |  _ <   / ___ )    ) V  V /";
		cout<<"\n\t (_____| /_/   )_) |_|  |_| |_____|   |____/  |_| )_) /_/   )_)    )_/)_/ ";
	}
	cin.ignore();
	cin.get();
	return 0;
}