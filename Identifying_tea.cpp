#include <iostream>

using namespace std;

int main(){

  int tea;

  while(scanf("%i", &tea) != EOF) {

    int count = 0;
    for(int i = 0; i < 5; i ++){
      int answer;
      scanf("%i", &answer);
      if(answer == tea) {
        count += 1;
      }
    }
    printf("%i\n", count);
  }
  return 0;
}
