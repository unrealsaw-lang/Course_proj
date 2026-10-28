#include <iostream>
#include "Person.h"
#include "Client.h"
#include "AuthorizationInfo.h"
#include "IdGenerator.h"
using namespace std;


int main(){
	Client user ("Ivan", "Ivanov", "Ivanovich", "email", "phone", "Mensk", 666);
	IdGenerator::generate(&user);
	user.signUp();
	user.runAuthorizationLoop();
	user.print(cout);
	return 0;
}
