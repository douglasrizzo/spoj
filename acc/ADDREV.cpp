#include <stdio.h>

int Reverse(int num_)
{
        int inv = 0;

        while (num_ > 0)
        {
                inv = inv * 10 + (num_%10);
                num_ /= 10;
        }

        return inv;
}

int main()
{
    int t,n,m;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &m, &n);
        printf("%d\n", Reverse(Reverse(m)+Reverse(n)));
    }
    return 0;
}
