import imp
import os
import json
from time import sleep
from numpy import void

file = "./get_id"
file_buff = "res_id.txt"

def load_database() -> list:
    with open("data.json", 'r') as file:
        data = json.load(file)
    return (data)

def save_database(data:list) -> void:
    with open("data.json", 'w') as file:
        json.dump(data, file, indent = 4)

def get_id_card() -> str:
    os.system(file + " &> " + file_buff)
    fd = open(file_buff, 'r')
    res = fd.read().replace(' ', '').replace('\n', '').replace('\t', '')
    fd.close()
    os.system("rm " + file_buff)
    if ("error" in res) or (res == ''):
        return "error"
    else:
        return res

def check_admin_card(data:list) -> bool:
    res = "error"
    print("Please present your admin card.")
    while res == "error":
        res = get_id_card()
    for i in data['db']:
        if i['id'] == res:
            if i['admin'] == True:
                return True
            else:
                print("Card is not admin")
                return False
    print("Card not recognized")
    return False

def add_credits(data_one_person:list, data_all:list) -> list:
    check = False
    while check == False:
        inp = input("Do you want to add some credits ? (Y/N) ")
        if (inp == "N" or inp == "Y"):
            check = True
        else:
            print("Please answer with Y/N")
    if inp == "Y" and check_admin_card(data_all) == True:
        check = False
        while check == False:
            inp = input("How do you want to add ? ")
            try:
                inp = int(inp)
                check = True
            except ValueError:
                print("Enter a number.")
        data_one_person["credits"] += inp
        print("You have been credited with " + str(inp))
    return data_one_person

def big_loop() -> void:
    res = get_id_card()
    check = False
    if res == "error":
        pass
    else:
        data = load_database()
        for i in data['db']:
            if i['id'] == res:
                print("You have: " + str(i['credits']) + " credits.")
                if i["credits"] == 0:
                    i = add_credits(i, data)
                    save_database(data)
                    return
                while check == False:
                    inp = input("Number to credit: ")
                    try:
                        inp = int(inp)
                        check = True
                    except ValueError:
                        print("Enter a number.")
                if (i['credits'] - int(inp) < 0):
                    print("You dont have enouth credits: " + str(i['credits']))
                    i = add_credits(i, data)
                    save_database(data)
                else:
                    i['credits'] -= int(inp)
                    save_database(data)
                    print("You have been debited with " + str(inp) + " credits.")
                return
        print("Card not in database.")
        new = {
            "name": "Unset",
            "id": res,
            "credits": 0,
            "admin": False
        }
        new = add_credits(new, data)
        data["db"].append(new)
        save_database(data)
print("Ready.")
while True:
    big_loop()
    sleep(1)
