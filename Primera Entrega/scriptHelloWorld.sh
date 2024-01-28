#!/bin/bash 
cd Desktop #Ingresa al Desktop de la computadora
mensaje="Hello World"   #Crea el mensaje que tendrá el archivo
HelloWorld="helloWorld.txt" #Crea el archivo
echo $mensaje > $HelloWorld #Le da los datos del mensaje al archivo
echo -e $mensaje    #Imprime el mensaje en la terminal
