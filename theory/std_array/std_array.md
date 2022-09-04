# 알고리즘

## 1. 연속된 자료구조와 연결된 자료구조

&nbsp;

> 1.연속된 자료구조  

data[0]     data[1]     data[2]     data[3]

| `data[0]` | `data[1]` | `data[2]` | `data[3]` |
|:---------:|:---------:|:---------:|:---------:|
|   BA    | BA + sizeof(type) | BA + 2 * sizeof(type) | BA + 3 * sizeof(type)|

- i 번째 요소에 접근하기 의해서는 BA + i * sizeof(type)

- 위와 같은 자료구조에서는 배열의 전체 크기와 상관없이 수식을 이용하여 모든 원소에 곧바로 접근할 수 있으므로 O(1)

&nbsp;

> 2.정적 배열과 동적배열

- 연산 성능 동일
- C스타일 배열이라고도 함
- 정적배열은 아래 형태로 선언

``` C
int arr[size]; 
```

- C에서 동적 배열은 아래 형태로 선언

``` C
int* arr = (int*)malloc(size * sizeof(int));
```

- 정적 배열은 stack에 동적 배열은 heap에 저장

- 배열같은 연속된 자료구조에서 각 원소를 서로 인접해 있기 때문에 하나의 원소에 접근할 때 그 옆에 있는 원소 몇개도 함께 캐시로 가져옴

- 이러한 속성을 캐시의 지역성 이라고 함

&nbsp;

> 3.연결된 자료구조

|`data`|next| -> |`data`|next| -> |`data`|next| -> |`data`|
NULL|

- 위와 같은 구조를 연결 리스트(linkd list) 라고 함

- 기본 구조에서 각각의 노드는 저장할 data와 다음 노드를 가리키는 포인터(next)를 가지고 있음

- 맨 마지막 노드는 자료구조의 끝을 나타내는 NULL을 가짐 

- linked list 에서 특정 원소에 접근하려면 리스트의 시작부분 부터 시작하여 원하는 원소에 도달할 때 까지 next 포인터를 따라 이동해야 하므로 원소 접근 시간은 노드 개수에 비례. 따라서 O(n)

- 배열과 달리 linked list는 포인터를 이용하여 원소의 삽입 또는 삭제를 매우 빠르게 수행할 수 있음

&nbsp;

> std::array

- std::array는 메모리를 자동으로 할당하고 해제

- 원소의 타입과 배열 크기를 매개변수로 하는 클래스

``` C++
std::array<int, 10> arr1; // 크기가 10인 int타입 배열 선언
arr1[0] = 1;    // 첫번째 원소를 1로 설정
```

ex)

``` C++
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
```

- std:array는 C스타일 배열과 똑같은 방식으로 배열 원소에 접근할 수 있는 [] 연산자를 제공

- std::array는 at(index)형식의 함수도 함께 제공하며, 이 함수는 인자로 전달된 index 값이 유효하지 않으면 std::out_of_range 예외 를 발생

- at() 함수가 [] 연산자보다 조금 느린 편 이지만, at() 함수를 잘 이용하면 예외를 적절하게 처리할 수 있음

ex)

``` C++
array<int, 4> arr3;

try
{
    printf("%d\n", arr3.at(3));    //에러 아님 
    printf("%d\ns", arr3.at(4));   // std::out_of_range 예외 발생
}
catch(const std::out_of_range& ex)
{
    std::cerr << ex.what() << endl;
}
```

- std::array 객체를 다른 함수에 전달하는 방식은 기본 데이터 타입을 전달하는 것과 유사

- 값 또는 참조로 전달할 수 있고, const를 함께 사용 가능

ex) 정의 함수 print()에 std::array 배열을 값으로 전달하는 예제

``` C++
void print(array<int, 5> arr)
{
    for(auto ele : arr)
        cout << ele << ", ";
}

array<int, 5> arr = {1, 2, 3, 4, 5};
print(arr);
```

- 위 예제에세는 print()함수의 매개변수 데이터 타입에 전달받을 배열 크기가 고정되어 있기 때문에 다른 크기의 배열을 전달할 수 없음

- 예를 들어 std::array<int, 10>을 전달하면 컴파일러는 함수 매개변수와 일치하지 않는다거나 또는 해당 매개변수 형식으로 변환할 수 없다는 에러 메시지를 출력

- 만약 다양한 크기의 std::array 객체에 대해 동작하는 범용적인 배열 출력 함수를 만들고 싶다면 print()를 함수 템플릿으로 선언하고, 배열 크기를 템플릿 매개변수로 전달하면 가능

ex)

``` C++
template <size_t N>
void print(const array<int, N>& arr)
{
    for(auto ele : arr)
        cout << ele << " ";
    
    cout << endl;
}

array<int, 5> arr = {1, 2, 3, 4, 5};
print(arr);
```

&nbsp;

- 배열의 모든 원소를 차례로 출력하기 위해 인덱스 값을 사용하는 for 반복문을 사용할 수도 있지만, 이 경우 배열의 크기를 정확하게 지정해야 하고 만약 인덱스 값이 배열 크기보다 같거나 커지면 에러 발생

- 범위 기반 for 반복문을 사용하여 std::array의 모든 원소에 접근할 수 있는 것은 반복자를 사용하기 때문. std::array는 begin()과 end()라는 이름의 멤버 함수를 제공하며 이들 함수는 가장 첫 번째 원소와 가장 마지막 원소의 위치(정확하게는 마지막 원소 다음 위치)를 반환

- 특정 원소 위치에서 다음 원소 위치로 이동하려면 반복자에 증가 연산자(++) 또는 덧셈 연산자(+) 같은 산술 연산을 수행할 수 있음

- 즉 범위 기반 for 반복문은 begin() 위치부터 시작하여 증가 연산자(++)를 통해 차례대로 원소를 이동하다 end() 위치에 도달하면 종료

- 반복자는 std::array, std::vector, std::map, std::set, std::list 처럼 반복 가능한 모든 STL 컨테이너에 대해 사용할 수 있음

- 컨테이너 내부의 위치를 나타내는 데 필요한 모든 기능에 대해서도 반복자가 사용. 예를 들어 특정 위치에 원소를 삽입하거나, 특정 위치 또는 범위에 있는 원소를 삭제하는 등의 작업에서도 반복자가 사용

- array::begin() 함수는 첫 번째 원소를 가리키는 반복자를 반환하고, array:end() 함수는 마지막 원소 다음을 가리키는 반복자를 반환.

ex)

``` C++
template <size_t N>
void print(const array<int, N>& arr)
{
    for(auto it = arr.begin(); it != arr.end(); it++)
    {
        auto element = *it;
        cout << element << ' ';
    }   
}

array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
print(arr);
```

- const_iterator 또는 reverse_iterator 같은 형태의 반복자도 사용할 수 있음

- const_iterator 반복자는 일반 반복자의 const 버전. const로 선언된 배열에 대해 begin() 또는 end() 같은 함수를 사용하면 const_iterator를 반환

- reverse_iterator를 사용하면 배열을 역방향으로 이동할 수 있음. 이 반복자를 ++같은 증가 연산자와 함께 사용할 경우, 일반 반복자와 반대 방향으로 이동 

&nbsp;

[] 연산자와 at()함수 외에 std::array에서 원소 접근을 위헤 사용할 수 있는 멤버 함수 표

| 함수 | 설명 |
|:---:|:---:|
| front() | 배열의 첫 번째 원소에 대한 참조를 반환 |
| back()  | 배열의 마지막 원소에 대한 참조를 반환  |
| data()  | 배열 객체 내부에서 실제 데이터 메모리 버퍼를 가리키는 포인터를  반환</br>반환된 포인터를 이용하여 다양한 포인터 연산을 수행할 수 있음</br>이 기능은 포인터를 함수의 인자로 받는 예전 스타일의 함수를 사용할 떄 유용|

ex)

``` C++
array<int, 10> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

cout << arr.front() << endl;    // 1 출력
cout << arr.back() <<endl;      // 10 출력
cout << *(arr.data() + 1) << endl;    // 2 출력
cout << *(arr.data() + 2) << endl;    // 3 출력
```

