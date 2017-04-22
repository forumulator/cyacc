(Very) Basic C Compiler in Flex/Yacc
====================================

### Build
The executable can be generated using make:
```bash
make all
```

### Usage
Currently, it only takes input from `stdin`, and generates output to `int.out`. To redirect from 
some other file, use, on windows (Powershell):
```bash
cat file.c | ./cyacc.exe
```
On linux/windows(cmd), use redirection:
```bash
./cyacc << file.c
```
### Source Structure
`src/`: Contains all source files  
  - `gramm.y`: Contains the actual semantic analysis code  
  - `calc.h`: Defines the various structs used
  - `calc.c`: Contains code for the various tables (eg. the symbol table, etc.)
  - `utils.c`: Contains utiltiy functions  
  
`gen/`: Contains the generated c files by bison and flex
`test/`: Contains misc. testing files. Only temporary.