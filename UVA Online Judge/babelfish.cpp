#include <iostream>
#include <map>
#include <sstream>
#include <string>

/*
 * Author:  Andrés Cimadamore(@acimadamore)
 * Judge:   Online Judge(Former UVA Online Judge)
 * Problem: 10282 - Babelfish
 * URL:     https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1223
 * Topics:  Ad hoc, EasyAF
 * 
 */

using namespace std;

int main(){

  map<string, string> dic;

  string line, english_word, translated_word, word_to_translate;

  getline(cin, line);

  while(line != ""){
    stringstream ss(line);

    ss >> english_word >> translated_word;

    dic[translated_word] = english_word;

    getline(cin, line);
  }

  while(cin >> word_to_translate){
    cout << (dic.count(word_to_translate) ? dic[word_to_translate] : "eh") << endl;
  }

  return 0;
}
