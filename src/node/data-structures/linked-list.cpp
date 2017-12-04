// myobject.cc
#include "linked-list.h"
#include "../../data-structures/linked-list.h"

namespace wrapper {

v8::Persistent<v8::Function> LinkedList::constructor;

LinkedList::LinkedList()
  :
  list_(std::make_unique<datastructures::LinkedList<int> >())
  {}

LinkedList::~LinkedList() {
}

void LinkedList::Init(v8::Local<v8::Object> exports) {
  v8::Isolate* isolate = exports->GetIsolate();

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
  tpl->SetClassName(v8::String::NewFromUtf8(isolate, "LinkedList"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "push_back", push_back);
  NODE_SET_PROTOTYPE_METHOD(tpl, "push_front", push_front);
  NODE_SET_PROTOTYPE_METHOD(tpl, "get", get);
  NODE_SET_PROTOTYPE_METHOD(tpl, "size", size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "reset", reset);
  NODE_SET_PROTOTYPE_METHOD(tpl, "delete", deleteAtPosition);
  NODE_SET_PROTOTYPE_METHOD(tpl, "insertAtPosition", insertAtPosition);

  constructor.Reset(isolate, tpl->GetFunction());
  exports->Set(v8::String::NewFromUtf8(isolate, "LinkedList"),
               tpl->GetFunction());
}

void LinkedList::New(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new LinkedList(...)`
    LinkedList* obj = new LinkedList();
    obj->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `LinkedList(...)`, turn into construct call.
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { args[0] };
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, constructor);
    v8::Local<v8::Object> result =
        cons->NewInstance(context, argc, argv).ToLocalChecked();
    args.GetReturnValue().Set(result);
  }
}

void LinkedList::push_back(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 1) {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Please provide one argument")));
      return;
    }

    // Check the argument types
    if (!args[0]->IsNumber()) {
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Argument should be a number")));
      return;
    }

    LinkedList* obj = ObjectWrap::Unwrap<LinkedList>(args.Holder());
    obj->list_->push_back(args[0]->Int32Value());
}

void LinkedList::push_front(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 1) {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Please provide one argument")));
      return;
    }

    // Check the argument types
    if (!args[0]->IsNumber()) {
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Argument should be a number")));
      return;
    }

    LinkedList* obj = ObjectWrap::Unwrap<LinkedList>(args.Holder());
    obj->list_->push_front(args[0]->Int32Value());
}

void LinkedList::get(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();
    // Check the number of arguments passed.
    if (args.Length() < 1 || args.Length() > 1) {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Please provide one argument")));
        return;
    }

    // Check the argument types
    if (!args[0]->IsNumber()) {
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Argument should be a number")));
      return;
    }

    LinkedList* obj = ObjectWrap::Unwrap<LinkedList>(args.Holder());
    if (args[0]->Int32Value() > obj->list_->size()) {
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Index out of bounds")));
      return;
    }
    int result = obj->list_->get(args[0]->Int32Value());
    args.GetReturnValue().Set(result);
}

void LinkedList::reset(const v8::FunctionCallbackInfo<v8::Value>& args) {
  LinkedList* obj = ObjectWrap::Unwrap<LinkedList>(args.Holder());
  obj->list_->reset();
}

void LinkedList::size(const v8::FunctionCallbackInfo<v8::Value>& args) {
  LinkedList* obj = ObjectWrap::Unwrap<LinkedList>(args.Holder());
  args.GetReturnValue().Set(obj->list_->size());
}

void LinkedList::deleteAtPosition(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  // Check the number of arguments passed.
  if (args.Length() < 1 || args.Length() > 1) {
    // Throw an Error that is passed back to JavaScript
    isolate->ThrowException(v8::Exception::TypeError(
      v8::String::NewFromUtf8(isolate, "Please provide one argument")));
      return;
  }

  // Check the argument types
  if (!args[0]->IsNumber()) {
    isolate->ThrowException(v8::Exception::TypeError(
      v8::String::NewFromUtf8(isolate, "Argument should be a number")));
    return;
  }

  LinkedList* obj = ObjectWrap::Unwrap<LinkedList>(args.Holder());
  obj->list_->erase(args[0]->Int32Value());
}

void LinkedList::insertAtPosition(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() != 2) {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Please provide the position and the value")));
      return;
    }

    // Check the argument types
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
      isolate->ThrowException(v8::Exception::TypeError(
        v8::String::NewFromUtf8(isolate, "Arguments should be a number")));
      return;
    }

    LinkedList* obj = ObjectWrap::Unwrap<LinkedList>(args.Holder());
    obj->list_->insertAtPosition(args[0]->Int32Value(), args[1]->Int32Value());
}

}  // namespace wrapper