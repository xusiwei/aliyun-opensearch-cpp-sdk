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

#ifndef ALIYUN_READER_READER_H_
#define ALIYUN_READER_READER_H_

#include <map>
#include <string>

namespace aliyun {
namespace reader {

class Reader {
 public:
  typedef std::string string;

  virtual ~Reader() {}

  virtual std::map<string, string> read(string response, string endpoint) = 0;
};

}  // namespace reader
}  // namespace aliyun

#endif  // ALIYUN_READER_READER_H_
