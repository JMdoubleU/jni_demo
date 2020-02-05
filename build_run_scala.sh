#!/bin/bash

./clean.sh
scalac Test.scala
javah -cp /usr/share/java/scala-library.jar:. Test
gfortran -fPIC -c Test.f -o Test_f.o
gcc -std=c11 -fPIC -c -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux Test.c -o Test_c.o
gfortran -shared Test_f.o Test_c.o -o libTest.so
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
export LD_LIBRARY_PATH
scala TestRunner
