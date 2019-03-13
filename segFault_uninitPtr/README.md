### Segmentation Fault (using null pointer)

This example is ~~about how using a null pointer **may** cause a segmentation fault~~ about using NULL pointers to access function members of a class.

---------------------------------------
Set-up:
- example.cpp
  - In this example, we have three classes: **Class T**, **Class CEBase**, **Class CE** (derived from **CEBase**).<br>
  - The variable **ptr_** is a **Class T** type pointer, and it is a member of the **Class CEBase**. <br>

- simpler_example.cpp (more straight-forward)
  - In this example, we have one class: **Class T** with two non-virtual public functions (func1, func2) and one virtual function (func3). <br>
    - func1 is non-virtual and does nothing but std::cout;
    - func2 is non-virtual and tries to operate on a member variable;
    - func3 is a virtual function and does nothing but std::cout;
  - a T type NULL pointer could access func1 successfully, while trying to access func2 and func3 would cause a seg fault.

---------------------------------------

Takeaway:
- When **ptr_** is **NULL**:
  - the non-virtual function members of **Class T** can still be accessed without any problem;
  - but trying to access the variable members would cause a segmentation fault; 
  - but trying to access the virtual function members would cause a segmentation fault; 
