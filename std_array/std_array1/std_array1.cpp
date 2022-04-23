#include <cstdio>
#include <iostream>
#include <array>

using namespace std;

void print_static(array<int, 5> arr);

template <size_t N>
void print(const array<int, N>& arr);

int main()
{
    array<int, 10> arr1;

    arr1[0] = 1;
    printf("arr1 배열의 첫 번째 원소: %d\n", arr1[0]);

    array<int, 4> arr2 = {1,2,3,4};
    printf("arr2 배열의 모든 원소: ");
    for(int i = 0; i < arr2.size(); i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");



    array<int, 4> arr3;
    try
    {
        printf("%d\n", arr3.at(3));    //에러 아님 
        printf("%d\n", arr3.at(4));
    }
    catch(const std::out_of_range& ex)
    {
        std::cerr << ex.what() << endl;
    }

    array<int, 5> arr_static = {1, 2, 3, 4, 5};
    print_static(arr_static);

    array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr);

    cout << arr.front() << endl;
    cout << arr.back() <<endl;
    cout << *(arr.data()+1) << endl;
}

void print_static(array<int, 5> arr)
{
    for(auto ele : arr)
        cout << ele << ", ";

    cout << endl;
}

template <size_t N>
void print(const array<int, N>& arr)
{
    for(auto it = arr.begin(); it != arr.end(); it++)
    {
        auto element = *it;
        cout << element << ' ';
    }   
    cout << endl;
}

