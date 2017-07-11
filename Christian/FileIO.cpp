#include <fstream>
#include <iostream>

// Reading a file
string line;
ifstream fileReader(/* filename */);
if (filer.is_open()) {
    while (! filer.eof()) { // eof = end of file
        getline(fileReader,line);
        // do something with line
    }
    fileReader.close();
} else {
    cout << "file not found!" << endl;
}

string word;
while(filer >> word){
    // splits the input from file at spaces " "
    // do something with word
}


// Writing a file
ofstream fileWriter(/* filename */);
if (fileWriter) {
    fileWriter << /* text to be written into the file */ << endl; // existing file is overwritten
    fileWriter.close();
}
