// MyShooterGame


#include "AI/ShooterAIController.h"
#include "AI/ShooterAICharacter.h"

void AShooterAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const auto ShooterCharacter = Cast<AShooterAICharacter>(InPawn);

	if (ShooterCharacter)
	{
		RunBehaviorTree(ShooterCharacter->BehaivorTreeAsset);
	}
}

