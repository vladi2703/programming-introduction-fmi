#include <iostream>
#include <cstddef>

const int ARR_CAPACITY = 1024;

bool check_equal (const int a[], int begin_a, int size, const int b[], int begin_b)
{
    for(std::size_t i=0; i<size; i++)
    {
        if(a[begin_a++] != b[begin_b++])
            return false;
    }
    return true;
}


std::size_t input_array (int arr[], int arr_capacity)
{
    std::size_t n;
    std::cin >> n;
    if( n > arr_capacity )      // ако n>капацитета, прочитаме само колкото място имаме
        n = arr_capacity;

    for(std::size_t i=0; i<n; i++)
        std::cin>>arr[i];

    return n;
}

int main()
{
    int arr_a[ARR_CAPACITY], arr_b[ARR_CAPACITY];

    int arr_a_size = input_array(arr_a, ARR_CAPACITY);
    int arr_b_size = input_array(arr_b, ARR_CAPACITY);

    int res = 0;

    for(int i=0; i + arr_a_size <= arr_b_size; i++)
    {
        if(check_equal(arr_a, 0, arr_a_size, arr_b, i))
            ++res;
    }

    std::cout << res << std::endl;

    return 0;
}
