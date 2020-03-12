'''Longest public string and longest public sequence'''
def main():
    word1 = input("Enter you word1:")
    word2 = input("Enter yuo word2:")
    for i in word1:
        print(i)
    for j in word2:
        print(j)
    print("public string".center(28,"*"))
    cell1 = publicStr(word1, word2)
    for ele in cell1:
        print(ele)
    print("public sequence".center(28,"*"))
    cell2 = publicSeq(word1, word2)
    for element in cell2:
        print(element)

def publicStr(word1, word2):
    cell = [[]]
    for i in range(len(word1)):
        for j in range(len(word2)):
            if word1[i] == word2[j]:
                cell[i][j] = cell[i-1][j-1]
            else:
                cell[i][j] = 0
    return cell
def publicSeq(word1, word2):
    cell = [[]]
    for i in range(len(word1)):
        for j in range(len(word2)):
            cell[i][j].extend(0)
            if word1[i] == word2[j]:
                cell[i][j] = cell[i-1][j-1]
            else:
                cell[i][j] = max(cell[i-1][j], cell[i][j-1])
    return cell
if __name__ == "__main__":
    main()