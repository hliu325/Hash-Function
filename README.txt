name: harrison liu; solo member
team: arigato dattebayo

as we discussed in class, a hash table is a data structure that maps keys to various slots. for this specific project, we implemented a chaining hash table, which is a table that does not care about collisions (when multiple keys point to the same slot)

for the hash table, i have a double pointer called stackArray. formHashTable(string* text, int size) is the main wrapper method that calls all the sub methods. my current hash function iteration is very simple, as i just convert the strings to ASCII. then i do [int_ASCII value] mod slots to generate my hash index. then, i simply just insert it into its respective stack slot within stackArray. finally, it's ready to be displayed.