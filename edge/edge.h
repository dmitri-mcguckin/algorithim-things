#ifndef S_EDGE
#define S_EDGE

#include <iostream>

using namespace std;

class Edge{
  private:
    char vertex_1;
    char vertex_2;
    int weight;

  public:
    // Constructors / destructors
    Edge();
    Edge(const char, const char, const int);
    Edge(const Edge&);
    ~Edge();

    // Member function stuff
    const bool operator <  (const Edge&);
    const bool operator <= (const Edge&);
    const bool operator >  (const Edge&);
    const bool operator >= (const Edge&);
    const bool operator == (const Edge&);
    const bool operator != (const Edge&);

    friend ostream& operator << (ostream&, const Edge&);
};

#endif
