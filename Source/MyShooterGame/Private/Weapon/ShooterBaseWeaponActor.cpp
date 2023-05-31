// MyShooterGame


#include "Weapon/ShooterBaseWeaponActor.h"
#include "Components/SkeletalMeshComponent.h"


AShooterBaseWeaponActor::AShooterBaseWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	SetRootComponent(WeaponMeshComponent);
}

void AShooterBaseWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
}



void AShooterBaseWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShooterBaseWeaponActor::Fire()
{

}