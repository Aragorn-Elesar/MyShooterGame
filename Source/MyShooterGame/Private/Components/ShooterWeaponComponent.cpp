// MyShooterGame


#include "Components/ShooterWeaponComponent.h"
#include "Weapon/ShooterBaseWeaponActor.h"
#include "GameFramework/Character.h"

UShooterWeaponComponent::UShooterWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UShooterWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();
}


void UShooterWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UShooterWeaponComponent::SpawnWeapon()
{
	if (!GetWorld())
	{
		return;
	}
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character)
	{
		return;
	}

	CurrentWeapon = GetWorld()->SpawnActor<AShooterBaseWeaponActor>(WeaponClass);
	if (!CurrentWeapon)
	{
		return;
	}
	
	FAttachmentTransformRules AttachmentRulls(EAttachmentRule::SnapToTarget, false);
	CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRulls, WeaponAttachPointName);
	CurrentWeapon->SetOwner(Character);
}

void UShooterWeaponComponent::Fire()
{
	if (!CurrentWeapon)
	{
		return;
	}
	CurrentWeapon->Fire();
}
