with open("./punctuation.txt", 'r') as f:
    with open("./resultPunc.txt", "w") as wf:
        i = 1
        for line in f.readlines():
            line = line.strip()
            wf.write(' s =="' + line+'" ||')
            i += 1
