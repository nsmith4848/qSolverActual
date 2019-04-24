# validateInputs
Takes a single double value that is one element of either the input or roots array, and also takes an int 'variableSpecifier' to know which element of the array was passed.
int boolRoots is a value that is either 0 or 1 and prevents unintended behavior if a value of the roots array was passed to validateInputs, mainly producing an error if the first value of the roots array is 0.

Also takes an integer 'log' to know if logging is enabled and takes a file pointer in case it is.

validateInputs will check if a significant loss of precision occurs when the double value is converted to a float.
It does this by finding the difference of the double value to its float conversion, and comparing the absolute value of that to the product of the larger of the two numbers and FLT_EPSILON, which is a constant value representing when a relative difference is greater than one float value.

validateInputs also checks the value against isnan() and isinf() to make sure it is not NaN or an INF, as well as making sure the 'a' input is not 0

There are many return values based on what errors validateInputs finds
0 = no error
2 = a is 0
3 = NaN
4 = INF
5 = Precision loss but otherwise fine