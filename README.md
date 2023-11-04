# Pseudo 
```the pseudo coding language```
___

## Introduction
The **Pseudo** language is a (*CONCEPTUAL*) human-readable, high-level programming language designed for easy transcompilation into multiple target languages. 

**Pseudo** aims to provide a simple and flexible way to write code that can be easily translated into various programming languages, enabling developers to focus on the core logic without being tied to a specific language syntax.  

This document specifies the key components, grammar, and language abilities of **Pseudo**.  
___


## 1. Key Symbols
The following key symbols are used in **Pseudo**:

`|`:  Denotes scope of blocks of code.  
> Vertically aligned `|` characters indicate scope.  
> Can be stacked horizontally to indicate nesting.  
  
`#`:  Decorator for specifying target language(s) for transcompilation.  
  
`%`:  Decorator for decompiling code from the source language into **Pseudo**.  
> Outputs the **Pseudo** code that corresponds to the provided code.  
  
`>`:  Used with % to indicate the direction of decompilation.  
> The code is decompiled or transpiled from the left to the right language.  
  
`$`:  Decorator for running code in the **Pseudo** compiler.  
> The code is executed as if it were run.  
> The source code is not transcompiled.  
  
  
___

## 2. Scoping
Block scopes are denoted by vertically aligned `|` characters. Whitespace between pipes is used only for alignment. Decorators can be stacked in scope to pipeline code across languages.  
Expression scopes are denoted by parenthesis blocks, opened with `(` and closed with `)`. Expression scopes can be nested, and will be passed into usage first, then evaluated from the inner-most out.

Examples:

### 2.1 Decompiling and running code
Input:
```
$
|%python3>pseudo
||print("Hello, world!")
```
**Pseudo** midstate:
```
| say "Hello, world!"
```
Output:
```
Hello, world!
```
### 2.2 Transcompiling into a target language
Input:
```
#python3
| say "The number is ", ( 1 + 1 )
```
Output:
```
print(f"The number is {( 1 + 1)}")
```
___

## 3. Grammar and Language Abilities
**Pseudo** uses a natural language based grammar, in the Subject Object Verb form.
**Pseudo** supports the following language constructs and abilities:

### 3.1 Variables
#### Creation, assignment, and manipulation:
```
the _1
```  
: Article system used to denote specificity of `_1`. Used in conjunction with verbs for declaration and manipulation.

```
the _1 is _2
```  
: Declares a mutable variable with a name `_1` containing the value `_2`. Can be written in multiple lines with `|` scoping.

```
the _1 is a _2
```
: Declares a variable `_1` of `_2` type, limiting its scope.

```
the _1 is always a _2
```
: Declares an immutable variable with a name `_1` containing the value `_2`. The value of `_1` cannot be changed hence.


### 3.2 User Input
#### Receiving and validating input
```
ask
```
: Built-in input function that gets user input

```
the _1 is _2 asked
```
: Requests user input with the status message `_2` and sets the variable `_1` to its value

### 3.3 Output
#### Printing to console
```
say _1
```
: Outputs the contents of the variable `_1`
```
say _1, _2, _3
```
: Outputs the concatenation of the variables `_1`, `_2`, and `_3`.

### 3.4 Arithmetic Operations
#### Basic arithmetic such as addition, subtraction, multiplication, and division
Can be stated with mathematical symbology or through built-in verbs ('`add`', '`subtract`', '`multiply`', etc.), which are mapped to their corresponding operators.

### 3.5 Conditionals
#### if, elif, and else
```
if _1
| _2
```
: Checks the boolean truth of case `_1` and executes scoped code `_2` if case `_1` is met.

```
_1 is _2
```
: Value checks `_1` against `_2` and returns boolean if they contain the same value, boolean false if different

```
_1 is a _2
```
: Type checks `_1` against `_2` type and returns boolean if they align, false otherwise.


### 3.6 Loops
#### for and while loops
```
for _1 from _2
| _3
```
: Executes scoped code `_3` for each iteration in `_2` as the ephemeral variable `_1`.
```
for _1 from _2 to _3
| _4
```
: Executes scoped code `_4` for each iteration in the range `_2` to `_3` as the ephemeral variable `_1`.

```
while _1
| _2
```
: Executes scoped code `_2` while the case `_1` is met.

```
until _1
| _2
```
: Executes scoped code `_2` until the case `_1` is met.

### 3.7 Functions, Classes, and Objects
#### Definition, instantiation, and invocation with or without parameters and return values
```
a _1 takes _2, _3, _4
| _5
| gives _6
```
: Declares a function of name `_1`, that accepts variables `_2` `_3` `_4`, does some processing `_5`, and returns `_6`


```
a _1 is a _2 takes _3a
| with _3a as _3b
| gives this _1
```
: Declares a class of name `_1` with typing `_2`, that accepts variable `_3a` and assigns it to the object's `_3b`.
Returns this object when instantiated. As seen in this example, verbs are in present tense, stating that it is to be done when called. This tensing is only used when verbs are used inside of function method or class scopes.

```
a _1 takes _2
| says _2

_3 _1ed
```
: Declares a function of name `_1` that accepts variable `_2` and prints it. `_1` is then called on the value of `_3`. functions are called with the past-tense suffix `ed`. Due to the Subject-Object-Verb ordering, parameters are given to functions in that order when called. This implementation can be seen in the use of `asked`, or, see the following examples for further clarification. All functions and methods are called in this manner.

### Examples:
#### Example 1: simple echo program
```
a echo takes variable
| says variable

"echo!" echoed
```
This program outputs "echo!" to the screen with no return. 

#### Example 2: factorial:
```
a factorial takes n
| if n is 0
|| gives 1
| gives n times ( n minus 1 ) factorialed


the num is "Enter a number: " asked
the result is num factorialed
say "Factorial of ", num, " is ", result
```
This program outputs the factorial of the inputted number in the form of the statement "Factorial of _number is _result"

