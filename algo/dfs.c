#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int CharIntMap[SIZE];



struct Stack {
  char items[SIZE];
  int top;
};



struct Stack* createStack() {
  struct Stack* s = malloc(sizeof(struct Stack));
  s->top = -1;
  return s;
}

int isEmpty(struct Stack* s) {
  return s->top == -1;
}

char pop(struct Stack* s) {
  int item;
  if (isEmpty(s)) {
    printf("Stack is empty");
    return -1;
  } 
    return s->items[s->top--];  
}


void push(struct Stack* s, char value) {
  if (s->top == SIZE - 1)
    printf("\nStack is Full!!");
  else {
    s->items[++(s->top)] = value;
  }
}


struct node {
  char vertex;
  struct node* next;
};

void addToList(struct node **head,char data){
      
      struct node* new_node = malloc(sizeof(struct node));
      new_node->vertex = data;
      if(!(*head)){
           *head=new_node;
           new_node->next = NULL;
      }
      else{
          struct node *temp = *head;
          while(temp->next){
              temp = temp->next;
          }
          temp->next = new_node;
          new_node -> next = NULL;
      }
 }
 



struct Graph {
    
  int numVertices;
  struct node** adjList;
  int* visited;
};


struct Graph* createGraph(int vertices) {

  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjList = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  
  for (size_t i = 0; i < vertices; i++) {
    graph->adjList[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

void printList(struct node *head){
    while(head){
        printf("%c\n",head->vertex);
        head = head->next;
    }
}

void addEdge(struct Graph* graph, char src, char dest) {



  addToList(graph->adjList + CharIntMap[src],dest); 

  addToList(graph->adjList + CharIntMap[dest],src);

}   


void DFS(struct Graph* graph, char startVertex) {

  struct Stack* s = createStack();

  graph->visited[CharIntMap[startVertex]] = 1;
  push(s, startVertex);

  while (!isEmpty(s)) {
    
    char currentVertex = pop(s);
    printf("Visited %c\n", currentVertex);

    struct node* temp = graph->adjList[CharIntMap[currentVertex]];

    while (temp) {
      char adjVertex = temp->vertex;

      if (graph->visited[CharIntMap[adjVertex]] == 0) {
        graph->visited[CharIntMap[adjVertex]] = 1;
        push(s,adjVertex);
      }
      temp = temp->next;
    }
  }
}

void printAdjList(struct Graph* graph){
    
    for(int i = 0;i < graph->numVertices;i++){

        struct node *head = graph->adjList[i];
        
        while(head){
            printf("%c ",head->vertex);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {

 
   int n;
  printf("Enter no of nodes\n");
  scanf("%d",&n);
    char vertices[n];
    for(size_t i = 0;i < n;i++){
        printf("Enter Node no %d\n",i + 1);
        scanf(" %c",vertices + i);
        CharIntMap[vertices[i]] = i;
    }
  struct Graph* graph = createGraph(n);
  
  printf("Start adding edges in the format a b .. Enter 0 0 to end adding new edges\n");
  

  
  while(1){
      char starting;
      scanf(" %c",&starting);
      char ending;
      scanf(" %c",&ending);
      if(starting == '0' && ending == '0'){
          break;
      }
      addEdge(graph,starting,ending);
  }

  DFS(graph , 'A');
  return 0;
}
