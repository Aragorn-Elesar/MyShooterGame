// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterBaseWeaponActor.generated.h"

class USkeletalMeshComponent;

UCLASS()
class MYSHOOTERGAME_API AShooterBaseWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AShooterBaseWeaponActor();

	virtual void StartFire();
	virtual void StopFire();

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* WeaponMeshComponent;

	virtual void MakeShot();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		FName MuzzleSoketName = "MuzzleSocket";

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float TraceMaxDistance = 1500.f;

	void MakeDamage(const FHitResult& HitResult);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float DamageAmount = 10.0f;



	APlayerController* GetPlayerController() const;

	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

	FVector GetMuzzleWorldLocation() const;

	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

	void MakeHit(FHitResult& HitResult, FVector& TraceStart, FVector& TraceEnd);

public:	
	virtual void Tick(float DeltaTime) override;


};
