# Problem J5: Rule of Three #
## Problem Description ##
A substitution rule describes how to take a sequence of symbols and convert it into a different sequence of symbols. For example, ```ABA```→```BBB```, is a substitution rule which means that ```ABA``` can be replaced with ```BBB```. Using this rule, the sequence ```AABAA``` would be transformed into thesequence ```ABBBA``` (the substituted symbols are inbold). In this task, you will be given three substitution rules, a starting sequence of symbols and a final sequence of symbols. You are to use the substitution rules to convert the starting sequence into thefinal sequence, using a specified number of substitutions. For example, if the three substitution rules were:
1. AA → AB2.
2. AB → BB3.
3. B → AA
we could convert the sequence ```AB``` into ```AAAB``` in ```4``` steps, by the following substitutions: <br/>
<center><b>AB</b> → <b>B</b>B → AA<b>B</b> → AA<b>AA</b> → AAAB,</center>

where the symbols to be replaced are shown in <b>bold</b>.  More specifically, from the initial sequence ```AB```, substitute rule ```2``` starting at position ```1```, to get the result ```BB```. From ```BB```, substitute rule ```3```, startingat position ```1```, to get the result ```AAB```. From ```AAB```, substitute rule ```3```, starting at position ```3```, to get theresult ```AAAA```. From ```AAAA```, substitute rule ```1```, starting at position ```3```, to get the result ```AAAB```, which is the final sequence. 

## Input Specification ##
The first three lines will contain the substitution rules.  Each substitution rule will be a sequenceof ```A```’s and ```B```’s, followed by a space following by another sequence of ```A```’s and ```B```’s. Both sequences will have between one and five symbols. The next line contains three space separated values, ```S```, ```I``` and ```F```.  The value ```S``` (```1``` ≤ ```S``` ≤ ```15```) is an integer specifying the number of steps that must be used, and the values ```I```(the initial sequence) and ```F``` (the final sequence) are sequences of ```A```’s and ```B```’s, where there are at least one and at most ```5``` symbols in ```I``` and at least one and at most ```50``` symbols in ```F```. For ```7``` of the ```15``` marks available, ```S``` ≤ ```6```.For an additional ```7``` of the ```15``` available marks, ```S``` ≤ ```12```.
## Output Specification ##
The output will be ```S``` lines long and describes the substitutions in order. Line <i>```i```</i> of the output will contain three space-separated values, ```R```<sub><i>```i```</i></sub>, ```P```<sub><i>```i```</i></sub>, and ```W```<sub><i>```i```</i></sub>:<br/>

* ```R```<sub><i>```i```</i></sub> is the substitution rule number (either ```1```, ```2``` or ```3```) that will be used.
* ```P```<sub><i>```i```</i></sub> is the starting position index of where the substitution rule will be applied in the sequence.Notice that the string is ```1```-indexed (i.e., the first character of the string is at index ```1```).
* ```W```<sub><i>```i```</i></sub> is the sequence that results from this substitution. Specifically, ```W```<sub><i>```i```</i></sub> is the sequence ofsymbols that results by applying substitution rule ```R```<sub><i>```i```</i></sub> starting at position ```P```<sub><i>```i```</i></sub> from the previous sequence of symbols, ```W```<sub>```i-1```</sub>,  where we define ```W```<sub>```0```</sub> to be the initial sequence ```I``` Note that ```W```<sub><i>```S```</i></sub> = ```F```, the final sequence. <br/><br/>
There will always be at least one sequence of ```S``` substitutions that will convert ```I``` into ```F```. If there is more than one possible sequence of substitutions, any valid sequence will be accepted.
## Sample Input ##
```
AA AB
AB BB
B AA
4 AB AAAB
```
## Possible Output for Sample Input ##
```
2 1 BB
3 1 AAB
3 3 AAAA
1 3 AAAB
```
## Explanation of Output for Sample Input ##
This is the example outlined in the problem description. Note that the following is another possiblevalid substitution sequence:
```
2 1 BB
3 2 BAA
1 2 BAB
3 1 AAAB
```
Specifically, showing the substitutions in <b>bold</b>, we get
<center><b>AB</b> → B<b>B</b> → B<b>AA</b> → <b>B</b>AB → AAAB.<center>