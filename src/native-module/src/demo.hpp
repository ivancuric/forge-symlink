#include <napi.h>

namespace demo {

  int add(int x, int y);

  // Wrapper for add
  Napi::Number addWrapped(const Napi::CallbackInfo& info);

  // Export API ??
  Napi::Object Init(Napi::Env env, Napi::Object exports);
  NODE_API_MODULE(addon, Init);
}
