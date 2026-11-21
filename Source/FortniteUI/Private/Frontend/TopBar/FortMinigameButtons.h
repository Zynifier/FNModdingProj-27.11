// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortMinigameButtons.generated.h"

class AActor;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMinigameButtons : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortMinigameButtons(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintPure)
	bool IsSpatialGameplayInterfaceReadyAndPawnValid(AActor* SpatialAsActor) const;

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* OnGetDesiredFocusTarget() const;

};

