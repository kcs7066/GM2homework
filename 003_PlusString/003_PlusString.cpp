#include <iostream>

int StringCount(const char* const _Str)
{
    int Count = 0;

    while (_Str[Count])
    {
        Count += 1;
    }

    return Count;
}

void PlusString(char* _Buffer, int _BufferSize, const char* const _Value0, const char* const _Value1)
{
    int StringCountA = StringCount(_Value0);
    int CountA = 0;
    int CountB = 0;
    while (_Value0[CountA])
    {
        _Buffer[CountA] = _Value0[CountA];
        CountA += 1;
    }
    while(_Value1[CountB])
    {
        _Buffer[StringCountA] = _Value1[CountB];
        CountB += 1;
        StringCountA += 1;
    }
}

int main()
{
    char Arr[100] = {};

    PlusString(Arr, 100, "AAAA", "BBBB");

    int a = 0;
}