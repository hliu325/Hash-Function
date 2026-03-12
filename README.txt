name: harrison liu
team: arigato dattebayo

as we discussed in class, a hash table is a data structure that maps keys to various slots. for this specific project, we implemented a chaining hash table, which is a table that does not care about collisions (when multiple keys point to the same slot)

for the hash table, i have a double pointer called stackArray. formHashTable(string* text, int size) is the main wrapper method that calls all the sub methods. 

the main idea of my hash function is to iterate over the input string and get a binary number by taking the value of its ASCII characters. however, the thing that makes this slightly different is that i will be shifting that value to the left by its position in the string (AKA the ith iteration in the loop), so that order actually makes a difference in the value. for example, the chars 'ba' and 'ab' would be considered different, as each character will be shifted by a different amount and it will be added to the total. i also used i % 63, so that i could make the most out of the 64 bits given in long without any risk. 

to be honest, i dont exactly have a good reason for doing (base % (i+1)) and adding that to the total, as i found that worked best through sheer trial and error. i believe it has something to do with it generates a very slight offset that somehow makes it perform better. as for the base value, it was really just a "troll" value but i ended up getting pretty lucky with it, so i kept it.
