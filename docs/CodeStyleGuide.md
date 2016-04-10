# Code Style Guide
Every contributor has to follow this code style. That will unify the source code and create simple, clear and fully readable source code.

### Header comment
Each file should contain the same header with copyrights.
```
/*
* Counter Strike 2D
*
* (c) 2016 Jakub Powierza & Karolina Olszewska
*
*/
```

### Class definition
For class definition use BigCamelCase.
```
class ThisIsExampleClass {};
```

### Method definition
For method definition use lowCamelCase.
```
void doSomethingUseful();
```

### Getters
It should follow method definition style, plus it has to start with 'get'.
```
int getSomething();
```

### Setters
As above, but this time it should start with 'set' and return void.
```
void setSomething(int value);
```

### Class instance variables
These should start with 'm_' and then follow lowCamelCase.
```
int m_nameOfTheVariable;
```

### Arguments
Arguments passed to functions and class methods has to follow lowCamelCase.
```
void methodThadDoesSomething(int firstArgument, string secondArgument);
```

### Sections
If you want to divide part of your code with separator or wrap some functions with section comment, use the following style:
```
//================================================================================
// Header for this section
//================================================================================
```