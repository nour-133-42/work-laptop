This project has been created as part of the 42 curriculum by <nalshmai>

Description:
    in push_swap you have tow stacks a and b, and the program will be given a.
    and using certen operations that the program will execute and print it will sort the element in the stack 

    the operations;
        sa (swap a): Swap the first 2 elements at the top of stack a.
            Do nothing if there is only one element or none.
        sb (swap b): Swap the first 2 elements at the top of stack b.
            Do nothing if there is only one element or none.
        ss : sa and sb at the same time.
        pa (push a): Take the first element at the top of b and put it at the top of a.
            Do nothing if b is empty.
        pb (push b): Take the first element at the top of a and put it at the top of b.
            Do nothing if a is empty.
        ra (rotate a): Shift up all elements of stack a by 1.
            The first element becomes the last one.
        rb (rotate b): Shift up all elements of stack b by 1.
            The first element becomes the last one.
        rr : ra and rb at the same time.
        rra (reverse rotate a): Shift down all elements of stack a by 1.
            The last element becomes the first one.
        rrb (reverse rotate b): Shift down all elements of stack b by 1.
            The last element becomes the first one.
        rrr : rra and rrb at the same time.

    I have used an algorithm called turk, there will be a link below of an article that shows how it works, and I implemented it using that article, if that is not enough:

    ██████╗ ████████╗███████╗███═╗  ███╗
    ██╔══██╗╚══██╔══╝██╔════╝████║ ████║
    ██████╔╝   ██║   █████╗  ██╔████╔██║
    ██╔══██╗   ██║   ██╔══╝  ██║ ██╔╝██║
    ██║  ██║   ██║   ██║     ██║ ╚═╝ ██║
    ╚═╝  ╚═╝   ╚═╝   ╚═╝     ╚═╝     ╚═╝


Instructions:
    1- check the normination by typing "norminette" in the terminal.
    2- start compiling using make by typing "make" in the terminal this will make an executable named "push_swap" you will test the code with.
    3- now test the code by using the tests in the evaluation sheet or make your own tests, and thare is a checker file that will be used in the evaluation this file is used to test the code.

Resources:
    1- an article of how turk algorithm works "https://medium.com/@ayogun/push-swap-c1f5d2d41e97"
    2- I used AI to implement the basic functions that I understood before hand, but the main algo I implemented it by my self.
    