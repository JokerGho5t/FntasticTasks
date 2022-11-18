#include "PawnRunners.h"

#include "Interactable.h"


APawnRunners::APawnRunners()
{
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->bDoCollisionTest = false;
	SpringArm->TargetArmLength = 1200;
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0, 0));

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
}

void APawnRunners::BeginPlay()
{
	Super::BeginPlay();

	const auto PC = GetWorld()->GetFirstPlayerController();
	if(!PC) return;
	
	auto InputMode = FInputModeGameAndUI();
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	PC->SetInputMode(InputMode);
	PC->SetShowMouseCursor(true);
}

void APawnRunners::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APawnRunners::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("RotateCamera", this, &APawnRunners::RotateCamera);
	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &APawnRunners::OnClick);

}

void APawnRunners::OnClick()
{
	const auto PlayerController = GetWorld()->GetFirstPlayerController();
	if(!PlayerController)
	{
		return;
	}
	
	FHitResult HitResult;
	
	const bool bHit = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Visibility, false, HitResult);

	if(bHit)
	{
		if(const auto Actor = HitResult.GetActor())
		{
			if(const auto InteractableActor = Cast<IInteractable>(Actor))
				InteractableActor->Execute_OnInteract(Actor);
		}
	}
}

void APawnRunners::RotateCamera(const float AxisValue)
{
	AddControllerYawInput(AxisValue * RotateSpeed * GetWorld()->GetDeltaSeconds());
}

