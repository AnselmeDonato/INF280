#include <iostream>
#include <string>

using namespace std;

int main() {
  char c;
  string numberString = "";
  bool startNumber = false;
  int nb_sub = 0;

  while(scanf("%c", &c) != EOF) {
    if(48 <= c && c <= 57) {
      numberString.append(&c);
      startNumber = true;
    }

    else{
      if(startNumber){
        for(int i = 0; i < numberString.size(); i ++){
          string sub = "";
          for(int j = i; j < numberString.size(); j ++){
            sub.push_back(numberString[j]);
            int number = stoi(sub);
            if(number % 3 == 0){
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
