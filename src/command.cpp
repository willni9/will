#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include "base.h"
#include "command.h"
#include "or.h"
#include "and.h"
#include "semicolon.h"
#include "connector.h"

using namespace std;

class Base;
class Command;
class Parse;

bool Command::execute(){
  //stringstream ss<cmd>;
  //struct stat info;
  string temp;
  vector<char*>word;
 
  if(cmd == "exit"){
  exit(0);
  }
  
  char *input;
  input = strtok((char *)this->cmd.c_str(), " ");
  //ss.tok(cmd); => get for_loop
  
  //if?while?
  while(input != NULL){
    word.push_back(input);
    input = strtok(NULL, " ");
  }
  
  char **arg = new char *[word.size()+1];
  
  unsigned int size = word.size();
  
  for(unsigned int i = 0; i < size; ++i) {
    arg[i]=word[i];
  }
   
  arg[size] = NULL;
  		
  int status = -1;
  pid_t pid = fork();
	
  if(pid == -1){
    perror("fork");
    exit(1);
  }

  if(pid == 0){
    if( execvp(arg[0], arg) ) {
      perror("execvp");
      exit(1);
    }
  }

  if(pid  > 0){
    waitpid(pid, &status, 0);
    if(status > 0){
    	return false;
    }else if(WEXITSTATUS(status) == 1){
      return false;
    }else if(WEXITSTATUS(status) == 0){
      return true;
    }
  }
  return false;
}
