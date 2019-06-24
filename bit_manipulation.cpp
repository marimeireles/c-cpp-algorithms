/**
You are given two 32-bit numbers, N and M, and two bit positions,
i and j Write a method to set all bits between i and j in N equal to M
(e g , M becomes a substring of N located at i and starting at j)
EXAMPLE:
Input: N = 10000000000, M = 10101, i = 2, j = 6
Output: N = 10001010100
**/

int bitCounter(int x) {
    int counter = 0;
    int comparator = 1;
    
    for(int i = 0; i < 32; i++){
        if((x & comparator) != 0) {
            counter++;
        }
        comparator = comparator << 1;
    }

    return counter;
}


void printBinary(int number)
{

    int numberOfBits = sizeof(number)*8;
    int comparator;

    for (int i = numberOfBits-1; i >= 0; --i)
    {
        comparator = number >> i;
        if(comparator & 1) {
            printf("1");
        }
        else
            printf("0");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    long int n = 10000000000;
    int m = 10101;
    int i = 2;
    int j = 6;
    m = m << 2;
    printBinary(m);
    return 0;
}