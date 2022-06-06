#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;


vector<string> findCompromise(vector<string> list1,
                              vector<string> list2){

  if(list1.size() == 0){
    vector<string> result = {};
    return result;
  }

  else{
    string _word = list1[0];
    list1.erase(list1.begin());

    for(int i = 0; i < list2.size(); i ++){
      if(list2[i].compare(_word) == 0){
        vector<string> list2_pris(list2.begin() + i + 1, list2.end());
        vector<string> list2_paspris = list2;
        vector<string> list_pris = findCompromise(list1,list2_pris);
        list_pris.insert(list_pris.begin(), _word);
        vector<string> list_paspris = findCompromise(list1,list2_paspris);
        if (list_pris.size()>list_paspris.size()){
          return list_pris;
        }
        return list_paspris;
      }
    }
    return findCompromise(list1,list2);
  }

}

void solve (vector<tuple<bool, bool, string>> _txt1, vector<tuple<bool, bool, string>> _txt2){

  vector<string> common1, common2; //The common words (in the same order than the text) in text1 and 2

  for(int i = 0; i < _txt1.size(); i ++){

    if(!get<0>(_txt1[i])){ //If we have not seen this word yet
      bool found = false;
      string _word = get<2>(_txt1[i]);

      for(int j = 0; j < _txt2.size(); j ++){ //Searching for similar words in txt2
        if(_word.compare(get<2>(_txt2[j])) == 0){
          get<0>(_txt2[j]) = true;
          get<1>(_txt2[j]) = true;
          found = true;
        }
      }

      for(int j = i; j < _txt1.size(); j ++){ //Searching for similar words in txt1
        if(_word.compare(get<2>(_txt1[j])) == 0){
          get<0>(_txt1[j]) = true;
          if(found){ //If have found a similar word in txt2
            get<1>(_txt1[j]) = true;
          }
        }
      }
    }
  }

  for(int i = 0; i < _txt1.size(); i ++){
    if(get<1>(_txt1[i])){
      common1.push_back(get<2>(_txt1[i]));
    }
  }

  for(int i = 0; i < _txt2.size(); i ++){
    if(get<1>(_txt2[i])){
      common2.push_back(get<2>(_txt2[i]));
    }
  }

/*
  for(int i = 0; i < common1.size(); i ++) {
    cout <<common1[i] << " ";
  }

  cout<< " "<< endl;

  for(int i = 0; i < common2.size(); i ++) {
    cout << common2[i] << " ";
  }
*/

  vector<string> longestCompromise = findCompromise(common1, common2);

  for(int i = 0; i < longestCompromise.size(); i++){
    cout << longestCompromise[i] << " ";
  }

}

int main() {
  vector<string> listCompromises;
  vector<tuple<bool, bool, string>> text1, text2; //First bool : same word in the same text ? Second bool : same word in the other text?
  string word;
  char c;
  int nbTextRead = 0;

  while(scanf("%c", &c) != EOF) {

    if(65 <= c && c <= 122)  { //ASCII code for letters
      word.push_back(c);
    }

    else{ //ASCII code for space

      if(nbTextRead == 0 && word.size() != 0){
        text1.push_back(make_tuple(false, false, word));
        word.clear();
      }
      else if(nbTextRead == 1 && word.size() != 0){
        text2.push_back(make_tuple(false, false, word));
        word.clear();
      }

      if (c == 35) { //35 is the ASCII code for #

        nbTextRead += 1;

        if(nbTextRead == 2){
          solve(text1, text2);
          text1.clear();
          text2.clear();
          nbTextRead = 0;
        }
      }

    }

  }
}
