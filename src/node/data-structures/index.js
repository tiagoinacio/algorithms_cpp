const ds = require('./build/Release/ds');
const list = new ds.LinkedList();

list.append(1);
list.append(2);
list.append(3);

console.log('appended value ', list.get(0));
console.log('appended value ', list.get(1));
console.log('appended value ', list.get(2));
console.log('list size = ', list.size());

console.log('deleting element at position 1');
list.delete(1);
console.log('list size = ', list.size());

console.log('reseting list');
list.reset();
console.log('list size = ', list.size());

list.preppend(1);
console.log('preppended value ', list.get(0));
console.log('list size = ', list.size());