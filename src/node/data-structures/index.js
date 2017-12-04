const ds = require('./build/Release/ds');
const list = new ds.LinkedList();

list.push_back(1);
list.push_back(2);
list.push_back(3);

console.log('push_back value ', list.get(0));
console.log('push_back value ', list.get(1));
console.log('push_back value ', list.get(2));
console.log('list size = ', list.size());

console.log('deleting element at position 1');
list.delete(1);
console.log('list size = ', list.size());

console.log('reseting list');
list.reset();
console.log('list size = ', list.size());

list.push_front(1);
console.log('push_front value ', list.get(0));
console.log('list size = ', list.size());