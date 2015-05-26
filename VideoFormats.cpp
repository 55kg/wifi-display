<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd"><html><head><title>media/libstagefright/wifi-display/VideoFormats.cpp - platform/frameworks/av - Git at Google</title><link rel="stylesheet" type="text/css" href="//www.google.com/css/go.css" /><link rel="stylesheet" type="text/css" href="/+static/prettify/prettify.vf-M93Ay4IiiWRQSJKPGWQ.cache.css" /><link rel="stylesheet" type="text/css" href="/+static/gitiles.JPyDgEz4Jj5aQRFU8GjJJQ.cache.css" /><script src="/+static/prettify/prettify_compiled.wQKdUVM0AfatEiTiXCI6lw.cache.js" type="text/javascript"></script></head><body onload="prettyPrint()"><h1><img src="//www.google.com/images/logo_sm.gif" alt="Google" />Git</h1><div class="menu"> <a href="https://www.google.com/accounts/ServiceLogin?service=gerritcodereview&continue=https://android.googlesource.com/login/platform/frameworks/av/%2B/android-4.3_r0.9/media/libstagefright/wifi-display/VideoFormats.cpp">Sign in</a> </div><div class="breadcrumbs"><a href="/?format=HTML">android</a> / <a href="/platform/frameworks/av/">platform/frameworks/av</a> / <a href="/platform/frameworks/av/+/android-4.3_r0.9">android-4.3_r0.9</a> / <a href="/platform/frameworks/av/+/android-4.3_r0.9/">.</a> / <a href="/platform/frameworks/av/+/android-4.3_r0.9/media">media</a> / <a href="/platform/frameworks/av/+/android-4.3_r0.9/media/libstagefright">libstagefright</a> / <a href="/platform/frameworks/av/+/android-4.3_r0.9/media/libstagefright/wifi-display">wifi-display</a> / VideoFormats.cpp</div><div class="sha1">blob: 458b1633d899c76d495c5ea118ef5ae287b7758f [<a href="/platform/frameworks/av/+log/android-4.3_r0.9/media/libstagefright/wifi-display/VideoFormats.cpp">file history</a>]</div><pre class="git-blob prettyprint linenums lang-cpp">/*
 * Copyright 2013, The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#define LOG_NDEBUG 0
#define LOG_TAG "VideoFormats"
#include <utils/Log.h>

#include "VideoFormats.h"

#include <media/stagefright/foundation/ADebug.h>

namespace android {

VideoFormats::config_t VideoFormats::mConfigs[][32] = {
    {
        // CEA Resolutions
        { 640, 480, 60, false, 0, 0},
        { 720, 480, 60, false, 0, 0},
        { 720, 480, 60, true, 0, 0},
        { 720, 576, 50, false, 0, 0},
        { 720, 576, 50, true, 0, 0},
        { 1280, 720, 30, false, 0, 0},
        { 1280, 720, 60, false, 0, 0},
        { 1920, 1080, 30, false, 0, 0},
        { 1920, 1080, 60, false, 0, 0},
        { 1920, 1080, 60, true, 0, 0},
        { 1280, 720, 25, false, 0, 0},
        { 1280, 720, 50, false, 0, 0},
        { 1920, 1080, 25, false, 0, 0},
        { 1920, 1080, 50, false, 0, 0},
        { 1920, 1080, 50, true, 0, 0},
        { 1280, 720, 24, false, 0, 0},
        { 1920, 1080, 24, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
    },
    {
        // VESA Resolutions
        { 800, 600, 30, false, 0, 0},
        { 800, 600, 60, false, 0, 0},
        { 1024, 768, 30, false, 0, 0},
        { 1024, 768, 60, false, 0, 0},
        { 1152, 864, 30, false, 0, 0},
        { 1152, 864, 60, false, 0, 0},
        { 1280, 768, 30, false, 0, 0},
        { 1280, 768, 60, false, 0, 0},
        { 1280, 800, 30, false, 0, 0},
        { 1280, 800, 60, false, 0, 0},
        { 1360, 768, 30, false, 0, 0},
        { 1360, 768, 60, false, 0, 0},
        { 1366, 768, 30, false, 0, 0},
        { 1366, 768, 60, false, 0, 0},
        { 1280, 1024, 30, false, 0, 0},
        { 1280, 1024, 60, false, 0, 0},
        { 1400, 1050, 30, false, 0, 0},
        { 1400, 1050, 60, false, 0, 0},
        { 1440, 900, 30, false, 0, 0},
        { 1440, 900, 60, false, 0, 0},
        { 1600, 900, 30, false, 0, 0},
        { 1600, 900, 60, false, 0, 0},
        { 1600, 1200, 30, false, 0, 0},
        { 1600, 1200, 60, false, 0, 0},
        { 1680, 1024, 30, false, 0, 0},
        { 1680, 1024, 60, false, 0, 0},
        { 1680, 1050, 30, false, 0, 0},
        { 1680, 1050, 60, false, 0, 0},
        { 1920, 1200, 30, false, 0, 0},
        { 1920, 1200, 60, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
    },
    {
        // HH Resolutions
        { 800, 480, 30, false, 0, 0},
        { 800, 480, 60, false, 0, 0},
        { 854, 480, 30, false, 0, 0},
        { 854, 480, 60, false, 0, 0},
        { 864, 480, 30, false, 0, 0},
        { 864, 480, 60, false, 0, 0},
        { 640, 360, 30, false, 0, 0},
        { 640, 360, 60, false, 0, 0},
        { 960, 540, 30, false, 0, 0},
        { 960, 540, 60, false, 0, 0},
        { 848, 480, 30, false, 0, 0},
        { 848, 480, 60, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
        { 0, 0, 0, false, 0, 0},
    }
};

VideoFormats::VideoFormats() {
    for (size_t i = 0; i < kNumResolutionTypes; ++i) {
        mResolutionEnabled[i] = 0;
    }

    setNativeResolution(RESOLUTION_CEA, 0);  // default to 640x480 p60
}

void VideoFormats::setNativeResolution(ResolutionType type, size_t index) {
    CHECK_LT(type, kNumResolutionTypes);
    CHECK(GetConfiguration(type, index, NULL, NULL, NULL, NULL));

    mNativeType = type;
    mNativeIndex = index;

    setResolutionEnabled(type, index);
}

void VideoFormats::getNativeResolution(
        ResolutionType *type, size_t *index) const {
    *type = mNativeType;
    *index = mNativeIndex;
}

void VideoFormats::disableAll() {
    for (size_t i = 0; i < kNumResolutionTypes; ++i) {
        mResolutionEnabled[i] = 0;
        for (size_t j = 0; j < 32; j++) {
            mConfigs[i][j].profile = mConfigs[i][j].level = 0;
        }
    }
}

void VideoFormats::enableAll() {
    for (size_t i = 0; i < kNumResolutionTypes; ++i) {
        mResolutionEnabled[i] = 0xffffffff;
        for (size_t j = 0; j < 32; j++) {
            mConfigs[i][j].profile = (1ul << PROFILE_CBP);
            mConfigs[i][j].level = (1ul << LEVEL_31);
        }
    }
}

void VideoFormats::setResolutionEnabled(
        ResolutionType type, size_t index, bool enabled) {
    CHECK_LT(type, kNumResolutionTypes);
    CHECK(GetConfiguration(type, index, NULL, NULL, NULL, NULL));

    if (enabled) {
        mResolutionEnabled[type] |= (1ul << index);
    } else {
        mResolutionEnabled[type] &= ~(1ul << index);
    }
}

bool VideoFormats::isResolutionEnabled(
        ResolutionType type, size_t index) const {
    CHECK_LT(type, kNumResolutionTypes);
    CHECK(GetConfiguration(type, index, NULL, NULL, NULL, NULL));

    return mResolutionEnabled[type] & (1ul << index);
}

// static
bool VideoFormats::GetConfiguration(
        ResolutionType type,
        size_t index,
        size_t *width, size_t *height, size_t *framesPerSecond,
        bool *interlaced) {
    CHECK_LT(type, kNumResolutionTypes);

    if (index >= 32) {
        return false;
    }

    const config_t *config = &mConfigs[type][index];

    if (config->width == 0) {
        return false;
    }

    if (width) {
        *width = config->width;
    }

    if (height) {
        *height = config->height;
    }

    if (framesPerSecond) {
        *framesPerSecond = config->framesPerSecond;
    }

    if (interlaced) {
        *interlaced = config->interlaced;
    }

    return true;
}

bool VideoFormats::parseH264Codec(const char *spec) {
    unsigned profile, level, res[3];

    if (sscanf(
            spec,
            "%02x %02x %08X %08X %08X",
            &profile,
            &level,
            &res[0],
            &res[1],
            &res[2]) != 5) {
        return false;
    }

    for (size_t i = 0; i < kNumResolutionTypes; ++i) {
        for (size_t j = 0; j < 32; ++j) {
            if (res[i] & (1ul << j)){
                mResolutionEnabled[i] |= (1ul << j);
                if (profile > mConfigs[i][j].profile) {
                    mConfigs[i][j].profile = profile;
                    if (level > mConfigs[i][j].level)
                        mConfigs[i][j].level = level;
                }
            }
        }
    }

    return true;
}

bool VideoFormats::parseFormatSpec(const char *spec) {
    CHECK_EQ(kNumResolutionTypes, 3);

    unsigned native, dummy;
    unsigned res[3];
    size_t size = strlen(spec);
    size_t offset = 0;

    if (sscanf(spec, "%02x %02x ", &native, &dummy) != 2) {
        return false;
    }

    offset += 6; // skip native and preferred-display-mode-supported
    CHECK_LE(offset + 58, size);
    while (offset < size) {
        parseH264Codec(spec + offset);
        offset += 60; // skip H.264-codec + ", "
    }

    mNativeIndex = native >> 3;
    mNativeType = (ResolutionType)(native & 7);

    bool success;
    if (mNativeType >= kNumResolutionTypes) {
        success = false;
    } else {
        success = GetConfiguration(
                mNativeType, mNativeIndex, NULL, NULL, NULL, NULL);
    }

    if (!success) {
        ALOGW("sink advertised an illegal native resolution, fortunately "
              "this value is ignored for the time being...");
    }

    return true;
}

AString VideoFormats::getFormatSpec(bool forM4Message) const {
    CHECK_EQ(kNumResolutionTypes, 3);

    // wfd_video_formats:
    // 1 byte "native"
    // 1 byte "preferred-display-mode-supported" 0 or 1
    // one or more avc codec structures
    //   1 byte profile
    //   1 byte level
    //   4 byte CEA mask
    //   4 byte VESA mask
    //   4 byte HH mask
    //   1 byte latency
    //   2 byte min-slice-slice
    //   2 byte slice-enc-params
    //   1 byte framerate-control-support
    //   max-hres (none or 2 byte)
    //   max-vres (none or 2 byte)

    return StringPrintf(
            "%02x 00 02 02 %08x %08x %08x 00 0000 0000 00 none none",
            forM4Message ? 0x00 : ((mNativeIndex << 3) | mNativeType),
            mResolutionEnabled[0],
            mResolutionEnabled[1],
            mResolutionEnabled[2]);
}

// static
bool VideoFormats::PickBestFormat(
        const VideoFormats &sinkSupported,
        const VideoFormats &sourceSupported,
        ResolutionType *chosenType,
        size_t *chosenIndex) {
#if 0
    // Support for the native format is a great idea, the spec includes
    // these features, but nobody supports it and the tests don&#39;t validate it.

    ResolutionType nativeType;
    size_t nativeIndex;
    sinkSupported.getNativeResolution(&nativeType, &nativeIndex);
    if (sinkSupported.isResolutionEnabled(nativeType, nativeIndex)) {
        if (sourceSupported.isResolutionEnabled(nativeType, nativeIndex)) {
            ALOGI("Choosing sink&#39;s native resolution");
            *chosenType = nativeType;
            *chosenIndex = nativeIndex;
            return true;
        }
    } else {
        ALOGW("Sink advertised native resolution that it doesn&#39;t "
              "actually support... ignoring");
    }

    sourceSupported.getNativeResolution(&nativeType, &nativeIndex);
    if (sourceSupported.isResolutionEnabled(nativeType, nativeIndex)) {
        if (sinkSupported.isResolutionEnabled(nativeType, nativeIndex)) {
            ALOGI("Choosing source&#39;s native resolution");
            *chosenType = nativeType;
            *chosenIndex = nativeIndex;
            return true;
        }
    } else {
        ALOGW("Source advertised native resolution that it doesn&#39;t "
              "actually support... ignoring");
    }
#endif

    bool first = true;
    uint32_t bestScore = 0;
    size_t bestType = 0;
    size_t bestIndex = 0;
    for (size_t i = 0; i < kNumResolutionTypes; ++i) {
        for (size_t j = 0; j < 32; ++j) {
            size_t width, height, framesPerSecond;
            bool interlaced;
            if (!GetConfiguration(
                        (ResolutionType)i,
                        j,
                        &width, &height, &framesPerSecond, &interlaced)) {
                break;
            }

            if (!sinkSupported.isResolutionEnabled((ResolutionType)i, j)
                    || !sourceSupported.isResolutionEnabled(
                        (ResolutionType)i, j)) {
                continue;
            }

            ALOGV("type %u, index %u, %u x %u %c%u supported",
                  i, j, width, height, interlaced ? &#39;i&#39; : &#39;p&#39;, framesPerSecond);

            uint32_t score = width * height * framesPerSecond;
            if (!interlaced) {
                score *= 2;
            }

            if (first || score > bestScore) {
                bestScore = score;
                bestType = i;
                bestIndex = j;

                first = false;
            }
        }
    }

    if (first) {
        return false;
    }

    *chosenType = (ResolutionType)bestType;
    *chosenIndex = bestIndex;

    return true;
}

}  // namespace android

</pre><div class="footer">Powered by <a href="https://code.google.com/p/gitiles/">Gitiles</a></div></body></html>