import pickle

dbfilename = 'assignment3.dat'

def readScoreDB():
    try:
        fH = open(dbfilename, 'rb')
    except FileNotFoundError as e:
        print("New DB: ", dbfilename)
        return []

    scdb = []
    try:
        scdb =  pickle.load(fH)
    except:
        print("Empty DB: ", dbfilename)
    else:
        print("Open DB: ", dbfilename)
    fH.close()
    return scdb



# write the data into person db
def writeScoreDB(scdb):
    fH = open(dbfilename, 'wb')
    pickle.dump(scdb, fH)
    fH.close()


def doScoreDB(scdb):
    while(True):
        inputstr = (input("Score DB > "))
        if inputstr == "": continue
        parse = inputstr.split(" ")
        exist = 0

        if parse[0] == 'add':
            try: 
                record = {'Name':parse[1], 'Age':int(parse[2]), 'Score':int(parse[3])}
            except ValueError:
                print("\nError! Please Enter Correct Number!\n")
            except IndexError:
                print("\nError! Please Enter Valid Input!\n")
            else:
                record = {'Name':parse[1], 'Age':parse[2], 'Score':parse[3]}
                scdb += [record]
                

        elif parse[0] == 'del':
            try:
                for p in scdb[::-1]:
                    if p['Name'] == parse[1]:
                        scdb.remove(p)
            except IndexError:
                print("\nError! Please Enter Valid Input!\n")

        elif parse[0] == 'show':
            sortKey ='Name' if len(parse) == 1 else parse[1]
            showScoreDB(scdb, sortKey)

        elif parse[0] == 'find':
            for i in scdb:
                if i['Name'] == parse[1]:
                    for attr in sorted(i):
                        print(attr + "=" + i[attr], end=' ')
                    print()
                    exist = 1
            if exist != 1:
                print("\nError! Invalid Name!\n")
                exist = 0

        elif parse[0] == 'inc':
            for i in scdb:
                if i['Name'] == parse[1]:
                    try:
                        i['Score'] = int(i['Score']) + int(parse[2])
                        exist = 1
                    except ValueError:
                        print("\nError! Please Enter Correct Number!\n")
                        break
                    except IndexError:
                        print("\nError! Please Enter Valid Input!\n")
                        break
            if exist != 1:
                print("\nError! Invalid Name!\n")

        elif parse[0] == 'quit':
            break
        
        else:
            print("\nInvalid command: " + parse[0]+"\n")


def showScoreDB(scdb, keyname):
    for p in sorted(scdb, key=lambda person: person[keyname]):
        for attr in sorted(p):
            print(attr + "=" + p[attr], end=' ')
        print()


scoredb = readScoreDB()
doScoreDB(scoredb)
writeScoreDB(scoredb)
