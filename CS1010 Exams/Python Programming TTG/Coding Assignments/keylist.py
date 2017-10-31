def print_hist(h):
    keylist = list(h.keys())
    keylist.sort()
    for key in keylist:
        print(key,h[key])

def main():
    somedic = {"a":1, "b":65, "c":30}
    print_hist(somedic)

main()
