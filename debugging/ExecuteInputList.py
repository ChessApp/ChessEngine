import os.path
from os import path

UserInputFilePath = "/home/chess/dev/ChessGame/code/Source/UI/www/UserInput.txt"
UserInputListPath = "/home/chess/dev/ChessGame/debugging/InputFile.txt"

listFile = open(UserInputListPath)
lines = listFile.readlines()

for line in lines:
  # Wait for game engine to consume current input
  while path.exists(UserInputFilePath) == True:
    pass

  if path.exists(UserInputFilePath) == False:
    line = line.strip("\n")
    print(line)
    targetFile = open(UserInputFilePath, "w")
    targetFile.write(line)
    targetFile.close()
