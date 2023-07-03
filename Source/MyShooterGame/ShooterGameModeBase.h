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

	void Killed(AController* KillerController, AController* VictimController);

	FGameData GetGameData() const { return GameData; }
	int64 GetCurrentRoundsNum() const { return CurrentRound; }
	int64 GetCurrentRoundTimeNum() const { return RoundCountDown; }

	void RespawnRequest(AController* Controller);

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TSubclassOf<AAIController> AIControllerClass;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		FGameData GameData;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
		TSubclassOf<APawn> AIPawnClass;

private:
	void SpawnBot();
	FTimerHandle GameRoundTimerHandle;
	int64 CurrentRound = 1;
	int64 RoundCountDown = 0;

	void StartRound();
	void GameTimerUpdate();

	void ResetPlayers();
	void ResetOnePlayer(AController* Controller);

	void CreateTeamsInfo();
	FLinearColor DetermineColorByTeamID(int64 Id) const;
	void SetPlayerCollor(AController* Controller);

	void LogPlayerInfo();
	void StartRespaw(AController* Controller);
};
