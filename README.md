# Four-Opertations-Interpreter
Demo of principle of compiler , simpe interpreter of four opertations - 编译原理示例，四则运算的解释器

```
$ ./Four-Opertations-Interpreter 1.2+3.4*(5.6/-7.8)+9.0
7.758974
```

## Extended Backus–Naur Form
```bnf
<expression> ::= <term> {(ADD|SUB) <term>}

<term> ::= <factor> {(MUL|DIV) <factor>}

<factor> ::= NUMBER | ({ADD|SUB} <factor>) | (LEFT_BRACKET <expression> RIGHT_BRACKET)
```