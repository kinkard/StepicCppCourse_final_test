//
// Created by kizim on 3/3/16.
//

#ifndef FINAL_REPLY_H
#define FINAL_REPLY_H

#include <string>
#include <vector>
#include <boost/asio.hpp>

struct header
{
  std::string name;
  std::string value;
};

/// A reply to be sent to a client.
struct reply
{
  /// The status of the reply.
  enum status_type
  {
    ok = 200,
    not_found = 404,
  } status;

  /// The headers to be included in the reply.
  std::vector<header> headers;

  /// The content to be sent in the reply.
  std::string content;

  /// Convert the reply into a vector of buffers. The buffers do not own the
  /// underlying memory blocks, therefore the reply object must remain valid and
  /// not be changed until the write operation has completed.
  std::vector<boost::asio::const_buffer> to_buffers();

  /// Get a stock reply.
  static reply stock_reply(status_type status);
};

#endif //FINAL_REPLY_H
