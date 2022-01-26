#include<stdio.h>
#include <list> 
#include <vector>

// 第1問(10点)
// 以下のクラスにコンストラクタ、デストラクタを追加してください。
// コンストラクタ、デストラクタの処理の内容はなんでも構いません

class Point
{
public:
    Point()
    {
        printf("Pointのコンストラクタ\n");
    }
    ~Point()
    {
        printf("Pointのデストラクタ\n");
    }
};
int main()
{
    Point point;

    printf("main関数のprintf\n");
    return 0;

}



// 第2問(10点)
// int型の変数をnewを使い確保してください。
// また、char型の配列をnewを使い確保してください。
// どちらもdeleteを呼び出すようにしてください。

int main()
{
    int* newInt = new int();
    char* newChar = new char();

    printf("newInt1 = %d\n", *newInt);
    printf("newchar = %d\n", *newChar);

    delete newChar;
    newChar = nullptr;
    delete newInt;
    newInt = nullptr;
}




// 第3問(15点)
// 以下の継承先クラスのデストラクタが正しく呼び出されるように、
// クラスを修正してください。

class Test
{
public:
    Test()
    {
        printf("Test\n");
    }
    virtual ~Test()
    {
        printf("~Test\n");
    }
};
class Test2 : public Test
{
public:
    Test2()
    {
        printf("Test2\n");
    }
    ~Test2()
    {
        printf("~Test2\n");
    }
};
int main()
{
    Test* t;
    t = new Test2();

    delete t;
    return 0;
}



// 第4問(25点)
// 以下の関数をテンプレート化して、
// 様々な型で計算できるようにしてください。

template <typename T>
float Calc(float a, float b, int type)
{
    float ans = 0;
    switch (type)
    {
    case 0:
        ans = a + b;
        break;
    case 1:
        ans = a - b;
        break;
    case 2:
        ans = a * b;
        break;
    case 3:
        ans = a / b;
        break;
    }

    return ans;
}

int main()
{
    int ans1;
    float ans2;
    char ans3;

    ans1 = Calc<int>(2, 5, 0);
    ans2 = Calc<float>(10.0f, 2.5f, 3);
    ans3 = Calc<char>(10, 4, 2);

    return 0;
}



// 第5問(25点)
// 次のプログラムを修正し、以下のような表示になるようにプログラムを作成してください。
// num = 50
// num = 40
// num = 30
// num = 20
// num = 10
// また、リストを修正してください。その際表示は以下のようになるようにしてください。
// num = 30

int main()
{
    std::list<int> lst;
    for (int i = 0; i <= 50; ++i)
    {
        if (i % 10)
        {
            lst.push_back(i);
        }
    }

    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

    for (int i = 0; i <= 30; ++i)
    {
        if (i == 30)
        {
            lst.push_back(i);
        }
        
    }


    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

}



// 第6問(25点)
// 第5問と同じ表示になるようにstd::vectorを使ってプログラムを記述してください。

int main()
{

    std::vector<int> vec;
    for (int i = 0; i <= 50; ++i)
    {
        if (i % 10)
        {
            vec.push_back(i);
        }
    }

    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

    for (int i = 0; i <= 30; ++i)
    {
        if (i == 30)
        {
            vec.push_back(i);
        }

    }


    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        printf("num = %d\n", *it);
    }

}
/*
*/