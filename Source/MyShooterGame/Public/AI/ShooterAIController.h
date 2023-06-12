// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTERGAME_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

protected:

	virtual void OnPossess(APawn* InPawn) override;
	
};
