#!/usr/bin/python3
# -*- encoding: utf-8 -*-

# Modules
from sys import argv
from csv import reader, DictReader

# Check for argument number
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(2)

# Get STR sequencies
with open(argv[1], 'r') as database:
    people = reader(database)
    for item in people:
        tandem = item
        tandem.pop(0)
        print(f'[DEBUG] Tandem: {tandem} - {type(tandem)}')
        break
    database.close()

# TODO

# Get DNA sequence
with open(argv[2], 'r') as dna:
    sample = reader(dna)
    for item in sequence:
        sequence = item
        print(f'[DEBUG] Sequence: {sequence[item]}')

# TODO