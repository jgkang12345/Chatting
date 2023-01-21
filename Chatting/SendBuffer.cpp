#include "SendBuffer.h"
#include "App.h"
#include <Windows.h>
#include "TimeUtils.h"
#define ENTER		13
#define BACKSPACE	8
#define SPACE		32
void SendBuffer::KeyBind(char* name, int key)
{
	switch (key)
	{
	case ENTER:
	{
		if (strlen(m_buffer) == 0)
			return;
		Message message = Message(name, m_buffer, TimeUtils::CurrentTickSum());
		m_message_collection->SendPush(message);
		App::GetInstance()->Send(message);
		m_pivot = 0;
		memset(m_buffer, '\0', m_buff_size);
		break;
	}

	case BACKSPACE:
		if (m_pivot > -1)
		{
			if (m_buffer[m_pivot] < 0)
			{
				m_buffer[m_pivot--] = '\0';
				m_buffer[m_pivot--] = '\0';
			}
			else
			{
				m_buffer[m_pivot--] = '\0';
			}
			if (m_pivot == -1) m_pivot++;
		}
		break;

	case SPACE:
		if (!(m_pivot + 1 >= m_buff_size))
		{
			m_buffer[m_pivot++] = ' ';
		}
		break;

	default:
		if (!(m_pivot + 1 >= m_buff_size))
			m_buffer[m_pivot++] = key;
		break;
	}
}
