//
// Created by kizim on 3/9/16.
//

#ifndef FINAL_HELPER_H
#define FINAL_HELPER_H

bool url_decode(const std::string& in, std::string& out)
{
  out.clear();
  out.reserve(in.size());
  for (std::size_t i = 0; i < in.size(); ++i)
  {
    if (in[i] == '%')
    {
      if (i + 3 <= in.size())
      {
        int value = 0;
        std::istringstream is(in.substr(i + 1, 2));
        if (is >> std::hex >> value)
        {
          out += static_cast<char>(value);
          i += 2;
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    else if (in[i] == '+')
    {
      out += ' ';
    }
    else if (in[i] == '?')
    {
      out += '\0';
    }
    else
    {
      out += in[i];
    }


  }
  return true;
}

#endif //FINAL_HELPER_H
