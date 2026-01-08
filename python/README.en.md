# Python Language Performance Test

## Development Environment

- **Python Version**: Python 3.8+ or PyPy 7.3+
- **Installation Methods**:
  - Download from official website: https://www.python.org/downloads/
  - Or install using package manager
  - Recommended to use virtual environment
- **Recommended IDEs**: Visual Studio Code (with Python extension), PyCharm, Jupyter Notebook
- **Operating System**: Linux, macOS, Windows

### Ubuntu 22.04 Installation Commands

#### Check Default Python Version

Ubuntu 22.04 has Python 3.10 installed by default:

```bash
python3 --version
```

#### Install pip and Necessary Dependencies

```bash
# Update package list
sudo apt update

# Install pip and necessary dependencies
sudo apt install -y python3-pip python3-venv build-essential

# Upgrade pip to the latest version
python3 -m pip install --upgrade pip
```

#### Install Numba

```bash
# Install Numba using pip
pip3 install numba

# Verify installation
python3 -c "import numba; print(numba.__version__)"
```

#### Create Virtual Environment and Install Dependencies

```bash
# Create virtual environment
python3 -m venv venv

# Activate virtual environment
source venv/bin/activate

# Install dependencies in the virtual environment
pip install numba

# Verify installation
python -c "import numba; print(numba.__version__)"

# Exit virtual environment
deactivate
```

#### Install PyPy (Optional, Better Performance)

```bash
# Update package list
sudo apt update

# Install PyPy 3
sudo apt install -y pypy3 pypy3-pip

# Verify installation
pypy3 --version

# Install Numba using PyPy's pip
pypy3 -m pip install numba
```

## Dependencies

- **Numba**: Used for JIT compilation to improve Python code performance
  - Version Requirement: Numba 0.55+

## Dependency Installation

### Install with pip

```bash
pip install numba
```

### Install with conda (If Using Anaconda)

```bash
conda install numba
```

### Create Virtual Environment and Install Dependencies

```bash
# Create virtual environment
python3 -m venv venv

# Activate virtual environment
# Linux/macOS:
source venv/bin/activate
# Windows:
venv\Scripts\activate

# Install dependencies
pip install numba
```

## Running Commands

### Run Python Script Directly

```bash
python3 test.py
```

### Run with PyPy (Optional, Better Performance)

```bash
pypy3 test.py
```

### Run in Virtual Environment

```bash
# Ensure virtual environment is activated
source venv/bin/activate  # Linux/macOS
# Or
venv\Scripts\activate  # Windows

python test.py
```

## Code Description

- Test Content: 1,000,000 queue operations, including random character generation, enqueue, and conditional dequeue
- Data Structure: Using array to simulate queue operations
- Random Number Generation: Custom efficient random number generator
- JIT Optimization: Using Numba's `@njit` decorator to JIT compile key functions

## Output Example

```
Python: 6.695181 milliseconds
```

## Notes

1. On first run, Numba will perform JIT compilation, which may cause a brief delay
2. Compiled cache files are stored in the `__pycache__` directory, which is ignored by `.gitignore`
3. Check Python version with `python --version`
4. Check Numba version with `pip show numba`
5. Use `--numba-seed` option to set random seed
6. Disable Numba JIT by commenting out the `@njit` decorator

## JIT Optimization Description

The Python code in this project uses Numba for JIT optimization:

1. Using `@njit` decorator to JIT compile core functions
2. Optimized loop structure to improve execution efficiency
3. Using Numba-compatible data structures
4. Added warm-up phase to avoid first compilation time affecting test results

These optimization measures make Python code performance close to native compiled languages.