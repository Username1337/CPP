
/* datatype */ /* array name */[/* number of elements */]
double d[100]; // double array with 100 elements
// there is no initilization in C / C++
double d[100] = { 0.0 }; // set all elements to 0.0
double d[5] = {1, 2, 3, 4, 5};
d[0] == 1
d[1] == 2
// d is just a pointer to the first element!

double d[4][2] = {
    {1,1},
    {2,2},
    {3,3},
    {4,4}
};

// length = sizeof(array) / sizeof(content datatype)
int length = sizeof(d) / sizeof(double);
