#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""File to answer the Python exercise of PEC3
   in the IoT Development course
"""

import random


class Dog:
    species = 'caniche'

    def __init__(self, name, age):
        self.name = name
        self.age = age


bambi = Dog("Bambi", 5)
mikey = Dog("Rufus", 6)

print("{} is {} and {} is {}.".format(
    bambi.name, bambi.age, mikey.name, mikey.age))

if (bambi.species == "caniche"):
    print("{0} is a {1}!".format(bambi.name, bambi.species))


#Crear 3 instancias de Dog e imprimir por pantalla
MAX_YEARS_A_DOG_CAN_LIVE = 20
camada = []

#Generate 3 Dog instances with random age
for index in range(3):
    camada.append(Dog(name="dog" + str(index),
                      age=random.randint(1, MAX_YEARS_A_DOG_CAN_LIVE)))

#Use some idiomatic For loop
for index, oneDog in enumerate(camada):
    print("{} is {}.".format(
        oneDog.name, oneDog.age))


def get_biggest_number(*argv):
    """Receives any number of integers and returns the largest value.
    Args:
    argv: Variable number of integers.
    Returns:
    Integer. The largest of the values received as input parameters.
    """
    # Check for null number of values or incorrect types
    if (not argv):
        print('ERROR: At least one integer value is expected as input parameter.')
        raise ValueError

    for arg in argv:
        if (type(arg) is not int):
            print('ERROR: Expected integer but different type was received as parameter.')
            raise ValueError
    
    integer_list = list (argv)
    #Sort in ascending order and return the last element
    return (sorted(integer_list)[-1])

#Testing no parameters
try:
  print (get_biggest_number())
except:
  print("An exception occurred.")

#Testing wrong type sent to the funcion
try:
  print (get_biggest_number("hello","bye"))
except:
  print("An exception occurred.")
#Correct value, should return 80
print ('This should return 80')
try:
  print (get_biggest_number(1,2,5,8,-1,3,0,10,80,13,24,8))
except:
  print("An exception occurred.")
