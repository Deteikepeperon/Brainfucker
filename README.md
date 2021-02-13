# Brainfucker

Brainfuck Interpreter

<br>

## Setup
```
mkdir build && cd build
cmake ..

make
./brainfuck ../sample/Hello_World.bf
```

<br>

## Brainfuck commands

| Character | Meaning |
|:--:|:--|
">" | increment pointer
"<" | decrement pointer
"+" | increment value at pointer
"-" | decrement value at pointer
"." | print value at pointer to output as a character
"," | read one character from input into value at pointer
"[" | begin loop (continues while value as pointer is non-zero)
"]" | end loop

<br>

## Sample Program
```
sample/
    ├ Brainfuck.bf
    ├ Excellent.bf
    ├ FizzBuzz.bf
    ├ Hello_World.bf
    ├ OK.bf
    ├ toyoda.bf
    └ Very_poor.bf
```