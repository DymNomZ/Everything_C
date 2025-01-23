#include <cstdlib>
#include <iostream>
#include <string.h>
#include <queue>
#include "graph.h"
#include "vertex.h"
using namespace std;

class GraphList : public Graph {

    Vertex vlist[10];
    char s_vertices[10];
    int num_vert;
    int s_edges[100];
    int num_edge;
    bool visited[10] = {false};

    public:
    GraphList() {
        num_vert = 0;
        num_edge = 0;
    }

    int numVertices() {
        return num_vert;
    }

    char* vertices() {
        return s_vertices;
    }

    int numEdges() {
        return num_edge;
    }

    int* edges() {
        return s_edges;
    }

    int getIdx(char x){
        for(int i = 0; i < num_vert; i++){
            if(s_vertices[i] == x) return i;
        }
        return -1;
    }

    int getEdge(Vertex* u, Vertex* v)  {

        for(int i = 0; i < u->size; i++){
            for(int j = 0; j < v->size; j++){
                if(u->edges[i] == v->edges[j]){
                    return u->edges[i];
                }
            }
        }
        
        return 0;
    }
    
    bool findEdge(int e){
        for(int i = 0; i < num_edge; i++){
            if(e == s_edges[i]) return true;
        }
        return false;
    }

    char* endVertices(int e)  {
        
        char ev[2] = {'-', '-'};
        
        if(findEdge(e)){

            int last = 0;
            //find first vertext
            for(int i = 0; i < num_vert; i++){
                //loop edge array of each vertex
                for(int j = 0; j < vlist[i].size; j++){
                    if(vlist[i].edges[j] == e){
                        ev[0] = vlist[i].elem;
                        last = i+1;
                        break;
                    }
                }
            }

            //find second vertext
            for(int i = last; i < num_vert; i++){
                //loop edge array of each vertex
                for(int j = 0; j < vlist[i].size; j++){
                    if(vlist[i].edges[j] == e){
                        ev[1] = vlist[i].elem;
                        break;
                    }
                }
            }

        }
        return ev;
    }

    char opposite(char v, int e)  {
    
        char* ev = endVertices(e);
        
        if(ev[0] == v) return ev[1];
        else if(ev[1] == v) return ev[0];
        else return '-';
    }

    int outDegree(char v)  {
        
        int vi = getV(v);
        if(vi == -1) return 0;
        
        int sum = 0;
        for(int i = 0; i < num_vert; i++){
            if(matrix[vi][i] != 0) sum++;
        }
        return sum;
    }

    int inDegree(char v)  {
        int vi = getV(v);
        if(vi == -1) return 0;
        
        int sum = 0;
        for(int i = 0; i < num_vert; i++){
            if(matrix[i][vi] != 0) sum++;
        }
        return sum;
    }

    int* outgoingEdges(char v) {
        
        int vi = getV(v);
        if(vi == -1) return NULL;
        
        int curr = 0;
        int* es = (int*)calloc(0, outDegree(v) * 4); 
        
        for(int i = 0; i < num_vert; i++){
            if(matrix[vi][i] != 0){
                es[curr++] = matrix[vi][i];
            }
        }
        return es;
    }

    int* incomingEdges(char v) {
        
        int vi = getV(v);
        if(vi == -1) return NULL;
        
        int curr = 0;
        int* es = (int*)calloc(0, outDegree(v) * 4); 
        
        for(int i = 0; i < num_vert; i++){
            if(matrix[i][vi] != 0){
                es[curr++] = matrix[i][vi];
            }
        }
        return es;
    }

    bool insertVertex(char x)  {
        if(num_vert >= 10) return false;
        else{
            s_vertices[num_vert++] = x;
            return false;
        }
    }

    bool insertEdge(char u, char v, int x)  {
        //get idx of u and v from s_vertices
        int ui = getIdx(u);
        int vi = getIdx(v);
        
        //if either idx does not exist
        if(ui == -1 || vi == -1) return false;
        
        //update matrix at the idx to store x
        if(matrix[ui][vi] == 0){
            matrix[ui][vi] = x;
            
            //add x in s_edges
            s_edges[num_edge] = x;
            
            //update num_edge
            num_edge++;
            return true;
        }
        else{
            cout << "Not Null" << endl;
            return false;
        }
        
    }

    int removeVertex(char v) {
    
        int d = getIdx(v);
        if(d == -1) return 0;
        
        int sum = 0;
        sum += inDegree(v);
        sum += outDegree(v);
        num_edge -= sum;
        
        for(int i = d; i < num_vert-1; i++){
            s_vertices[i] = s_vertices[i+1];
        }
        
        int i;
        
        while(d < num_vert){
            
            for(i = 0; i < num_vert; ++i){
                matrix[i][d] = matrix[i][d + 1];
            }
            
            for(i = 0; i < num_vert; ++i){
                matrix[d][i] = matrix[d + 1][i];
            }
            d++;
        }
        
        num_vert--;
        return sum;
    }

    bool removeEdge(int e)  {
    
        if(findEdge(e)){
            
            for(int i = 0; i < num_vert; i++){
                for(int j = 0; j < num_vert; j++){
                    if(matrix[i][j] == e){
                        matrix[i][j] = 0;
                    }
                }
            }
            num_edge--;
            return true;
        }
        else return false;
    }

    void resetVisited(){
        for(int i = 0; i < 10; i ++) visited[i] = false;
    }

    void dfs(int i){
        //assign true cause its now visited
        visited[i] = true;

        //get vertex and print
        cout << s_vertices[i] << " ";

        //check respective row
        for(int j = 0; j < num_vert; j++){
            if(matrix[i][j] != 0 && (!visited[j])){
                dfs(j);
            }
        }
    }

    void DFS(){
        //reset visited array
        resetVisited();

        //start with first vertex
        for(int i = 0; i < num_vert; i++){
            if(!visited[i]){
                dfs(i); // nice naming LOL
            }
        }

        cout << endl;
    }

    void BFS(){
        //reset visited array
        resetVisited();

        //we push their indexes
        queue<int> q;

        //start with first vertex
        q.push(0);
        //assign true cause its now visited
        visited[0] = true;

        while(!q.empty()){

            int i = q.front();
            //get vertex and print
            cout << s_vertices[i] << " ";

            q.pop();

            //check respective row
            for(int j = 0; j < num_vert; j++){
                if(matrix[i][j] != 0 && (!visited[j])){
                    visited[j] = true;
                    q.push(j);
                }
            }

        }

        cout << endl;
    }
    
    void print() {
        cout << "\t";
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
        }
        cout << endl;
        for (int i = 0; i < num_vert; i++) {
            cout << s_vertices[i] << "\t";
            for (int j = 0; j < num_vert; j++) {
                if (matrix[i][j] != 0) {
                    cout << matrix[i][j];
                }
                cout << "\t";
            }
            cout << endl;
        }
    }
};