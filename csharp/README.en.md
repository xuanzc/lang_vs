# C# Language Performance Test

## Development Environment

- **SDK**: .NET SDK
- **Version Requirement**: .NET 6.0+ or .NET Framework 4.7.2+
- **Installation Methods**:
  - Download from official website: https://dotnet.microsoft.com/download
  - Or install using package manager
- **Recommended IDEs**: Visual Studio, Visual Studio Code (with C# extension), Rider
- **Operating System**: Linux, macOS, Windows

### Ubuntu 22.04 Installation Commands

```bash
# Update package list
sudo apt update

# Install necessary dependencies
sudo apt install -y apt-transport-https 

# Add Microsoft package source key
wget https://packages.microsoft.com/config/ubuntu/22.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
rm packages-microsoft-prod.deb

# Update package list, including Microsoft package sources
sudo apt update

# Install .NET SDK 8.0 (latest LTS version)
sudo apt install -y dotnet-sdk-8.0

# Verify installation
dotnet --version
```

### Optional: Install Specific Versions of .NET SDK

```bash
# Install .NET SDK 6.0 (LTS version)
sudo apt install -y dotnet-sdk-6.0

# Install .NET SDK 7.0
sudo apt install -y dotnet-sdk-7.0
```

## Dependencies

- No external dependencies, only using .NET Standard Library

## Compilation Commands

### Compile with dotnet build

```bash
dotnet build -c Release
```

**Parameter Explanation**:
- `-c Release`: Specify build configuration as Release (optimized build)
- `csharp.csproj`: Project file (automatically found)

### Generate Self-Contained Executable

```bash
dotnet publish -c Release -r linux-x64 --self-contained true
```

**Parameter Explanation**:
- `-r linux-x64`: Specify runtime identifier (adjust according to target platform)
- `--self-contained true`: Generate self-contained executable including runtime

## Running Commands

### Run with dotnet run

```bash
dotnet run -c Release
```

**Parameter Explanation**:
- `-c Release`: Run with Release configuration

### Run Compiled Program Directly

```bash
./bin/Release/net8.0/csharp
```

**Explanation**:
- Path may vary slightly depending on .NET version and configuration

## Code Description

- Test Content: 1,000,000 queue operations, including random character generation, enqueue, and conditional dequeue
- Data Structure: Using .NET Standard Library's `Queue<char>`
- Random Number Generation: Using .NET Standard Library's `Random` class (static instance)

## Output Example

```
C#: 15.0721 milliseconds
```

## Notes

1. Using Release configuration can achieve better performance
2. The compiled `bin` and `obj` directories are ignored by `.gitignore`
3. You can check .NET SDK version with `dotnet --version`
4. The project file `csharp.csproj` defines basic project configuration
5. First run will download necessary .NET runtime components (if needed)

## Project File Description

The `csharp.csproj` file contains the following main configurations:

- Project SDK type (`Microsoft.NET.Sdk`)
- Target framework (e.g., `.NET 8.0`)
- Output type (console application)
- Other compilation options

You can modify project configuration by editing this file, such as changing the target framework version.