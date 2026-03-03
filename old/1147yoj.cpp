#include <stdio.h>
#include <assert.h>

typedef long long big_integer;

big_integer larger(big_integer first, big_integer second) { return first > second ? first : second; }
big_integer smaller(big_integer first, big_integer second) { return first < second ? first : second; }

big_integer rows_sequence_length, cols_sequence_length;
big_integer rows_sequence[40], cols_sequence[40];

void generate_sequence_recursive(big_integer value, big_integer *arr, big_integer *len, big_integer idx)
{
    arr[idx] = value;

    if (value == 1)
    {
        *len = idx + 1;
        return;
    }

    generate_sequence_recursive((value + 1) / 2, arr, len, idx + 1);
}

void generate_sequence(big_integer input, big_integer *count_ptr, big_integer output[])
{
    generate_sequence_recursive(input, output, count_ptr, 0);
}

big_integer calculate_product(big_integer x, big_integer y)
{
    return x * y;
}

big_integer calculate_result(big_integer width, big_integer height, big_integer operations)
{
    generate_sequence(width, &rows_sequence_length, rows_sequence);
    generate_sequence(height, &cols_sequence_length, cols_sequence);

    big_integer total_operations = (rows_sequence_length - 1) + (cols_sequence_length - 1);
    if (operations >= total_operations)
        return calculate_product(width, height) - 1;

    big_integer minimum_area = calculate_product(width, height);
    big_integer lower_bound = larger(0, operations - (cols_sequence_length - 1));
    big_integer upper_bound = smaller(rows_sequence_length, operations + 1);

    for (big_integer i = lower_bound; i < upper_bound; i++)
    {
        big_integer j = operations - i;
        assert(j < cols_sequence_length);
        big_integer current_area = calculate_product(rows_sequence[i], cols_sequence[j]);
        minimum_area = smaller(minimum_area, current_area);
    }

    return calculate_product(width, height) - minimum_area;
}

int main()
{
    big_integer test_cases;
    scanf("%lld", &test_cases);

    for (big_integer test_idx = 0; test_idx < test_cases; test_idx++)
    {
        big_integer width, height, operations;
        scanf("%lld%lld%lld", &width, &height, &operations);

        big_integer answer = calculate_result(width, height, operations);
        printf("%lld\n", answer);
    }

    return 0;
}
