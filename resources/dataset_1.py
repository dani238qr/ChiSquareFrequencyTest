import random

with open("python_dataset_1.txt","w") as fp:

    for i in range(100000):
        x=random.choice([0,1])
        fp.write(str(x))

