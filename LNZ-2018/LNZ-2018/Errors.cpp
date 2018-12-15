#include "stdafx.h"
#include "Errors.h"

// ����� ������: 0-99 - ��������� ������
//				100-109 - ������ ����������
//				110-119 - ������ �������� � ������ ������

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "[SYSTEM]������������ ��� ������"),
		ERROR_ENTRY_NODEF(1),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100, "[SYSTEM]�������� -in ������ ���� ����� �����������!"),
		ERROR_ENTRY_NODEF(101),ERROR_ENTRY_NODEF(102),ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "[SYSTEM]��������� ����� �������� ���������"),
		ERROR_ENTRY_NODEF(105),ERROR_ENTRY_NODEF(106),ERROR_ENTRY_NODEF(107),
		ERROR_ENTRY_NODEF(108),ERROR_ENTRY_NODEF(109),

		ERROR_ENTRY(110, "[SYSTEM]������ ��� �������� ����� � �������� �����(-in)"),
		ERROR_ENTRY(111, "[SYSTEM]������������ ������ � �������� �����(-in)"),
		ERROR_ENTRY(112, "[SYSTEM]������ ��� �������� ����� ���������(-log)"),
		ERROR_ENTRY(113, "[SYN]������������ ����������� �������"),
		ERROR_ENTRY(114,"[LEX]������� ������� ��������� �������"),ERROR_ENTRY_NODEF(115),
		ERROR_ENTRY(115,"[SYSTEM]������� ������� ����� ��������� ����"),
		ERROR_ENTRY_NODEF(117),ERROR_ENTRY_NODEF(118),ERROR_ENTRY_NODEF(119),
		ERROR_ENTRY(120, "[LEX]��������� ������������ ����� �������������� (>10). �������� �� 10"),
		ERROR_ENTRY(121,"[LEX]������������ ����� �������"),
		ERROR_ENTRY(122,"[LEX]������������ ����� �������������� ��� ���������� ������� ���������"),
		ERROR_ENTRY(123,"[LEX]����������� �������"),
		ERROR_ENTRY(124,"[LEX]����������� �������������"),
		ERROR_ENTRY(125,"[SEM]����������� ����� ����� main"),
		ERROR_ENTRY(126,"[SEM]������������ ����� ����� main"),
		ERROR_ENTRY_NODEF(127),
		ERROR_ENTRY_NODEF(128),
		ERROR_ENTRY_NODEF(129),
		ERROR_ENTRY_NODEF10(130),ERROR_ENTRY_NODEF10(140),ERROR_ENTRY_NODEF10(150),ERROR_ENTRY_NODEF10(160),
		ERROR_ENTRY_NODEF10(170),ERROR_ENTRY_NODEF10(180),ERROR_ENTRY_NODEF10(190),

		ERROR_ENTRY(200, "[SYN]�������� ��������� ���������"), //���� ������ ��������������� �����������
		ERROR_ENTRY(201, "[SYN]��������� ��������"),
		ERROR_ENTRY(202, "[SYN]������ � ���������"),
		ERROR_ENTRY(203, "[SYN]������ � ����������� ������ ��� ������"),
		ERROR_ENTRY(204, "[SYN]������ � ���������� ����������"),
		ERROR_ENTRY(205, "[SYN]������ � ���������� ���������� �������"),
		ERROR_ENTRY_NODEF(206),
		ERROR_ENTRY_NODEF(207), ERROR_ENTRY_NODEF(208), ERROR_ENTRY_NODEF(209),
		ERROR_ENTRY_NODEF10(210), ERROR_ENTRY_NODEF10(220), ERROR_ENTRY_NODEF10(230), ERROR_ENTRY_NODEF10(240), ERROR_ENTRY_NODEF10(250),
		ERROR_ENTRY_NODEF10(260), ERROR_ENTRY_NODEF10(270), ERROR_ENTRY_NODEF10(280), ERROR_ENTRY_NODEF10(290),

		//������������� ������
		ERROR_ENTRY(300, "[SEM]������������ ����� ���������� �������"),
		ERROR_ENTRY(301,"[SEM]������������ ���������� ���������� �������"),
		ERROR_ENTRY(302,"[SEM]���������� ��������� �� ��������������� ���"),
		ERROR_ENTRY(303,"[SEM]������������ �������� �� ��������"),ERROR_ENTRY(304,"[SEM]�������� ��� ������� ������"),
		ERROR_ENTRY(305,"[SEM]������� ���������� �������� ���"),ERROR_ENTRY(306,"[SEM]����� �� ������������ �������"),
		ERROR_ENTRY(307,"[SEM]����� ������� �� ������� �����������"),
		ERROR_ENTRY(308,"[SEM]������ �������� ��������� ��������� �������"),ERROR_ENTRY_NODEF(309),ERROR_ENTRY_NODEF10(310),
		ERROR_ENTRY_NODEF10(320), ERROR_ENTRY_NODEF10(330), ERROR_ENTRY_NODEF10(340), ERROR_ENTRY_NODEF10(350),
		ERROR_ENTRY_NODEF10(360), ERROR_ENTRY_NODEF10(370), ERROR_ENTRY_NODEF10(380), ERROR_ENTRY_NODEF10(390),

		//���������
		ERROR_ENTRY_NODEF100(400),ERROR_ENTRY_NODEF100(500),ERROR_ENTRY_NODEF100(600),
		ERROR_ENTRY_NODEF100(700),ERROR_ENTRY_NODEF100(800),ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
			return(errors[id]);
		else
			return(errors[0]);
	}
	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (id > 0 && id < ERROR_MAX_ENTRY)
		{
			errors[id].inext.col = col;
			errors[id].inext.line = line;
			return(errors[id]);
		}
		else
		{
			return(errors[0]);
		}
	}
}