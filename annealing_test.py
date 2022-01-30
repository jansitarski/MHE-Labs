import os
import re
from locale import atof

import numpy as np

colds = {
    "0.1": [],
    "0.01": [],
    "0.001": [],
    "0.0001": []
}
statistics = {
    "500": [],
    "1000": [],
    "1500": [],
    "2000": [],
    "2500": [],
    "3000": [],
    "3500": [],
    "4000": []
}

count = 0

for method_name in statistics:
    for cold in colds:
        for repeat in range(0,25):
            count += 1
            cmndName = "./a.out Annealing 20 20 14 " + str(method_name) + " 1000 0.9 " + str(cold)
            # print(cmndName)
            result = os.popen(cmndName)
            output = result.read()
            # print(output)
            calcTime = re.findall("dt.*", output)
            if (len(calcTime) > 0):
                calcTime = re.findall("[0-9.]+", calcTime[0])
                # print(float(calcTime[0]))
                result_val = re.findall("[0-9.]+", re.findall("result.*", output)[0])

            statistics[method_name].append([cold, int(result_val[0]), float(calcTime[0])])

#print(statistics)

with open("temp/result.plt", "w") as gnuplotfile:
    gnuplotfile.write("set term png\n")
    gnuplotfile.write("set output \"temp/result.png\"\n")
    gnuplotfile.write("plot ")
    for method_name in statistics:
        # print(method_name)
        print('{:16s}{:18s}{:s}'.format("rozmiar", "wynik_sredni", "czas"))
        summary = statistics[method_name]
        # print(summary)
        per_size = {}
        for values in summary:
            if (per_size.get(values[0]) is None):
                per_size[values[0]] = [[values[1], values[2]]]
            else:
                per_size[values[0]].append([values[1], values[2]])
        # print(per_size)
        for s in per_size:
            combined = np.mean(per_size[s], axis=0)
            print('{:s}{:19.2f}{:18.2f}'.format(str(s), combined[0], combined[1]))
            with open("temp/result_" + method_name + ".txt", "a") as myfile:
                myfile.write(str(s) + " " + str(combined[0]) + " " + str(combined[1]) + "\n")
        gnuplotfile.write("'temp/result_" + method_name + ".txt' u 1:3 w lines, ")
    # gnuplotfile.write("\n")

result = os.popen("gnuplot temp/result.plt")
output = result.read()
