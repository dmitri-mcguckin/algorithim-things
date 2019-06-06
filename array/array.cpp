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
  sort(data, 0, arr_size);

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

void Array::sort(const Edge*& array, const int i_lo, const int i_hi){
  int size = i_hi - i_lo;
  int mid = size / 2;

  if(size == 0)
    return;
  elif(size == 1){
    if(array[])
  }

  Edge* left = new Edge[mid - i_lo];
  Edge* right = new Edge[i_hi - mid + 1]

  sort(left, i_lo, mid);
  sort(right, mid + 1, i_hi);

  
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
