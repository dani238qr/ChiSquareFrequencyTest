import secrets

with open("python_dataset_2.txt","a") as fp:
    for i in range(10000000):
        fp.write(str(secrets.choice([0, 1])))


