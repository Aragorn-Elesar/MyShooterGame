// MyShooterGame


#include "Weapon/ShooterBaseWeaponActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

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
	MakeShot();
}

void AShooterBaseWeaponActor::MakeShot()
{
	if (!GetWorld())
	{
		return;
	}

	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd))
	{
		return;
	}

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);

	if (HitResult.bBlockingHit)
	{
		MakeDamage(HitResult);
		DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
	}
	else
	{
		DrawDebugLine(GetWorld(), GetMuzzleWorldLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
	}
}


APlayerController* AShooterBaseWeaponActor::GetPlayerController() const
{
	const auto Player = Cast<ACharacter>(GetOwner());
	if (!Player)
	{
		return nullptr;
	}
	return Player->GetController<APlayerController>();
}

bool AShooterBaseWeaponActor::GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const
{
	const auto Controller = GetPlayerController();
	if (!Controller)
	{
		return false;
	}
	Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
	return true;
}

FVector AShooterBaseWeaponActor::GetMuzzleWorldLocation() const
{
	return WeaponMeshComponent->GetSocketLocation(MuzzleSoketName);
}


bool AShooterBaseWeaponActor::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewLocation;
	FRotator ViewRotation;
	if(!GetPlayerViewPoint(ViewLocation, ViewRotation))
	{
		return false;
	}
	const FVector ShootDirection = ViewRotation.Vector();
	TraceStart = ViewLocation;
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	return true;
}

void AShooterBaseWeaponActor::MakeHit(FHitResult& HitResult ,FVector& TraceStart, FVector& TraceEnd)
{
	if (!GetWorld())
	{
		return;
	}
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());

	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility, CollisionParams);

}

void AShooterBaseWeaponActor::MakeDamage(const FHitResult& HitResult)
{
	const auto DamageActor = HitResult.GetActor();
	if (!DamageActor)
	{
		return;
	}
	DamageActor->TakeDamage(DamageAmount, FDamageEvent{}, GetPlayerController(), false);
}