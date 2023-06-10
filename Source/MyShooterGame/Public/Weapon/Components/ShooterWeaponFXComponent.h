// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterWeaponFXComponent.generated.h"

class UNiagaraSystem;
class UPhysicalMaterial;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSHOOTERGAME_API UShooterWeaponFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UShooterWeaponFXComponent();

	void PlayImpactFX(const FHitResult& Hit);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
		UNiagaraSystem* DefaultEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
		TMap<UPhysicalMaterial*, UNiagaraSystem*> EffectsMap;

	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
