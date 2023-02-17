# sqlite_clone
This is a very basic sqlite clone written in C++. It is inspired by the [Lets Build a Simple Database](https://cstack.github.io/db_tutorial/) tutorial, which is written in C. The intent is to create an implementation with similar speed, but with the modern language features that come with C++. The goal is to eventually make this implementation multi-threaded, to further increase performance.

As-is, the database only supports a couple of commands, and only allows you to create one table. Both the `Table` and `InputHandler` APIs are unit tested.

# Table of Contents
- [sqlite\_clone](#sqlite_clone)
- [Table of Contents](#table-of-contents)
- [Requirements](#requirements)
- [Usage](#usage)
  - [Building](#build)
  - [Commands](#run)
  - [Testing](#test)
  - [Statements](#statements)
- [TODOS](#todos)

# Requirements
- CMake 3.14 or above

# Usage

## Build
- `cmake -S . -B build`
- `cmake --build build`

## Run
- `./build/apps/sqlite_clone`

## Test
- `./build/tests/sqlite_clone_test`

## Statements

# TODOS
