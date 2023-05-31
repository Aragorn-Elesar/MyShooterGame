// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShooterGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYSHOOTERGAME_API AShooterGameHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;
private:
	void DrawCrossHair();
	
};
