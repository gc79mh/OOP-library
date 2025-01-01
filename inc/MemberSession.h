#ifndef MEMBER_SESSION_H 
#define MEMBER_SESSION_H

#include "Session.h"
#include "Member.h"
#include "User.h"

class MemberSession : public Session{
public:
  MemberSession (Library &library);
  ~MemberSession ();
  
  void start(Member *member);

  void displayMemberBooks(Member* user);

  void memberRent(Member* user);
  void memberReturn(Member* user);

};

#endif
