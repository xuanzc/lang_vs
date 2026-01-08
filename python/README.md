# Python语言性能测试

## 开发环境

- **Python版本**：Python 3.8+ 或 PyPy 7.3+
- **安装方式**：
  - 从官网下载安装包：https://www.python.org/downloads/
  - 或使用包管理器安装
  - 推荐使用虚拟环境
- **IDE推荐**：Visual Studio Code (with Python extension), PyCharm, Jupyter Notebook
- **操作系统**：Linux, macOS, Windows

### Ubuntu 22.04安装命令

#### 检查默认Python版本

Ubuntu 22.04默认已安装Python 3.10：

```bash
python3 --version
```

#### 安装pip和必要依赖

```bash
# 更新软件包列表
sudo apt update

# 安装pip和必要依赖
sudo apt install -y python3-pip python3-venv build-essential

# 升级pip到最新版本
python3 -m pip install --upgrade pip
```

#### 安装Numba

```bash
# 使用pip安装Numba
pip3 install numba

# 验证安装
python3 -c "import numba; print(numba.__version__)"
```

#### 创建虚拟环境并安装依赖

```bash
# 创建虚拟环境
python3 -m venv venv

# 激活虚拟环境
source venv/bin/activate

# 在虚拟环境中安装依赖
pip install numba

# 验证安装
python -c "import numba; print(numba.__version__)"

# 退出虚拟环境
deactivate
```

#### 安装PyPy（可选，性能可能更好）

```bash
# 更新软件包列表
sudo apt update

# 安装PyPy 3
sudo apt install -y pypy3 pypy3-pip

# 验证安装
pypy3 --version

# 使用PyPy的pip安装Numba
pypy3 -m pip install numba
```

## 依赖

- **Numba**：用于JIT编译，提高Python代码性能
  - 版本要求：Numba 0.55+

## 依赖安装

### 使用pip安装

```bash
pip install numba
```

### 使用conda安装（如果使用Anaconda）

```bash
conda install numba
```

### 创建虚拟环境并安装依赖

```bash
# 创建虚拟环境
python3 -m venv venv

# 激活虚拟环境
# Linux/macOS:
source venv/bin/activate
# Windows:
venv\Scripts\activate

# 安装依赖
pip install numba
```

## 运行命令

### 直接运行Python脚本

```bash
python3 test.py
```

### 使用PyPy运行（可选，性能可能更好）

```bash
pypy3 test.py
```

### 在虚拟环境中运行

```bash
# 确保已激活虚拟环境
source venv/bin/activate  # Linux/macOS
# 或
venv\Scripts\activate  # Windows

python test.py
```

## 代码说明

- 测试内容：100万次队列操作，包括随机字符生成、入队和条件出队
- 数据结构：使用数组模拟队列操作
- 随机数生成：自定义高效随机数生成器
- JIT优化：使用Numba的`@njit`装饰器对关键函数进行JIT编译

## 输出示例

```
Python: 6.695181 milliseconds
```

## 注意事项

1. 首次运行时，Numba会进行JIT编译，可能会有短暂延迟
2. 编译生成的缓存文件会被`__pycache__`目录存储，会被`.gitignore`忽略
3. 可以使用`python --version`检查Python版本
4. 可以使用`pip show numba`检查Numba版本
5. 使用`--numba-seed`选项可以设置随机数种子
6. 禁用Numba JIT可以通过注释掉`@njit`装饰器实现

## JIT优化说明

本项目中的Python代码使用了Numba进行JIT优化：

1. 使用`@njit`装饰器对核心函数进行JIT编译
2. 优化了循环结构，提高了执行效率
3. 使用了Numba兼容的数据结构
4. 添加了预热阶段，避免首次编译时间影响测试结果

这些优化措施使Python代码的性能接近原生编译型语言。