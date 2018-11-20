from hangman import Hangman
from guess import Guess
from word import Word


def gameMain():
    word = Word('words.txt')
    guess = Guess(word.randFromDB())

    #finished = False
    hangman = Hangman()
    maxTries = hangman.getLife()
    
    # Word check
    #print(guess.secretWord)
    
    while guess.numTries < maxTries:

        display = hangman.get(maxTries - guess.numTries)
        print(display)
        guess.display()

        guessedChar = input('Select a letter: ')
        if len(guessedChar) != 1:
            print('One character at a time!')
            continue
        if guessedChar in guess.guessedChars:
            print('You already guessed \"' + guessedChar + '\"')
            continue

        if guess.guess(guessedChar) == True:
            print('Success')
            break
        else:
            if guess.numTries == maxTries:
                print(hangman.get(0))
                print('word [' + guess.secretWord + ']')
                print('guess [' + guess.currentStatus + ']')
                print('Fail')
                break
            pass

if __name__ == '__main__':
    gameMain()
