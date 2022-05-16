#include <iostream>
using namespace std;

int main() {
  int area, w, l, mini_w, mini_l, n;

  while(scanf("%i", &w) != EOF) {
    area = 0;
    scanf("%i", &n);
    for(int i = 0; i < n; i++) {
      scanf("%i %i", &mini_w, &mini_l);
      area += mini_w * mini_l;
    }
    l = area / w;
    printf("%i\n", l);
  }
}
