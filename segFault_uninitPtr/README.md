### Segmentation Fault (using null pointer)

This example is ~~about how using a null pointer **may** cause a segmentation fault~~ about using NULL pointers to access function members of a class.

---------------------------------------
Set-up:
- example.cpp
  - In this example, we have three classes: **Class T**, **Class CEBase**, **Class CE** (derived from **CEBase**).<br>
  - The variable **ptr_** is a **Class T** type pointer, and it is a member of the **Class CEBase**. <br>

- simpler_example.cpp
  - In this example, we have one class: **Class T** with two non-virtual public functions (func1, func2) and one virtual function (func3).<br>

---------------------------------------

Takeaway:
- When **ptr_** is **NULL**:
  - the non-virtual function member of **Class T** can still be accessed without any problem;
  - but trying to accesse the variable member would cause a segmentation fault; 
