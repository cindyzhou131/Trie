#include <iostream>
#include <fstream>
#include <cstring>

#include "trie.h"

const long STRING_LIM = 100;


int main(int argc, char *argv[]){
//   int num_users = 0;
//   if(argc == 2){
//     num_users = atoi(argv[1]);
//   }
  
    Trie dicitionary;

  std::ifstream ifs;
  
  char word[STRING_LIM]; //c_str() does weird stuff to the null character
  std::string request = "";
  std::string data = "";
  while(true){
    std::cout << "Enter Command: ";
    std::cin >> request;

    if(request == "insert" || request == "i"){
      std::cout << "insert: ";
      std::cin >> request;
//       if(ifs.open(request.c_str(), std::ifstream::in) == 
//       while(ifs.getline(word, STRING_LIM)){
//         strncpy(word, request.c_str(),STRING_LIM);
//          dicitionary.insert(word);
//         std::cout << "new value added: " << word << std::endl;
//        }
      
      strncpy(word, request.c_str(),STRING_LIM);
      dicitionary.insert(word);
      std::cout << "new value added: " << word << std::endl;
    }else if(request == "search" || request == "s"){
      std::cout << "search for: ";
      std::cin >> request;
      strncpy(word, request.c_str(),STRING_LIM);
      dicitionary.search(word);
    }
    else if(request == "print" || request == "p"){
      dicitionary.print();
    }else if(request == "clear all"){
      dicitionary.delete_all();
    }else if(request == "delete" || request == "d"){
      std::cout << "delete value: ";
      std::cin >> request;
      strncpy(word, request.c_str(),STRING_LIM);
      dicitionary.delete_value(word);
    }else if(request == "quit" || request == "q"){
      std::cout << "Exiting..." << std::endl;
      return 0;
    }else if(request == "define" || request == "d"){
      std::cin >> request;
      std::cin >> data;
      strncpy(word, request.c_str(),STRING_LIM);
      dicitionary.insert_definition(word, data.c_str());
    
    }
  }
}
