set term png
set output "temp/result.png"
plot 'temp/result_500.txt' u 1:3 w lines, 'temp/result_1000.txt' u 1:3 w lines, 'temp/result_1500.txt' u 1:3 w lines, 'temp/result_2000.txt' u 1:3 w lines, 'temp/result_2500.txt' u 1:3 w lines, 'temp/result_3000.txt' u 1:3 w lines, 'temp/result_3500.txt' u 1:3 w lines, 'temp/result_4000.txt' u 1:3 w lines, 