/**
 * FairMQContextZMQ.cxx
 *
 * @since 2012-12-05
 * @author D. Klein, A. Rybalchenko
 */

#include "FairMQLogger.h"
#include "FairMQContextZMQ.h"
#include <sstream>

FairMQContextZMQ::FairMQContextZMQ(int numIoThreads)
{
  fContext = zmq_ctx_new ();
  if (fContext == NULL){
    stringstream logmsg;
    logmsg << "failed creating context, reason: " << zmq_strerror(errno);
    FairMQLogger::GetInstance()->Log(FairMQLogger::ERROR, logmsg.str());
  }

  int rc = zmq_ctx_set (fContext, ZMQ_IO_THREADS, numIoThreads);
  if (rc != 0){
    stringstream logmsg;
    logmsg << "failed configuring context, reason: " << zmq_strerror(errno);
    FairMQLogger::GetInstance()->Log(FairMQLogger::ERROR, logmsg.str());
  }
}

FairMQContextZMQ::~FairMQContextZMQ()
{
  Close();
}

void* FairMQContextZMQ::GetContext()
{
  return fContext;
}

void FairMQContextZMQ::Close()
{
  if (fContext == NULL){
    return;
  }

  int rc = zmq_ctx_destroy (fContext);
  if (rc != 0) {
    stringstream logmsg;
    logmsg << "failed closing context, reason: " << zmq_strerror(errno);
    FairMQLogger::GetInstance()->Log(FairMQLogger::ERROR, logmsg.str());
  }

  fContext = NULL;
}
