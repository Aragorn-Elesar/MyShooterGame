// MyShooterGame


#include "UI/Shooter_Pause_Widget.h"
#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"

bool UShooter_Pause_Widget::Initialize()
{
	bool InitStatus = Super::Initialize();

	if (Clear_Pause_Button)
	{
		Clear_Pause_Button->OnClicked.AddDynamic(this, &UShooter_Pause_Widget::On_Clear_Pause);
	}

	return InitStatus;
}

void UShooter_Pause_Widget::On_Clear_Pause()
{
	if (!GetWorld() || !GetWorld()->GetAuthGameMode())
	{
		return;
	}

	GetWorld()->GetAuthGameMode()->ClearPause();
}
