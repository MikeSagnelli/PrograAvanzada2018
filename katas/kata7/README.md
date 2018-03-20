###  The Goal

Batman will look for the hostages on
 a given building by jumping from one window to another using his 
grapnel gun. Batman's goal is to jump to the window where the hostages 
are located in order to disarm the bombs. Unfortunately he has a limited
 number of jumps before the bombs go off...

###  Rules

Before each jump, the 
heat-signature device will provide Batman with the direction of the 
bombs based on Batman current position: ![Image](https://www.codingame.com/fileservlet?id=1429015102200)

- U (Up)
- UR (Up-Right)
- R (Right)
- DR (Down-Right)
- D (Down)
- DL (Down-Left)
- L (Left)
- UL (Up-Left)
  

Your mission is to program the device so that **it indicates the location of the next window Batman should jump to** in order to reach the bombs' room **as soon as possible**.  
  

Buildings are represented as a rectangular array of windows, the window in the** top left corner of the building is at index (0,0)**.

###  Note

For some tests, **the bombs' location may change from one execution to the other**: the goal is to help you find the best algorithm in all cases.  
  

The tests provided are similar to the validation tests used to compute the final score but remain different.

###  Game Input

The program must first read the initialization data 
from standard input. Then, within an infinite loop, read the device data
 from the standard input and provide to the standard output the next 
movement instruction.

Initialization input

Line 1 :  2 integers 

W H. The (

W, 

H) couple represents the width and height of the building as a number of windows.

Line 2 :  1 integer 

N, which represents the number of jumps Batman can make before the bombs go off.

Line 3 :  2 integers 

X0

Y0, representing the starting position of Batman.

Input for one game turn

The direction indicating where the bomb is.

Output for one game turn

A single line with 2 integers 

X

Y separated by a space character. (

X, 

Y) represents the location of the next window Batman should jump to. 

X represents the index along the horizontal axis, 

Y represents the index along the vertical axis. (0,0) is located in the top-left corner of the building.

Constraints

1 ≤ 

W ≤ 10000  

1 ≤ 

H ≤ 10000  

2 ≤ 

N ≤ 100  

0 ≤ 

X, 

X0 &lt; W  

0 ≤ 

Y, 

Y0 &lt; H  

Response time per turn ≤ 150ms  

Response time per turn ≤ 150ms

Example

Initialization input

10 10     _Building has 100 windows (10x10)_
6         _Batman has 6 jumps to find the bombs_
2 5       _Batman starts at position (2,5)_

No output expected

Input for turn 1

UR
_Hostages are in the upward-right direction_

Output for turn 1

5 4
_Batman jumps to window (5,4)_

Input for turn 2

R
_Hostages are located to the right of Batman_

Output for turn 2

7 4
_Batman jumps to window (7,4)_

_Batman found the hostages. He can defuse the bombs in time. You win!_

### Synopsis

**Batman:** “_Come on Joker, give it up, I know you're hiding in here somewhere, you can't escape from me._”  
**Joker:** “_Oh, but I
 think I can Batman! Just look behind you. See these buildings over 
there? In each one of them there is a room full of hostages trapped with
 my sweet little Joker-BOMBS. They are about to go off any minute now in
 a marvellous firework! KA-BOOOM!!!_”  
**Batman:** “_Damn you Joker, you won't get away with this._”  
**Joker:** “_So what 
will it be Batman? Do you want to waste time chasing me or will you try 
to save the poor, poor hostages? I'd hurry if I were you...Ha-ha-ha_”  
**Batman:** “_Alfred, I don't have time to check all the buildings' windows: I need a gadget to help me._”  
**Alfred:** “_Certainly
 sir. I have the perfect device: it can track the bombs heat signature. 
I'm sending it to you as soon as I'm done reprogramming it._”  
**Joker:** “_So long Batman! Ha-ha-ha OH-OH-OH..._”