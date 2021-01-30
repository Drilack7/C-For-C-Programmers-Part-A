//Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional arrays!
int **array = new int*[10]; // allocate an array of 10 int pointers — these are our rows
for (int count = 0; count < 10; ++count)
    array[count] = new int[5]; // these are our columns

//We can then access our array like usual:
array[9][4] = 3; // This is the same as (array[9])[4] = 3;

//Deallocating a dynamically allocated two-dimensional array using this method requires a loop as well:
for (int count = 0; count < 10; ++count)
    delete[] array[count];
delete[] array; // this needs to be done last
