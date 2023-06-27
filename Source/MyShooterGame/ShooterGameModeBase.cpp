// MyShooterGame


#include "ShooterGameModeBase.h"
#include "Player/ShooterCharacter.h"
#include "Player/ShooterPlayerController.h"
#include "UI/ShooterGameHUD.h"
#include "AIController.h"

AShooterGameModeBase::AShooterGameModeBase()
{
	DefaultPawnClass = AShooterCharacter::StaticClass();
	PlayerControllerClass = AShooterPlayerController::StaticClass();
	HUDClass = AShooterGameHUD::StaticClass();
}

void AShooterGameModeBase::StartPlay()
{
	Super::StartPlay();

	SpawnBot();
}

UClass* AShooterGameModeBase::GetDefaultPawnClassForController_Implementation(AController* InController)
{
	if (InController && InController->IsA<AAIController>())
	{
		return AIPawnClass;
	}
	return Super::GetDefaultPawnClassForController_Implementation(InController);
}

void AShooterGameModeBase::SpawnBot()
{
	if (!GetWorld())
	{
		return;
	}

	for (int64 i = 0; i < GameData.PlayersNum-1; i++)
	{
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		const auto ShooterAIController = GetWorld()->SpawnActor<AAIController>(AIControllerClass, SpawnInfo);
		RestartPlayer(ShooterAIController);
	}
}
