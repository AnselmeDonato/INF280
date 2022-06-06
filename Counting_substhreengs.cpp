#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main() {
  char c;
  string numberString = "";
  bool startNumber = false;
  int nb_sub = 0;

  while(scanf("%c", &c) != EOF) {
    if(48 <= c && c <= 57) {
      numberString.push_back(c);
      startNumber = true;
    }

    else{
      if(startNumber){
        for(int i = 0; i < numberString.size(); i ++){
          long maybe_sub = 0;
          for(int j = i; j < numberString.size(); j ++){
            maybe_sub += numberString[j] - '0';
            if( maybe_sub % 3 == 0){
              nb_sub += 1;
            }
          }
        }
      }

      if(c == 10){
        printf("%i\n", nb_sub);
        nb_sub = 0;
      }

      startNumber = false;
      numberString.clear();

    }

  }

  return 0;
}
