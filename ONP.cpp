#include <stdio.h>
#include <stack>
#include <queue>
#include <iostream>

//en.wikipedia.org/wiki/Shunting-yard_algorithm

bool isOperator(char c)
{
    std::string ops="+-*/^";
    for(unsigned i = 0; i<ops.length(); i++)
        if(c==ops[i]) return true;

    return false;
}

bool isLetter(char c)
{
    std::string numbers="abcdefghijklmnopqrstuvwxyz";
    for(unsigned i = 0; i<numbers.length(); i++)
        if(c==numbers[i]) return true;

    return false;
}

bool hasPrecedenceOver(char c1, char c2)
{
    if(c2=='^') return false;
    if(c1=='^') return true;
    if(c2=='/'||c2=='*') return false;
    if(c1=='/'||c1=='*') return true;
    return false;
}

int main()
{
    int t;
    std::string m;
    std::stack<char> ops;
    std::queue<char> out;

//SHUNTING YARD ALGORITHM

    scanf("%d", &t);
    while(t--)
    {
        std::cin>>m; // read a line from cin into line

        for(unsigned i=0; i<m.length(); i++)
        {
            if(isLetter(m.at(i)))
                out.push(m.at(i));

            else if(isOperator(m.at(i)))
            {
                while(!ops.empty()&&isOperator(ops.top())&&hasPrecedenceOver(ops.top(),m.at(i)))
                {
                    out.push(ops.top());
                    ops.pop();
                }

                ops.push(m.at(i));
            }
            else if(m.at(i)=='(')
                ops.push(m.at(i));

            else if(m.at(i)==')')
            {
                while(ops.top()!='(')
                {
                    out.push(ops.top());
                    ops.pop();
                }
                ops.pop();
            }
        }

        while(!ops.empty())
        {
            out.push(ops.top());
            ops.pop();
        }
    while(!out.empty())
    {
        printf("%c",out.front());
        out.pop();
    }
    printf("\n");
    }


    return 0;
}
