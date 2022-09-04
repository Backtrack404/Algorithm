/*
2. 자연수의 합
자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요.

▣ 입력설명
첫 줄에 자연수 A, B가 공백을 사이에 두고 차례대로 입력된다. (1<=A<B<=100)

▣ 출력설명
첫 줄에 더하는 수식과 함께 합을 출력합니다.

▣ 입력예제 1
3 7

▣ 출력예제 1
3 +4 +5 +6 +7 = 25
*/


#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int answer = 0;

    cin >> a;
    cin >> b;

    for(a; a < b; a++)
    {
        answer +=  a;    
        cout << a << " + ";
    }
    
    answer += a;
    cout << b << " = " << answer;

    return 0;
}