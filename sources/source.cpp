// Copyright 2020 Your Name <your_email>

#include <iostream>
#include <string>

#include "..\\include\\Stack1.h"

struct mySt{
  std::string a;
};

int main(){
  Stack1<mySt> a;
  a.push(mySt{"hello"});
  std::cout<<a.head().a;
}
