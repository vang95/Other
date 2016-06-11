#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
public:
    Node(int value, std::size_t index);
public:
    int value() const;
    std::size_t index() const;
    Node * perent() const;
    Node * left() const;
    Node * rigth() const;
    Node * next() const;
    void setVaue(int value);
    void setIndex(std::size_t index);
    void setPerent(Node * node);
    void setLeft(Node * node);
    void setRigth(Node * node);
    void setNext(Node * node);
public:
    friend std::ostream & operator << (std::ostream & os, const Node & node);
    friend void swap(Node * one, Node * two);
private:
    int m_value;
    std::size_t m_index;
    Node * m_ptrPerent;
    Node * m_ptrLeft;
    Node * m_ptrRigth;
    Node * m_ptrNext;
};

#endif // NODE_H
