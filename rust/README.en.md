# Rust Language Performance Test

## Development Environment

- **Toolchain**: Rust toolchain (including rustc compiler and cargo build tool)
- **Version Requirement**: Rust 1.56+ (supports 2021 syntax)
- **Installation Method**: Install using rustup (recommended)
  ```bash
  curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
  ```
- **Operating System**: Linux, macOS, Windows

### Ubuntu 22.04 Installation Commands

#### Method 1: Install using apt package manager (Recommended for simplicity)

```bash
# Update package list
sudo apt update

# Install Rust development environment
sudo apt install -y rustc cargo

# Verify installation
rustc --version
cargo --version
```

#### Method 2: Install using rustup (Officially recommended, supports multi-version management)

```bash
# Update package list
sudo apt update

# Install necessary dependencies
sudo apt install -y curl build-essential libssl-dev libffi-dev 

# Install Rust toolchain
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# Configure environment variables (current session)
source $HOME/.cargo/env

# Permanently configure environment variables (add the following line to ~/.bashrc or ~/.zshrc)
echo 'export PATH="$HOME/.cargo/bin:$PATH"' >> ~/.bashrc

# Verify installation
rustc --version
cargo --version
```

## Dependencies

- No external dependencies, only using Rust Standard Library

## Compilation Commands

### Compile directly with rustc

```bash
rustc -O test.rs
```

**Parameter Explanation**:
- `-O`: Enable optimization, equivalent to `-C opt-level=2`
- `test.rs`: Source file name

### Build with cargo

```bash
cargo build --release
```

**Parameter Explanation**:
- `--release`: Enable release mode, generate optimized executable

## Running Commands

### Run executable directly

```bash
./test
```

### Run with cargo

```bash
cargo run --release
```

## Code Description

- Test Content: 1,000,000 queue operations, including random character generation, enqueue, and conditional dequeue
- Data Structure: Using Rust Standard Library's `VecDeque`
- Random Number Generation: Custom linear congruential generator (thread-safe)

## Output Example

```
Rust: 6.334495 milliseconds
```

## Notes

1. Using `-O` or `--release` optimization can achieve better performance
2. The compiled `test` file and `target` directory are ignored by `.gitignore`
3. You can check Rust version with `rustc --version` or `cargo --version`
4. First run of cargo will create a `Cargo.lock` file, recording dependency versions
5. Use `cargo clean` to clean up compiled files

## Cargo.toml Description

The project includes a `Cargo.toml` file for the cargo build system:

- Defines project name, version, and author
- Specifies Rust version requirements
- Declares no external dependencies

You can use `cargo check` command to quickly check code syntax errors without generating an executable.