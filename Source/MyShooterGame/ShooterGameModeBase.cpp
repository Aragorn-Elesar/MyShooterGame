// MyShooterGame


#include "ShooterGameModeBase.h"
#include "Player/ShooterCharacter.h"
#include "Player/ShooterPlayerController.h"

AShooterGameModeBase::AShooterGameModeBase()
{
	DefaultPawnClass = AShooterCharacter::StaticClass();
	PlayerControllerClass = AShooterPlayerController::StaticClass();
}
