#include <iostream>
#include <string>

void fizzbuzz(int num);

int main()
{
    int num{150};
    fizzbuzz(num);
    return 0;
}

void fizzbuzz(int num)
{
    for (int i{1}; i <= num; ++i)
    {
        std::string out{};                  // 本轮的“词袋”，初始为空

        if (i % 3 == 0)
            out += "fizz";
        if (i % 5 == 0)
            out += "buzz";
        if (i % 7 == 0)
            out += "pop";
        if (out.empty())                    // 一个词都没装上，才打印数字
            out = std::to_string(i);

        std::cout << out << '\n';
    }
}
