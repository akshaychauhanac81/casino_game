#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<conio.h>
using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
    string playerName;
    int amount;
    int  betmoney;
    int guess;
    int dice;
    char choice;
    system("COLOR 2F");

    srand(time(0));

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');

    cout << "\n\nEnter Your Name :INR";
    getline(cin, playerName);

    cout << "\n\nEnter Deposit amount to play game : INR";
    cin >> amount;

    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is INR " << amount << "\n";

        do

            cout <<playerName<<"\nenter money to bet : INR";
            cin >> betmoney;
            if(betmoney > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(betmoney > amount);

		do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);

        dice = rand()%10 + 1;

        if(dice == 1 || dice == 6 || dice == guess)
        {
            cout << "\n\nGood Luck!! You won INR=" << betmoney * 10;
            amount = amount + betmoney * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost INR "<< betmoney <<"\n";
            amount = amount - betmoney;
        }

        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have INR " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";
        cin >> choice;
    }while(choice =='Y'|| choice=='y');

    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is INR " << amount << "\n\n";
    cout<<"\n\n Thanks to all, and developed by akshay\n";
    drawLine(70,'=');

    return 0;
}

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}

void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}
