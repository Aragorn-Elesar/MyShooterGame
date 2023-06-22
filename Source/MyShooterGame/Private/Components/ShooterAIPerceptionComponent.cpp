// MyShooterGame


#include "Components/ShooterAIPerceptionComponent.h"
#include "AIController.h"
#include "ShooterUtiles.h"
#include "Components/ShooterHealthComponent.h"
#include "Perception/AISense_Sight.h"

AActor* UShooterAIPerceptionComponent::GetClosesEnemy() const
{
	TArray<AActor*> PerciveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PerciveActors);

	if (PerciveActors.Num() == 0)
	{
		return nullptr;
	}

	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller)
	{
		return nullptr;
	}

	const auto Pawn = Controller->GetPawn();
	if (!Pawn)
	{
		return nullptr;
	}

	float BestDistance = MAX_FLT;
	AActor* BestPawn = nullptr;

	for (const auto PerciveActor : PerciveActors)
	{
		const auto HealthComponent = ShooterUtiles::GetShooterPlayerComponent<UShooterHealthComponent>(PerciveActor);
		if (HealthComponent && !HealthComponent->IsDead()) // and check if enemy or not
		{
			const auto CurrenDistance = (PerciveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
			if (CurrenDistance < BestDistance)
			{
				BestDistance = CurrenDistance;
				BestPawn = PerciveActor;
			}
		}
	}
	return BestPawn;
}
