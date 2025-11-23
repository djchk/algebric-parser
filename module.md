### Algebric Parser
Simple OOP C++ implementation of an algebraic expression parser
- Supports: numbers (int/float), identifiers (variables), binary operators + - * /,
- unary + and -, parentheses

so here I have to first start with writing tokens.
Late realization : I think I should implement a custom display format for debugging of tokens.

- Idea is to implement the recursive-descent algorithm for parsing but the code is modular .

### BCNF Grammar for the parser
- exp -> term ((+ | -) term)*
- term -> factor ((* | /) factor)*
- factor -> unary
- unary -> (+ | -) unary | primary
- primary -> NUM | VAR | ( exp )

this is the basic Idea till now where we can parse the basic algebraic eqns with podmas precedences

- Till now we have a symbolic math engine that can parse any f(x) into an AST
- Now I have multiple choice of things to build on the top of it as this is essentially nothing but tree traversal algorithm