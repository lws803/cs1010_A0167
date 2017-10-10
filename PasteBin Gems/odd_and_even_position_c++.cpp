#include <iostream>
#include <climits>
using namespace std;
int main()
{
 
    int number;
    cin >> number;
 
    double even_sum{ 0 };
    double odd_sum{ 0 };
   
    double even_min_number  { 1000000000.0 };
    double odd_min_number   { 1000000000.0 };
    double even_max_number  { -1000000000.0 };
    double odd_max_number   { -1000000000.0 };
 
    for (int i = 1; i <= number; i++)
    {
        double current_number;
        cin >> current_number;
 
        if (i % 2 == 0)
        {
            even_sum += current_number;
        }
        else
        {
            odd_sum += current_number;
        }
        if (current_number < even_min_number && i % 2 == 0)
        {
            even_min_number = current_number;
        }
        else if (current_number < odd_min_number && i % 2 != 0)
        {
            odd_min_number = current_number;
        }
        if (current_number > even_max_number && i % 2 == 0)
        {
            even_max_number = current_number;
        }
        else if (current_number > odd_max_number && i % 2 != 0)
        {
            odd_max_number = current_number;
        }
    }
    if (number > 1)
    {
        cout << "OddSum=" << odd_sum << ',' << endl;
        cout << "OddMin=" << odd_min_number << ',' << endl;
        cout << "OddMax=" << odd_max_number << ',' << endl;
        cout << "EvenSum=" << even_sum << ',' << endl;
        cout << "EvenMin=" << even_min_number << ',' << endl;
        cout << "EvenMax=" << even_max_number << endl;
    }
   
    if (number == 1)
    {
        cout << "OddSum=" << odd_sum << ',' << endl;
        cout << "OddMin=" << odd_min_number << ',' << endl;
        cout << "OddMax=" << odd_max_number << ',' << endl;
        cout << "EvenSum=" << 0 << ',' << endl;
        cout << "EvenMin=" << "No" << ',' << endl;
        cout << "EvenMax=" << "No" << endl;
    }
 
    if (number == 0)
    {
        cout << "OddSum=" << number << ',' << endl;
        cout << "OddMin=" << "No" << ',' << endl;
        cout << "OddMax=" << "No" << ',' << endl;
        cout << "EvenSum=" << number << ',' << endl;
        cout << "EvenMin=" << "No" << ',' << endl;
        cout << "EvenMax=" << "No" << endl;
    }
 
    return 0;
}