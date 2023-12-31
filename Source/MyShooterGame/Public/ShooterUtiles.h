#pragma once
#include "Player/ShooterPlayerState.h"

class ShooterUtiles
{
public:
	template<typename T>
	static T* GetShooterPlayerComponent(AActor* PlayerPawn)
	{
		if (!PlayerPawn)
		{
			return nullptr;
		}
		const auto Component = PlayerPawn->GetComponentByClass(T::StaticClass());
		return Cast<T>(Component);
	}

	bool static AreEnemies(AController* Controller1, AController* Controller2)
	{
		if (!Controller1 || !Controller2 || Controller1 == Controller2)
		{
			return false;
		}

		const auto PlayerState1 = Cast<AShooterPlayerState>(Controller1->PlayerState);
		const auto PlayerState2 = Cast<AShooterPlayerState>(Controller2->PlayerState);

		return PlayerState1 && PlayerState2 && PlayerState1->GetTeamID() != PlayerState2->GetTeamID();
	}


	static FText Text_From_Int(int64 number)
	{
		return FText::FromString(FString::FromInt(number));
	}
};