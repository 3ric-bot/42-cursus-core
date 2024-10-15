# libftTester

This repository contains a testing framework for the LibFT project, which is a reimplementation of the C standard library functions. The Makefile is designed to compile and test both mandatory and bonus functions using C++.

## Features

    * + Utility Scripts: Includes utility scripts for enhanced error detection and logging during 
	  compilation and runtime.
    * + Valgrind Integration: Automatically checks for memory leaks, invalid reads/writes, and other 
	  memory-related issues.
    * + Automatic Compilation: Compiles individual function tests and displays detailed error messages if 
	  compilation or runtime errors occur.
    * + Docker Support: Provides Docker commands for isolated testing environments.

## How to Run it

To run the code, clone the repository into your local libft folder, then navigate to the libify directory.

Open a terminal in Visual Studio Code or use the on your pc to execute the code.

If you encounter a file not found error, customize the LIBFT_PATH variable in the Makefile to point to your libft project

## Commands
make m = launch mandatory tests  
make b = launch bonus tests  
make a = launch mandatory tests + bonus tests  
make [function name] = launch associated test ex: `make calloc`     


MOK / MKO = test about your malloc size (this shouldn't be tested by moulinette)
