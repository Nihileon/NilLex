with open("./keyWord.txt", 'r') as f:
    with open("./result.txt", "w") as wf:
        i = 1
        for line in f.readlines():
            line = line.strip()
            wf.write('{"' + line + '",' + str(i) + '},\n')
            i+=1
