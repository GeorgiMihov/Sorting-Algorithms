#include <iostream>

using namespace std;

///Heap Sort
//array must be of a numeric type for this to work (or needs to have all the methods and operators defined for the code bellow)
template<typename T>
void buildHeap(T arr[], int size, int index)
{
    int largest = index; //in the begining largest = root (root = index)
    int left = 2*index + 1; //left child index
    int right = 2*index + 2; //right child index

    //check if left child is bigger than root
    if(left < size && arr[left] > arr[largest])
        largest = left;

    //check if right child is bigger than the largest so far
    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != index)
    {
        //move bigger element to root of heap
        swap(arr[index], arr[largest]);

        buildHeap(arr, size, largest);
    }

}

template<typename T>
void heapSort(T arr[], int size)
{
    for(int i = size / 2 - 1; i >= 0; i--)
    {
        buildHeap(arr,size,i);
    }

    for(int i = size - 1; i >= 0; i--)
    {
        swap(arr[0],arr[i]);

        buildHeap(arr, i, 0);
    }

}



int main()
{
    int arr[] = {5,4,2,6,7,12,1,10,15,11};
    heapSort(arr,10);


    for(int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}



