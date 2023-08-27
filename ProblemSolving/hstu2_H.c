#include <cstdio>
#include <algorithm>

using namespace std;

struct card
{
    int a;
    int b;
};

bool cmp(const card& left, const card& right)
{
    return (left.b > right.b)
        || (left.b == right.b && left.a > right.a);
}

int main()
{
    int n;
    int num[100][4] = {0};
    scanf("%d", &n);

    card c[1000];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &c[i].a, &c[i].b);
    }

    sort(c, c + n, cmp);
    int points(c[0].a), cards(c[0].b);
    for (int i = 1; i < n && i <= cards; ++i)
    {
        points += c[i].a;
        cards += c[i].b;
    }

    printf("%d\n", points);
    return 0;
}
