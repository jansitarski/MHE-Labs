import os
import re
import numpy as np

statistics = {
    "Hill": [],
    "Tabu": []
}

count = 0

for method_name in statistics:
    for problem_size in range(5, 10):
        for repeat in range(1, 15):
            count += 1
            cmndName = "./a.out " + method_name + " " + str(problem_size) + " 30 100 100 100 " + str(count) + " 10"
            # print(cmndName)
            result = os.popen(cmndName)
            output = result.read()
            #print(output)
            calcTime = re.findall("dt.*", output)
            if (len(calcTime) > 0):
                calcTime = re.findall("[0-9.]+", calcTime[0])
                # print(calcTime)
                result_val = re.findall("[0-9.]+", re.findall("result.*", output)[0])

                statistics[method_name].append([problem_size, int(result_val[0]), float(calcTime[0])])

#print(statistics)

for method_name in statistics:
    print(method_name)
    summary = statistics[method_name]
    print(summary)
    per_size = {}
    for values in summary:
        if (per_size.get(values[0]) is None):
            per_size[values[0]] = [[values[1], values[2]]]
        else:
            per_size[values[0]].append([values[1], values[2]])
    print(per_size)
    for s in per_size:
        combined = np.mean(per_size[s], axis=0)
        with open("result_" + method_name + ".txt", "a") as myfile:
            myfile.write(str(s) + " " + str(combined[0]) + " " + str(combined[1]) + "\n")
        ##gnuplotfile.write("'result_" + method_name + ".txt")
    ##gnuplotfile.write("\n")

#result = os.popen("gnuplot result.plt")
#output = result.read()
