# sqlite_clone
This is a very basic sqlite clone written in C++. It is inspired by the [Lets Build a Simple Database](https://cstack.github.io/db_tutorial/) tutorial, which is written in C. The intent is to create an implementation with similar speed, but with the modern language features that come with C++. The goal is to eventually make this implementation multi-threaded, to further increase performance.

As-is, the database only supports a couple of commands, and only allows you to create one table. Both the `Table` and `InputHandler` APIs are unit tested.

# Table of Contents
- [sqlite\_clone](#sqlite_clone)
- [Table of Contents](#table-of-contents)
- [Requirements](#requirements)
- [Usage](#usage)
  - [Build](#build)
  - [Run](#run)
  - [Test](#test)
  - [Statements](#statements)
- [TODOS](#todos)

# Requirements
- CMake 3.14 or above
- Some version of Linux (other OS's not tested)

# Usage

## Build
- `cmake -S . -B build`
- `cmake --build build`

## Run
- `./build/apps/sqlite_clone`

## Test
- `./build/tests/sqlite_clone_test`

## Statements
Current implemented statements are `SELECT` and `INSERT`. `SELECT` returns all
current entries in the database table. `INSERT` inserts an entry (row) into the
table.

# TODOS
- Create a thread worker to run the REPL. This way, the app can focus on thread management instead of running the REPL to handle input.
- Create a threaded class to allow for multiple named tables.
- Add more commands, e.g. remove, etc.
- Implement a thread-safe queue to pass data between the REPL thread and table threads.
