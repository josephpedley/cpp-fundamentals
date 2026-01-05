// basics/memory_layout.cpp

// Concept: Memory layout
// Goal: Understand where objects live and how long they exist
//
// Memory regions covered:
// - Stack (automatic storage)
// - Heap (dynamic storage)
// - Static / global storage
//
// Key questions to ask when writing c++:
// - Where is this object stored?
// - Who owns it?
// - When is it destroyed?

#include <iostream>

// ------------------------------------------------------------
// GLOBAL / STATIC STORAGE
// ------------------------------------------------------------
int global_var = 42;           // Lives for entire program
static int file_static = 100;  // File scope, entire program

void static_example() {
    static int function_static = 0; // Initialized once, persists
    function_static++;
    std::cout << "  function_static: " << function_static << '\n';
} // function_static NOT destroyed here

// ------------------------------------------------------------
// STACK STORAGE (AUTOMATIC)
// ------------------------------------------------------------
void stack_example() {
    int local = 10;            // Created when function enters
    int array[3] = {1, 2, 3};  // Stack array
    
    std::cout << "  local: " << local << '\n';
    std::cout << "  array[0]: " << array[0] << '\n';
} // local and array DESTROYED here (stack unwinds)

// ------------------------------------------------------------
// HEAP STORAGE (DYNAMIC)
// ------------------------------------------------------------
int* heap_example() {
    int* p = new int(99);      // Allocated on heap
    std::cout << "  *p (heap): " << *p << '\n';
    return p;                  // Memory persists after function
} // WARNING: p pointer destroyed, but not the int it points to!

// ------------------------------------------------------------
// MAIN DEMONSTRATION
// ------------------------------------------------------------
int main() {
    std::cout << "===== STACK STORAGE =====\n";
    stack_example();           // local destroyed
    
    std::cout << "\n===== HEAP STORAGE =====\n";
    int* heap_ptr = heap_example();
    std::cout << "  heap_ptr points to: " << *heap_ptr << '\n';
    // MUST remember to clean up!
    delete heap_ptr;           // Manual cleanup required - smart pointers do this for you, I will cover this too.
    heap_ptr = nullptr;        // Good practice
    
    std::cout << "\n===== STATIC STORAGE =====\n";
    std::cout << "  global_var: " << global_var << '\n';
    std::cout << "  file_static: " << file_static << '\n';
    
    static_example();  // 1
    static_example();  // 2
    static_example();  // 3 - persists between calls!
    
    std::cout << "\n===== ADDRESS COMPARISON =====\n";
    int stack1, stack2;
    int* heap1 = new int(1);
    
    std::cout << "  stack1: " << &stack1 << " (stack - high memory)\n";
    std::cout << "  stack2: " << &stack2 << " (near stack1)\n";
    std::cout << "  heap1:  " << heap1 << " (heap - different region)\n";
    std::cout << "  global: " << &global_var << " (low memory)\n";
    
    delete heap1;  // Clean up
    
    std::cout << "\n===== DANGEROUS PATTERNS =====\n";
    
    // Dangling pointer (pointer to destroyed object)
    int* dangling;
    {
        int temp = 777;
        dangling = &temp;
    } // temp destroyed
    // *dangling = 5; // UNDEFINED BEHAVIOR - would crash
    
    // Memory leak (forgetting delete)
    int* leak = new int(888);
    // Forgot: delete leak;
    // Memory allocated but never freed
    
    std::cout << "  (examples commented out to prevent crashes)\n";
    
    return 0;
} // All remaining automatic variables destroyed here

// ------------------------------------------------------------
// Key Takeaways:
// 1. Stack: Automatic lifetime, fast, limited size
// 2. Heap: Manual lifetime, flexible, slower
// 3. Static: Program lifetime, one instance
// 4. Address hints: Stack grows down, heap fragmented
// 5. Ownership: Who deletes heap objects? (RAII solves this)
// ------------------------------------------------------------