
auto // keyword for automatic typededuction by the compiler
// datatype has to be known at compile time!

const // makes a value assigned to a variable non-modifiable

bool b; // boolean
char c; // character

// usable modifiers for whole number data types
// signed and unsigned is also possible for characters, but not for doubles and floats
signed // half the values are positive the other half is negative
unsigned // only values >= 0
short // smaller range of values
long // wider range of values

int i; // integer
long l; // long is a long int but can also have long long
double d; // double
float f; // float

size_t size = sizeof(/* datatype */) // returns the size of an datatype in Bytes

// different Bit-integers
uint8_t u8 = 9;
int8_t s8 = -10;

uint16_t u16 = 11;
int16_t s16 = -12;

uint32_t u32 = 13;
int32_t s32 = -14;

uint64_t u64 = 15;
int64_t s64 = -16;

// strings
string s1 = "Hello World"; // multiple functions for strings see docu
s1[1] = 'a'; // s1 == "Hallo World" strings are accessed like arrays
const char* s2 = "Hello World"; // C String: last character is \0
char s3[] = "Hello World"; // C String: last character is \0
