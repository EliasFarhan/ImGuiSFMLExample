#include <engine.h>


int main(int argc, char **argv)
{
	Engine::GetInstance()->Init();
	Engine::GetInstance()->Start();

#ifdef WIN32
	system("pause");
#endif
	return EXIT_SUCCESS;
}
