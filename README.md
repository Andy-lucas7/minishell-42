<h1 align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="42" width="40" height="40" /> 
  <br>
  Minishell
</h1>

<p align="center">
  <b>As beautiful as a shell can be.</b><br>
  <i>A minimalist bash re-implementation written in C for the 42 curriculum.</i>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" alt="Language C" />
  <img src="https://img.shields.io/badge/Score-125%2F100-success.svg" alt="Score" />
  <img src="https://img.shields.io/badge/Norminette-Passing-brightgreen.svg" alt="Norminette" />
</p>

---

## 💡 About The Project

**Minishell** is a project from the 42 curriculum that requires us to build a simple shell from scratch. We learn about processes, file descriptors, pipes, signals, and parsing while strictly adhering to POSIX standards. The goal is to recreate a minimalist version of `bash`.

### ✨ Core Features

*   **Command Execution**: Supports absolute/relative paths and commands found via the `$PATH` environment variable.
*   **Pipes (`|`)**: Chains multiple commands together, directing the output of one to the input of the next.
*   **Redirections**:
    *   `<` redirects input.
    *   `>` redirects output.
    *   `<<` (Here document) reads input until a delimiter is seen.
    *   `>>` redirects output in append mode.
*   **Environment Variables**: Handles expansion of variables (e.g., `$USER`, `$PWD`) and the exit status of the most recently executed foreground pipeline (`$?`).
*   **Quoting**:
    *   `'` (Single quotes) prevent interpretation of meta-characters.
    *   `"` (Double quotes) prevent interpretation of meta-characters except for `$`.
*   **Signal Handling**: Accurately handles `ctrl-C`, `ctrl-D` and `ctrl-\` similarly to bash.
*   **Built-in Commands**:
    *   `echo` (with `-n` option)
    *   `cd` (with only a relative or absolute path)
    *   `pwd` (without any options)
    *   `export` (without any options)
    *   `unset` (without any options)
    *   `env` (without any options or arguments)
    *   `exit` (with exit status handling)

## 🛠️ Architecture

The project is structured into three main phases:
1.  **Lexer/Parser**: Uses a custom finite state machine to tokenize the user input, handle quotes, and expand environment variables before generating an Abstract Syntax Tree (AST) or a command table.
2.  **Executor**: Iterates over the command table, creating child processes (`fork`), setting up pipes and file descriptors (`dup2`), and executing binaries (`execve`).
3.  **Built-ins & Signals**: Manages local execution of built-ins and intercepts system signals using `sigaction`.

## 🚀 Getting Started

### Prerequisites
*   `gcc` or `clang`
*   `make`
*   `readline` library

### Installation

1. Clone the repository
   ```sh
   git clone https://github.com/Andy-lucas7/minishell-42.git
   cd minishell-42
   ```

2. Compile the executable
   ```sh
   make
   ```

3. Run Minishell
   ```sh
   ./minishell
   ```

## 🎮 Usage Examples

```bash
minishell$ echo "Hello World" > output.txt
minishell$ cat output.txt | grep "World" | wc -l
1
minishell$ export MY_VAR="42"
minishell$ echo $MY_VAR
42
minishell$ exit
```

## 🧠 What I Learned

This project was a deep dive into system programming in C. I learned how operating systems manage processes, how inter-process communication works via pipes, and how complex string parsing algorithms function under the hood. Managing memory leaks in a program that constantly spawns new processes was one of the biggest challenges.

---
<p align="center">Made with ❤️ by Lucas Andrey</p>
