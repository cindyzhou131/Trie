#include <iostream>
#include <fstream>
#include <cstring>

#include "trie.h"


void Trie::search(const char * value){
  char f_char = value[0];
  if(root.find(f_char) == root.end()){
    std::cout << "None";
    return;
  }
  std::string prefix;

  root[f_char]->search_helper(++value, prefix);


}

void Trie::node::search_helper(const char * value, std::string prefix){
  char f_char = value[0];
  if(next_level[f_char]->value == '\0'){
    std::cout << prefix << std::endl;
    return;
  }

  if(value == '\0'){

  }else{
    prefix += f_char;
    letters.second->search_helper(++value, prefix);
  }
}

void Trie::node::print_value(node * end){
  for(auto letters: next_level){
    letters.second->search_helper(++value, prefix);
  }
}

void Trie::insert(const char * value){
  // std::cout << "inseret" << std::endl;
  // std::cout << value[0] << std::endl;
  char f_char = value[0];
  if(root.find(f_char) == root.end()){
    root[f_char] = new Trie::node(value[0]);

  }
  root[f_char]->insert_helper(++value);
}

void Trie::node::insert_helper(const char * value){
  // std::cout << "inseret helper" << std::endl;
  // std::cout << value << std::endl;
  // std::cout << value[0] << std::endl;
  if(value[0] == '\0'){
    next_level[value[0]] = new Trie::node(value[0]);
    return;
  }

  if(next_level.find(value[0]) == next_level.end()){
    next_level[value[0]] = new Trie::node(value[0]);
    insert_helper(++value);
  }
}



int main(int argc, char *argv[]){
  int num_users = 0;
  Trie dicitionary;
  if(argc == 2){
    num_users = atoi(argv[1]);
  }
  // for(int i = 0; i < num_users; i++){
  //   // dictionary.insert()
  // }
  std::string request = "";

  while(true){

    std::cin >> request;

    if(request == "insert"){
      std::cin >> request;
      dicitionary.insert(request.c_str());
    }else if(request == "search"){
      std::cin >> request;
      dicitionary.search(request.c_str());
    }

  }








}
