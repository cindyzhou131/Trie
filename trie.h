#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <unordered_map>
class Trie{
public:
  void search(const char * value);
  void insert(const char * value);
  // void delete(const char * value);
  struct node{
  public:
    node(char in_value) : value(in_value){};
    char value;
    std::unordered_map<char ,node *> next_level;
    void search_helper(const char * value, std::string prefix);
    void insert_helper(const char * value);

  };
private:

  std::unordered_map<char , node *> root;
};

#endif
