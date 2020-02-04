#!/bin/bash

./clean.sh
javac Test.java
javah Test
gcc -std=c11 -shared -fPIC -I/usr/lib/jvm/java-8-openjdk-amd64/include -I/usr/lib/jvm/java-8-openjdk-amd64/include/linux Test.c -o libTest.so
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
export LD_LIBRARY_PATH
java Test
