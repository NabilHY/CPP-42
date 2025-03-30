## CPP-42

#### CPP08
This module focuses on **STL containers, iterators, and algorithms**, requiring students to implement custom container-like classes while leveraging the C++98 Standard Template Library.

#### Key Exercises:

1. **Exercise 00: Easy Find**
   - **Objective**: Implement a template function to find values in containers
   - **Concepts**: Template functions, iterator basics, STL container interfaces
   - **Requirements**: Throw exception when value not found

2. **Exercise 01: Span**
   - **Objective**: Create a number storage class with span calculation
   - **Concepts**: STL algorithms, exception handling, iterator ranges
   - **Features**:
     - Add numbers individually or via iterator range
     - Calculate shortest/longest spans
     - Exception-safe operations

3. **Exercise 02: MutantStack**
   - **Objective**: Make std::stack iterable through inheritance
   - **Concepts**: Container adaptors, iterator implementation
   - **Implementation**:
     - Provides begin()/end() iterators
     - Maintains all original stack functionality
     - Demonstrates stack iteration capabilities

### Key Concepts Learned
- **STL Containers**: Proper usage of vector, list, stack
- **Iterator Patterns**: Implementing and using iterators
- **STL Algorithms**: Applying sort, min_element, max_element
- **Template Programming**: Generic container operations
- **Exception Handling**: Robust error management

### Module-Specific Rules
- **Mandatory STL Usage**: Must use STL containers/algorithms where applicable
- **Performance Requirements**: Span must handle 10,000+ elements efficiently
- **Iterator Proficiency**: Demonstrated through range operations
