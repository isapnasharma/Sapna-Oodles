/* C++ code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf -L C++ -E -t /private/var/folders/g3/7_v82tm95798_8qvw7dgx8cm0000gn/T/mac/androidcurrentlocation-generated/KrollGeneratedBindings.gperf  */
/* Computed positions: -k'' */

#line 3 "/private/var/folders/g3/7_v82tm95798_8qvw7dgx8cm0000gn/T/mac/androidcurrentlocation-generated/KrollGeneratedBindings.gperf"


#include <string.h>
#include <v8.h>
#include <KrollBindings.h>

#include "com.oodles.androidcurrentlocation.AndroidCurrentLocationModule.h"
#include "com.oodles.androidcurrentlocation.ExampleProxy.h"


#line 14 "/private/var/folders/g3/7_v82tm95798_8qvw7dgx8cm0000gn/T/mac/androidcurrentlocation-generated/KrollGeneratedBindings.gperf"
struct titanium::bindings::BindEntry;
/* maximum key range = 17, duplicates = 0 */

class AndroidCurrentLocationBindings
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static struct titanium::bindings::BindEntry *lookupGeneratedInit (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
AndroidCurrentLocationBindings::hash (register const char *str, register unsigned int len)
{
  return len;
}

struct titanium::bindings::BindEntry *
AndroidCurrentLocationBindings::lookupGeneratedInit (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 2,
      MIN_WORD_LENGTH = 46,
      MAX_WORD_LENGTH = 62,
      MIN_HASH_VALUE = 46,
      MAX_HASH_VALUE = 62
    };

  static struct titanium::bindings::BindEntry wordlist[] =
    {
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""},
#line 17 "/private/var/folders/g3/7_v82tm95798_8qvw7dgx8cm0000gn/T/mac/androidcurrentlocation-generated/KrollGeneratedBindings.gperf"
      {"com.oodles.androidcurrentlocation.ExampleProxy", ::com::oodles::androidcurrentlocation::androidcurrentlocation::ExampleProxy::bindProxy, ::com::oodles::androidcurrentlocation::androidcurrentlocation::ExampleProxy::dispose},
      {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""}, {""},
      {""}, {""}, {""}, {""}, {""}, {""},
#line 16 "/private/var/folders/g3/7_v82tm95798_8qvw7dgx8cm0000gn/T/mac/androidcurrentlocation-generated/KrollGeneratedBindings.gperf"
      {"com.oodles.androidcurrentlocation.AndroidCurrentLocationModule", ::com::oodles::androidcurrentlocation::AndroidCurrentLocationModule::bindProxy, ::com::oodles::androidcurrentlocation::AndroidCurrentLocationModule::dispose}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
#line 18 "/private/var/folders/g3/7_v82tm95798_8qvw7dgx8cm0000gn/T/mac/androidcurrentlocation-generated/KrollGeneratedBindings.gperf"

