// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterWeaponComponent.generated.h"

class AShooterBaseWeaponActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYSHOOTERGAME_API UShooterWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShooterWeaponComponent();

	void StartFire();
	void StopFire();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		TSubclassOf<AShooterBaseWeaponActor> WeaponClass;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName WeaponAttachPointName = "WeaponSoket";
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
		AShooterBaseWeaponActor* CurrentWeapon = nullptr;
	void SpawnWeapon();
};
