#!/usr/bin/env python3
##
## EPITECH PROJECT, 2024
## B-MUL-100-STG-1-1-myradar-camille.billard
## File description:
## generator
##

import random
import sys

#Modify those variable if wanted
MAX_DELAY = 15
MAX_SPEED = 75
MAX_RADIUS = 25
SCREEN_WIDTH = 1920 - 20
SCREEN_HEIGHT = 1080 - 20

def generate_file(list_air, list_tow):
    f = open(f"test_files/file_{len(list_air)}_{len(list_tow)}.txt", "w")
    air_index = 0
    tow_index = 0
    for i in range(len(list_air) + len(list_tow)):
        choice = random.randint(0,5)
        if choice == 1 and tow_index < len(list_tow):
            line = " ".join(map(str, list_tow[tow_index]))
            f.write(line)
            f.write("\n")
            tow_index += 1
        else:
            line = " ".join(map(str, list_air[air_index]))
            f.write(line)
            f.write("\n")
            air_index += 1
    while tow_index < len(list_tow):
        line = " ".join(map(str, list_tow[tow_index]))
        f.write(line)
        f.write("\n")
        tow_index += 1
    while air_index < len(list_air):
        line = " ".join(map(str, list_air[air_index]))
        f.write(line)
        f.write("\n")
        air_index += 1
    f.close()


def generate_list(nb_air, nb_tow):
    list_air = []
    list_tow = []
    for i in range(nb_air):
        pos = [random.randint(0, SCREEN_WIDTH), random.randint(0, SCREEN_HEIGHT)]
        dest = [random.randint(0, SCREEN_WIDTH), random.randint(0, SCREEN_HEIGHT)]
        while pos[0] < dest[0] + 50 and pos[0] > dest[0] - 50:
            dest[0] = random.randint(0, SCREEN_WIDTH);
        while pos[1] < dest[1] + 50 and pos[1] > dest[1] - 50:
            dest[1] = random.randint(0, SCREEN_HEIGHT);
        list_air.append(['A',pos[0], pos[1], dest[0], dest[1], random.randint(20, MAX_SPEED), random.randint(0, MAX_DELAY)])
    for i in range(nb_tow):
        list_tow.append(['T',random.randint(0, SCREEN_WIDTH), random.randint(0, SCREEN_HEIGHT), random.randint(3, MAX_RADIUS)])
    generate_file(list_air, list_tow)


def main():
    if len(sys.argv) == 2 and sys.argv[1] == "-h":
        print("USAGE:\n\t./map_generator [OPTIONS] nb_aircraft nb_tower")
        print("\nOPTIONS\n\tnb_aircraft\tnumber of aircraft wanted\n\tnb_tower\tnumber of tower")
        print("\nOUTPUT\n\t'file_[nb_aircraft]_[nb_tower].radar'")
        sys.exit(0)
    if len(sys.argv) != 3:
        sys.exit(84)
    try:
        int(sys.argv[1])
        int(sys.argv[1])
    except:
        sys.exit(84)
    generate_list(int(sys.argv[1]), int(sys.argv[2]))
    sys.exit(0)

if __name__ == "__main__":
    main()