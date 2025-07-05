#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

string column_number_to_string(int col_number)
{
    col_number--;

    int threshold = 26, iterations = 0;
    for(; col_number >= threshold; col_number -= threshold, threshold *= 26, iterations++) ;

    string col_string = "";
    while(col_number >= 26)
    {
        col_string += char(col_number % 26) + 'A';
        col_number /= 26;
    }
    col_string += char(col_number % 26) + 'A';
    while((int)col_string.length() <= iterations)
        col_string += "A";

    reverse(col_string.begin(), col_string.end());
    return col_string;
}

int column_string_to_number(string col_string)
{
    int col_number = 0, threshold = 26;
    for(int iterations = (int)col_string.length() - 1; iterations; col_number += threshold, threshold *= 26, iterations--) ;

    int extra_cols = 0;
    for(auto c : col_string)
    {
        extra_cols *= 26;
        extra_cols += (c - 'A');
    }

    col_number += extra_cols;
    return col_number +  1;
}

void solve()
{
    string cell_text;
    cin >> cell_text;

    string current_string = "";
    int current_number = 0;

    bool is_alpha = true, is_num = false;

    vector<string> all_strings;
    vector<int> all_numbers;

    for(char c : cell_text)
    {
        if(isalpha(c))
        {
            if(is_num)
            {
                all_numbers.push_back(current_number);
                current_number = 0;
            }

            current_string += c;
            is_alpha = true;
            is_num = false;
        }
        else if(isdigit(c))
        {
            if(is_alpha)
            {
                all_strings.push_back(current_string);
                current_string = "";
            }

            current_number *= 10;
            current_number += (c - '0');
            is_alpha = false;
            is_num = true;
        }
    }

    if(is_num)
    {
        all_numbers.push_back(current_number);
        current_number = 0;
    }
    if(is_alpha)
    {
        all_strings.push_back(current_string);
        current_string = "";
    }

    if(all_numbers.size() == 2)
    {
        int row_number = all_numbers[0], col_number = all_numbers[1];

        string col_string = column_number_to_string(col_number);

        cout << col_string << row_number << "\n";
        
    }
    else if(all_numbers.size() == 1)
    {
        string col_string = all_strings[0];
        int row_number = all_numbers[0];

        int col_number = column_string_to_number(col_string);

        cout << "R" << row_number << "C" << col_number << "\n";
    }
}

int main()
{
    // vector<int> test_nums = {1, 100, 3297, 398217, 3298};
    // vector<string> test_strings = {"BAA", "BZZ", "ABCD", "A", "AA"};

    // for(int num : test_nums)
    //     assert(column_string_to_number(column_number_to_string(num)) == num);
    // for(string str : test_strings)
    //     assert(column_number_to_string(column_string_to_number(str)) == str);

    int T;
    cin >> T;
    while(T--)
        solve();
}