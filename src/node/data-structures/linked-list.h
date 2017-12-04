// data-structures.h
#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <node.h>
#include <node_object_wrap.h>
#include "../../data-structures/linked-list.h"

namespace wrapper {

class LinkedList : public node::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);

 private:
  explicit LinkedList();
  ~LinkedList();

  static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void push_back(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void push_front(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void insertAtPosition(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void deleteAtPosition(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void reset(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void size(const v8::FunctionCallbackInfo<v8::Value>& args);
  static void get(const v8::FunctionCallbackInfo<v8::Value>& args);
  static v8::Persistent<v8::Function> constructor;
  std::unique_ptr<datastructures::LinkedList<int> > list_;
};

}  // namespace wrapper

#endif