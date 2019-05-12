#include <iostream>
#include <string>
#include "rshell.h"
#include "base.h"

using namespace std;

int main(){
//  rShell rShell;
  while(true){
  cout << "$ ";
     
  rShell rShell;
/*  while(theinput != "exit")
  {
        rShell.Display();
        getline(cin,theinput);
        cout<<endl;
        if(theinput =="exit")
    {
        break;
    }*/
//        rShell.Display();
        rShell.the_input();
        rShell.parse();
        rShell.run_execute();
 //       rShell.Tree();
  }  
        return 0 ;
}
