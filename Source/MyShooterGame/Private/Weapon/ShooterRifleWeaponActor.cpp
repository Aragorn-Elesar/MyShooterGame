// MyShooterGame


#include "Weapon/ShooterRifleWeaponActor.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"


void AShooterRifleWeaponActor::StartFire()
{
	MakeShot();
	GetWorldTimerManager().SetTimer(ShotTimerHandle, this, &AShooterRifleWeaponActor::MakeShot, TimeBetweenShot, true);

}

void AShooterRifleWeaponActor::StopFire()
{
	GetWorldTimerManager().ClearTimer(ShotTimerHandle);
}

void AShooterRifleWeaponActor::MakeShot()
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

bool AShooterRifleWeaponActor::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewLocation;
	FRotator ViewRotation;
	if (!GetPlayerViewPoint(ViewLocation, ViewRotation))
	{
		return false;
	}
	const auto HalfRad = FMath::DegreesToRadians(BulletSpread);
	const FVector ShootDirection = FMath::VRandCone(ViewRotation.Vector(), HalfRad);
	TraceStart = ViewLocation;
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	return true;
}

void AShooterRifleWeaponActor::MakeDamage(const FHitResult& HitResult)
{
	const auto DamageActor = HitResult.GetActor();
	if (!DamageActor)
	{
		return;
	}
	DamageActor->TakeDamage(DamageAmount, FDamageEvent{}, GetPlayerController(), false);
}