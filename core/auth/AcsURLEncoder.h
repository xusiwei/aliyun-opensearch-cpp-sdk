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

#ifndef CORE_AUTH_ACSURLENCODER_H_
#define CORE_AUTH_ACSURLENCODER_H_

#include <curl/curl.h>
#include <string>

namespace aliyun {

namespace auth {

class AcsURLEncoder {
 public:
  typedef std::string string;

  AcsURLEncoder();

  ~AcsURLEncoder();

  string encodeString(string input);

  static AcsURLEncoder * getInstance();

  // static(class) usage
  static string encode(string in) {
    return getInstance()->encodeString(in);
  }

  static string percentEncode(string in) {
    string basis = encode(in);
    replace(basis, "+", "%20");
    replace(basis, "*", "%2A");
    replace(basis, "%7E", "~");  // swap it ?
    return basis;
  }

 private:
  static void replace(string& operand, string source, string target) {
    string::size_type pos = operand.find(source);
    if (pos != string::npos) {
      operand.replace(pos, source.length(), target);
    }
  }

  void updateUri(char* uri);

 private:
  CURL* curl_;
  char* uri_;

  static AcsURLEncoder* sInstance_;
};

}  // namespace auth

}  // namespace aliyun

#endif  // CORE_AUTH_ACSURLENCODER_H_