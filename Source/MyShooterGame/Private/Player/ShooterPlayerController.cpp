// MyShooterGame


#include "Player/ShooterPlayerController.h"
#include "Components/ShooterRespawnComponent.h"

AShooterPlayerController::AShooterPlayerController()
{
	RespawnComponent = CreateDefaultSubobject<UShooterRespawnComponent>("RespawnComponent");
}
