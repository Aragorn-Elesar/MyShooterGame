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
	void NextWeapon();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	 TArray<TSubclassOf<AShooterBaseWeaponActor>> WeaponClasses;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName WeaponEquipSoketName = "WeaponSoket";

	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
		FName WeaponArmorySoketName = "ArmorySocket";

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
		UAnimMontage* EquipAnimMontage;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
		AShooterBaseWeaponActor* CurrentWeapon = nullptr;

	UPROPERTY()
		TArray<AShooterBaseWeaponActor*> Weapons;

	int64 CurrentWeaponIndex = 0;

	void SpawnWeapons();

	void AttachWeaponToSoket(AShooterBaseWeaponActor* Weapon, USceneComponent* SceneComponent,
		const FName& SoketName);

	void EquipWeapon(int64 WeaponIndex);

	void PlayAnimMontage(UAnimMontage* Animation);

	void InitAnimation();

	void OnEquipFinished(USkeletalMeshComponent* MeshComp);

};
