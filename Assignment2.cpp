/*
Ben Moores 
23016063
168147832

Write a C++ program that simulates the MASSEY machine. The program must receive input in the form
of a text file consisting of MASSEY machine code instructions. Your program then simulates the
machine running, i.e. it works through the machine code instructions (in the correct sequence) changing
values of registers and memory locations as required. You must design appropriate output that assists a
machine code programmer to see what is going on with the machine code instructions. You should
display items such as program counter, instructions register, values of recently changed registers, and
values of recently changed memory locations. Ensure that you read through all the sections below.

Section A - input
The input to your program is a single text file containing a MASSEY machine code program.
For example, here is a typical input file where each line is a machine code instruction:

100A
1107
3209
6312
D307
43FF
E000
43EE
E000
0003

Notes about the input:
    1. The programmer using the simulation can give the file whatever name they like. It is best to read
    in the file name when you start. A typical file name would be “prog1.txt”.
    2. Each line of the file is one machine code instruction. There is no other text in the file.
    3. Make several (at least five) different files, each with a different machine code program. Test your
    program on a variety of machine code programs.
    4. Do not attempt to check for invalid input. Assume every program contains correct machine code
    instructions although a program may have logic errors, e.g. instructions in the incorrect order.

Here is an incomplete piece of code that may be useful when reading a file of hexadecimal numbers. Note
that you can input a hex number directly from the text file into the variable hexnumber.

    string filename; int hexnumber, i;
    cin >> filename;
    inputfile.open(filename.c_str(), fstream::in);
    // include code here to check if the file opened correctly
    i = 0;
    while (inputfile >> hex >> hexnumber) {
    memory[i] = hexnumber;
    i++; }

(Hint: Start off by writing a program that reads the file and displays each line on the screen.
 This is to check that your input is working correctly before you proceed to the rest of the program).


Section B – program design
Your program must use the following global variables:
int memory[256];
int reg[16]; // note: "register" is a reserved word
int pc, ir;

The array “memory” represents the memory of the MASSEY machine.
The array “reg” represents the registers of the MASSEY machine.
The variable “pc” is the Program Counter and “ir” is the Instruction Register.

Note that there should be no strings in this program (except the filename).

The basic algorithm for your program is:
    • read instructions from the file and load them into memory
    • run through the instructions and execute each instruction correctly

Notes about the program design:
    5. Study the MASSEY machine code instructions in the notes.
    6. Ensure that your input program correctly executes a valid machine code instruction.
    7. You do not have to execute instruction 5 (floating point addition) – ignore instruction 5.
    8. Do not check for invalid instructions. Only deal with valid instructions.
    9. You must have at least two functions in your program.
    10. Test extensively. Ensure that you have tested every instruction (except 5). Use machine code programs from the notes as test data.

(Hint: get your program working for a few instructions, perhaps those in the input example. When these
instructions are working correctly, expand the program to handle other instructions.)


Section C - output
The output must meet the following requirements:
    - display the full program (showing the memory locations) before executing the program
    - identify the important items to display during execution of the instructions
    - display one line for every machine code instruction (showing any changes)

Your display should look very similar to the following example:
Enter the file name of the MASSEY machine code: program1.txt
Memory[00] = 100A
Memory[01] = 1107
Memory[02] = 3209
Memory[03] = 6312
Memory[04] = D307
Memory[05] = 43FF
Memory[06] = E000
Memory[07] = 43EE
Memory[08] = E000
Memory[09] = 0003
PC: 00 IR: 100A Register R0 = 000A
PC: 01 IR: 1107 Register R1 = 0007
PC: 02 IR: 3209 Register R2 = 0003
PC: 03 IR: 6312 Register R3 = 000A
PC: 04 IR: D307 TRUE – jump to location 07
PC: 07 IR: 43EE Memory[EE] = 000A
PC: 08 IR: E000 Program halts

Notes about the output:
    11. Every number in the display is a hexadecimal number. Do not display any decimal numbers.
    12. Display all lines that have been input from the file and loaded into memory. Note that the location
    (the index) in memory is displayed as 2 digits and the contents of memory is 4 digits.
    13. Display one line of output for each machine code instruction – just after it has been executed.
    14. On each line, display the Program Counter (2 digits) and the Instruction Register (4 digits) –
    recall that the IR contains the current instruction.
    15. On each line, display any register that has changed. E.g. the first instruction above loads R0 so the
    value in R0 is displayed. The register number is 1 digit and the register contents are 4 digits.
    16. On each line, display any memory location that has changed. E.g. the instruction 43EE loads a
    value into memory location EE so the value in memory[EE] is displayed. Note that the location
    (the index) in memory is displayed as 2 digits and the contents of memory is 4 digits.
    17. Study the display for D307 (a jump instruction). There is also an alternative display which is:
    FALSE – do not jump
    18. Note the display for E000 (the halt instruction).
    19. When displaying negative numbers, ignore the required number of digits stated above. For
    example, the display for -6 usually appears as FFFF FFFA. That is fine. While it is interesting to
    think about how to display negative numbers, don’t waste time on this aspect.
(Hint: to start with, get your program reading the file, loading instructions into the memory, and then
displaying the memory locations and the instructions – first part of the output. Once this is working, then
expand the output to display the results of the instructions.) 

//opcodes - decide which methods/functions to run - colum, a
1 - Load Register with value (last 2 digits as hex)
2 - Load Register with value from other register value
3 - Load Register with value from memoy address
4 - Store value from register to memory address
5 - Add values from 2 registers into a third register location (floating point addition, do not use)
6 - Add values from 2 registers into a third register location (integer addition, use this one)
7 - Negate value in register (compliment and +1)
8 - Shift register right
9 - Shift register left
A - AND results of binary AND into third register
B - OR results of binary OR into third register
C - XOR results of binary XOR into third register
D - Jump/goto if value matches
E - Exit, final line of all programs

//operands - send the variables to the opcode method/function, columns b-d
column b - register address in hex
Column c/d - value


BONUS STUFF!!!!!!!!!!!!!

Here are some code fragments that may be useful when working on Assignment 2.
You do not have to use all of them – there are always different ways of doing things.
If you use a different approach, that is fine as long as it works correctly. Find what is
useful for you in the code fragments below and ignore the rest.

1. What is an integer value?
    int value;
    value = 65;
value is 65 (the usual display) or 41 (if displayed as hexadecimal) or the binary
number 0000 0000 0100 0001 (if using 16 bits). An integer is all these things at
once – it just depends how you display it and you cannot display the binary.

2. Extracting the second hexadecimal digit from an integer value
assume that you have loaded the full number into the variable ‘value’:
    int mask, temp;
    mask = 0x000F;
    temp = value >> 8;
    d2 = temp & mask;
mask is an integer value loaded with the binary 0000 0000 0000 1111
The hexadecimal for this particular binary mask is 000F

Load a hexadecimal value directly into an integer by placing 0x before the number
Note that when you do an AND with this mask it is designed to leave the last four
binary digits unchanged, i.e. it will leave the last hexadecimal digit unchanged. All
other digits will be converted to zero.

Shift the value 8 binary digits ( = 2 hexadecimal digits) to the right to move the
second hexadecimal digit to be the last digit. You would need a different shift for
each digit. The fourth digit would not need any shift at all.

3. Displaying an integer value as hexadecimal with upper case letters
    d2 = temp & mask;
    cout << hex << uppercase << d2 << endl;

4. Displaying an integer value with 4 digits
    value = 3;
    cout.fill('0'); cout.width(4);
    cout << value; // this will display 0003
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int memory[256];
int reg[16]; // note: "register" is a reserved word
int pc, ir, lrg;

void getprogram(), print_results();
int mask_variable(int mask,unsigned int value), opcode(int value);

class instruction_class{
    private:
        int command;
        int opcode;
        int regno;
        int operand;
    public:
        void loaddata(int ref);
        void calculate();
        void print(int count);
};

instruction_class instruction;

int main(){ // use pc instead of an i counter or it'll run through every line even if there is a jump
    //int i;
    getprogram();
    pc = 0;
    //for (i = 0; i < lrg; i++){ //PC and i won't always match, this might not be the right way to approach this - definitely where the whole thing is fucking up
    while (pc >= 0){
        //cout << "PC is " << pc << endl;
        instruction.loaddata(memory[pc]);
        instruction.calculate();
    }
}

/////////////////////////////////functions//////////////////////////////////////////
//load the program from a text file into memory
//this will take up as many memory addresses as there are lines of text
void getprogram(){
    int i;
    string filename;
    fstream program;
    cout << "Enter the file name of the MASSEY machine code: " << endl;
    cin >> filename;
    //filename = "test3.txt";////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////swap these lines over after testing
    program.open(filename.c_str(), fstream::in);
    if (program.is_open() == false) {
        cout << "ERROR: not able to open " << filename << endl;
    } else {
        i = 0;
        while (program >> hex >> ir) {
            memory[i] = ir;
            //cout << "hexnumber: " << hexnumber << endl;
            cout << "Memory[";
            cout.fill('0'); 
            cout.width(2);
            cout << right << i << "] = ";
            cout.fill('0'); 
            cout.width(4);
            cout << right << uppercase << hex << ir << endl;
            // instruction.loaddata(ir);
            //cout << "Memory: " << memory[i] << endl;
            i++; 
        }
        lrg = i;
        //cout << "used: " << pc << endl;
        // cout << "Memory: " << memory[5] << endl;
    }    
}

//get the value from each column, 0 to ignore, 1 to retrieve
int mask_variable(int mask,unsigned int value){
    int temp;
    temp = value & mask;
    return temp;
}

////////instruction class methods//////////////////////////
void instruction_class::loaddata(int command){
    ///command = memory[ref];
    //cout << "memory is: " << memory[ref] << endl;
    //cout << "command is " << command << endl;
    opcode = mask_variable(0xF000, command) >> 12;
    if ((opcode != 2) and (opcode != 7)){
        regno = mask_variable(0x0F00, command) >> 8;
        operand = mask_variable(0x00FF, command);
    }
    else{
        //cout << "weird stuff in here" << endl;
        //opcode = mask_variable(0xFF00, command) >> 8;
        regno = mask_variable(0x0F0, command) >> 4;
        operand = mask_variable(0x000F, command);
    }
//     cout << "opcode is " << opcode << endl;
//     cout << "regno is " << regno << endl;
//     cout << "operand is " << operand << endl;
}

void instruction_class::calculate(){
    int reg1, reg2;
    switch (opcode){
         case 0: if (opcode == 0){
            reg[regno] = operand;
            //cout << "Case 0" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //Load Register with value (last 2 digits as hex)
        case 1: if (opcode == 1){
            reg[regno] = operand;
            //cout << "Case 1" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //Load Register with value from other register value
        case 2: if (opcode == 2){
            reg[regno] = reg[operand];
            //cout << "Case 2" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //Load Register with value from memoy address
        case 3: if (opcode == 3){
            reg[regno] = memory[operand];
            //cout << "Case 3" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //Store value from register to memory address
        case 4: if (opcode == 4){
            //cout << "Operand is: " << operand << endl;
            memory[operand] = reg[regno];
            cout << "PC: ";
            cout.fill('0'); 
            cout.width(2);
            cout << right << pc;
            cout << " IR: ";
            cout.fill('0'); 
            cout.width(4);
            cout << right << memory[pc];
            cout << " Memory [";
            cout.fill('0'); 
            cout.width(2);
            cout << operand << "] = ";
            cout.fill('0'); 
            cout.width(4);
            cout << right << memory[operand] << endl;
            pc ++;
            break;
        }
        //Add values from 2 registers into a third register location (integer addition, use this one)
        case 6: if (opcode == 6){
            reg1 = mask_variable(0xF0, operand);
            reg2 = mask_variable(0x0F, operand);
            reg[regno] = reg1 + reg2;
            //cout << "Case 6" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //Negate value in register (compliment and +1) - - - come back to this later, should work ok but might need to uwe another method to excplicitly compliment+1 --  ok, this one is a right cunt!
        case 7: if (opcode == 7){
            //cout << "reg: " << reg[regno] << endl;
            if (reg[regno] == 0){
                pc ++;
                break;
            }
            else{
                //cout << "non-zero value" << endl;
                reg[regno] = 0 - reg[regno];
                reg[regno] = mask_variable(0xFFFF, reg[regno]);
                //cout << "value: " << reg[regno] << endl;
                //cout << "Case 7" << endl;
                instruction.print(pc);
                pc ++;
                break;
            }
        }
        //Shift register right
        case 8: if (opcode == 8){
            reg[regno] = reg[regno] >> operand;
            //cout << "Case 8" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //Shift register left
        case 9: if (opcode == 9){
            reg[regno] = reg[regno] << operand;
            //cout << "Case 9" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //AND results of binary AND into third register
        case 10: if (opcode == 0xA){
            reg1 = mask_variable(0xF0, operand);
            reg2 = mask_variable(0x0F, operand);
            reg[regno] = reg1 & reg2;
            //cout << "Case A" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //OR results of binary OR into third register
        case 11: if (opcode == 0xB){
            reg1 = mask_variable(0xF0, operand);
            reg2 = mask_variable(0x0F, operand);
            reg[regno] = reg1 | reg2;
            //cout << "Case B" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //XOR results of binary XOR into third register
        case 12: if (opcode == 0xC){
            reg1 = mask_variable(0xF0, operand);
            reg2 = mask_variable(0x0F, operand);
            reg[regno] = reg1 ^ reg2;
            //cout << "Case C" << endl;
            instruction.print(pc);
            pc ++;
            break;
        }
        //Jump to pc[#] if X matches reg[00]
        case 13: if (opcode == 0xD){
            if (reg[regno] == reg[0]){
                cout << "PC: ";
                cout.fill('0'); 
                cout.width(2);
                cout << right << pc;
                cout << " IR: ";
                cout.fill('0'); 
                cout.width(4);
                cout << right << memory[pc];
                pc = operand;
                cout << " TRUE - jump to location ";
                cout.fill('0'); 
                cout.width(2);
                cout << pc << endl;
            }
            else{
                cout << "false - continuing" << endl;
                pc ++;
            }
            break;
        }
        case 14: if (opcode == 0xE){
            //cout << "Case E" << endl;
            cout << "PC: ";
            cout.fill('0'); 
            cout.width(2);
            cout << right << pc;
            cout << " IR: ";
            cout.fill('0'); 
            cout.width(4);
            cout << right << memory[pc];
            cout << " Program halts" << endl;
            pc = -1;
        }
    }
}

void instruction_class::print(int count){
    ir = memory[count];
    cout << "PC: ";
    cout.fill('0'); 
    cout.width(2);
    cout << right << pc;
    cout << " IR: ";
    cout.fill('0'); 
    cout.width(4);
    cout << right << memory[count] << " Register R" << regno << " = " ;
    cout.fill('0'); 
    cout.width(4);
    cout << right << reg[regno]  << endl;
}