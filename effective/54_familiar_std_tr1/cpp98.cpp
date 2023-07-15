// g++ cpp98.cpp -o cpp98 && ./cpp98

#include <iostream>
#include <cassert>

using namespace std;

// function object
struct add_x
{
    add_x(int x) : x(x) {}
    int operator()(int y) const { return x + y; }

private:
    int x;
};

// std stack example
#include <stack>
#include <vector>

// priority queue example
#include <queue>

//  mem fun example
#include <functional>

struct Foo
{
    int print_sum(int n1, int n2)
    {
        return n1 + n2;
    }
    int data = 10;
};

// not1 example
#include <functional>
#include <algorithm>

bool IsOdd(int i)
{
    return ((i % 2) == 1);
}

int main()
{
    {
        // function object
        add_x add42(42);  // create an instance of the function object
        int i = add42(8); // and "call" it
        assert(i == 50);
    }

    {
        // std stack example
        stack<int> s;
        s.push(1);
        s.push(2);
        s.push(3);

        vector<int> expected{1, 2, 3};

        while (!s.empty())
        {
            assert(s.top() == expected.back());
            s.pop();
            expected.pop_back();
        }
    }

    {
        // priority queue example
        priority_queue<int> q;
        q.push(3);
        q.push(1);
        q.push(2);

        vector<int> expected{3, 2, 1};

        while (!q.empty())
        {
            assert(q.top() == expected.front());
            q.pop();
            expected.erase(expected.begin());
        }
    }

    {
        // mem fun example
        Foo foo;
        auto f = std::mem_fn(&Foo::print_sum);
        assert(f(foo, 1, 2) == 3);
    }

    {
        // not1 example
        int numbers[] = {10, 20, 30, 40, 50, 60, 70};
        int cx;

        cx = count_if(numbers, numbers + 7, not1(bind2nd(less<int>(), 40)));
        assert(cx == 4);
    }
}
