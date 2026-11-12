#include <AppVersion.h>
#include <string>

// Only this translation unit receives the changing version and Git defines.
#ifndef CROSSINK_VERSION
#define CROSSINK_VERSION "dev"
#endif

#ifndef CROSSINK_GIT_SHA
#define CROSSINK_GIT_SHA "unknown"
#endif

#ifndef CROSSINK_GIT_DIRTY
#define CROSSINK_GIT_DIRTY "unknown"
#endif

#ifndef CROSSINK_SUPPORT_VERSION
#define CROSSINK_SUPPORT_VERSION "unknown"
#endif
#ifndef CROSSINK_SDK_SHA
#define CROSSINK_SDK_SHA "unknown"
#endif

namespace AppVersion {
const char* version() { return CROSSINK_VERSION; }
// Display label for Settings > System only. Keep firmware version/userAgent unchanged.
const char* versionLabel() {
  static const std::string label = [] {
    const std::string revision = CROSSINK_GIT_SHA;
    const std::string shortRevision = (revision == "unknown" || revision.empty())
                                          ? "xxxxxx"
                                          : revision.substr(0, 6);
    return std::string("CrossInk v2.0.0-") + shortRevision + "_RC by 4htet";
  }();
  return label.c_str();
}
const char* userAgent() { return "CrossInk-ESP32-" CROSSINK_VERSION; }
const char* supportVersion() { return CROSSINK_SUPPORT_VERSION; }
const char* sdkSha() { return CROSSINK_SDK_SHA; }
const char* gitSha() { return CROSSINK_GIT_SHA; }
const char* gitDirtyFlag() { return CROSSINK_GIT_DIRTY; }
}  // namespace AppVersion
