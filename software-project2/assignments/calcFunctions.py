from math import factorial as fact

def factorial(numStr):
    try:
        n = int(numStr)
        r = str(fact(n))
    except:
        r = 'Error!'
    return r

def decToBin(numStr):
    try:
        n = int(numStr)
        r = bin(n)[2:]
    except:
        r = 'Error!'
    return r

def binToDec(numStr):
    try:
        n = int(numStr, 2)
        r = str(n)
    except:
        r = 'Error!'
    return r

def decToRoman(numStr):
    try:
        num = int(numStr)
    except ValueError:
        return 'Error!'
    if num >= 4000:
        return 'Error!'
    romans = [
        (1000, 'M'), (900, 'CM'), (500, 'D'), (400, 'CD'),
        (100, 'C'), (90, 'XC'), (50, 'L'), (40, 'XL'),
        (10, 'X'), (9, 'IX'), (5, 'V'), (4, 'IV'),
        (1, 'I')
    ]
    result = ''
    for value, letters in romans:
        while num >= value:
            result += letters
            num -= value
    return result

def romanToDec(romanStr):
    num = 0


    romans = [(900, 'CM'), (400, 'CD'), (90, 'XC'), (40, 'XL'),
              (9, 'IX'), (4, 'IV'), (1000, 'M'), (500, 'D'),
              (100, 'C'), (50, 'L'), (10, 'X'),  (5, 'V'),
               (1, 'I')]

    i = 0
    while (len(romanStr) > 0):
        for roman in romans:
            if romanStr[0:2] == roman[1]:
                num += roman[0]
                romanStr = romanStr[2:]
                break
            elif romanStr[0] == roman[1]:
                num += roman[0]
                romanStr = romanStr[1:]
                break

    return num

functionMap = [
    ('factorial (!)', factorial),
    ('-> binary', decToBin),
    ('binary -> dec', binToDec),
    ('-> roman', decToRoman),
    ('roman -> dec', romanToDec),
]

functionList = [x[0] for x in functionMap]

constantValue = [
    '3.141592',
    '3E+8',
    '340',
    '1.5E+8',
]
