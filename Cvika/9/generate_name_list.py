import random

file = open("mena.txt","w")

names = ["Liam","Noah","Oliver","William","Elijah","James","Benjamin","Lucas","Mason","Ethan","Alexander","Henry","Jacob","Michael","Daniel","Logan","Jackson","Sebastian","Jack","Aiden","Owen","Samuel","Matthew","Joseph","Levi","Mateo","David","John","Wyatt","Carter","Julian","Luke","Grayson","Isaac","Jayden","Theodore","Gabriel","Anthony","Dylan","Leo","Lincoln","Jaxon","Asher","Christopher","Josiah","Andrew","Thomas","Joshua","Ezra","Hudson","Charles","Caleb","Isaiah","Ryan","Nathan","Adrian","Christian","Maverick","Colton","Elias","Aaron","Eli","Landon","Jonathan","Nolan","Hunter","Cameron","Connor","Santiago","Jeremiah","Ezekiel","Angel","Roman","Easton","Miles","Robert","Jameson","Nicholas","Greyson","Cooper","Ian","Carson","Axel","Jaxson","Dominic","Leonardo","Luca","Austin","Jordan","Adam","Xavier","Jose","Jace","Everett","Declan","Evan","Kayden","Parker","Wesley","Kai"]

for _ in range(500):
    file.writelines(names[random.randrange(0,100)]+"\n")
