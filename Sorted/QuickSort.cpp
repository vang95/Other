#include <iostream>

template<class T> void display(T * arr, std::size_t begin, std::size_t size);
template<class T> void quickSort(T * arr, int p, int r);
template<class T> int partition(T * arr, int p, int r);

int main(void)
{
    const std::size_t size = 11;
    int arr[size] = { -2, 5, -11, 8, 7, 1, 3, 5, 6, 4, -100};
    display(arr, 0, size);
    quickSort(arr, 0, size);
    display(arr, 0, size);
    return 0;

}

template<class T>
void display(T * arr, std::size_t begin, std::size_t size)
{
    if(size == 0){
        std::cout << "array if null" << std::endl;
        return;
    }
    for(std::size_t i = begin; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template<class T>
void quickSort(T * arr, int p, int r)
{
    if(p >= r - 1)
        return;
    int q = partition(arr, p, r);
    quickSort(arr, p, q);
    quickSort(arr, q + 1, r);
}

template<class T>
int partition(T * arr, int p, int r)
{
    T x = arr[r - 1];
    int i = p - 1;
    for(int j = p; j < r - 1; ++j){
        if(arr[j] <= x)
            std::swap(arr[j], arr[++i]);
    }
    std::swap(arr[++i], arr[r - 1]);
    return i;
}
