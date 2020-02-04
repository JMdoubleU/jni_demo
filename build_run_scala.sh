#!/bin/bash

./clean.sh
scalac TestRunner.scala
javah -cp /usr/share/java/scala-library.jar:. Test
gcc -std=c11 -shared -fPIC -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux Test.c -o libTest.so
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
export LD_LIBRARY_PATH
scala TestRunner
