#include<iostream>
#include<time.h>
#include<cstdlib>
#include<iomanip>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::setw;


void outboard(int arrayy[9][9],char arr[9][9]);
void play(int arrayy[9][9],char arr[9][9],int& column , int& row, int& number);

int main()
{

	int x;
	int y;
	int Board[9][9];
	char cBoard[9][9];
	int column;
	int row;
	int number;
	int z=0;
	ifstream Sudoku("cipher");


	cout<<endl;
	cout<<" Welcome In Sudoku Game by Nikita Zaitsev "<<endl<<endl;
	cout<<"Enter ( 1 ) to begin the game, ( 2 ) for more info...."<<endl;
	cin>>y;

	if(y==2)
	{
		cout<<"Number puzzles appeared in newspapers in the late 19th century, when French"<<endl;
		cout<<"puzzle setters began experimenting with removing numbers from magic squares."<<endl;
		cout<<"Le Sicle, a Paris-based daily, published a partially completed 9*9 magic "<<endl;
		cout<<"square with 3*3 sub squares on November 19, 1892."<<endl;
		cout<<"[8] It was not a Sudoku because it contained double-digit numbers and required "<<endl;
		cout<<"arithmetic rather than logic to solve, but it shared key characteristics: "<<endl;
		cout<<"each row, column and sub-square added up to the same number. "<<endl;
		cout<<endl;

		cout<<"In this game you will choose square by Enter the number of row and space "<<endl;
		cout<<"and the number of column. Then you will add a number from 1 to 9 ."<<endl;

		while(y!=1)
		{
		cout<<"Please Enter 1: ";
		    cin>>y;
		}
	}
	cout<<endl<<endl;
	if(y==1)
	{

		for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			Sudoku >> Board[i][j];
		}
	}
	outboard(Board,cBoard);
	cout<<"If you want to change the numbers in Sudoku please enter 1 :\nIf you want start the game enter 2 : "<<endl;
	cin>>x;
	}

	while(x==1)
	{
		for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			Sudoku >> Board[i][j];
		}
	}
		outboard(Board,cBoard);
	cout<<"If you want to change the numbers in Sudoku please enter 1 :\nIf you want start the game enter 2 : "<<endl;
	cin>>x;
	}
	if(x==2)
		play(Board,cBoard,column ,row,number);


	return 0;
}

void outboard(int arrayy[9][9],char arr[9][9])
{

	cout<<endl;
		cout<<" Welcome In Sudoku Game by Nikita Zaitsev "<<endl<<endl;
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(arrayy[i][j]==0)
			{
				arr[i][j]=arrayy[i][j];
			}
			arr[i][j]=' ';
	}
	}

	cout<<setw(3)<<"      1   2   3   4   5   6   7   8   9"<<endl;
	cout<<setw(3)<<"    -------------------------------------"<<endl;
	cout<<setw(3)<<"    -------------------------------------"<<endl;
	for(int i=0; i<9; i++)
	{
		cout<<i+1<<"-"<<setw(3);
		for(int j=0; j<9; j++)
		{
			if(arrayy[i][j]==0)
				cout<<"|"<<" "<<arr[i][j]<<" ";
			else
				cout<<"|"<<" "<<arrayy[i][j]<<" ";

		}
		cout<<"|";
		cout<<endl;
		cout<<setw(3)<<"    -------------------------------------"<<endl;

	}
	cout<<setw(3)<<"    -------------------------------------"<<endl;
	cout<<endl<<endl;
}

void play(int arrayy[9][9],char arr[9][9],int& column , int& row, int& number)
{
	int count=0;
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(arrayy[i][j]==0)
				count++;
		}

	}
	int z;
	while(count!=0)
	{
		z=0;
		cout<<"You have "<<count<<" of spaces.."<<endl;
		cout<<"choose the square by enter the row number then space then the column number..."<<endl;
		cin>>row>>column;
		row=row-1;
		column=column-1;
		count=0;
		if(arrayy[row][column]==0)
		{
		if((column>=0 && column<9) && (row>=0 && row<9))
		{
			cout<<"Please add number...."<<endl;
			cin>>number;
			if(number>0 && number<10)
			{

				for(int i=0; i<9; i++)
				{
					if(arrayy[row][i]==number)
					{
						z=1;
						cout<<"There are the same number in row..."<<endl<<endl;

						break;
					}
					else if (arrayy[i][column]==number)
					{
						z=1;
						cout<<"There are the same number in column..."<<endl<<endl;
						break;
					}
					{

					}
				}
				if(row<=2 && column<=2)
				{
				for(int i=0; i<=2; i++)
				{
					for(int j=0; j<=2; j++)
					{
						if(arrayy[i][j]==number)
						{
							z=1;
						    cout<<"There are the same number in square 1..."<<endl<<endl;

						    break;
						}
					}
				}
				}
				if(row<=2 && (column>2 && column<6))
				{
				for(int i=0; i<=2; i++)
				{
					for(int j=3; j<=5; j++)
					{
						if(arrayy[i][j]==number)
						{
							z=1;
						    cout<<"There are the same number in square 2..."<<endl<<endl;
						    break;
						}
					}
				}
				}
				if(row<=2 && (column>5 && column <9))
				{
				for(int i=0; i<=2; i++)
				{
					for(int j=6; j<=8; j++)
					{
						if(arrayy[i][j]==number)
						{
							z=1;
						    cout<<"There are the same number in square 3..."<<endl<<endl;
						    break;
						}
					}
				}
				}
				if((row>2 && row<6) && (column <=2))
				{
				for(int i=3; i<=5; i++)
				{
					for(int j=0; j<=2; j++)
					{
						if(arrayy[i][j]==number)
						{
							z=1;
						    cout<<"There are the same number in square number 4..."<<endl<<endl;
						    break;
						}
					}
				}
				}
				if((row>2 && row<6) && (column >2 && column<6))
				{
				for(int i=3; i<=5; i++)
				{
					for(int j=3; j<=5; j++)
					{
						if(arrayy[i][j]==number)
						{
							z=1;
						    cout<<"There are the same number in square number 5..."<<endl<<endl;
						    break;
						}
					}
				}
				}
				if((row>2 && row<6)&&(column>5 &&column<9))
				{
				for(int i=3; i<=5; i++)
				{
					for(int j=6; j<=8; j++)
					{
						if(arrayy[i][j]==number)
						{

							z=1;
						    cout<<"There are the same number in square number 6..."<<endl<<endl;
						    break;
						}
					}
				}
				}
				if((row>5 && row<9)&&(column<=2))
				{
				for(int i=6; i<=8; i++)
				{
					for(int j=0; j<=2; j++)
					{
						if(arrayy[i][j]==number)
						{

							z=1;
						    cout<<"There are the same number in square number 7..."<<endl<<endl;
						    break;
						}
					}
				}
				}
				if((row>5 && row<9)&&(column>2 && column<6))
				{
				for(int i=6; i<=8; i++)
				{
					for(int j=3; j<=5; j++)
					{
						if(arrayy[i][j]==number)
						{

							z=1;
							cout<<"There are the same number in square number 8..."<<endl<<endl;
						    break;
						}
					}
				}
				}
				if((row>5 && row<9)&&(column>5 && column<9))
				{
				for(int i=6; i<=8; i++)
				{
					for(int j=6; j<=8; j++)
					{
						if(arrayy[i][j]==number)
						{

							z=1;
							cout<<"There are the same number in square number 9..."<<endl<<endl;
						    break;
						}
					}
				}
				}

				if(z!=1)
				{

					arrayy[row][column]=number;
				    outboard(arrayy,arr);
					(10);
					cout<<"Success"<<endl;
					cout<<endl;
				}
			}
			else
			{

				cout<<"You have to enter from 1 to 9 in cell ..."<<endl;
            }
		}
		else
		{

			cout<<"You have to enter from 1 to 9 in row and column ..."<<endl;
		}

	}
	else
	{

		cout<<"There are another number in this cell...."<<endl;
	}

	for(int i=0; i<9; i++)
	    {
		for(int j=0; j<9; j++)
		{
			if(arrayy[i][j]==0)
				count++;
		}
	}

	if(count==0)
	{
		(9);
		cout<<" YOU WIN "<<endl<<endl;
	}




	}
}
