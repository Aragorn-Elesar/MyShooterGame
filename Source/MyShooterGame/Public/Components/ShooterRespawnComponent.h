// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterRespawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSHOOTERGAME_API UShooterRespawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UShooterRespawnComponent();

	void Respawn(int64 RespawnTime);

private:
	FTimerHandle RespawnTimer;
	int64 RespawnTimerCountDown = 0;

	void RespawnTimeUpdate();
};
