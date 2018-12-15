#pragma once

typedef short GRBALHABET;	// ������� �������� ���������� ( ��������� > 0, ����������� < 0) 
#define NS(n)	(Rule::Chain::N(n))
#define TS(n)	(Rule::Chain::T(n))
#define ISNS(n) (GRB::Rule::Chain::isN(n))

namespace GRB
{
	struct Rule		// ������� � ���������� �������
	{
		GRBALHABET	nn;		//	���������� ( ����� ������ �������) < 0
		int iderror;		//	������������� ���������������� ���������
		short	size;		//	���������� ������� - ������ ������ �������
		struct Chain		//	������� ( ������ ����� ������� )
		{
			short size;				//	����� �������
			GRBALHABET* nt;			//	������� ���������� (>0) � ������������ (<0)
			Chain() { size = 0; nt = 0; };
			Chain(
				short psize,		//	���������� ������� � �������
				GRBALHABET s, ...	//	������� (�������� ��� ����������)
			);
			char* getCChain(char* b);//	�������� ������ ������� �������
			static GRBALHABET T(char t) { return  GRBALHABET(t); };	//	�������
			static GRBALHABET N(char n) { return -GRBALHABET(n); };	//	����������
			static bool isT(GRBALHABET s) { return s > 0; };		//	��������?
			static bool isN(GRBALHABET s) { return s < 0; };		//	����������?
			static char alphabet_to_char(GRBALHABET s) { return isT(s) ? char(s) : char(-s); };	// GRBALPHABET -> char
		} *chains;						//	������ �������� - ������ ������ �������
		Rule() { nn = 0x00; size = 0; }
		Rule(

			GRBALHABET pnn,				// ����������
			int iderror,				// ������������� ���������������� ���������
			short psize,				// ���������� ������� - ������ ������ �������
			Chain c, ...				// ��������� ������� - ������ ������ �������
		);
		char* getCRule(					// �������� ������� � ���� N-> ������� (��� �����������)
			char*b,			// �����
			short nchain	// ����� ������� ( ������ ����� ) � �������
		);
		short Rule::getNextChain(		// �������� ��������� �� j ���������� �������, ������� �� ����� ��� -1
			GRBALHABET t,			// ������ ������ �������
			Rule::Chain& pchain,	// ������������ �������
			short j					// ����� �������
		);
	};
	struct  Greibach			// ���������� �������
	{
		short size;				// ���������� ������
		GRBALHABET startN;		// ��������� ������
		GRBALHABET stbottomT;	// ��� �����
		Rule* rules;			// ��������� ������
		Greibach() { short size = 0; startN = 0; stbottomT = 0; rules = 0; };
		Greibach(
			GRBALHABET	pstartN,		// ��������� ������
			GRBALHABET  pstbottomT,		// ��� �����
			short psize,				// ��������� ������
			Rule r, ...					// �������
		);
		short getRule(							// �������� �������, ������������ ����� ������� ��� -1
			GRBALHABET pnn,			// ����� ������ �������
			Rule& prule				// ������������ ������� ����������
		);
		Rule getRule(short n);					// �������� ������� �� ������
	};
	void Print_Rules(Greibach greibach);
};