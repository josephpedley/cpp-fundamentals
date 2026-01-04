// basics/pointers.cpp

// Concept: Pointers
// Goal: Understand pointer variables vs pointees
// Questions:
// - What does a pointer store?  - Memory addresses
// - What does dereferencing do? - Accesses value at address
// - What happens when a pointer is reassigned? - Changes where it points

#include <iostream>

int main() {
    // 1. BASIC POINTER
    int value = 42;
    int* ptr = &value;  // ptr stores address of value
    
    std::cout << "value: " << value << " at " << &value << '\n';
    std::cout << "ptr stores: " << ptr << '\n';
    std::cout << "*ptr dereferences to: " << *ptr << '\n';
    
    // 2. DEREFERENCING MODIFIES POINTEE
    *ptr = 100;  // Changes value through pointer
    std::cout << "After *ptr = 100, value is: " << value << '\n';
    
    // 3. POINTER REASSIGNMENT
    int x = 10, y = 20;
    int* p = &x;
    std::cout << "\nInitially p points to x: " << *p << '\n';
    
    p = &y;  // p now points to y
    std::cout << "After p = &y, *p is: " << *p << " (y's value)\n";
    
    // 4. MULTIPLE POINTERS TO SAME OBJECT
    int num = 5;
    int* p1 = &num;
    int* p2 = &num;  // Both point to same address
    
    *p1 = 99;
    std::cout << "\n*p1 changed num to: " << num << '\n';
    std::cout << "*p2 sees: " << *p2 << " (same object)\n";
    
    // 5. NULL POINTER SAFETY
    int* nullPtr = nullptr;
    // *nullPtr = 5; // CRASH: dereferencing null pointer
    
    if (nullPtr) {  // Checks if not null
        // Safe to dereference
    }
    
    // 6. POINTER ARITHMETIC (Arrays)
    int arr[3] = {10, 20, 30};
    int* arrPtr = arr;  // Points to first element
    
    std::cout << "\narr[0]: " << *arrPtr << '\n';
    std::cout << "arr[1]: " << *(arrPtr + 1) << '\n';  // Pointer arithmetic
    std::cout << "arr[2]: " << arrPtr[2] << '\n';     // Array syntax works
    
    // 7. DANGLING POINTER EXAMPLE
    int* dangling;
    {
        int temp = 777;
        dangling = &temp;
    } // temp destroyed at end of scope, dangling points to invalid memory
    
    // *dangling; // UNDEFINED BEHAVIOR

    return 0;
}

// Key Insights:
// 1. Pointer stores ADDRESS, not value
// 2. *ptr accesses value at stored address
// 3. Reassignment changes what the pointer points to
// 4. Multiple pointers can alias the same object
