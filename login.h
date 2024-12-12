#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "login.cpp"
using namespace std;

login::login()                                    //constructor that is initializing the variables usercounter
{
     ifstream in("userCounter.txt");
     in >> userCounter;

    

     checkCredentials = true;
}

void login::delay()
{    
     for (int i = 0; i < 100000000; i++)
     {
     }
}

bool login::init()
{
     Choicedisplay();
     if (choice == 1)
     {
          createAccount();
     }
     else if (choice == 2)
     {
        loginPage();
        return true;
     }
     else if (choice == 3)
     {
          //system("cls");
          exit(0);
          return false;
     }
}


void login::Choicedisplay()
{
     do
     {
          system("cls");
          cout << "*************** E-Book Reader ***************" << endl
               << endl;
          cout << endl;

          if (choice == 0)
          {
               cout << "Choose your option:" << endl;
          }
          else if (choice != 1 && choice != 2 && choice != 3)
          {
               cout << "Invalid Choice choose again" << endl;
          }

          cout << "1. Create Account" << endl;
          cout << "2. Log into existing account" << endl;
          cout << "3. Exit" << endl<<endl;
          cout << "Enter your choice: ";
          cin >> choice;

     } while (choice != 1 && choice != 2 && choice != 3);
}

bool login::loginPage()
{
     system("cls");
     cout << "*************** E-Book Reader ***************" << endl
          << endl;
     cout << "                User Login" << endl
          << endl;

     cout << "Enter Username: ";
     cin >> UsernameInput;
     cout << "Enter Password: ";
     cin >> PasswordInput;

     checkCredentials = checkUser(UsernameInput, PasswordInput);

     while (checkCredentials!=true)
     {
          system("cls");
          cout << "*************** E-Book Reader ***************" << endl
               << endl;
          cout << "                 User Login" << endl
               << endl;

          cout << "Invalid Username or Password! try again" << endl;

          cout << "Enter Username: ";
          cin >> UsernameInput;
          cout << "Enter Password: ";
          cin >> PasswordInput;

          checkCredentials = checkUser(UsernameInput, PasswordInput);
     }








     system("cls");
     cout << "*************** E-Book Reader ***************" << endl
          << endl;
     cout << "              Login sucessfull" << endl<< endl;

     cout << "                Welcome "<<UsernameInput << endl<< endl;
     cout << endl;

     system("pause");
     return true;
}




bool login::createAccount()
{
     system("cls");
     cout << "*************** E-Book Reader ***************" << endl
          << endl;
     cout << "               Create Account" << endl
          << endl;

     cout << "Enter Username: ";
     cin >> username;
     cout << "Enter Password: ";
     cin >> password;

     string userNumber = "user/user" + to_string(userCounter) + ".txt";         /* create a new file for every user and store username*/
     ofstream out(userNumber);                                                  // and password 
     out << username << endl;
     out << password << endl;

     ofstream out2("userCounter.txt");
     userCounter = userCounter + 1;
     out2 << userCounter;






     //again choose to login or exit the program


     system("cls");
     cout << "*************** E-Book Reader ***************" << endl
          << endl;
     cout << "         Account Created Sucessfully" << endl
          << endl;

     
     system("pause");


     init();


     

}


bool login::checkUser(string userName , string passWord)
{

     for(int i=0 ; i<=userCounter ; i++)
     {

          string userNumber = "user/user" + to_string(i) + ".txt";
          ifstream in(userNumber);
          in>>username;
          in>>password;

          if(userName == username && passWord == password)
          {
               return true;
          }
         
     }
     
     return false;
     
}


