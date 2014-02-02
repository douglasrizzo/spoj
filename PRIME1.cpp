#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    unsigned int m, n;

    //captura iterações
    scanf("%d", &t);
    while(t--)
    {
        //captura intervalo de numeros
        scanf("%lld %lld", &m, &n);

        int interval = n - m,
            raiz = static_cast<int>(sqrt(n));
        //vamos pegar os primos de 0 à raiz de n

        bool arr[raiz];
        arr[0] = arr[1] = false;

        for(int i = 2; i <= raiz; i++)
            arr[i] = true;

        for(int i = 2; i <= raiz;)
        {
            //marca todos os múltiplos
            for(int j = i; (j * i) <= n; j++)
                arr[j * i] = false;

            //encontra o próximo primo
            for(int k = i + 1; ; k++)
            {
                if(k == n)
                    goto printers;
                if(arr[k])
                {
                    i = k;
                    break;
                }
            }
        }

printers:
        for(int i = 0; i <= sqrt(n); i++)
            if(arr[i])
                printf("%d\n", i);

        return 0;
    }
}
