#include "Unit.h"


AUnit::AUnit()
{
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessAI = EAutoPossessAI::Spawned;
	
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Skeletal Mesh");
	const auto Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	
	SkeletalMesh->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");
	FloatingPawnMovement->MaxSpeed = 400;
}

void AUnit::BeginPlay()
{
	Super::BeginPlay();	
}

void AUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUnit::InitUnit(UBehaviorTree* BehaviorTree, FLinearColor UnitColor, FVector Location)
{
	const auto AI = Cast<AAIController>(GetController());
	AI->RunBehaviorTree(BehaviorTree);
	AI->GetBlackboardComponent()->SetValueAsVector(FName("Target"), Location);
	
	auto const Instance = UMaterialInstanceDynamic::Create(SkeletalMesh->GetMaterial(0), SkeletalMesh);
	Instance->SetVectorParameterValue("BodyColor", UnitColor);
	SkeletalMesh->SetMaterial(0, Instance);
}

