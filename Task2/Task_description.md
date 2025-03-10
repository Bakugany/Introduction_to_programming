Introduction

The Lindenmayer system, abbreviated as L-system, is a formal system defining languages. It was created by the biologist Aristid Lindenmayer for the purpose of modeling plants.

A deterministic context-free L-system, called D0L, is a triple (S, A, R), where S is an alphabet, A is a word over S called the axiom, and R is a set of replacement rules that associate symbols with words over S. For each element in S, there is at most one rule in R.

A word w belongs to the language defined by the L-system if and only if there exists a non-negative integer n such that w has a derivation of length n. We assume that the axiom has a derivation of length 0. A word with a derivation of length n + 1 is obtained from a word with a derivation of length n by simultaneously replacing each symbol with the word specified by its rule, or by leaving it unchanged if no rule exists for it.

We consider a textual interpretation of the words of the language defined by the L-system. The interpretation begins with a sequence of lines called the prologue, followed by a sequence of lines corresponding to the individual symbols of the word, and ends with a sequence of lines called the epilogue. The lines corresponding to the symbols are defined by interpretation rules. For each symbol, there is at most one interpretation rule. Symbols in the word for which no interpretation has been defined are omitted.

Task

Write a program that reads from the input the derivation length, the description of the L-system, and its interpretation, and then outputs the interpretation of the derived word that belongs to the language defined by the L-system.
