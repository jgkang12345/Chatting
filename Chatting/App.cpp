#include "App.h"
#include "ConsoleHelper.h"
#include "GUI.h"
#include <conio.h>
#include "SendBuffer.h"
#include "MessageCollection.h"
#include "Session.h"
#include "SocketHelper.h"
#include <process.h>
App* App::m_instance = nullptr;
unsigned int _stdcall RecvProc(void* Args);

void App::Init()
{
	ConsoleHelper::Clear();
	ConsoleHelper::ShowConsoleCursor(false);
	InputName();
	ConsoleHelper::SetConsoleSize(50, 30);
	printf("클라의 연결을 대기중입니다...");

	m_gui = new GUI(25, 20, 25, 5);
	Message InitVal = {};
	m_message_collection = new MessageCollection<Message>(20, InitVal);


	if (WSAStartup(MAKEWORD(2,2), &m_wsa_data) != 0)
		printf("Failed WSAStartup() \n");

	m_socket = SocketHelper::CreateIP4Socket();

	if (m_socket == INVALID_SOCKET)
		printf("Failed socket() \n");

	SocketHelper::InitIP4Socket(m_sock_addr_in, "58.236.86.23", 3000);

	if (bind(m_socket, (SOCKADDR*)&m_sock_addr_in, sizeof(m_sock_addr_in)) == SOCKET_ERROR)
		printf("Binding Error \n");

	if (listen(m_socket, 5) == SOCKET_ERROR)
		printf("listen Error \n");

	m_session = new Session();
	int	sizeClientAddr = sizeof(m_session->GetSockAddrIN());
	m_session->SetScoket(accept(m_socket, (SOCKADDR*)(&(m_session->GetSockAddrIN())), &sizeClientAddr));
	printf("접속완료 ! \n");

	unsigned int threadID = 0;
	m_hThread = (HANDLE)_beginthreadex(NULL, 0, &RecvProc, nullptr, 0, &threadID);

	m_send_buffer = new SendBuffer(m_message_collection);
	m_gui->Render();
}

void App::InputName()
{
	printf("이름을 입력하세요: ");
	scanf_s("%s", m_name, sizeof(m_name));
}

void App::Update()
{
	while (true)
	{
		if (_kbhit())
		{
			int key = _getch();
			if (key >= 128)
			{
				m_send_buffer->KeyBind(m_name, key);
				int key2 = _getch();
				m_send_buffer->KeyBind(m_name, key2);
			}
			else
			{
				m_send_buffer->KeyBind(m_name, key);
			}
			m_gui->Render();
			m_gui->BufferRender(m_send_buffer);
			m_gui->MsgRender(m_message_collection);
		}
	}
}

void App::Clear() 
{
	CloseHandle(m_hThread);
}

void App::RecvEventBind()
{
	while (true)
	{
		int recvLen = recv(m_session->GetScoket(), m_session->GetRecvBuf(), sizeof(Message), 0);
		Message* msg = reinterpret_cast<Message*>(m_session->GetRecvBuf());
		m_message_collection->RecivePush(*msg);
		m_gui->Render();
		m_gui->MsgRender(m_message_collection);
	}
}

unsigned int _stdcall RecvProc(void* Args)
{
	if (App::GetInstance() == nullptr)
	{
		printf("App Not Init()");
		return 0;
	}

	App::GetInstance()->RecvEventBind();

	return 0;
}

void App::Send(const Message& message)
{
	int ok = send(m_session->GetScoket(), (char*)&message, sizeof(Message), 0);
	int a = 3;
}