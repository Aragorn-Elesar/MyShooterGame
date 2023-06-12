// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShooterCoreTypes.h"
#include "ShooterBaseWeaponActor.generated.h"


class USkeletalMeshComponent;
class UNiagaraSystem;
class UNiagaraComponent;


UCLASS()
class MYSHOOTERGAME_API AShooterBaseWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AShooterBaseWeaponActor();

	virtual void StartFire();
	virtual void StopFire();
	FOnClipEmptySignature OnClipEmpty;
	void ChangeClip();
	bool CanReload() const;
	FWeaponUIData GetUIData() const { return UIData; }
	FAmmoData GetAmmoData() const {return CurrentAmmo;}
	bool TryToAddAmmo(int64 ClipsAmount);

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* WeaponMeshComponent;

	virtual void MakeShot();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		FName MuzzleSoketName = "MuzzleSocket";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		float TraceMaxDistance = 1500.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
		FAmmoData DefaultAmmo {15, 10, false};

	APlayerController* GetPlayerController() const;

	bool GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const;

	FVector GetMuzzleWorldLocation() const;

	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const;

	void MakeHit(FHitResult& HitResult, FVector& TraceStart, FVector& TraceEnd);
	
	void DecreaseAmmo();
	bool IsAmmoEmpty() const;
	bool IsClipEmpty() const;
	void LogAmmo();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
		FWeaponUIData UIData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
		UNiagaraSystem* MuzzleFX;

	UNiagaraComponent* SpawnMuzzleFX();

	bool IsAmmoFull() const;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	FAmmoData CurrentAmmo;

};
