# Go Language Performance Test

## Development Environment

- **Compiler**: Go compiler (gc)
- **Version Requirement**: Go 1.16+ (supports module system)
- **Installation Methods**:
  - Download from official website: https://golang.org/dl/
  - Or install using package manager
- **Operating System**: Linux, macOS, Windows

### Ubuntu 22.04 Installation Commands

#### Install using apt package manager (Recommended)

```bash
# Update package list
sudo apt update

# Install Go compiler
sudo apt install -y golang-go

# Verify installation
go version
```

#### Download latest version from official website (Optional)

```bash
# Download Go 1.21.5 (latest stable version, adjust as needed)
wget https://go.dev/dl/go1.21.5.linux-amd64.tar.gz

# Extract to /usr/local
sudo tar -C /usr/local -xzf go1.21.5.linux-amd64.tar.gz

# Configure environment variables (current session)
export PATH=$PATH:/usr/local/go/bin

# Permanently configure environment variables (add the following line to ~/.bashrc or ~/.zshrc)
echo 'export PATH="$PATH:/usr/local/go/bin"' >> ~/.bashrc

# Verify installation
go version
```

## Dependencies

- No external dependencies, only using Go Standard Library

## Compilation Commands

### Compile with go build

```bash
go build -o test test.go
```

**Parameter Explanation**:
- `-o test`: Specify the output executable file name as `test`
- `test.go`: Source file name

### Install with go install

```bash
go install test.go
```

**Explanation**:
- Installs the compiled executable to `$GOPATH/bin` or `$GOBIN` directory

## Running Commands

### Run executable directly

```bash
./test
```

### Run directly with go run

```bash
go run test.go
```

**Explanation**:
- Compiles and runs immediately, no executable file generated

## Code Description

- Test Content: 1,000,000 queue operations, including random character generation, enqueue, and conditional dequeue
- Data Structure: Using slices to simulate queue operations
- Random Number Generation: Custom Xorshift random number generator

## Output Example

```
Go: 8.151746 milliseconds
```

## Notes

1. Go compiler automatically optimizes code, no need to explicitly specify optimization level
2. The compiled `test` file is ignored by `.gitignore`
3. You can check Go version with `go version`
4. Use `go env` to view Go environment variables
5. For simple programs, `go run` is recommended for quick execution

## Go Module Description

This project is a simple single-file program and does not use Go modules. To convert it to a module:

1. Initialize module:
   ```bash
   go mod init github.com/username/lang_vs/go
   ```

2. Add dependencies (if any):
   ```bash
   go get github.com/your/dependency
   ```

3. Build program:
   ```bash
   go build
   ```