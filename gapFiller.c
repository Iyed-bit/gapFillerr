#include <stdio.h>
#include <stdlib.h>

void readList (int* l,int lg){
  for (int i = 0; i < lg; i++){
    printf("l[%d] = ", i);
    scanf("%d", &l[i]);
  }
  
}
void printList (int* l, int n){
  for (int i = 0; i < n; i++)
    printf("%d | ", l[i]);
  printf("\n");
}

void main()
{      
  int lg;
  printf("list length: ");
  scanf("%d",&lg);                         //              d
  int* l = malloc(lg*sizeof(int)); // [1] [2] [3]<---->[5] [6]  
  
  if (l == NULL){
    fprintf(stderr, "Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }
  readList(l, lg); 
  printList(l, lg);
  
                             //  0   1   2    3   4   5
  int i = 0, j, k, d;              //          i           <---->
                               //                         j = (i + 1) + d  ---> (lg - 1) + d 
                               //                                               lg + d 
  while (i < lg - 1){                                                                       
    d = l[i+1] - l[i] - 1;
    
    if (d > 0){
      lg += d;
      int* temp = realloc(l, lg*sizeof(int));
      if (temp == NULL){
        fprintf(stderr, "Memory Allocation failed.\n");
        exit(EXIT_FAILURE);
      }
      l = temp;
      j = lg - 1 + d;
      while(j >= i + 1 + d){
        l[j] = l[j-d];
        j--;
      }
      k = i + 1;
      while(k <= i + d){
        l[k] = l[k-1] + 1;
        k++;
      }
      } 
    i++;
    }  
  for (int i = 0; i < lg; i++)
    printf("%d|",l[i]);
  free(l); 
}
