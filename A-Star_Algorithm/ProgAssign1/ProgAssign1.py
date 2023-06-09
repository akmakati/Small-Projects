import numpy as np
import math
from queue import PriorityQueue
locations = PriorityQueue()
distTrav = 0
prevDist = 0
tempADist = 0

def nextNodeFind(arr, currNode, searchChar, directChar, nodeIndX, nodeIndY, hChoice):

    #variables to search the list in the correct direction
    xIncr, yIncr = incrementVar(directChar)
    #temporary list to store valid points
    tempList = []
    #indexing through the list and adding accepted points to the temp list
    for k in range(arrX):
        #if nodes in the acceptable direction matching the search char or the final node around append them to the list
        if (arr[nodeIndX][nodeIndY][0][0:1] == searchChar or arr[nodeIndX][nodeIndY] == arr[arrX-1][arrY-1]):
            if(arr[nodeIndX][nodeIndY] not in dontVisitNodes and arr[nodeIndX][nodeIndY][4] != 1):
                tempList.append(arr[nodeIndX][nodeIndY])
                #rint(currNode)
        #incrementing search characters in the apporpriate direction accoding to find index
        nodeIndX = nodeIndX + xIncr
        nodeIndY = nodeIndY + yIncr
        #if the search indexs are greater than the array size break
        if (nodeIndX >= arrX or nodeIndY >= arrY):
            break
        if (nodeIndX < 0 or nodeIndY < 0):
            break

    #if nothing is found return the current node and mark it as visited
    if not tempList:
        currNode = locations.get()
        indexCheck = currNode[1]
        nodeIndX, nodeIndY = findIndex(indexCheck, arr)
        arr[nodeIndX][nodeIndY][4] = 1
        nonSBS.pop()

        return currNode

    #calling the shortest distance function to determine which is the best point to select
    newNode = findShortestDist(currNode, tempList, hChoice)
    indexCheck = newNode[1]
    nodeIndX, nodeIndY = findIndex(indexCheck, arr)
    arr[nodeIndX][nodeIndY][4] = 1



    return newNode

# function that finds the x and y index variables to parse the list in the desired direction
def findIndex(newNode, arr):

    for k in range(arrX):
        for j in range(arrY):
            if(newNode == arr[k][j]):
                return k, j
                break
    return 0, 0
#finds the index of the start variable entered
def findStartIndex(newNode, arr):

    for k in range(arrX):
        for j in range(arrY):
            if(newNode == arr[k][j][0]):
                return k, j
                break
    return 0, 0
#this handles the heuristic functions
def findShortestDist(currNode, tempList, hChoice):

    global prevDist
    global locations
    #setting up currdistance and finaldistance pairs for easier reading
    currDist = (currNode[1][2], currNode[1][3])
    finalDist = (finalX, finalY)
    #tracks the prev distance
    prevDist = currNode[3]
    #indexs through the list of possible nodes to travel to
    for var in tempList:
        varDist = (int(var[2]), int(var[3]))
        #if the shortest path heuristic is chosen
        if(hChoice == '1'):
            #calculates the distance from the next node to the final node
            tempADist = math.sqrt(((finalDist[0] - varDist[0]) ** 2) + ((finalDist[1] - varDist[1]) ** 2))
            distTrav = prevDist + math.sqrt(((currDist[0]-varDist[0])**2)+((currDist[1]-varDist[1])**2))
            locations.put((tempADist + distTrav, var, currNode[1], distTrav))
            nodesToTravel.append([currNode[1], var, tempADist+distTrav])
        #if the least node heuristic is chosen
        if(hChoice == '2'):

            tempADist = 0
            distTrav = prevDist + 1
            locations.put((tempADist + distTrav, var, currNode[1], distTrav))
            nodesToTravel.append([currNode[1], var, tempADist+distTrav])


    retNode = locations.get()

    route.append(retNode)

    return retNode
#find the number to increment in the proper direction to find possible nodes
def incrementVar(directChar):
    xIncr = 0
    yIncr = 0
    if directChar == 'N':
        xIncr = -1
        yIncr = 0
    elif directChar == 'S':
        xIncr = 1
        yIncr = 0
    elif directChar == 'E':
        xIncr = 0
        yIncr = 1
    elif directChar == 'W':
        xIncr = 0
        yIncr = -1
    elif directChar == 'NE':
        xIncr = -1
        yIncr = 1
    elif directChar == 'NW':
        xIncr = -1
        yIncr = -1
    elif directChar == 'SE':
        xIncr = 1
        yIncr = 1
    elif directChar == 'SW':
        xIncr = 1
        yIncr = -1

    return xIncr, yIncr
#fills the list for non step by step
def fillNonSBS(SBS):
    tempList = []
    catchVar = SBS[-1][1]
    #this reverses the list since that's the easiest way to find the shortest path, start from the end and go to each node that got it there
    while(len(SBS) > 0):
        tempVar = SBS.pop()
        if(catchVar == tempVar[1]):
            tempList.append([tempVar[2], tempVar[1]])#, SBS[3]])
            catchVar = tempVar[2]
    tempList.reverse()
    #once the actual shortest path is found it's printed and the distances between the two nodes is calculated
    print('The final solution is: ')
    tot = 0
    dist = 0
    for x in tempList:
        #if this is the shortest distance it uses the distance formula
        if hChoice == '1':
            dist = math.sqrt(((x[1][2] - x[0][2]) ** 2) + ((x[1][3] - x[0][3]) ** 2))
        #shortest path distance is 1
        if hChoice == '2':
            dist = 1
        tot += dist
        print(x[0][0], 'to:',x[1][0], 'distance:', dist)
    print('Total path distance:', tot)
#fills the list for step by step
def fillSBS(nodes, startNode):
    nonSBSList1= []
    valList = []
    pathEndNode = []
    nonSBSList1.append(startNode[1][0])
    #nodes is the expansion path and it's appending the node name to a temporary list
    for x in nodes:
        nonSBSList1.append(x[1][0])
        #valList.append(x[1][0])
    #for each node in the expansion pass it's creating a list of values that contain the start node the destination node and the distance
    for x in nonSBSList1:
        for y in nodes:
            if(x == y[2][0]):
                valList.append([x, y[1][0], y[0]])

    print('STEP BY STEP: ')
    #for each node in expansion or each 'node selected'
    for x in nonSBSList1:
        print('*************************************************************')
        check = 0
        print('node selected: ', x)
        catchVar = x
        #this function pops already visisted locations out of the node at the end of the possible path list to ensure it's correct
        if(len(pathEndNode)>0):

            if catchVar == pathEndNode[0][0]:
                pathEndNode.pop(0)
            elif catchVar == pathEndNode[len(pathEndNode)-1][0]:
                pathEndNode.pop(-1)
            else:
                for i in range(len(pathEndNode)-1):
                    if catchVar == pathEndNode[i][0]:
                        pathEndNode.pop(i)
        #this is a list  of possible nodes to travel created it the distance calculated function
        #if x matches it prints all the nodes x can travel to
        print('Possible node to traveL: ',  end='')
        for y in nodesToTravel:
            if(x == y[0][0]):
                check = 1
                print(y[1][0],' ', end='')
                #appends nodes x can travel to to the end of the pathendlist
                pathEndNode.append([y[1][0], y[2]])
                catchVar2 = x
        if(check == 0):
            print(catchVar2, end='')
        print('')
        print('node at the end of possible path: ', end='')
        #prints all remaining viable paths
        for x in pathEndNode:
            print(x[0],"(",x[1],')',' ',end='')
        print('')
    print('***************************************************************')


#----------------------------MAIN------------------------------------------

#input file start of main
inFileName = "maze.txt"

f = open(inFileName, "r")
Lines = f.readlines()

#print(Lines[0])  # can access each line with an indint(
numList = Lines[0].split()  # creating a num list from the info in line zero

arrX = int(numList[0])  # casting this info into a int to work with
arrY = int(numList[1])

arr = np.full((arrX, arrY, 5), ('str', 'str', 'str', 'str', 0))  # creating the tuple with numpy
arr = arr.tolist()

#print(arr)

temp = []
route = []

#list to keep track of all the possible nodes and there total distances
distanceCheckList = []
#list of unaccepted nodes
dontVisitNodes = []

nodesAtEnd = []
nodesToTravel = []
nodes = []
SBS = []
nonSBS = []
#distance travelled
distTrav = 0
# test = Lines.split()

for k in range(1, arrX + 1):  # goes from 1 to arrX + 1
    temp = Lines[k].split() # sets all the info from line 1 to a temp list
    for i in range(arrY):  # for in in the arrY range
        temp[i] = temp[i].split('-')  # splits the test at [i] by the -
    arr[k - 1] = temp  # adds the temp list tuple info to the arr index 0



for k in range(arrX):
    for j in range(arrY):
        arr[k][j][2] = int(arr[k][j][2])
        arr[k][j][3] = int(arr[k][j][3])
        arr[k][j].append(0)

#end position variables
finalX = int(arr[arrX-1][arrY-1][2])
finalY = int(arr[arrX-1][arrY-1][3])

#initalizing currNode to the start Node
hChoice = input("Enter 1 for straight-line heuristic and 2 for least-node heuristic\n")

printInput = input("Enter 1 for step by step print and 2 for non step by step print\n")

startNode = input("Enter a starting node in form, R0, B16, R61, etc\n")
indexX, indexY = findStartIndex(startNode, arr)

currNode = arr[indexX][indexY]
#setting 1st node to already visited
arr[indexX][indexY][4] = 1

locations.put((0, currNode, currNode, 0))
passNode = locations.get()

i = 0
true = 1

startNode = passNode
while((passNode[1] != arr[arrX-1][arrY-1])):

    charSearch = passNode[1][0]
    directChar = passNode[1][1]
    indexSearch = passNode[1]
    nodeIndX, nodeIndY = findIndex(indexSearch, arr)

    if (charSearch[0][0:1] == 'R'):
        searchChar = 'B'
    else:
        searchChar = 'R'

    passNode = nextNodeFind(arr, passNode, searchChar, directChar, nodeIndX, nodeIndY, hChoice)
    nodes.append(passNode)

    nonSBS.append(passNode)
    #print('nonsbs', nonSBS)
    #if(passNode[1] == arr[arrX-1][arrY-1]):
    #    true = 0



if(printInput == '1'):
    SBS = nodes
    fillSBS(nodes, startNode)
    fillNonSBS(SBS)

if(printInput == '2'):
    SBS = nodes
    fillNonSBS(SBS)

#print(nodesToTravel)


