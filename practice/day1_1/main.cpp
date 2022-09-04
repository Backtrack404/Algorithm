#include <iostream>

/*
문제 

1. 1부터 N까지 M의 배수합

자연수 N이 입력되면 1부터 N까지의 수 중 M의 배수합을 출력하는 프로그램을 작성하세요.

▣ 입력설명
첫 줄에 자연수 N과 M이 차례대로 입력됩니다.(3<=M<N<=1000)

▣ 출력설명
첫 줄에 M의 배수합을 출력한다.

▣ 입력예제 1
15 3

▣ 출력예제 1
45
*/

using namespace std;

int main()
{
    int endNum = 0;
    int multiple = 0;
    int answer = 0;

    cin >> endNum; 
    cin >> multiple;

    for(int i = 1; i <= endNum; i++)
    {
        if (multiple * i <= endNum)
            answer +=  multiple * i; 
    }

    cout << answer << endl;

    return 0;
}