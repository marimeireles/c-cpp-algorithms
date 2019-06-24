#include <string>

int fibonacci(int x)
{
    if (x == 0)
    {
        return 0;
    }
    if (x == 1 || x == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(x-1) + fibonacci(x-2);
    }
}

string string_permutation(string s)
{

}

int main(int argc, char const *argv[])
{
    printf("%d", fibonacci(5));
    return 0;
}

//to completely cover a grid I can
//treat the paths as x and y
// I'll need a array<point> where point = x,y
// I need to create a function that receives coordinates x, y
// then I add this point to the current path I'm going
// I do an if, if both x and y equal 0, then return true
// if I can't go ahead (e.g if I have a x or y negative)
// then I have to quit that way. 
// Inside each if I call the function again.
// Eventually it will explore every possible position.
//O(n)!

to permute every word in an array I can
receive a string I want to permute
create an array of permutations
get the first letter of the string I want to permute
remove the first char of the string I want to permute
and put it in a string variable with the remainders
call the function again using the string I just created that contain the remainders
and put it in a words array
once my string == 0 I'll be in the on my base case
where I return the permutations string

