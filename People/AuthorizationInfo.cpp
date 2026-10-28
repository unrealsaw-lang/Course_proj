#include "AuthorizationInfo.h"
using namespace std;

AuthorizationInfo::AuthorizationInfo(Person* P, const string& log, const string& pass) : person(P), login(log), password(pass) {}