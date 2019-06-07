#include "edge.h"

//
// Edge implementation
//
Edge::Edge() : vertex_1('~'), vertex_2('~'), weight(-1){}

Edge::Edge(const char vertex_1, const char vertex_2, const int weight) : vertex_1(toupper(vertex_1)), vertex_2(toupper(vertex_2)), weight(weight) {}

Edge::Edge(const Edge& src) : vertex_1(src.vertex_1), vertex_2(src.vertex_2), weight(src.weight){}

Edge::~Edge() {}

const bool Edge::operator <  (const Edge& src){ return (this->weight <  src.weight); }
const bool Edge::operator <= (const Edge& src){ return (this->weight <= src.weight); }
const bool Edge::operator >  (const Edge& src){ return (this->weight >  src.weight); }
const bool Edge::operator >= (const Edge& src){ return (this->weight >= src.weight); }
const bool Edge::operator == (const Edge& src){ return (this->weight == src.weight); }
const bool Edge::operator != (const Edge& src){ return (this->weight != src.weight); }

ostream& operator << (ostream& buffer, const Edge& src){
  buffer << "{ " << src.vertex_1 << ", " << src.vertex_2 << ", " << src.weight << " }";
  return buffer;
}

char Edge::get_start() { return vertex_1; }
char Edge::get_end() { return vertex_1; }

