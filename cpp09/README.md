## CPP-42

#### CPP09
This module focuses on **practical applications of STL containers** through three distinct projects, each requiring different container implementations while maintaining C++98 compliance.

#### Key Exercises:

1. **Exercise 00: Bitcoin Exchange**
   - **Objective**: Create a program to calculate Bitcoin values using historical data
   - **Concepts**: File I/O, date parsing, container selection (map recommended)
   - **Requirements**:
     - Handle CSV data files
     - Find nearest dates for price lookup
     - Validate input formats
   - **Container Use**: Must use at least one STL container

2. **Exercise 01: Reverse Polish Notation Calculator**
   - **Objective**: Implement a stack-based RPN calculator
   - **Concepts**: Stack operations, postfix notation, error handling
   - **Requirements**:
     - Process basic arithmetic operations
     - Handle single-digit operands
     - Validate expression syntax
   - **Container Use**: Must use a different container than Exercise 00

3. **Exercise 02: PmergeMe**
   - **Objective**: Implement Ford-Johnson merge-insert sort algorithm
   - **Concepts**: Sorting algorithms, container performance comparison
   - **Requirements**:
     - Handle 3000+ elements
     - Time two different container implementations
     - Display before/after results with timing
   - **Container Use**: Must use two different STL containers

### Key Concepts Learned
- **STL Container Mastery**: Appropriate container selection for different use cases
- **Algorithm Implementation**: Custom sorting algorithm development
- **Performance Analysis**: Timing and comparing container operations
- **Data Processing**: Handling real-world data formats (CSV, RPN)
- **Error Handling**: Robust input validation and error reporting

### Module-Specific Rules
- **Container Restrictions**: Each exercise must use different container(s)
- **Performance Requirements**: PmergeMe must handle large datasets
- **Output Formatting**: Strict requirements for exercise outputs
