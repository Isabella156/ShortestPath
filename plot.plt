set xlabel "latitude"
set ylabel "longitude"
set xrange [-1.565:-1.54]
set xtics 0.005
set yrange [53.801:53.812]
set ytics 0.001
plot "original.dat" using 1:2:3 t "label" with labels hypertext point pt 7 pointsize 2 lc rgb "#0288D1", \
"original.dat" using 1:2 t "original" with linespoints linecolor 35 linewidth 3 pointtype 7 pointsize 0.3,\
"shortest.dat" t "shortest" with linespoints linecolor 58 linewidth 5 pointtype 14 pointsize 0.5