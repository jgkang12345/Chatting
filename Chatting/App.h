#pragma once
class GUI;
class SendBuffer;
class App
{
private:
	GUI*			m_gui;
	SendBuffer*		m_send_buffer;
public:
	void Init();
	void Update();
};

