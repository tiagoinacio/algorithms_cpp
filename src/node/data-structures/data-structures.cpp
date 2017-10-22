// data-structures.cpp
#include <node.h>
#include "linked-list.h"

namespace wrapper {

void InitAll(v8::Local<v8::Object> exports) {
  LinkedList::Init(exports);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)

}  // namespace wrapper