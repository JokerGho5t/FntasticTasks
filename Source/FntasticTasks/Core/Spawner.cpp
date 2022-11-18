#include "Spawner.h"

#include "NiagaraComponentPool.h"

ASpawner::ASpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Mesh->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	Mesh->Mobility = EComponentMobility::Static;
	Mesh->SetGenerateOverlapEvents(false);
	Mesh->bUseDefaultCollision = true;

	RootComponent = Mesh;
}

void ASpawner::OnInteract_Implementation()
{
	auto Point = GetActorLocation() + SpawnPoint;
	
	UGameplayStatics::PlaySoundAtLocation(this, SpawnSound, Point);
	UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, SpawnFX, Point);
	FX->SetColorParameter(FName("Color"), UnitColor * 1000);

	const auto Rotation = UKismetMathLibrary::FindLookAtRotation(Point, TargetPoint->GetActorLocation());
	AUnit* Unit = GetWorld()->SpawnActor<AUnit>(UnitForSpawn, Point, Rotation);
	Unit->InitUnit(BTAsset, UnitColor, TargetPoint->GetActorLocation());
}