from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtWidgets import QLineEdit, QToolButton
from PyQt5.QtWidgets import QSizePolicy
from PyQt5.QtWidgets import QLayout, QGridLayout

from keypad2 import numPadList, operatorList, constantList
from calcFunctions import * #factorial, decToBin, binToDec, decToRoman, functionList, constantValue

class Button(QToolButton):

    def __init__(self, text, callback):
        super().__init__()
        self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Preferred)
        self.setText(text)
        self.clicked.connect(callback)

    def sizeHint(self):
        size = super(Button, self).sizeHint()
        size.setHeight(size.height() + 20)
        size.setWidth(max(size.width(), size.height()))
        return size


class Calculator(QWidget):

    def __init__(self, parent=None):
        super().__init__(parent)

        # Display Window
        self.display = QLineEdit()
        self.display.setReadOnly(True)
        self.display.setAlignment(Qt.AlignRight)
        self.display.setMaxLength(15)

        # Button Creation and Placement
        numLayout = QGridLayout()
        opLayout = QGridLayout()
        constLayout = QGridLayout()
        funcLayout = QGridLayout()

        buttonGroups = {
            'num': {'buttons': numPadList, 'layout': numLayout, 'columns': 3},
            'op': {'buttons': operatorList, 'layout': opLayout, 'columns': 2},
            'constants': {'buttons': constantList, 'layout': constLayout, 'columns': 1},
            'functions': {'buttons': functionList, 'layout': funcLayout, 'columns': 1},
        }

        for label in buttonGroups.keys():
            r = 0; c = 0
            buttonPad = buttonGroups[label]
            for btnText in buttonPad['buttons']:
                button = Button(btnText, self.buttonClicked)
                buttonPad['layout'].addWidget(button, r, c)
                c += 1
                if c >= buttonPad['columns']:
                    c = 0; r += 1

        # Layout
        mainLayout = QGridLayout()
        mainLayout.setSizeConstraint(QLayout.SetFixedSize)

        mainLayout.addWidget(self.display, 0, 0, 1, 2)
        mainLayout.addLayout(numLayout, 1, 0)
        mainLayout.addLayout(opLayout, 1, 1)
        mainLayout.addLayout(constLayout, 2, 0)
        mainLayout.addLayout(funcLayout, 2, 1)

        self.setLayout(mainLayout)

        self.setWindowTitle("My Calculator")


    def buttonClicked(self):

#        if self.display.text() == 'Error!':
#            self.display.setText('')

        button = self.sender()
        key = button.text()
        text = self.display.text()
        if len(text) >= 1:
            last = text[len(text)-1]
        #func = [factorial, decToBin, binToDec, decToRoman]
        if text[0:6] == 'Error!':
            self.display.setText(text[6:])
            print(self.display.text())
        elif key == '=':
            try:
                result = str(eval(self.display.text()))
            except:
                result = 'Error!'
            self.display.setText(result)
        elif key == 'C':
            self.display.clear()
        elif key == 'U':
            self.display.setText(text[:len(text)-1])
        elif key in operatorList: # Operator should not be stacked
            if len(text) == 0 and key == '-':
                self.display.setText(text+key)
            elif key == '(':
                self.display.setText(text+key)
            elif key == ')':
                openCount = 0
                closeCount = 0
                for alp in text:
                    if alp == '(':
                        openCount += 1
                    elif alp == ')':
                        closeCount += 1
                if openCount > closeCount:
                    self.display.setText(text+key)
            elif len(text) >= 1 and (last == '(' or last == ')'):
                self.display.setText(text+key)

            elif len(text) >= 1 and (last not in operatorList):
                self.display.setText(text+key)


        #### CONSTANT OPERATOR ####

        elif key in constantList:
            if len(text) >= 1 and text[len(text)-1] in operatorList:
                index = constantList.index(key)
                self.display.setText(text+constantValue[index])


        #### FUNCTION OPERATOR ####
        
        elif key in functionList:
            #index = functionList.index(key)
            result = functionMap[functionList.index(key)][1](text)
            if result == 'Error!':
                self.display.setText(str(result)+text)
            else:
                self.display.setText(str(result))
        else:
            self.display.setText(self.display.text() + key)


if __name__ == '__main__':

    import sys

    app = QApplication(sys.argv)
    calc = Calculator()
    calc.show()
    sys.exit(app.exec_())

