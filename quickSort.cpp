#include <iostream>

using namespace std;

///Quick Sort
//array must be of a numeric type for this to work (or needs to have all the methods and operators defined for the code bellow)
//left is begining of arr and right is end of arr
template<typename T>
T partition(T arr[], int left, int right)
{
    T pivot = arr[right];
    int index = left - 1;
    //index is index of smaller elements

    for(int j = left; j <= right - 1; j++)
    {
        if(arr[j] <= pivot)
        //if element is smaller or equal to pivot increment index and  
        {
            index++;
            swap(arr[index],arr[j]);
        }
    }

    swap(arr[index+1], arr[right]);
    return index + 1;
}

template<typename T>
void quickSort(T arr[], int left, int right)
{
    if(left >= right)
     return;

    T partitionIndex = partition(arr, left, right);

    quickSort(arr, left, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, right);

}


int main()
{
    int arr[] = {5,4,2,6,7,10,23,21,11,9};
    quickSort(arr,0,10);

    for(int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
