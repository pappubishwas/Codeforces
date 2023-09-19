import random

import pyautogui as pg

import time

animal=('bukacuda','kangkimagi')

time.sleep(8)

for i in range(10):
    a=random.choice(animal)
    pg.write(a)
    pg.press('enter')