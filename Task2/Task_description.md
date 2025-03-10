# Introduction

The Lindenmayer System, abbreviated as L-system, is a formal system that defines languages. It was created for modeling plants by the biologist Aristid Lindenmayer.

A deterministic context-free L-system, called D0L, is defined as a triple (S, A, R), where S is an alphabet, A is a word over S called the axiom, and R is a set of rewriting rules that associate symbols with words over S. For each element of S, there is at most one rule in R.

A word w belongs to the language defined by the L-system if and only if there exists a nonnegative integer n such that w has a derivation of length n. We assume that the axiom has a derivation of length 0. A word with a derivation length of n+1 is obtained from a word with a derivation length of n by simultaneously replacing each symbol with the word specified by its rule, or leaving it unchanged if no rule is provided.

We consider a textual interpretation of the words defined by an L-system. The interpretation starts with a sequence of lines, called the prolog, followed by a sequence of lines corresponding to the individual symbols of the word, and ends with a sequence of lines called the epilog. The lines corresponding to the symbols are determined by interpretation rules. For each symbol, there is at most one interpretation rule. Symbols for which no interpretation is specified are omitted.

## Task

Write a program that reads from the input a derivation length, a description of an L-system, and its interpretation rules, and writes to the output the interpretation of the derived word belonging to the language defined by the L-system.

### Input Format

- The input begins with a line containing a nonnegative integer specifying the derivation length.
- This is followed by lines describing the L-system and lines describing the interpretation of the word.

The L-system description consists of:
- A line containing the axiom.
- A sequence of lines with rewriting rules. Each rewriting rule line starts with the symbol to be replaced, followed by the word that replaces it. The alphabet of the L-system is not explicitly given; it is assumed to be the set of symbols that appear in the axiom and in the rewriting rules.

The description of the word's interpretation consists of:
- A sequence of prolog lines,
- Followed by a sequence of interpretation rule lines,
- And then a sequence of epilog lines.

Each of these three sequences is preceded by an empty line. An interpretation rule line starts with the symbol to be interpreted, and the rest of the line is the text that should be output for that symbol.

### Output Format

The output of the program is a sequence of lines that represents the interpretation of the derived word.
