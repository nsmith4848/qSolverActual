# getLine
getLine takes an array of doubles of size 3 as input, and an integer 'NLINE' which dictates the allowed length of a line of user input.
Also takes an integer 'log' to know if logging is enabled and takes a file pointer in case it is.

getLine will print out a help statement if 'help' is input, otherwise it will attempt to store three space separated numbers in each element of the supplied array.
Returns a value that shows what actions was taken based on user input.
-1 = help was input
-2 = quit was input
 1 = The user did not input three values

Any letters input will be assumed to be 0, as long as it's not the word 'help' or 'quit' 