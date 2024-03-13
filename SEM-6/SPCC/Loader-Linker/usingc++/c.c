#include <stdio.h>
#include <stdlib.h>
// Declare the function defined in the C++ file
extern void displayMessage();

int main() {
    // Call the function from the C++ object file
    displayMessage();
    printf("Hello from C!\n");
    system("pause");
    return 0;
}
