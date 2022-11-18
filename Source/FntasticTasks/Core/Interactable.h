#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class FNTASTICTASKS_API IInteractable
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnInteract();
};
