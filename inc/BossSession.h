
#ifndef BOSS_SESSION_H 
#define BOSS_SESSION_H

#include "Session.h"

class BossSession : public Session {
public:
  BossSession (Library *library);
  ~BossSession ();
  
  void start();
  
  void addWorker();
  void removeUser();

};

#endif
