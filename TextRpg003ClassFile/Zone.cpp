#include "Zone.h"
#include <conio.h>
#include <BaseSystem/EngineDebug.h>

void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "에 입장했습니다.\n";
}

bool UZone::IsConnecting(UZone* _LinkZone)
{
	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (_LinkZone == LinkZone[i])
		{
			return true;
		}
	}

	return false;
}

// 100분 25분때 안됐어 무조건 질문.
// 50분때 또 안됐어 또 질문
// 아예 핀트가 나감. => 정답 제발 평생해도 

bool UZone::InterConnecting(UZone* _LinkZone)
{
	// 2줄이면 됩니다.
	// 만들어주세요.
	// 기본이 저한테 기본입니다.
	// 무식하게 짜세요.
	// 디버깅
	_LinkZone->Connecting(this);
	this->Connecting(_LinkZone);

	return true;
}

bool UZone::Connecting(UZone* _LinkZone)
{
	if (this == _LinkZone)
	{
		MSGASSERT("자기자신을 자신에게 연결하려고 했습니다.");
		return false;
	}


	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("이미 연결된 지역을 같은 지역에 또 연결하려고 했습니다.");
		return false;
	}

	for (size_t i = 0; i < LINKZONEMAX; i++)
	{
		if (nullptr == LinkZone[i])
		{
			LinkZone[i] = _LinkZone;
			// 무한 루프
			// _LinkZone->Link(this);
			return true;
		}
	}

	MSGASSERT("이미 모든 연결이 완결된 지역이라 연결에 실패했습니다.");
	return false;
}