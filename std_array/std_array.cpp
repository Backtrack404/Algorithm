#include <cstdio>
#include <stdio.h>
#include <array>

using namespace std;
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
}