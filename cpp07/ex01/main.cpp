#include <iter.hpp>

void    add(int &a)
{
    a += 1;
}

void    add(float &a)
{
    a += 1;
}

int main( void ) {
    
    {
        int arr[3] = {5, -1, 10};
        std::cout << "Int array:" << std::endl;
        iter(arr, 3, print);
        iter(arr, 3, add);
        std::cout << "Int array after iter():" << std::endl;
        iter(arr, 3, print);
    }
    {
        float arr[3] = {5.4, -1, 10};
        std::cout << "Float array:" << std::endl;
        iter(arr, 3, print);
        iter(arr, 3, add);
        std::cout << "Int array after iter():" << std::endl;
        iter(arr, 3, print);
    }
    {
        std::string arr[4] = {"asrg", "basfdsaf", "col", "eeeee123456"};
        std::cout << "String array printed with iter:" << std::endl;
        iter(arr, 4, print);
    }
    return 0;
}