// basics/objects_classes.cpp
//
// Concept: Objects and classes
// Goal: Understand what an object is, what a class defines,
//       and how construction, destruction, and encapsulation work.
//
// Key ideas:
// - A class defines a type (layout + behaviour)
// - An object is an instance of that type
// - Constructors establish invariants
// - Destructors clean up resources
// - Access control enforces correct usage

#include <iostream>

// ------------------------------------------------------------
// SIMPLE CLASS DEFINITION
// ------------------------------------------------------------
class Counter {
private:
    int value; // invariant: value >= 0

public:
    // Constructor: runs when object is created
    Counter(int start = 0) : value(start) {
        std::cout << "Counter constructed\n";
    }

    // Destructor: runs when object is destroyed
    ~Counter() {
        std::cout << "Counter destroyed\n";
    }

    void increment() {
        value++;
    }

    int get() const {
        return value;
    }
};

// ------------------------------------------------------------
// PASSING OBJECTS
// ------------------------------------------------------------
void increment_by_value(Counter c) {
    // Copy is made
    c.increment();
}

void increment_by_reference(Counter& c) {
    // Operates on original object
    c.increment();
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main() {
    std::cout << "===== STACK OBJECT =====\n";
    Counter a(5); // constructed on stack
    a.increment();
    std::cout << "a value: " << a.get() << '\n';

    std::cout << "\n===== PASSING OBJECTS =====\n";
    increment_by_value(a);
    std::cout << "after by_value: " << a.get() << '\n';

    increment_by_reference(a);
    std::cout << "after by_reference: " << a.get() << '\n';

    std::cout << "\n===== HEAP OBJECT =====\n";
    Counter* p = new Counter(10);
    p->increment();
    std::cout << "heap counter: " << p->get() << '\n';
    delete p; // destructor called here (using new and delte is NOT preferred. Will talk about unique_ptr ins a later commit)

    std::cout << "\n===== END OF MAIN =====\n";
    return 0;
}
