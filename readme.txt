Juste histoire de ne pas oublier :

g++ -o Candle_Box Candle_Box.cpp

Get-content candles.txt | ./Candle_Box

(ATTENTION sur Mac on dirait que c'est)

clang++ -o Candle_Box Candle_Box.cpp

cat candles.txt | ./Candle_Box

(ET NON PAS gcc -o blabla blabla.cpp parce que gcc c'est un compilateur DE C IDIOT )
(On peut compiler du c++ avec gcc en rajoutant le flag -lstdc++ : ça donne genre )

gcc -o blabla blabla.cpp -lstdc++

(si j'ai bien tout compris )
