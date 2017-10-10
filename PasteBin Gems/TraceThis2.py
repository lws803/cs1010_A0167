
import csv
import matplotlib.pyplot as plt

f = open("eurovision-final.csv", "rt")
list = []
data = {}
for l in csv.reader(f):
    if l[0] == '2009':
        posamezno_leto = []
        for i in range(16, len(l) - 12):
            posamezno_leto.append(l[i])
        list.append(posamezno_leto)
        data[l(0)] = posamezno_leto
    else:
        break

print data['Israel']

#for i in range(0, 26):
#   print(list[i])
"""" 
def d(a, b):
    print(a, b)
    
x = data['irena']
y = data['joze']

list(zip(x, y))

zip - zadrga

naprej

for p in zip(x, y):
    print(p)
    
terka???
t = (10, 50)
s, t = (10, 50)

for a,b in zip(x, y):
    print (a, "<>", b)
    

sum([(a - b)**2 for a, b in zip(x, y)])

import math

math.sqrt(sum([(a - b)**2 for a, b in zip(x, y)]))  - evklidska razdalja za ta dva vektorja          





  
plt.plot(tockeX, tockeY, 'ro')
plt.axis([0, 12, 0, 12])
plt.show()


#to bi naj uporabli

class HierarchicalClustering:
    def __init__(self, file_name):
        f = open(file_name)
        self.header = f.readline().strip().split("\t")[1:]
        self.data = {}
        for line in f:
            row = line.strip().split("\t")
            self.data[row[0]] = [float(x) for x in row[1:]]

        # self.clusters =

    def row_distance(self, r1, r2):
        pass

    def cluster_distance(self, c1, c2):
        pass

    def closest_cluster(self):
        pass

    def run(self, n_clusters=2):
        pass


hc = HierarchicalClustering("data/grades.csv")
hc.run()
"""