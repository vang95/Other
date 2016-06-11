#include "node.h"

Node::Node(int value, std::size_t index)
    : m_value(value), m_index(index), m_ptrLeft(nullptr), m_ptrRigth(nullptr), m_ptrPerent(nullptr), m_ptrNext(nullptr)
{ }

int Node::value() const
{
    return m_value;
}

std::size_t Node::index() const
{
    return m_index;
}

Node * Node::perent() const
{
    return m_ptrPerent;
}

Node * Node::left() const
{
    return m_ptrLeft;
}

Node * Node::rigth() const
{
    return m_ptrRigth;
}

Node * Node::next() const
{
    return m_ptrNext;
}

void Node::setPerent(Node * node)
{

    m_ptrPerent = node;
}

void Node::setLeft(Node * node)
{
    m_ptrLeft = node;
}

void Node::setRigth(Node * node)
{
    m_ptrRigth = node;
}

void Node::setNext(Node * node)
{
    m_ptrNext = node;
}

void Node::setIndex(std::size_t index)
{
    m_index = index;
}

void Node::setVaue(int value)
{
    m_value = value;
}

std::ostream & operator << (std::ostream & os, const Node & node)
{
    os << node.value();
    return os;
}

void swap(Node * one, Node * two)
{
    int temp = one->value();
    one->setVaue(two->value());
    two->setVaue(temp);
}
