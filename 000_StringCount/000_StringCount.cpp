#include <iostream>
#include <stdlib.h>

// 지금만들라고 하는 함수들은
// strlen

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        Count += 1;
    }

    return Count;
}

int main()
{
    // [B][B][B][B][0]

    int Count = StringCount("BBBB");
    int a = 0;
}
