// MyShooterGame


#include "UI/ShooterGameHUD.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"

void AShooterGameHUD::DrawHUD()
{
	Super::DrawHUD();

	//DrawCrossHair();
}

void AShooterGameHUD::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass);
	if (PlayerHUDWidget)
	{
		PlayerHUDWidget->AddToViewport();
	}
}

void AShooterGameHUD::DrawCrossHair()
{
	const TInterval<float> Centre(Canvas->SizeX * 0.5f, Canvas->SizeY * 0.5f);
	const float HalflineSize = 10.0f;
	const float LineThickness = 2.0f;
	const FLinearColor LineColor = FLinearColor::Green;
	
	DrawLine(Centre.Min - HalflineSize, Centre.Max, Centre.Min + HalflineSize, Centre.Max, LineColor, LineThickness);
	DrawLine(Centre.Min , Centre.Max - HalflineSize, Centre.Min , Centre.Max + HalflineSize, LineColor, LineThickness);
}
