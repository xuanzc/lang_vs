# C++ Language Performance Test

## Development Environment

- **Compiler**: G++ (GNU C++ Compiler) or Clang++
- **Version Requirements**: GCC 4.8+ or Clang 3.5+ or compatible compilers
- **Operating System**: Linux, macOS, Windows (using MinGW, Cygwin, or MSVC)

### Ubuntu 22.04 Installation Commands

#### Install G++ Compiler

```bash
# Update package list
sudo apt update

# Install G++ compiler
sudo apt install -y g++

# Verify installation
g++ --version
```

#### Install Clang++ Compiler (Optional)

```bash
# Update package list
sudo apt update

# Install Clang++ compiler
sudo apt install -y clang++

# Verify installation
clang++ --version
```

## Dependencies

- No external dependencies, only using C++ Standard Library

## Compilation Command

```bash
g++ -O2 -o test test.cpp
```

**Parameter Explanation**:
- `-O2`: Enable optimization level 2, balancing compilation time and runtime performance
- `-o test`: Specify the output executable file name as `test`
- `test.cpp`: Source file name

## Running Command

```bash
./test
```

## Code Description

- Test Content: 1,000,000 queue operations, including random character generation, enqueue, and conditional dequeue
- Data Structure: Using C++ Standard Library's `std::deque`
- Random Number Generation: Custom Xorshift random number generator

## Output Example

```
C++: 5.944982 milliseconds
```

## Notes

1. Using `-O2` optimization level can achieve better performance
2. The compiled `test` file is ignored by `.gitignore`
3. Ensure there is no existing `test` file in the current directory before running
4. You can check the G++ version with `g++ --version`
5. You can also use Clang++ compiler: `clang++ -O2 -o test test.cpp`