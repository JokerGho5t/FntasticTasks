#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "GameFramework/FloatingPawnMovement.h"

#include "Unit.generated.h"

class UBehaviorTree;

UCLASS()
class FNTASTICTASKS_API AUnit : public APawn
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UFloatingPawnMovement* FloatingPawnMovement;
	
public:

	AUnit();

	virtual void Tick(float DeltaTime) override;

	void InitUnit(UBehaviorTree* BehaviorTree, FLinearColor UnitColor, FVector Location);

protected:

	virtual void BeginPlay() override;
};
