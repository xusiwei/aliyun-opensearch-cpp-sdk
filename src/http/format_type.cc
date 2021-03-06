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

#include "aliyun/http/format_type.h"

#include <apr_general.h>
#include <string.h>

namespace aliyun {
namespace http {


FormatType::FormatType(Value v)
    : value_(v) {
}

std::string FormatType::toString() const {
#define S(e) #e
  static const char* NAMES[] = { S(INVALID), S(XML), S(JSON), S(RAW) };
#undef S
  int v = value_;
  return NAMES[(0 <= v && v <= RAW) ? v : INVALID];
}

std::string FormatType::mapFormatToAccept(FormatType format) {
  if (FormatType::XML == format.value_)
    return "application/xml";
  if (FormatType::JSON == format.value_)
    return "application/json";

  return "application/octet-stream";
}

FormatType FormatType::mapAcceptToFormat(std::string accept) {
  if (strncasecmp(accept.c_str(), "application/xml",
                    sizeof("application/xml")) == 0
      || strncasecmp(accept.c_str(), "text/xml", sizeof("text/xml")) == 0)
    return FormatType(XML);
  if (strncasecmp(accept.c_str(), "application/json",
                    sizeof("application/json")) == 0)
    return FormatType(JSON);

  return FormatType(RAW);
}

#if 0
FormatType &FormatType::operator=(FormatType::Value v) {
  this->value_ = v;
  return *this;
}
#endif

}  // namespace http
}  // namespace aliyun

