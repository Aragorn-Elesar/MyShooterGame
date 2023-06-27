// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Public/ShooterCoreTypes.h"
#include "ShooterGameModeBase.generated.h"

class AAIController;

UCLASS()
class MYSHOOTERGAME_API AShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AShooterGameModeBase();

	virtual void StartPlay() override; 
	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;
protected:

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TSubclassOf<AAIController> AIControllerClass;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FGameData GameData;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TSubclassOf<APawn> AIPawnClass;

private:
	void SpawnBot();
};
