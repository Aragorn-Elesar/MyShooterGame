// MyShooterGame


#include "Weapon/Components/ShooterWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "PhysicalMaterials/PhysicalMaterial.h" 

UShooterWeaponFXComponent::UShooterWeaponFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UShooterWeaponFXComponent::PlayImpactFX(const FHitResult& Hit)
{
	auto Effect = DefaultEffect;

	if (Hit.PhysMaterial.IsValid())
	{
		const auto PhysMat = Hit.PhysMaterial.Get();
		if (EffectsMap.Contains(PhysMat))
		{
			Effect = EffectsMap[PhysMat];
		}
	}

	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), Effect, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());

}

void UShooterWeaponFXComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UShooterWeaponFXComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

