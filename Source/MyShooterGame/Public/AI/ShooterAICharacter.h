// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Player/ShooterCharacter.h"
#include "ShooterAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class MYSHOOTERGAME_API AShooterAICharacter : public AShooterCharacter
{
	GENERATED_BODY()
public:
	AShooterAICharacter(const FObjectInitializer& ObjInit);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
		UBehaviorTree* BehaivorTreeAsset;

	virtual void OnDeath() override;
};
