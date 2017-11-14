#include <log.h>
#include <engine.h>

void Log::Msg(std::string msg)
{
	Engine::GetInstance()->console.AddLog(msg);
}
void Log::Err(std::string err)
{
	Engine::GetInstance()->console.AddLog(err);
}
