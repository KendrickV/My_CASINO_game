#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

void rules()
{
   system("cls");
   cout << "\t\t\t*******CASINO RULES!*******\n";
   cout << "\t\t1. Choose a number between 1 to 10\n";
   cout << "\t\t2. Winner gets 10 times of the money bet\n";
   cout << "\t\t3. Wrong bet, and you lose the amount you bet\n\n";
   cout << "\t\t   Press [Any Key] to continue";
}

void welcome()
{
	system("cls");
	system("color f");
	cout<<"\n\t\t\t\t*******WELCOME TO LUCKY STRIKE CASINO********\n\n";
}

void losingEffect(int k)
{
	system("color c");
	cout<<"\n\t\t\tBetter Luck next time. You lost: $"<<k<<endl;
	cout<<"\n\t\t\t\t       ________  \n";
	cout<<"\t\t\t\t      /        \\   \n";
	cout<<"\t\t\t\t     /          \\  \n";
	cout<<"\t\t\t\t    |  ==    ==  | \n";
	cout<<"\t\t\t\t    |  !      !  | \n";
	cout<<"\t\t\t\t    \\    ___     / \n";
	cout<<"\t\t\t\t     \\  /   \\   /  \n";
	cout<<"\t\t\t\t      \\        /   \n";
	cout<<"\t\t\t\t       \\______/   \n";
	for(int i=5; i>1; i--)Beep(i*100, 100);
	Sleep(3000);
}

void winningEffect(int k)
{
	int x=0;

	//fireworks effect
	while(x<4)
	{   
	    welcome();
	    system("color b");
	    
	    cout<<"\t\t\tWOW YOU ARE IN LUCK TODAY .... YOU WON: $"<<k<<endl;
	    
		for(int i=0; i<7; i++)Beep(i*200, 100);
		for(int i=0; i<6; i++)
		{
			cout<<"\t\t\t";
			for(int j=0; j<41; j++)
			{
	 			if(rand()%4==0) cout<<"*";
				else cout<<" ";
	 		}
			cout<<endl;
		}
		Sleep(300);
		system("cls");
		x++;
	}
}

int main()
{
	srand(time(0));
	
   string player;
   int balance=0;
   int Bamount=0;
   int Gnumber=0;
   int dice;
   char choice;
   
    rules();
   	_getch();

   welcome();
   cout<<"\t\tPlease enter your name: ";
   getline(cin,player);
   
   cout<<"\t\tPlease enter the starting balance amount: $"; 
   cin>>balance;
   
   do
   {
   		do
   		{
   			welcome();
			cout<<"\n\t\tDear "<<player<<", your current balance is: $"<<balance<<"\n";
   			cout<<"\t\tPlease enter the betting amount: $"; 
   			cin>>Bamount;
   			if(Bamount>balance)
   			{
   				cout<<"\t\tBetting amount can not exceed your balance!!!"<<endl;
				Sleep(2000);
			}
		}while(Bamount>balance);
		
		do
		{
   			welcome();
			cout<<"\n\t\tPlease choose a number from 1 - 10: ";
			cin>>Gnumber;
			if(Gnumber<1 || Gnumber>10)
			{
				cout<<"\t\tNumber should be between 1 - 10"<<endl;
				Sleep(2000);	
			}
			
		}while(Gnumber<1 || Gnumber>10);
		
		if(Bamount<rand()%5+1) dice=Gnumber; // in order to make the player to feel lucky so he will play more
		else dice=rand()%10+1;
		
		if(dice==Gnumber) // WINING SIDE
		{
			winningEffect(Bamount*10);
			balance += Bamount*10;	
		}
		else             // LOSING SIDE
		{
			welcome();
			balance-=Bamount;
			losingEffect(Bamount);
		}
		
		welcome();
		cout<<"\n\t\t\tThe winning number was: "<<dice<<endl;
		cout<<"\t\t\tYour current balance is: $"<<balance<<endl;
		
		Sleep(2000);
		
		if(balance == 0)
		{
			welcome();
			cout<<"\n\t\t\tYou do not have any money left to play: $"<<balance<<endl;
			Sleep(3000);
			break;
		}
			
		cout<<"\n\t\t\tDo you want to play again? y/n: ";
		cin>>choice;
			
	}while(choice=='y' || choice=='Y');
	
	welcome();
	cout<<"\n\t\t\tThank you for playing!!!! Your balance is: $"<<balance<<endl;
		
return 0;
}
   

