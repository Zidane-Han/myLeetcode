## Bitwise Operator
https://www.tutorialspoint.com/python/bitwise_operators_example.htm
- **&**             
(AND: operator copies a bit to the result if it exists in both operands)
```python
a = 60        # 60 = 0011 1100
b = 13        # 13 = 0000 1101

c = a & b     # 12 = 0000 1100
```
- **|** 
(OR: it copies a bit if it exists in either operand)
```python
c = a | b     # 61 = 0011 1101
```
- **^** (XOR: it copies the bit if it is set in one operand but not both)
```python
c = a ^ b     # 49 = 0011 0001
```
- **~** (Ones Complement: it is unary and has the effect of 'flipping' bits)
```python
c = ~a     # -61 = 1100 0011
```
- **<<** (Left Shift: the left operands value is moved left by the number of bits specified by the right operand)
```python
c = a << 2     # 240 = 1111 0000
```
- **>>** (Right Shift: the right operands value is moved right by the number of bits specified by the right operand)
```python
c = a >> 2     # 15 = 0000 1111
```