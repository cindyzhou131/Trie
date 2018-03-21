#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <unordered_map>
class Trie{
public:

  struct node{
  public:
    node(char in_value) : value(in_value){};
    ~node();
    char value;
    bool word = false;
    std::unordered_map<char ,node *> next_level;
    void search_helper(const char * value, std::string &prefix);
    void insert_helper(const char * value);
    void print_helper(std::string & prefix);
    void print_string(std::string & prefix);
    bool delete_helper(const char * value);


  };

  void search(const char * value);
  void insert(const char * value);
  void print();
  void delete_all();
  void delete_value(const char * value);
  // void delete(const char * value);
private:

  std::unordered_map<char , node *> root;
};

#endif
