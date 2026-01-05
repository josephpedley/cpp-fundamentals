// basics/const_correctness.cpp
//
// Concept: Const correctness
// Goal: Understand what const applies to and why it matters
//
// What const can protect:
// - Variables: prevents modification through that name
// - Pointers: protects the pointer, the pointee, or both
// - References: prevents modification through that reference
// - Methods: prevents modification of observable object state
//
// Binding rule (read right-to-left):
//   const int* p        -> pointer to const int
//   int* const p        -> const pointer to int
//   const int* const p  -> const pointer to const int
//
// Const prevents accidental mutation via:
// - compile-time enforcement
// - const references and pointers
// - const member functions
// - const function parameters

#include <iostream>

// ------------------------------------------------------------
// 4. CONST IN FUNCTION PARAMETERS
// ------------------------------------------------------------
void print_value(const int& x) {
    // x = 100; 
    // ^ COMPILE ERROR:
    // const reference prevents modification of argument

    std::cout << x << '\n';
}

// ------------------------------------------------------------
// 5. CONST MEMBER FUNCTIONS
// ------------------------------------------------------------
class Counter {
private:
    int value = 0;

public:
    int get() const {
        // const member function:
        // promises not to modify object state
        return value;
    }

    void increment() {
        value++;
    }
};

int main() {
    // --------------------------------------------------------
    // 1. BASIC CONST VARIABLES
    // --------------------------------------------------------
    const int immutable = 10;

#if 0
    immutable = 20;
    // ^ COMPILE ERROR:
    // const variable cannot be modified
#endif

    // --------------------------------------------------------
    // 2. CONST POINTERS
    // --------------------------------------------------------
    int a = 5;
    int b = 6;

    // Pointer to const int
    const int* p1 = &a;

#if 0
    *p1 = 7;
    // ^ COMPILE ERROR (intentional):
    // cannot modify pointee through pointer-to-const
#endif

    p1 = &b; // OK: pointer itself is not const

    // Const pointer to int
    int* const p2 = &a;

    *p2 = 12; // OK: pointee is mutable

#if 0
    p2 = &b;
    // ^ COMPILE ERROR:
    // const pointer cannot be reassigned
#endif

    // Const pointer to const int
    const int* const p3 = &a;

#if 0
    *p3 = 8;  // cannot modify pointee
    p3 = &b; // cannot reassign pointer
#endif

    // --------------------------------------------------------
    // 3. CONST REFERENCES
    // --------------------------------------------------------
    const int& ref = a;

#if 0
    ref = 9;
    // ^ COMPILE ERROR:
    // cannot modify through const reference
#endif

    a = 9; // OK: object itself is not const

    print_value(a);

    // --------------------------------------------------------
    // CONST OBJECTS & METHODS
    // --------------------------------------------------------
    const Counter c; // Using class from 5.

#if 0
    c.increment();
    // ^ COMPILE ERROR:
    // cannot call non-const method on const object
#endif

    std::cout << c.get() << '\n';

    return 0;
}

// ------------------------------------------------------------
// Key Takeaways:
// - const prevents mutation through that name
// - const does not make an object globally immutable
// - const enables safe aliasing and clearer APIs
// - const correctness is enforced at compile time
// ------------------------------------------------------------
