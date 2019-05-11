
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "base.h"
#include "command.h"
#include "parse.h"

using namespace std;

class Base;
class Command;
class Parse;

bool Command::execute(){
  stringstream ss<cmd>;
  string temp;
  vector<char*>word;
 
  if(cmd == "exit"){
  exit(0);
  }
  
  char *input;
  input = strtok((char *)this->cmd(), " ");
  while(input != NULL){
    word.push_back(input);
    input = strtok(NULL, " ");
  }
  
  char **arg = new char *[word.size()+1];
  
  for(unsigned i = 0; i < word.size(); ++i]{
    arg[i]=word[i];
  }
   		
  int status;
  pid_t pid = fork();
	
  if(pid == -1){
    perror("fork");
    exit(1);
  }

  if(pid == 0){
    if(execvp(arg[0], arg) == -1) {
      perror("execvp");
      exit(1);
    }
  }

  if(pid  > 0){
    waitpid(pid, &status, 0);
    ifWEITSTATUS(status) > 0){
    	return false;
    }else if(WEXITSTATUS(status) == 1){
      return false;
    }else if(WEXITSTUTAS(status) == 0){
      return true;
    }
  }
  return false;
}
