/**
 * FairMQConfigurable.h
 *
 * @since 2012-10-25
 * @author D. Klein, A. Rybalchenko
 */

#ifndef FAIRMQCONFIGURABLE_H_
#define FAIRMQCONFIGURABLE_H_

#include <string>

using std::string;

class FairMQConfigurable
{
  public:
    enum {
      Last = 1
    };
    FairMQConfigurable();
    virtual void SetProperty(const int key, const string& value, const int slot = 0);
    virtual string GetProperty(const int key, const string& default_ = "", const int slot = 0);
    virtual void SetProperty(const int key, const int value, const int slot = 0);
    virtual int GetProperty(const int key, const int default_ = 0, const int slot = 0);
    virtual ~FairMQConfigurable();

    // TODO: by value for integers
};

#endif /* FAIRMQCONFIGURABLE_H_ */
