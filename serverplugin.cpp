#include "includes.hpp"

CServerPlugin g_Plugin;

EXPOSE_SINGLE_INTERFACE_GLOBALVAR(CServerPlugin, IServerPluginCallbacks, INTERFACEVERSION_ISERVERPLUGINCALLBACKS, g_Plugin);

CServerPlugin::CServerPlugin()
{
	m_iClientCommandIndex = 0;
}

CServerPlugin::~CServerPlugin()
{
}

bool CServerPlugin::Load(CreateInterfaceFn interfaceFactory, CreateInterfaceFn gameServerFactory)
{
	return addon::load();
}

void CServerPlugin::Unload()
{
	return addon::unload();
}

const char *CServerPlugin::GetPluginDescription()
{
	return "force volumetrics for projected textures patch";
}

void CServerPlugin::LevelInit(const char *pMapName)
{}

void CServerPlugin::LevelShutdown()
{}

void CServerPlugin::SetCommandClient( int index )
{}
