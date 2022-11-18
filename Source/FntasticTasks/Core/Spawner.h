#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Unit.h"

#include "Spawner.generated.h"

class AUnit;
class UBehaviorTree;
class USoundCue;

UCLASS()
class FNTASTICTASKS_API ASpawner : public AActor, public IInteractable
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Rendering,Physics,Components|StaticMesh", AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(MakeEditWidget = true, AllowPrivateAccess = true))
	FVector SpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true))
	AActor* TargetPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true))
	UNiagaraSystem* SpawnFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true))
	USoundBase* SpawnSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true))
	UBehaviorTree* BTAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true))
	FLinearColor UnitColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true))
	TSubclassOf<AUnit> UnitForSpawn;
	
public:

	ASpawner();
	
	virtual void OnInteract_Implementation() override;
};
