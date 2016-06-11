#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "node.h"

class Heap
{
public:
    Heap(const int * arr, std::size_t size);
    ~Heap();
public:
    std::size_t size() const;
    Node & operator[] (std::size_t index) const;
    void show() const;
    friend std::ostream & operator << (std::ostream & os, const Heap & heap);
private:
    void initialization(const int * arr, std::size_t size);
    void deleteMemory();
private:
    std::size_t m_size;
    Node * m_root;

};

#endif // HEAP_H
