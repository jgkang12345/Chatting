#pragma once

#include "MessageCollection.h"
#include <winsock2.h>
#include <WS2tcpip.h>
class GUI;
class SendBuffer;
class Session;
struct Message;
class App
{
private:
	static	App*					m_instance;
	GUI*							m_gui;
	SendBuffer*						m_send_buffer;
	MessageCollection<Message>*		m_message_collection;
	WSADATA							m_wsa_data;
	SOCKET							m_socket;
	SOCKADDR_IN						m_sock_addr_in;
	Session*						m_session;
	char							m_name[50];
	HANDLE							m_hThread;
public:
	static App* GetInstance()
	{
		if (m_instance == nullptr)
			m_instance = new App();

		return m_instance;
	}
	void Init();
	void InputName();
	void Update();
	void RecvEventBind();
	void Clear();
	void Send(const Message& message);
};

