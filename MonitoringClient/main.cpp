#include "main.h"

int main(int ac, char **av)
{
	Client *client = new Client();
	client->setServer("localhost");
	client->setPort("16000");
	client->Run();

	return 0;
}