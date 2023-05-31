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

	virtual void Fire();

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* WeaponMeshComponent;

public:	
	virtual void Tick(float DeltaTime) override;

};
