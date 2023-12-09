#include <stdio.h>

void main()
{
  int l [22]= {1, 2, 3, 5, 6}; // 1 2 3 4 5 6 8 
  int lg = 5;
  for (int i = 0; i < lg; i++){
    int d = l[i+1] - l[i] - 1;
    if (d > 0) {
      lg += d;
      for (int j = lg - 1; j < i + d + 2; j--)
        l[j] = l[j-d];
      for (int k = i ; k < d + i ; k++)
        l[k+1] = l[k] + 1;
    }
  }
  for (int i = 0; i < lg; i++)
    printf("%d|",l[i]); 
}