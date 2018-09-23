#include <stdio.h>
 
int minDepth(int a[], int root, int numeros){
  int esq = 2*root+1;
  int dir = 2*root+2;
 
  if(a[root] == -1){
    return 0;
  }
 
  if(dir < numeros){
    if(a[esq] == -1){
      return 1;
    }
 
    if(a[dir] == -1 && a[esq] != 12){
      return 1;
    }
 
    if(a[dir] == -1 && a[esq] == 12){
      return 2;
    }
 
    if(minDepth(a, esq, numeros) >= minDepth(a, dir, numeros)){
      return minDepth(a, dir, numeros) + 1;
    }else{
      return minDepth(a, esq, numeros) + 1;
    }
  }else{
    if(esq < numeros){
        return minDepth(a, esq, numeros) + 1;
      }else{
        return 1;
    }
  }
}
 
int maxDepth(int a[], int root, int numeros)  
{
  int esq = (2*root) + 1;
  int dir = (2*root) + 2;
 
  if (a[root] == -1){
    return 0;
  }
  else
  {
    if(dir < numeros){
      int lDepth = maxDepth(a, esq, numeros);
      int rDepth = maxDepth(a, dir, numeros);
   
      if (lDepth > rDepth){
        return(lDepth + 1);
      }else{
        return(rDepth + 1);
      }
    }
    else{
      if(esq < numeros){
        int lDepth = maxDepth(a, esq, numeros);
        return(lDepth + 1);
      }
      else{
        return 1;
      }
    }
  }
}
 
int main(void) {
  int casos, numeros;
 
  scanf("%d", &casos);
 
  while(casos--){
    scanf("%d", &numeros);
    int tree[numeros];
 
    for(int i = 0; i < numeros; i++){
      scanf("%d", &tree[i]);
    }
 
    int min = minDepth(tree, 0, numeros);
    int max = maxDepth(tree, 0, numeros);
 
    if(max-min<=1){
      printf("T\n");
    }else{
      printf("F\n");
    }
  }
  return 0;
}
