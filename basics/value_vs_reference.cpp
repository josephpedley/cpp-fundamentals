// Concept: Value vs Reference vs Pointer
// Goal: Understand copying vs aliasing
// Questions:
// - Which changes persist outside the function?
// - Why?

#include <iostream>

void by_value(int x){
    x = 10;
}

void by_reference(int& x){
    x = 20;
}

void by_pointer(int* x) {
    if (x) {
        *x = 30;
    }
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    by_value(a);
    by_reference(b);
    by_pointer(&c);

    std::cout << "a (by value): " << a << '\n'; // 1 - x is a copy, modifying x modifies the copy. Original a remains untouched
    std::cout << "b (by reference): " << b << '\n'; // 20 - x is an alias to b, assigning to x assigns to b
    std::cout << "c (by pointer): " << c << '\n'; // 30 - x points to c, *x dereferences the pointer, pointed to object is modified.


    return 0;
}

// Takeaways:
// Passing by value copies
// Passing by reference aliases
// Passing by pointer aliases indirectly