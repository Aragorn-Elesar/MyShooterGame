// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Shooter_Pause_Widget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class MYSHOOTERGAME_API UShooter_Pause_Widget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual bool Initialize() override;

protected:
	UPROPERTY(meta = (BindWidget))
	UButton* Clear_Pause_Button;

	UFUNCTION()
	void On_Clear_Pause();
};