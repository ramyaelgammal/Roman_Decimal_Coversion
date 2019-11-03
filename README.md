# Roman_Decimal_Coversion
This C++ program converts from Roman to Decimal and vice versa, using TDD approach while developing.

Roman Coversion
===============
- RomanNumerals is responsible for conversion to decimal
- Starting from leftmost to the rightmost, it takes each symbol and converts it to the equivalent decimal value.
- In case current symbol's value is greater than or equal (>=) the next symbol's value 
  - it adds each symbol decimal values accumulatively to get the decimal equivalent.
- Otherwise: it subtract this value from the next symbol's value and add to the total.
- Example: 
      
      XVI = 10 + 5 + 1 = 16
      XIV = 10 + (5 - 1) = 14
      where X = 10, V = 5, I = 1
 - Maximum allowed value is 10000 = MMMMMMMMMM [10 Ms]
 
 Decimal Conversion
 ==================
 - DecimalNumerals is the class responsible for conversion to Roman
 - There are 13 Roman unique symbols collection:
   - [I : 1],   [IV : 4], [V : 5],   [IX : 9], [X : 10],  [XL : 40] ,[L : 50],
     [XC : 90], [C : 100] [CD : 400] [D : 500] [CM : 900] [M : 1000]
     
  - Taking the decimal number then start iterating on the above list from right to left i.e. from 1000 till reaching to 1.
  - Each time if there is quotient not equal to zero then repeat that symbol as many times as the quotient is.
  - then take the remainder to divide on the next symbol value.
  - It is like how many symbols of this value the decimal value has then add as many symbol of this value.
  
  Example: 
  
    | Remainder     | Div        | Quotient | Symbol
    | ------------- |------------| -------- |-------- 
    | 2464          | 2464/1000  |  2       | MM
    | 464           | 464/900    |  0       |
    | 464           | 464/500    |  0       |
    | 464           | 464/400    |  1       | CD
    | 64            | 64/100     |  0       | 
    | 64            | 64/90      |  0       | 
    | 64            | 64/50      |  1       | L
    | 14            | 14/40      |  0       |
    | 14            | 14/10      |  1       | X
    | 4             | 4/9        |  0       |
    | 4             | 4/5        |  0       | 
    | 4             | 4/4        |  1       | IV
    Roman Equivallent is MMCDLXIV
           
           
Run the Application
===================
  
once you run the application a prompt shall be shown as follows:

    Roman to Decimal Conversion and vice-versa:
       - Press 't' to run test cases
       - Press 'r <Roman Numeral>'to convert to a Decimal Number ex.: r XI ==> 11
       - Press 'd <Decimal Number>'  to convert a Decimal Number to Roman Numeral
    Please enter a choice:
  
 - to convert from Roman type 'r' followed by the Roman symbols
 
       Ex. r MMDCCLXII 
       should get Equivalent Roman Numeral is: 2762
       
  - to convert from Decimal type 'd' followed by the Decimal number
    Example:      
            
        d 5435
        Equivalent Decimal Number is: MMMMMCDXXXV
  - last option 't' is to list all the test cases used in TDD [Test Driven Development] way used in developing
    this application. Each test case helped adding more conditions, fixing algorithm bugs, and prevent program runtime
    crashing.
    - Provide test cases to test:
       - the Roman/Decimal conversion according to the mehtods mentioned above.
       - passing float, negative numbers, or numbers off limit 10000 to Decimal conversion.
       - the Roman boundaries like XIV and XVI to make sure the conversion method work.
       - input of garbage strings, it helped in adding try catch statement and a validator function.
       - invalid patterns like XMM, X cannot be before M.

Notes:
-----
- Tested on linux and windows, run the same.
- compiled using g++ in linux and Microsoft Visual Studio community edition in Windows
- Used internet search for the idea of conversion and the Regex used to test the validity of a Roman number
  against.


   




