#include <iostream>
#include <string>
#include <vector>

using namespace std;

void findCompromise(string _txt1, string _txt2){
  cout << "Compromise found" << endl;
  cout << _txt1 << endl;
  cout << _txt2 << endl;
}

int main() {
  string text1, text2; //As we are comparing words and not characters, we will store texts as vectors of strings (words)
  char c;
  int nbTextRead = 0;

  while(scanf("%c", &c) != EOF) {

    if (c == 35) { //35 is the ASCII code for #
      nbTextRead += 1;

      if(nbTextRead == 2){
        findCompromise(text1, text2);
        text1.clear();
        text2.clear();
        nbTextRead = 0;
      }
      continue;
    }

    if(nbTextRead == 0){
      text1.push_back(c);
    }
    else if(nbTextRead == 1){
      text2.push_back(c);
    }

  }
}
