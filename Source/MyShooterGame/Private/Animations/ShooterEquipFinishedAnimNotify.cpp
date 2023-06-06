// MyShooterGame


#include "Animations/ShooterEquipFinishedAnimNotify.h"

void UShooterEquipFinishedAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	OnNotifySignature.Broadcast(MeshComp);
	Super::Notify(MeshComp, Animation);
}
