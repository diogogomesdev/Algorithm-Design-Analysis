#include <iostream>
#include <list>

using namespace std;

int matrix[1500][1500];

// Classe que representa um no
class Node {
public:
  list<int> adj;  // Lista de adjacencias
  bool visited;   // Valor booleano que indica se foi visitado numa pesquisa
  int distance;   // Distancia ao no origem da pesquisa

  Node() {        // Nao e preciso mais nada porque adj ja foi criada
  };              // mas queria mostrar que em C++ tambem existem construtores
};

// Classe que representa um grafo
class Graph {
public:
  int n;          // Numero de nos do grafo
  Node *nodes;    // Array para conter os nos

  Graph(int n) {
    this->n = n;
    nodes = new Node[n+1];  // +1 se os comecam em 1 ao inves de 0
  }

  void addLink(int a, int b) {
    nodes[a].adj.push_back(b);
    nodes[b].adj.push_back(a);
  }
  
  void bfs(int v) {
    list<int> q;
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    
    q.push_back(v);
    nodes[v].visited = true;
    nodes[v].distance = 0;

    while (q.size() > 0) {
      int u = q.front(); q.pop_front();
      matrix[v][u] = nodes[u].distance;
      //cout << u << " [dist=" << nodes[u].distance << "]" << endl;
      for (auto w : nodes[u].adj){
        if (!nodes[w].visited) {
          q.push_back(w);
          nodes[w].visited  = true;
          nodes[w].distance = nodes[u].distance + 1; 	  
        }
      }
    }

  }
};

int main() {
  int n, e, a, b;
  
  cin >> n;
  Graph *g = new Graph(n);
  cin >> e;
  for (int i=0; i<e; i++) {
    cin >> a >> b;
    g->addLink(a, b);
  }

  int diametro = 0, raio = 1501, nos_centrais[1500], nc=0, c1=0,
  nos_perifericos[1500], c2=0;
  bool np = false;
  int max_dia = 0, max_raio = 0;

  for(int i=1;i<=n;i++){
    g->bfs(i);
    for(int j=1;j<=n;j++){
      if(matrix[i][j] > max_dia) max_dia = matrix[i][j];
      if(matrix[i][j] > max_raio) max_raio = matrix[i][j];
    }
    if(max_dia > diametro) diametro = max_dia;
    if(max_raio < raio) raio = max_raio;
    max_raio = 0;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(matrix[i][j] <= raio) nc++;
      if(matrix[i][j] == diametro) np = true;
    }
    if(np){
      nos_perifericos[c2] = i;
      c2++;
      np = false;
    }
    if(nc == n){
      nos_centrais[c1] = i;
      c1++;
    }
    nc = 0;
  }

  cout << diametro << endl;
  cout << raio << endl;
  for(int i=0;i<c1;i++){
    if(i==c1-1) cout << nos_centrais[i] << endl;
    else cout << nos_centrais[i] << " ";
  }
  for(int i=0;i<c2;i++){
    if(i==c2-1) cout << nos_perifericos[i] << endl;
    else cout << nos_perifericos[i] << " ";
  }

  return 0;
}
