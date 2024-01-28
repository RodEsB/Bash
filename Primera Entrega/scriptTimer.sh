#!/bin/bash
echo "Ingresa el timeout para la destruccion de su laptop: " #Pedir valor en segundos
read timeOut #Almacena los datos ingresados en la terminal
sleep $timeOut &    #Le da el valor almacenado
sleep_pid=$!    #Tiempo de almacen
read -p "Presiona cualquier tecla para evitarlo" #Evita el proceso
#timeout $timeOut pmset sleepnow
kill $sleep_pid #Detener el proceso
echo -e "Tranquilo solo era una broma :)"   #Comentario gracioso
