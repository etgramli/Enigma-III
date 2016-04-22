# Enigma-III

## Description
This is a implementation of a "Emigma III" wooden model for a IT-Security lecture.

## Command line options
### -h
Helo text
### -g1 <alphabet permutation>
### -g2 <alphabet permutation>
### -g3 <alphabet permutation>
Permutations of the alphabet for the first, second and third gearwheel. (i.e. "ADCBEHFGILJKMPNOQTRSUXVWZY")
### -s <start positions>
Start positions of the three gearwheels. (i.e. "SEC")

## Introduction
This Enigma-III consists of three "gearwheels", every with a (seperate) permutataion of the letters of the alphabet. - Just to make it clear: A permutataion in this case is a list of the characters of the alphabet (all 26) with a order, that may be different from the normal order. The program assumes that all letters are only once in the permutataion.

You can set a start position of every gearwheel seperately. If you did not, the first letter is the start position.

## Encryption
The message is encrypted letter by letter; the letters on even positions will be enrypted by the first gearwheel and the odd positions will be encrypted by the second one. The final encrypted letter can be read from the third gearwheel.

If the currently encrypted letter is not on the start position of the active gearwheel, the gearwheel rotates to the letter to search. This causes the left and right neighbor gearwheels to rotate in the opposite direction, of course.

## Decryption
An encrypted message has to be processed letter by letter, too. All encrypted letters have to be the input of gearwheel three. The even position letters have to be read from the first gearwheel and the odd letters from the second gearwheel respectively.
