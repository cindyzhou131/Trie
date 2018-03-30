#include <iostream>
#include <cstring>
#include "trie.h"

void Trie::insert_definition(const char * value, const char * def){
  auto node = search(value);
  if(node == nullptr){
  std::cout << "Word is not in the dictionary insert before defining" << std::endl;
  }
  if(node->definition != nullptr){
  std::cout << "Redefining" << std::endl;
  }
  node->definition = def;
}

Trie::node * Trie::search(const char * value){
  char f_char = value[0];
  if(f_char ==  '\0'){
    return nullptr;
  }
  if(root.find(f_char) == root.end()){
    std::cout<< "None";
    return nullptr;
  }
  std::string prefix;
  prefix += value[0];

  return root[f_char]->search_helper(++value, prefix);
}


Trie::node * Trie::node::search_helper(const char * value, std::string &prefix){
  char f_char = value[0];
  prefix += f_char;

  if(f_char == '*'){
    prefix.pop_back();
    for(auto entry : next_level){
      entry.second->print_string(prefix);
    }
    return nullptr;
  }else if(f_char == '\0'){
    if(word){
      std::cout << prefix << std::endl;
    }else{
      std::cout << "Word does not exists" << std:: endl;
    }
  }
  if(next_level.find(f_char) == next_level.end()){
    std::cout << prefix;
    return nullptr;
  }
  return next_level[f_char]->search_helper(++value, prefix);

}

void Trie::node::print_string(std::string & prefix){
  prefix += value;
  if(word){
    std::cout << prefix << std::endl;
  }
  for(auto info : next_level){
    info.second->print_string(prefix);
    prefix.pop_back();
  }
}

void Trie::insert(const char * value){

  char f_char = value[0];
  if(f_char == '\0'){
    return;
  }
  if(root.find(f_char) == root.end()){
    root[f_char] = new Trie::node(f_char);
  }
  root[f_char]->insert_helper(++value);
}

void Trie::node::insert_helper(const char * value){
  char f_char = value[0];
  std::cout << f_char;
  if(f_char == '\0'){
    word = true;
    return;
  }

  if(next_level.find(f_char) == next_level.end()){
    next_level[f_char] = new Trie::node(f_char);
  }
  ++value;

  next_level[f_char]->insert_helper(value);
}

void Trie::print(){
  std::string prefix = "";
  for(auto entry : root){
    // std::cout<< entry.first << std::endl;

      entry.second->print_helper(prefix);
  }
}

void Trie::node::print_helper(std::string &prefix){
  prefix += value;
  if(word){
    std::cout << prefix << std::endl;
  }
  for(auto info : next_level){
    info.second->print_helper(prefix);
  }
  prefix.pop_back();
}


bool Trie::node::delete_helper(const char * value){

  char f_char = value[0];

  if(f_char == '\0'){
    if(word){
      word = false;
      if(next_level.empty()){
        return true;
      }else{
        next_level.erase(f_char);
      }
      return true;
    }else{
      std::cout << "not a word" << std::endl;
      std::cout << "Word Does not Exist" << std::endl;
      return false;
    }
  }
  if(next_level.find(f_char) == next_level.end()){
    std::cout << "no map case " << value << std::endl;
    std::cout << "Word Does not Exist" << std::endl;
    return false;
  }


  bool d_val = next_level[f_char]->delete_helper(++value);
  //the truth value propogration is off
  //write it out

  if(d_val){
    auto entry = next_level[f_char];
    next_level.erase(f_char);
    delete entry;
    entry = nullptr;
    return true;
  }
  return false;
}

void Trie::delete_value(const char * value){
  char f_char = value[0];

  if(root.find(f_char) == root.end()){
    std::cout << "Word Does not Exist" << std::endl;
  }else{
    root[f_char]->delete_helper(++value);
  }
}

void Trie::delete_all(){
  for(auto entry : root){
    delete entry.second;
  }
}
      
Trie::node::~node(){
  for(auto entry : next_level){
    delete entry.second;
    entry.second = nullptr;
  }
}
