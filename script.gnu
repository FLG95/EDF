  set size ratio 1
  set autoscale
  set xlabel "Stations ID"
  set ylabel "Consomomation"
  title "Top 10 des consomations les plus insolites"
  with impulses
  linecolor rgb "red"
  plot "$1" using 1:3