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
