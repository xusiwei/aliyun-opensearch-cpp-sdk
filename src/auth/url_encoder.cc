/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */


#include "aliyun/auth/url_encoder.h"

namespace aliyun {

namespace auth {

UrlEncoder *UrlEncoder::sInstance_ = NULL;

UrlEncoder::UrlEncoder()
    : curl_(NULL),
      uri_(NULL) {
  curl_ = curl_easy_init();
}

UrlEncoder::~UrlEncoder() {
  curl_easy_cleanup(curl_);
  curl_free(uri_);
}

UrlEncoder::string UrlEncoder::encodeString(string input) {
  if (input.length() == 0) {
    return "";
  }
  char* uri = curl_easy_escape(curl_, input.c_str(), input.length());
  updateUri(uri);
  return uri;
}

UrlEncoder *UrlEncoder::getInstance() {
  if (sInstance_ == NULL) {
    static UrlEncoder stub;
    sInstance_ = &stub;
  }
  return sInstance_;
}

void UrlEncoder::updateUri(char* uri) {
  if (NULL != uri_) {
    curl_free(uri_);
  }
  uri_ = uri;
}

}  // namespace auth

}  // namespace aliyun

