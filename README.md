# Hangman
A serializable hangman game that is played in the terminal. Users can either start a new game or resume a saved game.

## Running
1. Download the files and navigate into the repository.
2. Open Terminal and enter ```make``` to compile the files.
3. Run the executable
   - To start a new game, type ```./HM```
   - To resume an old game, type ```./HM <filename>```
4. At any point during hangman, you can save the game and exit by entering ```!```. You will be prompted to enter a file name where your game will be serialized as text.

# Sample Output
```
Welcome to Hangman

__________
0 of 8 wrong letters
Enter a letter or enter ! to save game and exit: e

__________
1 of 8 wrong letters
Enter a letter or enter ! to save game and exit: a

________a_
1 of 8 wrong letters
Enter a letter or enter ! to save game and exit: o

_o____o_a_
1 of 8 wrong letters
Enter a letter or enter ! to save game and exit: i

_o_i_io_a_
1 of 8 wrong letters
Enter a letter or enter ! to save game and exit: s

_osi_io_a_
1 of 8 wrong letters
Enter a letter or enter ! to save game and exit: b

_osi_io_a_
2 of 8 wrong letters
Enter a letter or enter ! to save game and exit: p

posi_io_a_
2 of 8 wrong letters
Enter a letter or enter ! to save game and exit: t

positio_a_
2 of 8 wrong letters
Enter a letter or enter ! to save game and exit: n

positiona_
2 of 8 wrong letters
Enter a letter or enter ! to save game and exit: l

positional
Congratulations, you win
```
