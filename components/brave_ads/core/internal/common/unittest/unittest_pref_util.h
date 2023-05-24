/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_COMMON_UNITTEST_UNITTEST_PREF_UTIL_H_
#define BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_COMMON_UNITTEST_UNITTEST_PREF_UTIL_H_

#include <cstdint>
#include <string>

#include "base/values.h"

namespace base {
class Time;
}  // namespace base

namespace brave_ads {

// Unlike |ads_client_mock_->Set*Pref| in |UnitTestBase|, |SetDefault*Pref| does
// not notify observers.
void SetDefaultBooleanPref(const std::string& path, bool value);
void SetDefaultIntegerPref(const std::string& path, int value);
void SetDefaultDoublePref(const std::string& path, double value);
void SetDefaultStringPref(const std::string& path, const std::string& value);
void SetDefaultInt64Pref(const std::string& path, int64_t value);
void SetDefaultUint64Pref(const std::string& path, uint64_t value);
void SetDefaultDictPref(const std::string& path, base::Value::Dict value);
void SetDefaultListPref(const std::string& path, base::Value::List value);
void SetDefaultTimePref(const std::string& path, base::Time value);

}  // namespace brave_ads

#endif  // BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_COMMON_UNITTEST_UNITTEST_PREF_UTIL_H_
