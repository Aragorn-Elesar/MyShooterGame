// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Weapon/ShooterBaseWeaponActor.h"
#include "ShooterRifleWeaponActor.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTERGAME_API AShooterRifleWeaponActor : public AShooterBaseWeaponActor
{
	GENERATED_BODY()

public:
	virtual void StartFire() override;
	virtual void StopFire() override;

protected:
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float TimeBetweenShot = 0.1f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float BulletSpread = 1.5f;

private:
	FTimerHandle ShotTimerHandle;
};
