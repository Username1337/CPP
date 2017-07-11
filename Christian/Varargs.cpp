#include <cstdarg>

// variable number of arguments can be taken by that function
// but it has to be one at least
void sum(int n1, ...) {
    va_list list;
    va_start(list,n1); // initializes the list of paramters
    int sum = 0;
    int n = n1;
    // the end of the list of paramters has to be marked by some specification:
    // e.g. the first paramter denotes the number of paramters; the last paramter is 0; ...
    while(n != 0) {
        sum += n;
        n = va_arg(list,int); // takes the next paramter out of the list
    }
}
