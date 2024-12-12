#include<iostream>
#include<fstream>
using namespace std;

class login
{
    public:

    login();        //constructor
    bool init();    //initialize function to initialize the program
    void Choicedisplay();         //ask to login or create account
    bool loginPage();               // run if user choose to login
    bool createAccount();           //run if user choose to create account
    void delay();                   //simple delay programe
    bool checkUser(string userName , string passWord);  //check user input and match from all the user files created
    //void searchFile();


    private:
        int choice = 0;
        string UsernameInput;
        string username;
        string PasswordInput;
        string password;
        int userCounter;
        bool checkCredentials;

};

