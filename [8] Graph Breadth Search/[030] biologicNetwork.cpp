// Exemplo de pesquisa em profundidade (DFS) num grafo nao dirigido

#include <iostream>

#define MAX 101      // Maximo numero de nos

using namespace std;

int N, r, c, sum=0, rf;              // Numero de nos do grafo
bool visited[MAX][MAX];  // Que nos ja foram visitados?
char caixa[MAX][MAX];

void dfs(int y, int x){
  if(y<0 || y>=r || x<0 || x>=c || visited[y][x] || caixa[y][x]!='#') return;
  sum++;
  visited[y][x] = true;
  dfs(y-1,x);
  dfs(y+1,x);
  dfs(y,x-1);
  dfs(y,x+1);
  dfs(y-1,x-1);
  dfs(y+1,x+1);
  dfs(y+1,x-1);
  dfs(y-1,x+1);
}

int main() {
  int max=0;

  //input
 
  cin >> N;
  for(int h=0;h<N;h++){
    cin >> r >> c;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin >> caixa[i][j];
      }
    }

    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        if(caixa[i][j]=='#' && !visited[i][j]){
          dfs(i,j);
          if(sum>max) max = sum;
          sum=0;
        }
      }
    }
    cout << max << endl;
    max = 0;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        caixa[i][j] = '.';
      }
    }
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        visited[i][j] = false;
      }
    }
  }

  

  return 0;
}
