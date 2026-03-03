#include <stdio.h>
#include <stdlib.h>

typedef long long integer;

integer larger(integer first, integer second)
{
    return first > second ? first : second;
}

#define MAXSIZE 200000
integer length, limit;
integer cost[MAXSIZE], value[MAXSIZE];

integer findMaximumValue()
{
    integer start = 0;
    integer end = 0;
    integer costSum = 0;
    integer valueSum = 0;
    integer bestValue = 0;

    while (end < length)
    {
        costSum = costSum + cost[end];
        valueSum = valueSum + value[end];

        for (; costSum > limit && start <= end; start++)
        {
            costSum -= cost[start];
            valueSum -= value[start];
        }

        integer currentValue = valueSum;
        bestValue = larger(bestValue, currentValue);

        end++;
    }

    return bestValue;
}

#define calculateResult findMaximumValue

int main()
{
    scanf("%lld", &length);
    scanf("%lld", &limit);

    for (integer i = 0; i < length; i++)
        scanf("%lld", &cost[i]);
    

    for (integer i = 0; i < length; i++)
        scanf("%lld", &value[i]);
    

    integer answer = calculateResult();

    printf("%lld\n", answer);

    return 0;
}
