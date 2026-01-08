# C Language Performance Test

## Development Environment

- **Compiler**: GCC (GNU Compiler Collection)
- **Version Requirement**: GCC 4.8+ or compatible compiler
- **Operating System**: Linux, macOS, Windows (using MinGW or Cygwin)

### Ubuntu 22.04 Installation Commands

```bash
# Update package list
sudo apt update

# Install GCC compiler
sudo apt install -y gcc

# Verify installation
gcc --version
```

## Dependencies

- No external dependencies, only uses C standard library

## Compilation Command

```bash
gcc -O2 -o test test.c
```

**Parameter Explanation**:
- `-O2`: Enable optimization level 2, balancing compilation time and runtime performance
- `-o test`: Specify output executable file name as `test`
- `test.c`: Source file name

## Run Command

```bash
./test
```

## Code Description

- Test Content: 1,000,000 queue operations, including random character generation, enqueue, and conditional dequeue
- Data Structure: Custom circular queue (array-based implementation)
- Random Number Generation: Custom Xorshift random number generator

## Output Example

```
C: 5.944982 milliseconds
```

## Notes

1. Using `-O2` optimization level provides better performance
2. The compiled `test` file is ignored by `.gitignore`
3. Ensure there is no existing file named `test` in the current directory before running
4. You can use `gcc --version` to check the GCC version