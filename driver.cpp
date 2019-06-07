#include <iostream>
#include <string.h>
#include <fstream>
#include "array/array.h"
#include "edge/edge.h"
#include "utilities/utilities.h"

using namespace std;

void print_array(const int array[], const int size){
  cout << "[ ";
  for(int i = 0; i < size; ++i)
    cout << array[i] << " ";
  cout << "]" << endl;
}

void merge_sort(int* array, int left, int right){
  int size = right - left;
  int mid = size / 2;

  if(size <= 1)
    return;

  int a_left[mid];
  for(int i = 0; i < mid; ++i)
    a_left[i] = array[i + left];

  int a_right[mid];
  for(int i = 0; i < mid; ++i)
    a_right[i] = array[i + mid];

  merge_sort(a_left, left, mid);
  merge_sort(a_right, mid, right - 1);

  int i = 0, j = 0, k = 0;
  int temp[size];

  while(i < mid && j < mid){
    if(a_left[i] < a_right[j]){
      temp[k] = a_left[i];
      ++i;
    }
    else{
      temp[k] = a_right[j];
      ++j;
    }

    ++k;
  }

  while(i < mid){
    temp[k] = a_left[i];
    ++i;
    ++k;
  }

  while(j < mid){
    temp[k] = a_right[j];
    ++j;
    ++k;
  }

  for(int a = 0; a < size; ++a)
    array[a] = temp[a];

  cout << "Temp: ";
  print_array(temp, size);
}

int main(const int argc, const char** argv){
  int x[8] = { 60, 70, 50, 20, 12, 10, 73, 71 };
  int y[4] = { 5, 3, 6, 9 };

  cout << "Unsorted: ";
  print_array(y, 4);

  merge_sort(y, 0, 4);

  cout << "Sorted: ";
  print_array(y, 4);

  // int node_count = 0;
  // char* nodes;
  // Array edges;
  // ifstream file;
  //
  // //
  // // File read in
  // //
  // file.open("graphs/graph02");
  //
  // // Count the nodes and put them in a list
  // file >> node_count;
  // nodes = new char[node_count];
  // for(int i = 0; i < node_count; ++i)
  //   file >> nodes[i];
  //
  // // Begin traversing down the rows
  // for(int i = 0; i < node_count; ++i){
  //   char current_node, garbage;
  //   file >> current_node;
  //
  //   // Begin traversin down the columns
  //   for(int j = 0; j < node_count; ++j){
  //     char value;
  //     file >> value;
  //
  //     // cout << "Looking at value(" << i << "): " << value << endl;
  //
  //     if(value != '-' && j > i)
  //       edges.append(Edge(current_node, nodes[j], value - 48));
  //   }
  // }
  //
  // file.close();
  //
  // if(edges.sort())
  //   cout << "Here's a list of the edges from file (read as non-directional)" << endl;
  // else
  //   cout << "There was an oopsie trying to sort the array! :(" << endl << "This is what I was able to do so far: " << endl;
  //
  // cout << edges << endl;

  return 0;
}
