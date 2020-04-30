# Project description
### University project for Compilation Techniques course

This is a C++ project that simulates a Recursive descent parser using a CFG(Context-free grammar).

**Input example : **

** CFG : **

  -	* S A B C * ** -> start symbol for CYG and its ne-terminals **
  - * 2 a b * ** -> number of terminals and terminals **
  - * 6 * ** -> number of tranzitions
  - 
	*S aAv*
	*S bC*
	*A aA*
	*A b*
	*C bC*
	*C C*
		** --> given transitions **

*a word : * **w**

**Output :** **_True_** *- if the string is derivable from the given grammar* or **_False_** *- otherwise.* **->** *a message will be displayed*
