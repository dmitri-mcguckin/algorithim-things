#include <iostream>
#include <string.h>
#include <fstream>
#include "array/array.h"
#include "edge/edge.h"
#include "utilities/utilities.h"

using namespace std;

int main(const int argc, const char** argv){
  int node_count = 0;
  char* nodes;
  Array edges;
  ifstream file;

  //
  // File read in
  //
  file.open("graphs/graph02");

  // Count the nodes and put them in a list
  file >> node_count;
  nodes = new char[node_count];
  for(int i = 0; i < node_count; ++i)
    file >> nodes[i];

  // Begin traversing down the rows
  for(int i = 0; i < node_count; ++i){
    char current_node, garbage;
    file >> current_node;

    // Begin traversin down the columns
    for(int j = 0; j < node_count; ++j){
      char value;
      file >> value;

      // cout << "Looking at value(" << i << "): " << value << endl;

      if(value != '-' && j > i)
        edges.append(Edge(current_node, nodes[j], value - 48));
    }
  }

  file.close();

  if(edges.sort())
    cout << "Here's a list of the edges from file (read as non-directional)" << endl;
  else
    cout << "There was an oopsie trying to sort the array! :(" << endl << "This is what I was ableto do so far: " << endl;

  cout << edges << endl;

  return 0;
}
