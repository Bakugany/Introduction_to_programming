Introduction

We consider an implementation of the Pętlik programming language. The syntax of the language is described by the following grammar with the start symbol Program:

Program → InstructionSequence
InstructionSequence → ε | InstructionSequence Instruction
Instruction → Increment | Repeat
Increment → Variable
Repeat → '(' Variable InstructionSequence ')'
Variable → 'a' | ... | 'z'

The program consists only of those characters that are enclosed in apostrophes in the grammar. No other characters—even spaces or line breaks—may appear in the source code.

The program has access to 26 variables, whose values are non-negative integers.

The instructions derived from the symbol InstructionSequence are executed sequentially from the first to the last.

The Increment instruction, written as a variable, is equivalent to the following C instruction:

  ++variable;

The Repeat instruction, written in the form (variable ...), is equivalent to the following C instruction:

  while (variable > 0) {
    --variable;
    ...
  }

The implementation of the language consists of an optimizing compiler, which generates code for a virtual machine, and an interpreter for the code of that machine.

The machine executes the following instructions:

  INC Variable (increment)
    Increments the value of the variable by one;

  ADD Variable0 Variable1 (add)
    Adds the value of Variable1 to Variable0;

  CLR Variable (clear)
    Resets the variable to zero;

  JMP Address (jump)
    Jumps to the instruction at the given address;

  DJZ Variable Address (decrement or jump if zero)
    If the variable is zero, jumps to the instruction at the given address; otherwise, decrements the variable by one;

  HLT (halt)
    Terminates program execution.

The execution of a program in machine language begins with the first instruction.

Unless specified otherwise, after executing an instruction, the machine proceeds to the next instruction in the code.

For an instruction sequence, the compiler generates code in the order from the first to the last instruction. The generated code for the program ends with an HLT instruction.

If a Repeat instruction does not contain a nested Repeat—i.e. if the parentheses contain a sequence of variables Variable0, ..., VariableN (for N ≥ 0), and if none of the variables Variable1, ..., VariableN is the same as Variable0—then the compiler generates optimized code of the following form:

  ADD Variable1 Variable0
  ...
  ADD VariableN Variable0
  CLR Variable0

If the conditions required for generating optimized code are not met, the compiler generates the standard code.

The standard code for an Increment instruction (of the form Variable) is:

  INC Variable

The standard code for a Repeat instruction (of the form (Variable ...)) is:

  DJZ Variable End
  ...
  JMP Start

where Start is the address of the first instruction in the sequence and End is the address of the instruction immediately following the last instruction in the sequence.

Command

Write a program that implements the Pętlik language.

The program reads and executes commands for:

  - printing the value of a variable, and
  - executing a program written in the Pętlik language.

Before executing the first command, all variables are initialized to 0.

The variables retain their values between commands; they are not reset before each program execution.
