
int i = 1;
i == 1
{ // lokales i verdeckt globales i
    int i = 2;
    i == 2
    { // lokales i verdeckt lokales i
         double d = 234;
         int i = 3;
         i == 3
    }
    // d is out of scope and unknown
    i == 2
}
i == 1
