#include <iostream>
#include <cstdlib>
#include <ctime>
#include "heap.h"

template<class T> void display(T * arr, std::size_t size);
template<class T> void sorted(T * arr, std::size_t);
void swap(Node * one, Node * two);
void heapSort(Heap & heap);
void maxHeapify(Heap & heap, std::size_t index);
void maxHeapify(Heap & heap, std::size_t index, std::size_t size);
void bildMaxHeapify(Heap & heap);
void display(Heap & heap);
int main(void)
{
    srand(time(0));
    const std::size_t size = std::rand() % 1000;
    int * arr = new int [size];
    for(std::size_t i = 0; i < size; ++i)
        arr[i] = std::rand() % 1000 + 1;
//    display(arr, size);
//    sorted(arr, size);
//    display(arr, size);
    Heap heap(arr, size);
//    std::cout << "Heap input: " << std::endl << heap << std::endl;
//    bildMaxHeapify(heap);
//    std::cout << "Heap: " << std::endl << heap << std::endl;
    heap.show();
    heapSort(heap);
//    std::cout << "Result: " << std::endl << heap << std::endl;
    heap.show();
    delete [] arr;
    return 0;
}

template<class T> void display(T * arr, std::size_t size)
{
    std::cout << "Array: ";
    for(std::size_t i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<class T> void sorted(T * arr, std::size_t size)
{
    for(std::size_t i = 1; i < size; ++i)
        for(int j = i; arr[j - 1] > arr[j] && j > 0; --j)
            std::swap(arr[j - 1], arr[j]);
}

void heapSort(Heap & heap)
{
    bildMaxHeapify(heap);
    std::size_t size = heap.size();
    for(std::size_t i = size - 1; i >= 1; --i){
        Node * zero = &heap[0];
        Node * ptr = &heap[i];
        swap(zero, ptr);
        maxHeapify(heap, 0, i);
    }
}

void maxHeapify(Heap & heap, std::size_t index)
{
    Node * ptr = &heap[index];
    Node * left = ptr->left();
    Node * rigth = ptr->rigth();
    Node * largest = nullptr;
    if(left != nullptr && left->value() > ptr->value())
        largest = left;
    else
        largest = ptr;
    if(rigth != nullptr && rigth->value() > largest->value())
        largest = rigth;
    if(largest != ptr){
        swap(largest, ptr);
        maxHeapify(heap, largest->index());
    }
}

void maxHeapify(Heap & heap, std::size_t index, std::size_t size)
{
    Node * ptr = &heap[index];
    Node * left = ptr->left();
    Node * rigth = ptr->rigth();
    Node * largest = nullptr;
    if(left != nullptr && left->index() < size && left->value() > ptr->value())
        largest = left;
    else
        largest = ptr;
    if(rigth != nullptr && rigth->index() < size && rigth->value() > largest->value())
        largest = rigth;
    if(largest != ptr){
        swap(largest, ptr);
        maxHeapify(heap, largest->index(), size);
    }
}

void bildMaxHeapify(Heap & heap)
{
    int mid = heap.size() / 2;
    for(int i = mid; i >= 0; --i)
        maxHeapify(heap, i);
}

