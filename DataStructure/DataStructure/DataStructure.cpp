#include "sort_header.h"
#include "search.h"

using namespace std;
    

int main()
{

    char arr[] = "abbdcsaggsada";
    int table[26] = { 0 };

    for (int i = 0; i < 26; i++)
    {
        table[i] = char_count(arr, char(i + 97));
    }
    
    char_n_number(table, 26);



    return 0;
}

