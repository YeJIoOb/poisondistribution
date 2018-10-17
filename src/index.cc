#include <node.h>
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
  if (args.Length() < 2)
  {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Bad arguments")));
    return;
  }
  if (!(args[0]->IsNumber() && args[1]->IsNumber()))
  {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Bad arguments")));
    return;
  }
  int x = (int)args[0]->NumberValue();
  double prob = (double)args[1]->NumberValue();

  if (!(prob >= 0 && prob <= 1))
  {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Second argument must be between 0 and 1")));
    return;
  }
  double result = alglib_impl::invpoissondistribution(x, prob, NULL);
  args.GetReturnValue().Set(v8::Number::New(isolate, result));
}

void Method2(const FunctionCallbackInfo<Value> &args)
{
  Isolate *isolate = args.GetIsolate();
  if (args.Length() < 2)
  {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Bad arguments")));
    return;
  }
  if (!(args[0]->IsNumber() && args[1]->IsNumber()))
  {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Bad arguments")));
    return;
  }
  int x = (int)args[0]->NumberValue();
  double expValue = (double)args[1]->NumberValue();

  if (!(expValue >= 0 && expValue <= 1))
  {
    isolate->ThrowException(v8::Exception::TypeError(v8::String::NewFromUtf8(isolate, "Second argument must be between 0 and 1")));
    return;
  }
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