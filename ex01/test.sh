#!/bin/bash

echo "========================================"
echo "         RPN TEST SUITE"
echo "========================================"
echo

echo "===== 1. Basic addition: \"8 2 +\" | Expected result: 10 ====="
./RPN "8 2 +"
echo

echo "===== 2. Basic subtraction: \"8 9 -\" | Expected result: -1 ====="
./RPN "8 9 -"
echo

echo "===== 3. Basic multiplication: \"8 9 *\" | Expected result: 72 ====="
./RPN "8 9 *"
echo

echo "===== 4. Basic division: \"8 2 /\" | Expected result: 4 ====="
./RPN "8 2 /"
echo

echo "===== 5. Subtraction order: \"9 2 -\" | Expected result: 7 ====="
./RPN "9 2 -"
echo

echo "===== 6. Division order: \"8 4 /\" | Expected result: 2 ====="
./RPN "8 4 /"
echo

echo "===== 7. Multiple operations: \"7 2 4 + -\" | Expected result: 1 ====="
./RPN "7 2 4 + -"
echo

echo "===== 8. Multiple operations: \"5 2 * 3 +\" | Expected result: 13 ====="
./RPN "5 2 * 3 +"
echo

echo "===== 9. Intermediate result greater than 9: \"8 9 * 2 /\" | Expected result: 36 ====="
./RPN "8 9 * 2 /"
echo

echo "===== 10. Negative intermediate result: \"2 8 - 3 +\" | Expected result: -3 ====="
./RPN "2 8 - 3 +"
echo

echo "===== 11. Zero result: \"4 4 -\" | Expected result: 0 ====="
./RPN "4 4 -"
echo

echo "===== 12. Zero as operand: \"0 5 +\" | Expected result: 5 ====="
./RPN "0 5 +"
echo

echo "===== 13. Integer division: \"7 2 /\" | Expected result: 3 ====="
./RPN "7 2 /"
echo

echo "===== 14. Longer expression: \"1 2 + 3 * 4 -\" | Expected result: 5 ====="
./RPN "1 2 + 3 * 4 -"
echo

echo "===== 15. Complex expression: \"8 9 * 9 - 9 - 9 - 4 - 1 +\" | Expected result: 42 ====="
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
echo

echo "========================================"
echo "              ERROR TESTS"
echo "========================================"
echo

echo "===== 16. Not enough operands: \"8 +\" | Expected result: Error ====="
./RPN "8 +"
echo

echo "===== 17. Operator first: \"+\" | Expected result: Error ====="
./RPN "+"
echo

echo "===== 18. Two operators: \"8 2 + +\" | Expected result: Error ====="
./RPN "8 2 + +"
echo

echo "===== 19. Too many operands: \"7 2 4 1 -\" | Expected result: Error ====="
./RPN "7 2 4 1 -"
echo

echo "===== 20. Only operands: \"1 2 3\" | Expected result: Error ====="
./RPN "1 2 3"
echo

echo "===== 21. Division by zero: \"8 0 /\" | Expected result: Error: division by zero ====="
./RPN "8 0 /"
echo

echo "===== 22. Division by calculated zero: \"8 4 4 - /\" | Expected result: Error: division by zero ====="
./RPN "8 4 4 - /"
echo

echo "===== 23. Invalid character: \"8 a +\" | Expected result: Error ====="
./RPN "8 a +"
echo

echo "===== 24. Invalid symbol: \"8 2 %\" | Expected result: Error ====="
./RPN "8 2 %"
echo

echo "===== 25. Multi-digit operand: \"10 2 +\" | Expected result: Error ====="
./RPN "10 2 +"
echo

echo "===== 26. Negative input operand: \"-2 3 +\" | Expected result: Error ====="
./RPN "-2 3 +"
echo

echo "===== 27. Decimal operand: \"2.5 3 +\" | Expected result: Error ====="
./RPN "2.5 3 +"
echo

echo "===== 28. Empty expression: \"\" | Expected result: Error ====="
./RPN ""
echo

echo "===== 29. Spaces only | Expected result: Error ====="
./RPN "     "
echo

echo "===== 30. No argument | Expected result: Error: invalid number of arguments. ====="
./RPN
echo

echo "===== 31. Too many arguments | Expected result: Error: invalid number of arguments. ====="
./RPN "8 2 +" "3"
echo

echo "===== 32. Missing quotes: 8 2 + | Expected result: Error: invalid number of arguments. ====="
./RPN 8 2 +
echo

echo "===== 33. Missing quotes with longer expression: 8 9 * 2 / | Expected result: Error: invalid number of arguments. ====="
./RPN 8 9 "*" 2 /
echo

echo "===== 34. Alphabetic operand: \"a\" | Expected result: Error ====="
./RPN "a"
echo

echo "===== 35. Alphabetic operand in expression: \"8 a +\" | Expected result: Error ====="
./RPN "8 a +"
echo

echo "===== 36. Uppercase alphabetic operand: \"8 A +\" | Expected result: Error ====="
./RPN "8 A +"
echo

echo "===== 37. Word as operand: \"8 hello +\" | Expected result: Error ====="
./RPN "8 hello +"
echo

echo "===== 38. Number 10 as input operand: \"10 2 +\" | Expected result: Error ====="
./RPN "10 2 +"
echo

echo "===== 39. Number greater than 10: \"11 2 +\" | Expected result: Error ====="
./RPN "11 2 +"
echo

echo "===== 40. Large input number: \"42 2 +\" | Expected result: Error ====="
./RPN "42 2 +"
echo

echo "===== 41. Very large input number: \"999 2 +\" | Expected result: Error ====="
./RPN "999 2 +"
echo

echo "===== 42. Multi-digit zero: \"00 2 +\" | Expected result: Error ====="
./RPN "00 2 +"
echo

echo "===== 43. Decimal operand: \"2.5 3 +\" | Expected result: Error ====="
./RPN "2.5 3 +"
echo

echo "===== 44. Invalid symbol: \"8 % 2\" | Expected result: Error ====="
./RPN "8 % 2"
echo

echo "===== 45. Parentheses: \"( 8 2 + )\" | Expected result: Error ====="
./RPN "( 8 2 + )"
echo

echo "===== 46. Attached tokens: \"8 2+\" | Expected result: Error ====="
./RPN "8 2+"
echo

echo "===== 47. Attached expression: \"82+\" | Expected result: Error ====="
./RPN "82+"
echo

echo "========================================"
echo "          END OF TEST SUITE"
echo "========================================"
