#include <iostream>
#include "login.h"
#include "app.h"
#include <stdlib.h>
using namespace std;

int main()
{
  login obj;
  bool islogin = obj.init(); // calls the init funtion in login class

  // if user login is succesfull:
  app obj2;


  if (islogin)
  {
    obj2.init();
  }



  return 0;
}