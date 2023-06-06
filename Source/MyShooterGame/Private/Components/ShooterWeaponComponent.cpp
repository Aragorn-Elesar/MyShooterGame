// MyShooterGame


#include "Components/ShooterWeaponComponent.h"
#include "Weapon/ShooterBaseWeaponActor.h"
#include "GameFramework/Character.h"
#include "Animations/ShooterEquipFinishedAnimNotify.h"

DEFINE_LOG_CATEGORY_STATIC(LogWeaponStatic, All, All);

UShooterWeaponComponent::UShooterWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UShooterWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentWeaponIndex = 0;
	InitAnimation();
	SpawnWeapons();
	EquipWeapon(CurrentWeaponIndex);
}

void UShooterWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason) 
{
	CurrentWeapon = nullptr;
	for (auto Weapon : Weapons)
	{
		Weapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		Weapon->Destroy();
	}
	Weapons.Empty();

	Super::EndPlay(EndPlayReason);
}


void UShooterWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UShooterWeaponComponent::SpawnWeapons()
{

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character || !GetWorld())
	{
		return;
	}

	for (auto WeaponClass : WeaponClasses)
	{	
		auto Weapon = GetWorld()->SpawnActor<AShooterBaseWeaponActor>(WeaponClass);
		if (!Weapon)
		{
			continue;
		}
		Weapon->SetOwner(Character);
		Weapons.Add(Weapon);

		AttachWeaponToSoket(Weapon, Character->GetMesh(), WeaponArmorySoketName);

	}

	if (!CurrentWeapon)
	{
		return;
	}	
}

void UShooterWeaponComponent::StartFire()
{
	if (!CurrentWeapon)
	{
		return;
	}
	CurrentWeapon->StartFire();
}

void UShooterWeaponComponent::StopFire()
{
	if (!CurrentWeapon)
	{
		return;
	}
	CurrentWeapon->StopFire();
}



void UShooterWeaponComponent::AttachWeaponToSoket(AShooterBaseWeaponActor* Weapon, USceneComponent* SceneComponent,
	const FName& SoketName)
{
	if (!Weapon || !SceneComponent)
	{
		return;
	}
	FAttachmentTransformRules AttachmentRulls(EAttachmentRule::SnapToTarget, false);
	Weapon->AttachToComponent(SceneComponent, AttachmentRulls, SoketName);
}

void UShooterWeaponComponent::EquipWeapon(int64 WeaponIndex)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character)
	{
		return;
	}
	if (CurrentWeapon)
	{
		CurrentWeapon->StopFire();
		AttachWeaponToSoket(CurrentWeapon, Character->GetMesh(), WeaponArmorySoketName);
	}

	CurrentWeapon = Weapons[WeaponIndex];
	AttachWeaponToSoket(CurrentWeapon, Character->GetMesh(), WeaponEquipSoketName);
	PlayAnimMontage(EquipAnimMontage);
}


void UShooterWeaponComponent::NextWeapon()
{
	CurrentWeaponIndex = (CurrentWeaponIndex + 1) % Weapons.Num();
	EquipWeapon(CurrentWeaponIndex);
}

void UShooterWeaponComponent::PlayAnimMontage(UAnimMontage* Animation)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character)
	{
		return;
	}

	Character->PlayAnimMontage(Animation);
}

void UShooterWeaponComponent::InitAnimation()
{
	if (!EquipAnimMontage)
	{
		return;
	}
	const auto NotifyEvents = EquipAnimMontage->Notifies;

	for (auto NotifyEvent : NotifyEvents)
	{
		auto EquipFinishedNotify = Cast<UShooterEquipFinishedAnimNotify>(NotifyEvent.Notify);
		if (EquipFinishedNotify)
		{
			EquipFinishedNotify->OnNotifySignature.AddUObject(this, &UShooterWeaponComponent::OnEquipFinished);
			break;
		}
	}
}

void UShooterWeaponComponent::OnEquipFinished(USkeletalMeshComponent* MeshComp)
{
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character)
	{
		return;
	}

	if (Character->GetMesh() == MeshComp)
	{
		UE_LOG(LogWeaponStatic, Display, TEXT("Finished"));
	}
}
