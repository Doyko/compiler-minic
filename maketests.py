#!/usr/bin/env python3
import subprocess
import glob

YELLOW = "\033[93m"
BLUE = "\033[96m"
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

def testFolder(folder, OK, options = ""):

    if(OK == 0):
        path = folder + "OK/*"
    else:
        path = folder + "KO/*"

    files = glob.glob(path)

    print(YELLOW + "=== Lancement des tests de " + path + " ===" + RESET)
    print(BLUE + "=> " + str(len(files)) + " tests\n" + RESET)

    i = 0
    for f in files:
        if(subprocess.run(["./minicc", f, options]).returncode == OK):
            i += 1
            print(GREEN + "test " + f + " reussi !" + RESET)
            print(BLUE + str(i) + "/" + str(len(files)) + RESET)
        else:
            print(RED + "test " + f + " echoue !" + RESET)
            print(BLUE + str(i) + "/" + str(len(files)) + RESET)

    print(BLUE + "=> resultat pour " + path + " : " + str(i) + "/" + str(len(files)) + "\n" + RESET)

print(YELLOW + "===== Lancement des tests =====\n" + RESET)

folders = ["Tests/Syntaxe/", "Tests/Verif/", "Tests/Gencode/"]

testFolder(folders[0], 0, "-s")
testFolder(folders[0], 1, "-s")
testFolder(folders[1], 0, "-v")
testFolder(folders[1], 1, "-v")
testFolder(folders[2], 0)
testFolder(folders[2], 1)
