#include <node.h>
#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>
#include <locale>
#include <vector>
#include "./alglib/ap.h"
#include "./alglib/specialfunctions.h"

namespace demo
{

using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  int x = (int)args[0]->NumberValue();
  double prob = (double)args[1]->NumberValue();
  double result = alglib_impl::invpoissondistribution(x, prob, NULL);
  args.GetReturnValue().Set(v8::Number::New(isolate, result));
}

void Method2(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  int x = (int)args[0]->NumberValue();
  double expValue = (double)args[1]->NumberValue();
  double result = alglib_impl::poissondistribution(x, expValue, NULL);
  args.GetReturnValue().Set(v8::Number::New(isolate, result));
}

void Initialize(Local<Object> exports)
{
  NODE_SET_METHOD(exports, "invPoissonDistribution", Method);
  NODE_SET_METHOD(exports, "poissonDistribution", Method2);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace demo