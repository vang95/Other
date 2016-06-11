#include "heap.h"

Heap::Heap(const int * arr, std::size_t size)
    : m_size(size)
{
    initialization(arr, size);
}

Heap::~Heap()
{
    deleteMemory();
}

void Heap::initialization(const int * arr, std::size_t size)
{
    if(size < 1){
        std::cout << "Error, size < 1" << std::endl;
        return;
    }
    //Предворительна инициализация и связывание в список
    Node * node = new Node(arr[0], 0);
    m_root = node;
    for(std::size_t i = 1; i < size; ++i){
        Node * temp = node;
        node = new Node(arr[i], i);
        temp->setNext(node);
    }
    //Заполнение списка в пирамиду
    Node * ptr = m_root;
    for(std::size_t i = 1; i <= m_size; ++i)
    {
        if(i != 1)
            ptr->setPerent(&Heap::operator[] (i / 2 - 1));
        if(i * 2 <= m_size)
            ptr->setLeft(&Heap::operator[] (i * 2 - 1));
        if(i * 2 + 1 <= m_size)
            ptr->setRigth(&Heap::operator[] (i * 2));
        ptr = ptr->next();
    }
}

void Heap::deleteMemory()
{
    Node * ptr;
    for(ptr = m_root; ptr != nullptr; ptr = ptr->next())
        delete ptr;
}

std::size_t Heap::size() const
{
    return m_size;
}

void Heap::show() const
{
    Node * ptr;
    for(ptr = m_root; ptr != nullptr; ptr = ptr->next())
        std::cout << ptr->value() << " -> ";
    std::cout << std::endl;
}

std::ostream & operator << (std::ostream & os, const Heap & heap)
{
    if(heap.size() == 0){
        os << "Heap null!";
        return os;
    }
    Node * ptr;
    for(ptr = heap.m_root; ptr->left() != nullptr || ptr->rigth() != nullptr; ){
            os << "  ( " << ptr->value() << " )" << std::endl;
        if(ptr->left() != nullptr)
            os << ptr->left()->value() << "[" << ptr->value() << "] ";
        if(ptr->rigth() != nullptr)
            os << ptr->rigth()->value() << "[" << ptr->value() << "] ";
        ptr = ptr->next();
        os << std::endl;
    }
    return os;
}

Node & Heap::operator [] (std::size_t index) const
{
    if(index >= m_size){
        std::cout << "Node not find" << std::endl;
        return * m_root;
    }
    Node * ptr = m_root;
    for(std::size_t i = 0; i < m_size; ++i){
        if(index == i)
            return * ptr;
        ptr = ptr->next();
    }
}
