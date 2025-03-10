# Introduction

We consider the implementation of the **Pętlik** programming language. The syntax of the language is described by the following grammar with the start symbol **Program**:

```
Program → InstructionSequence
InstructionSequence → ε | InstructionSequence Instruction
Instruction → Increment | Loop
Increment → Variable
Loop → '(' Variable InstructionSequence ')'
Variable → 'a' | ... | 'z'
```

A program consists solely of the characters that are enclosed in apostrophes in the grammar. Aside from these, no other characters—even spaces or newlines—may appear in the source code.

The program has access to 26 variables, whose values are nonnegative integers.

The instructions derived from the symbol **InstructionSequence** are executed in order from the first to the last.

An **Increment** instruction, in the form of a single variable, is equivalent to the following C language instruction:

```c
++variable;
```

A **Loop** instruction, in the form `(variable ...)`, is equivalent to the following C language construct:

```c
while (variable > 0) {
    --variable;
    ...
}
```

The implementation of the language consists of an optimizing compiler, which generates code for a virtual machine, and an interpreter for that machine code.

## Virtual Machine Instructions

The machine executes the following instructions:

- **INC Variable (increment)**  
  Increments the value of the variable by one.

- **ADD Variable0 Variable1 (add)**  
  Adds the value of **Variable1** to **Variable0**.

- **CLR Variable (clear)**  
  Resets the variable **Variable** to 0.

- **JMP Address (jump)**  
  Jumps to the instruction at the specified **Address**.

- **DJZ Variable Address (decrement or jump if zero)**  
  If **Variable** has the value 0, jump to the instruction at **Address**; otherwise, decrement the value of **Variable** by 1.

- **HLT (halt)**  
  Terminates the execution of the program.

Execution of the machine language program begins with the first instruction.

If an instruction does not specify otherwise, after its execution, control passes to the next instruction in the code.

For a sequence of instructions, the compiler generates code in order from the first to the last instruction. The code generated for a program ends with the **HLT** instruction.

If a **Loop** instruction does not contain another nested **Loop** instruction—meaning that within the parentheses there is a sequence of variables `Variable0, ..., VariableN` (for N ≥ 0), and none of the variables `Variable1, ..., VariableN` is equal to **Variable0**—the compiler generates optimized code of the following form:

```
ADD Variable1 Variable0
...
ADD VariableN Variable0
CLR Variable0
```

If the conditions for generating optimized code for the instruction are not met, the compiler generates the standard code.

Standard code for an **Increment** instruction, in the form of a variable, is:

```
INC Variable
```

Standard code for a **Loop** instruction, in the form `(Variable ...)`, is:

```
DJZ Variable End
...
JMP Start
```

where **Start** is the address of the first instruction of this sequence, and **End** is the address of the instruction immediately following the last instruction of this sequence.

## Task

Write a program that implements the **Pętlik** programming language.

The program reads and executes the following commands:

- **Printing the value of a variable;**
- **Execution of a program written in the Pętlik language.**

Before the execution of the first command, the values of all variables are 0.

Variables retain their values after execution of a command. They are not reset before each execution of a program.

## Input Format

The program's input consists of a sequence of lines, each containing one command.

- A command for printing the value of a variable begins with the character `=`, followed by the name of the variable.
- A line that contains a command for executing a program contains source code in the Pętlik language.

## Output Format

The output of the program is the result of executing the commands for printing variable values.

The value of a variable is printed in decimal notation on a single line, without any insignificant leading zeroes.

The value 0 is represented by the digit `0`, and positive values start with a nonzero digit.
