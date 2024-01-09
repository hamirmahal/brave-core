/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_SERVING_ELIGIBLE_ADS_PRIORITY_PRIORITY_H_
#define BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_SERVING_ELIGIBLE_ADS_PRIORITY_PRIORITY_H_

#include <cstddef>

#include "base/containers/flat_map.h"
#include "brave/components/brave_ads/core/internal/serving/eligible_ads/priority/priority_util.h"

namespace brave_ads {

template <typename T>
base::flat_map</*priority*/ int, /*creative_ads*/ T>
SortCreativeAdsIntoBucketsByPriority(const T& creative_ads) {
  base::flat_map<int, T> buckets;

  for (const auto& creative_ad : creative_ads) {
    if (creative_ad.priority == 0) {
      // Do not include ads with a priority of 0.
      continue;
    }

    buckets[creative_ad.priority].push_back(creative_ad);
  }

  return buckets;
}

template <typename T>
T HighestPriorityCreativeAds(const T& creative_ads) {
  const base::flat_map<int, T> buckets =
      SortCreativeAdsIntoBucketsByPriority(creative_ads);

  LogNumberOfCreativeAdsPerBucket(buckets);

  if (buckets.empty()) {
    return {};
  }

  return buckets.cbegin()->second;
}

template <typename T>
void LogNumberOfCreativeAdsPerBucket(
    const base::flat_map</*priority*/ int, /*creative_ads*/ T>& buckets) {
  size_t bucket = 1;

  for (const auto& [priority, creative_ads] : buckets) {
    LogNumberOfUntargetedCreativeAdsForBucket(creative_ads, priority, bucket);
    LogNumberOfTargetedCreativeAdsForBucket(creative_ads, priority, bucket);

    ++bucket;
  }
}

}  // namespace brave_ads

#endif  // BRAVE_COMPONENTS_BRAVE_ADS_CORE_INTERNAL_SERVING_ELIGIBLE_ADS_PRIORITY_PRIORITY_H_
