# Leetcode Solutions

## Overview

This repository contains solutions to various Leetcode problems implemented in C++. Each problem is solved using different methods and approaches to provide a comprehensive understanding of the problem-solving techniques.

## Structure

Each problem is organized in its own folder, named after the problem number and title. Inside each folder, you will find:

- `README.md`: A file that describes the problem, the solution approach, and relevant tags.
- `one.cpp`, `two.cpp`, etc.: C++ files containing different solution methods for the problem.

### Example Folder Structure

Leetcode/
├── 1143 Largest Common Substring/
│ ├── README.md
│ ├── one.cpp
│ └── two.cpp
├── 0001 Two Sum/
│ ├── README.md
│ ├── one.cpp
│ └── two.cpp
README.md

## Makefile

The repository includes a `Makefile` that simplifies the process of compiling and running the C++ files. You can compile and run a specific solution file using the following commands:

```bash
make run PROBLEM=1143 SOLUTION=one
```

Above command will compile and run the `one.cpp` file inside the `1143 Largest Common Substring` folder. You can replace the `PROBLEM` and `SOLUTION` variables with the desired problem number and solution file name.

```bash
make run PROBLEM=1143
```

Above command will compile and run all the solution files inside the `1143 Largest Common Substring` folder.

```bash
make clean
```

Above command will remove all the compiled files from the repository.

## README Files

The `README.md` file inside each problem folder follows a consistent structure:

- **Problem**: A brief description of the problem statement.
- **Solution**: A detailed explanation of the solution approaches used in the corresponding C++ files.
- **Tags**: Relevant tags that categorize the problem and solution techniques.

### Example README Structure

```markdown
# Problem Title

## Problem

Description of the problem.

## Solution

1. One - Description of the first solution approach.
2. Two - Description of the second solution approach.

## Tags

- Tag1
- Tag2
- Tag3
```

## Searching by Tags in VSCode

To search for problems based on tags in Visual Studio Code:

1. Open the command palette by pressing Ctrl+Shift+P (Windows/Linux) or Cmd+Shift+P (Mac).
2. Type `Search: Find in Files` and press Enter.
3. In the search bar, type the tag you want to search for (e.g., Dynamic Programming).
4. VSCode will display all the files containing the specified tag, allowing you to quickly locate relevant problems and solutions.

This structure and tagging system will help you efficiently navigate and utilize the repository for studying and solving Leetcode problems.
