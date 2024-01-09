from sys import argv
import argparse
from random import randint, uniform, seed
from copy import deepcopy
from dataclasses import dataclass

@dataclass
class Data:
    planes: int
    towers: int
    radius: int
    floating: bool
    number: int
    seed: int
    path: str

class Manager:
    def __init__(self) -> None:
        self.__towers_nb: list[int] = []
        self.__planes_nb: list[int] = []
        self.__towers: list[str] = []
        self.__towers_: list[str] = []
        self.__planes: list[str] = []
        self.__parse_args()
        self.__file: list = self.__get_file(self.__data.path)
        self.__rand_env()
        self.__generate()

    def __get_file(self, path:str) -> list[str]:
        with open(path, 'r') as o:
            return (o.read().split('\n'))

    def __parse_args(self) -> None:
        parser = argparse.ArgumentParser()
        parser.add_argument('-p', '--planes', metavar="Planes",required=True, choices=range(1, 1000000), dest="planes", help="Amount of planes as a signed integer", type=int)
        parser.add_argument('-t', '--towers', metavar="Towers",required=True, choices=range(2, 50), dest="towers", help="Amount of towers as a signed integer", type=int)
        parser.add_argument('-r', '--radius', metavar="Radius", default=30, choices=range(5, 100), dest="radius", help="Percentage of the screen taken as a maximum value for the radius of the towers", type=int)
        parser.add_argument('-f', '--float', metavar="Float Coordinates", default=False, choices=[True, False], dest="float", help="Can coordinates contain floating numbers", type=bool)
        parser.add_argument('-n', '--number', metavar="Number of files generated", default=1, choices=range(1,100), dest="number", help="Turns -t & -p as maximum values and generates n .rdr files.", type=int)
        parser.add_argument('-s', '--seed', metavar="Seed to use to generate", default=None, dest="seed", help="Seed that will be used for any random calculation", type=int)
        parser.add_argument('-pa', '--path', metavar="Custom path to the towers' file.", default=".towers_pos", dest="path", help="Custom path to the towers' file.", type=str)
        res = parser.parse_args()
        self.__data = Data(planes=res.planes, towers=res.towers, radius=res.radius, floating=res.float, number=res.number, seed=res.seed, path=res.path)

    def __rand_env(self) -> None:
        self.__max = 0
        if (self.__data.seed != None):
            seed(self.__data.seed)
        if (self.__data.floating is True):
            self.__random = uniform
        else:
            self.__random = randint
        if (self.__data.number != 1):
            for _ in range(self.__data.number):
                self.__towers_nb.append(self.__random(2, self.__data.towers))
                self.__planes_nb.append(self.__random(1, self.__data.planes))
        if (self.__data.planes > 10):
            self.__max = 15
        self.__towers_nb.append(self.__data.towers)
        self.__planes_nb.append(self.__data.planes)

    def __save_file(self, name: str) -> None:
        a = '\n'.join(self.__towers) + '\n' + '\n'.join(self.__planes)
        with open(name, 'w') as o:
            o.write(f"{a}\n")
            o.close()

    def __generate_towers(self, element: int) -> None:
        tmp = deepcopy(self.__file)
        for i in range(self.__towers_nb[element]):
            a = randint(0, len(tmp)-1)
            self.__towers.append(f"{tmp[a]} {randint(5, self.__data.radius)}")
            self.__towers_.append(f"{tmp[a]}")
            tmp.pop(a)

    def __generate_planes(self, index: int) -> None:
        tmp = deepcopy(self.__towers_)
        for i in range(self.__planes_nb[index]):
            a = randint(1, len(tmp)-1)
            self.__planes.append(f"{tmp[a].replace('T', 'A')} {tmp[a-1].replace('T ', '')} {randint(15, 150)} {randint(0, self.__max)}")

    def __generate(self) -> None:
        for i in range(self.__data.number):
            self.__generate_towers(i)
            self.__generate_planes(i)
            self.__save_file(f"{self.__planes_nb[i]}_planes_{self.__towers_nb[i]}_towers.rdr")
            self.__towers = []
            self.__towers_ = []
            self.__planes = []

if __name__ == "__main__":
    m = Manager()