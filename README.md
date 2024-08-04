This is a Password_Generator

What does it do?

It generates a random password that is 15 charachters long with a dash after the 5th and 10th chrachter
Like so: 42O77-olL7i-IsVv2
Use it as you please

How it works?

The following functions help to generate a random password:
    1. vector<int> genUps()
    2. vector<int> genLows()
    3. vector<int> genNums()
    4. string asciiConverter(int num)
    5. string intToStr(int num)
    6. void shuffleVector(vector<string>& vec)
    7. vector<string> genPass()
    
Below are explanations on how the functions work:

    - The first 3 functions start by creating a vector of a specified size

        - These functions then seed the current time using srand() and time(NULL)
        - Then they go through a loop that iterate through as many times as the size of
        our specified vector and generates a random numbers each time
        - genUps generates numbers between 65-90 to correspond with the ascii charts
        uppercase letter values of 65-90 inclusively
        - genLows generates numbers between 97-122 to correspond with the ascii charts
        lowercase letter values of 97-122
        - genNums generates numbers between 0-9 to use as the number portion of the passwords

    - Functions 4 and 5 convert the numbers generated into either string letters or the
    string representation of the integer

        - asciiConverter would take the numbers generated from genUps and genLows and return
        the corresponding uppercase/lowercase letters for those numbers
        - intToStr take the nuts generated from nums() and change the type from integer to
        string

    - Function 6, shuffleVector(), simply takes a vector as an input and shuffles the elements
    of the vector around
    

    genPass() function:
    
    - In our genPass function we create three vectors and initialize them to hold the vector
    of numbers returned from our first 3 functions; genUps, genLows, and genNums
    - Next we create an empty vector called passWord
    - Then we pass the vectors holding the uppercase ascii values and lowercase ascii values
    into a for loop that uses the ascii converter function to convert them into the lowercase
    and uppercase chars that we use in the password and then add them to our passWord vector
    - We do the same thing with the vector storing our integer nums that we convert to strings
    to store in our passWord vector
    - Next we pass the passWord vector into the shuffleVector() function to rearrange and mix up
    all of the items in the vector randomly
    - Then we insert two dashes into the vector to get the desired password format
    - And lastly we return our final and complete passWord vector
    
    int main() program:
    
    - In our main function we create a string vector and set it equal to the vector the is returned
    from genPass
    - We then simply print our password using a for loop to the right of a message that reads
    “Here’s a random password: “
    
    Note to future self or fellow programmer:
    
    Hi, ;}
