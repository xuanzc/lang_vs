# Java Language Performance Test

## Development Environment

- **JDK**: Java Development Kit
- **Version Requirement**: JDK 8+ or OpenJDK 8+
- **Installation Methods**:
  - Download from official website: https://www.oracle.com/java/technologies/downloads/
  - Or install OpenJDK using package manager
- **Recommended IDEs**: IntelliJ IDEA, Eclipse, NetBeans
- **Operating System**: Linux, macOS, Windows

### Ubuntu 22.04 Installation Commands

#### Install OpenJDK 17 (Recommended, default version for Ubuntu 22.04)

```bash
# Update package list
sudo apt update

# Install OpenJDK 17 JDK
sudo apt install -y openjdk-17-jdk

# Verify installation
java --version
javac --version
```

#### Install Other Versions of OpenJDK (Optional)

```bash
# Install OpenJDK 11 JDK
sudo apt install -y openjdk-11-jdk

# Install OpenJDK 8 JDK
sudo apt install -y openjdk-8-jdk
```

#### Set Default Java Version (Optional)

```bash
# List installed Java versions
sudo update-alternatives --config java

# Follow the prompts to enter the corresponding number to select the default version

# Similarly set the default version for javac
sudo update-alternatives --config javac
```

## Dependencies

- No external dependencies, only using Java Standard Library

## Compilation Commands

### Compile with javac

```bash
javac Test.java
```

**Parameter Explanation**:
- `Test.java`: Source file name
- Generates `Test.class` file after compilation

### Compile with javac and Specify Output Directory

```bash
javac -d . Test.java
```

**Parameter Explanation**:
- `-d .`: Specify compilation output directory as current directory

## Running Commands

### Run with java

```bash
java Test
```

**Parameter Explanation**:
- `Test`: Class name (without `.class` extension)

### Run with java -cp to Specify Classpath

```bash
java -cp . Test
```

**Parameter Explanation**:
- `-cp .`: Specify classpath as current directory

## Code Description

- Test Content: 1,000,000 queue operations, including random character generation, enqueue, and conditional dequeue
- Data Structure: Using array to simulate circular queue
- Random Number Generation: Custom Xorshift random number generator

## Output Example

```
Java: 21.707181 milliseconds
Sum: 87855
```

## Notes

1. The compiled `.class` files are ignored by `.gitignore`
2. You can check Java version with `java --version` or `javac --version`
3. Ensure the same Java version is used for both compilation and execution
4. For complex projects, build tools like Maven or Gradle are recommended
5. Use `javac -verbose Test.java` to view detailed compilation process
6. Use `java -Xmx512m Test` to specify maximum JVM memory

## Code Optimization Description

The Java code in this project has been optimized:

1. Using primitive type arrays instead of container classes to avoid auto-boxing/unboxing
2. Implemented efficient Xorshift random number generator
3. Reduced method calls and directly operated on arrays
4. Avoided frequent object creation
5. Added code to prevent compiler optimization, ensuring accurate test results

These optimization measures have significantly improved the performance of the Java code.