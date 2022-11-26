#include"vector.h"

coordinate sumVector(coordinate vector_a, coordinate vector_b)
{
    return (coordinate) {vector_a.x+vector_b.x,vector_a.y+vector_b.y};
}