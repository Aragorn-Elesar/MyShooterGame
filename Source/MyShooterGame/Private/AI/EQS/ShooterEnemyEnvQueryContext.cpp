// MyShooterGame


#include "AI/EQS/ShooterEnemyEnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Actor.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

void UShooterEnemyEnvQueryContext::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	const auto QueryOwner = Cast<AActor>(QueryInstance.Owner.Get());
	const auto BlackBoard = UAIBlueprintHelperLibrary::GetBlackboard(QueryOwner);
	if (!BlackBoard)
	{
		return;
	}
	const auto ContextActor = BlackBoard->GetValueAsObject(EnemyActorKeyName);

	UEnvQueryItemType_Actor::SetContextHelper(ContextData, Cast<AActor>(ContextActor));


}
