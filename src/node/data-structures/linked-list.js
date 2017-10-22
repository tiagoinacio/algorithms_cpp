const ds = require('./build/Release/ds');
const list = new ds.LinkedList();

list.append(1);
list.append(2);
list.append(3);

console.log(list.get(0));
console.log(list.get(1));
console.log(list.get(2));