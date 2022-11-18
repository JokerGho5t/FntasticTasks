#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"

#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"

#include "PawnRunners.generated.h"

UCLASS()
class FNTASTICTASKS_API APawnRunners : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;
	
	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin="0.0"))
	float TraceLength = 5000.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin="0.0"))
	float RotateSpeed = 25.f;	
	
public:
	
	APawnRunners();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
protected:

	virtual void BeginPlay() override;

private:
	
	void OnClick();
	void RotateCamera(float AxisValue);
};
