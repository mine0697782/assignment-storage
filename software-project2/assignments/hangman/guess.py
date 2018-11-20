class Guess:

    def __init__(self, word):
        self.secretWord = word
        self.guessedChars = []
        self.numTries = 0
        self.currentStatus = ''
        for i in range(len(self.secretWord)):
            #self.currentStatus.append(" _")        
            self.currentStatus += "_"
        pass


    def display(self):
        print("Current:", self.currentStatus, "\nTries: ", self.numTries, "\nAlready Used: ", self.guessedChars)
        pass


    def guess(self, character):
        self.guessedChars.append(character)
        for i in range(len(self.secretWord)):
            if character == self.secretWord[i]:
                self.currentStatus = self.currentStatus[:i] + character + self.currentStatus[i+1:]
        if character not in self.secretWord:
            self.numTries += 1

        return self.secretWord == self.currentStatus

        pass
