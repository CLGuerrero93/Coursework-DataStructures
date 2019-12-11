# Makefile for Project 1
#cc=/opt/csw/gcc3/bin/g++
#debug=-g

p1: p1.o LinkedList.o
	g++ -o p1 p1.o LinkedList.o
p1.o: p1.cpp LinkedList.h
	g++ -c p1.cpp
LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp
