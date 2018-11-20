import pickle
import sys
from PyQt5.QtWidgets import (QWidget, QPushButton,
    QHBoxLayout, QVBoxLayout, QApplication, QLabel,
    QComboBox, QTextEdit, QLineEdit, QGridLayout)
from PyQt5.QtCore import Qt


class ScoreDB(QWidget):

    def __init__(self):
        super().__init__()
        self.initUI()
        self.dbfilename = 'assignment6.dat'
        self.scoredb = []
        self.readScoreDB()
        self.showScoreDB()

        ####  INITALIZE  ####
       
    def initUI(self):

        nameLabel = QLabel('Name')
        ageLabel = QLabel('Age')
        scoreLabel = QLabel('Score')
        amountLabel = QLabel('Amount')
        keyLabel = QLabel('Key')
        resultLabel = QLabel('Result')

        self.nameEdit = QLineEdit()
        self.ageEdit = QLineEdit()
        self.scoreEdit = QLineEdit()
        self.amountEdit = QLineEdit()
        self.keyBox = QComboBox()
        self.resultBox = QTextEdit()
        self.resultBox.setReadOnly(True)

        self.keyBox.addItems(['Name', 'Age', 'Score'])

        self.addButton = QPushButton('Add')
        self.delButton = QPushButton('Del')
        self.findButton = QPushButton('Find')
        self.incButton = QPushButton('Inc')
        self.showButton = QPushButton('Show')

        grid = QGridLayout()
        grid.setSpacing(10)

        ####  Set Layout  ####
        
        grid.addWidget(nameLabel, 1, 0)
        grid.addWidget(self.nameEdit, 1, 1)
        grid.addWidget(self.addButton, 1, 3)

        grid.addWidget(ageLabel, 2, 0)
        grid.addWidget(self.ageEdit, 2, 1)
        grid.addWidget(self.delButton, 2, 3)

        grid.addWidget(scoreLabel, 3, 0)
        grid.addWidget(self.scoreEdit, 3, 1)
        grid.addWidget(self.findButton, 3, 3)

        grid.addWidget(amountLabel, 4, 0)
        grid.addWidget(self.amountEdit, 4, 1)
        grid.addWidget(self.incButton, 4, 3)

        grid.addWidget(keyLabel, 5, 0)
        grid.addWidget(self.keyBox, 5, 1)
        grid.addWidget(self.showButton, 5, 3)
        
        grid.addWidget(resultLabel, 7, 0)
        grid.addWidget(self.resultBox, 8, 0, 3, 10)

        self.setLayout(grid)
        
        ####  Box Layout Setting  ####

        '''
        line1 = QHBoxLayout()
        line1.addWidget(nameLabel)
        line1.addWidget(nameEdit)
        line1.addStretch(1)
        line1.addWidget(addButton)
     
        line2 = QHBoxLayout()
        line2.addWidget(ageLabel)
        line2.addWidget(ageEdit)
        line2.addStretch(1)
        line2.addWidget(delButton)
 
        line3 = QHBoxLayout()
        line3.addWidget(scoreLabel)
        line3.addWidget(scoreEdit)
        line3.addStretch(1)
        line3.addWidget(findButton)

        line4 = QHBoxLayout()
        line4.addWidget(amountLabel)
        line4.addWidget(amountEdit)
        line4.addStretch(1)
        line4.addWidget(incButton)
 
        line5 = QHBoxLayout()
        line5.addWidget(keyLabel)
        line5.addWidget(keyBox)
        line5.addStretch(1)
        line5.addWidget(showButton)

        entireBox = QVBoxLayout()
        entireBox.addLayout(line1)
        entireBox.addLayout(line2)
        entireBox.addLayout(line3)
        entireBox.addLayout(line4)
        entireBox.addLayout(line5)

        self.setLayout(entireBox)
        '''

        ########################



        ####  Functions  ####

        self.addButton.clicked.connect(self.buttonClicked)
        self.delButton.clicked.connect(self.buttonClicked)
        self.findButton.clicked.connect(self.buttonClicked)
        self.showButton.clicked.connect(self.buttonClicked)
        self.incButton.clicked.connect(self.buttonClicked)

        ####  Size  ####

        self.setGeometry(300, 300, 500, 400)
        self.setWindowTitle('Assignment6')    
        self.show()

    def buttonClicked(self):
        sender = self.sender()
        
        if sender.text() == 'Add':
            try:
                record = {'Name':str(self.nameEdit.text()), 'Age':int(self.ageEdit.text()), 'Score':int(self.scoreEdit.text())}
                self.scoredb += [record]
                self.showScoreDB()
            except ValueError :
                pass
        elif sender.text() == 'Del':
            for data in self.scoredb[::-1]:
                if data['Name'] == self.nameEdit.text():
                    self.scoredb.remove(data)
            self.showScoreDB()
        
        elif sender.text() == 'Find':
            for data in self.scoredb:
                if data['Name'] == self.nameEdit.text():
                    self.showScoreDB(data['Name'])

        elif sender.text() == 'Inc':
            try:
                for data in self.scoredb:
                    if data['Name'] == self.nameEdit.text():
                        data['Score'] = int(data['Score']) + int(self.amountEdit.text())
                self.showScoreDB()
            except ValueError:
                pass

        elif sender.text() == 'Show':
            self.showScoreDB()
        
    def closeEvent(self, event):
        self.writeScoreDB()

    def readScoreDB(self):
        try:
            fH = open(self.dbfilename, 'rb')
        except FileNotFoundError as e:
            self.scoredb = []
            return

        try:
            self.scoredb =  pickle.load(fH)
        except:
            pass
        else:
            pass
        fH.close()


    # write the data into person db
    def writeScoreDB(self):
        fH = open(self.dbfilename, 'wb')
        pickle.dump(self.scoredb, fH)
        fH.close()

    def showScoreDB(self, name=None):
        if name != None:
            self.resultBox.setPlainText("")
            for data in self.scoredb:
                if data['Name'] == name:
                    self.resultBox.setPlainText(self.resultBox.toPlainText()+"Age={0:<10} Name={1:<20} Score={2:<10}\n".format(data['Age'], data['Name'], data['Score']))
            self.resultBox.setPlainText(self.resultBox.toPlainText()+"================================\n")
            for data in sorted(self.scoredb, key=lambda person: person[self.keyBox.currentText()]):
                self.resultBox.setPlainText(self.resultBox.toPlainText()+"Age={0:<10} Name={1:<20}     Score={2:<10}\n".format(data['Age'], data['Name'], data['Score']))
       
        else:
            self.resultBox.setPlainText("")
            for data in sorted(self.scoredb, key=lambda person: person[self.keyBox.currentText()]):
                self.resultBox.setPlainText(self.resultBox.toPlainText()+"Age={0:<10} Name={1:<20} Score={2:<10}\n".format(data['Age'], data['Name'], data['Score']))
        pass


if __name__ == '__main__':    
    app = QApplication(sys.argv)
    ex = ScoreDB()
    sys.exit(app.exec_())

