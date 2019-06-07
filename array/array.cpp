#include "array.h"

//
// Array implementation
//
Array::Array() : arr_size(0), data(NULL){}

Array::Array(const Array& src) : arr_size(src.arr_size){
  data = new Edge[arr_size];

  for(int i = 0; i < arr_size; ++i)
    data[i] = src.data[i];
}

Array::~Array(){
  if(data)
    delete [] data;
}

const int Array::size(){
  return arr_size;
}

const bool Array::append(const Edge number){
  ++arr_size;
  Edge temp[arr_size];

  for(int i = 0; i < arr_size - 1; ++i)
    temp[i] = data[i];

  if(data)
    delete [] data;
  data = new Edge[arr_size];

  for(int i = 0; i < arr_size - 1; ++i)
    data[i] = temp[i];

  data[arr_size - 1] = number;

  return false;
}

const bool Array::remove(const Edge number){
  int j = 0;
  Edge temp[arr_size];

  for(int i = 0; i < arr_size; ++i){
    if(data[i] != number){
      temp[j] = data[i];
      ++j;
    }
  }

  if(data)
    delete [] data;
  data = new Edge[j];

  for(int i = 0; i < j; ++i)
    data[i] = temp[i];

  arr_size = j;

  return false;
}

const bool Array::sort(){
  sort();

  // Post sort verification
  bool is_sorted = true;
  Edge last = data[0];
  for(int i = 0; i < arr_size; ++i){
    if(last > data[i]){
      is_sorted = false;
      break;
    }
  }

  return is_sorted;
}

void Array::sort(Edge* array, const int i_lo, const int i_hi){

}

const Edge Array::operator [] (const int index){
  Edge temp;
  if(index >= 0 && index < arr_size)
    temp = data[index];
  return temp;
}

ostream& operator << (ostream& buffer, const Array& src){
  if(src.data)
    for(int i = 0; i < src.arr_size; ++i){
      if(i == 0)
        buffer << " [ ";
      else
        buffer << "   ";

      buffer << src.data[i];

      if(i == src.arr_size - 1)
        buffer << " ]" << endl;
      else
        cout << endl;
    }

  return buffer;
}

bool Array::build_tree(const int vertices) {
  // Sort if we haven't already
  sort();
  Array tree;

  // Arranged in alphabetical order
  int trees[vertices];
  // Initialize tree number to 0
  for (int i = 0; i < vertices; i++)
    trees[i] = 0;
  int highest_tree = 1;
  bool done = false;
  // Add vertices to tree, avoiding cycles
  for (int i = 0; i < arr_size && !done; i++) {
    int start_tree = trees[data[i].get_start()];
    int end_tree = trees[data[i].get_end()];
    // Not a cycle. Add to list.
    if (start_tree != end_tree) {
      if (start_tree != 0 || end_tree != 0) {
        if ( start_tree < end_tree)
          trees[data[i].get_end()] = start_tree;
        else
          trees[data[i].get_start()] = end_tree;
      }
      else {
        // Both not currently connected to a tree
        // So make a new tree
        end_tree = highest_tree;
        start_tree = highest_tree;
        highest_tree++;
      }
    }
    for (int n=0; n < vertices-1; n++) {
      if (trees[n] == 0 || trees[n] != trees[n+1])
        break;
      else
        done = true;
    }
  }
  cout << tree << endl;
  return true;
}
