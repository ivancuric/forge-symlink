#include "demo.hpp"

namespace demo {

  int add(int x, int y) {
    return x + y;
  }

  Napi::Number addWrapped(const Napi::CallbackInfo& info) {
    // Plain value?
    Napi::Env env = info.Env();

    if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
      Napi::TypeError::New(env, "number arguments expected!")
        .ThrowAsJavaScriptException();
    }

    Napi::Number x = info[0].As<Napi::Number>();
    Napi::Number y = info[1].As<Napi::Number>();
    int result = add(x.Int32Value(), y.Int32Value());

    return Napi::Number::New(env, result);
  }

  Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("add", Napi::Function::New(env, addWrapped));

    return exports;
  }
}
