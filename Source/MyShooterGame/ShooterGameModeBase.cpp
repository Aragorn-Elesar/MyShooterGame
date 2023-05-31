// MyShooterGame


#include "ShooterGameModeBase.h"
#include "Player/ShooterCharacter.h"
#include "Player/ShooterPlayerController.h"
#include "UI/ShooterGameHUD.h"

AShooterGameModeBase::AShooterGameModeBase()
{
	DefaultPawnClass = AShooterCharacter::StaticClass();
	PlayerControllerClass = AShooterPlayerController::StaticClass();
	HUDClass = AShooterGameHUD::StaticClass();
}
