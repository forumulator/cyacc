(Very) Basic C Compiler in Flex/Yacc
====================================

### Build
Clone the repo using git:
```bash
git clone https://github.com/forumulator/cyacc
```
The executable can be generated using make:
```bash
cd cyacc/
make cyacc
```

### Usage
The program takes a single argument, which is the name of the input file.
Thus, to gen code for file `a.c`, use:
```bash
./cyacc a.c
```
If no arguments are given, it reads the input from `stdin`. Thus, one can also run:
```bash
cat a.c | ./cyacc
```

The output is currently always generate in a file called int.out.  

### Source Structure
`src/`: Contains all source files  
  - `gramm.y`: Contains the actual semantic analysis code  
  - `calc.h`: Defines the various structs used
  - `calc.c`: Contains code for the various tables (eg. the symbol table, alias table, etc.)
  - `utils.c`: Contains utiltiy functions  
  - `func.c`: Contains the code for analysis of c funcitons.
  
`gen/`: Contains the generated c files by bison and flex  
`test/`: Contains misc. testing files. Only temporary  