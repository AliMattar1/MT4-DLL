#pragma once
#include "stdafx.h"
//#include "atltime.h"
#include "MT4ManagerAPI.h"
class CManager
{
private:
	CManagerFactory   m_factory;
	CManagerInterface *m_manager;

public:
	CManager() : m_factory("C:/mtmanapi.dll"), m_manager(NULL)
	{
		m_factory.WinsockStartup();
		if (m_factory.IsValid() == FALSE || (m_manager = m_factory.Create(ManAPIVersion)) == NULL)
		{
			return;
		}
	}

	~CManager()
	{
		if (m_manager != NULL)
		{
			if (m_manager->IsConnected())
				m_manager->Disconnect();
			m_manager->Release();
			m_manager = NULL;
		}
		m_factory.WinsockCleanup();
	}

	bool IsValid()
	{
		return(m_manager != NULL);
	}

	CManagerInterface* operator->()
	{
		return(m_manager);
	}
};