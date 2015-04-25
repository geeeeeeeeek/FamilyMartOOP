#include <iostream>
#include "event.h"

using namespace std;
int main(int argc, char* argv[])
{
	event::eventmanager em;
	em.listen();
	return 0;
}