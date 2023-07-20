// MyShooterGame

#pragma once

#include "CoreMinimal.h"
#include "Player/ShooterCharacter.h"
#include "ShooterPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class MYSHOOTERGAME_API AShooterPlayerCharacter : public AShooterCharacter
{
	GENERATED_BODY()
	
public:
	AShooterPlayerCharacter(const FObjectInitializer& ObjInit);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual bool IsRunning() const override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USpringArmComponent* SpringArmComponent;

	virtual void OnDeath() override;

private:
	void MoveForward(float Amount);
	void MoveRightLeft(float Amount);

	bool WantsToRun = false;
	bool IsMovingForward = false;
	void OnStartRun();
	void OnStopRun();

};
