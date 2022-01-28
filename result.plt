set term png
set output "result.png"
plot 'result_Hill.txt' u 1:3 w lines, 'result_Tabu.txt' u 1:3 w lines, 