# sqlite_clone
This is a very basic sqlite clone written in C++. It is inspired by the [Lets Build a Simple Database](https://cstack.github.io/db_tutorial/) tutorial, which is written in C. The intent is to create an implementation with similar speed, but with the modern language features that come with C++. The goal is to eventually make this implementation multi-threaded, to further increase performance.

As-is, the database only supports a couple of commands, and only allows you to create one table. Both the `Table` and `InputHandler` APIs are unit tested.

# Table of Contents
- [TOC]

# Requirements
- CMake 3.14 or above

# Usage
- `cmake -S . -B build`
- `cmake --build build`
- `./build/apps/sqlite_clone`

## Build
- `cmake -S . -B build`
- `cmake --build build`

## Run
- `./build/apps/sqlite_clone`

## Test
- `./build/apps/sqlite_clone_test`

## Commands

# TODOS
