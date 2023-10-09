# push_swap
My fifth proyect at 42. An algorithm that uses a limited list of instructions to sort a stack with the lowest number of actions.

## Instruction list
Command	Name	Description
sa	Swap a	Swaps the first two numbers of stack a
sb	Swap b	Swaps the first two numbers of stack b
ss	Swap a + swap b	Does sa and then sb
pa	Push a	Moves the first number of stack b to the top of stack a
pb	Push b	Moves the first number of stack a to the top of stack b
ra	Rotate a	Moves the last number of stack a to the top of stack a
rb	Rotate b	Moves the last number of stack b to the top of stack b
rr	Rotate a + Rotate b	Does ra and then rb
rra	Reverse rotate a	Moves the first number of stack a to the bottom of stack a
rrb	Reverse rotate b	Moves the first number of stack b to the bottom of stack b
rrr	Reverse rotate a + Reverse rotate b	Does rra and then rrb
