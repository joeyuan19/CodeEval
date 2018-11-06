#include <iostream>

int main(int argc, char *argv[]) {
    short int n = 1;
    char * n_byte_order = (char *) &n;
    if (!n_byte_order[0]) {
        std::cout << "BigEndian" << std::endl;
    } else {
        std::cout << "LittleEndian" << std::endl;
    }
    return 0;
}



