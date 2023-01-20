#include "SendBuffer.h"

#define ENTER		13
#define BACKSPACE	8
#define SPACE		32
void SendBuffer::KeyBind(int key)
{
	switch (key)
	{
	case ENTER:
		break;

	case BACKSPACE:
		break;

	case SPACE:
		break;

	default:
		m_buffer[m_pivot++] = key;
		break;
	}
}

void SendBuffer::Write()
{

}

void SendBuffer::Enter()
{

}
