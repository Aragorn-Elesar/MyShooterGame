// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Weapon/ShooterBaseWeaponActor.h"
#include "ShooterRifleWeaponActor.generated.h"

class UShooterWeaponFXComponent;

UCLASS()
class MYSHOOTERGAME_API AShooterRifleWeaponActor : public AShooterBaseWeaponActor
{
	GENERATED_BODY()

public:
	AShooterRifleWeaponActor();
	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		float TimeBetweenShot = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		float BulletSpread = 1.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		float DamageAmount = 10.0f;

	UPROPERTY(VisibleAnywhere, Category = "VFX")
		UShooterWeaponFXComponent* WeaponFXComponent;

	virtual void BeginPlay() override;
private:
	FTimerHandle ShotTimerHandle;

	void MakeDamage(const FHitResult& HitResult);

};
