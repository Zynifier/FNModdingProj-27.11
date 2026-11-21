// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortToyInterface.generated.h"

class AFortPlayerController;

UINTERFACE(BlueprintType, Blueprintable)
class UFortToyInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortToyInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Visuals")
	void InitializeToyInstance(AFortPlayerController* OwningPC, int32 NumTimesSummoned);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Visuals")
	void InitializeToyPreviewInFrontend();

	UFUNCTION(BlueprintImplementableEvent, Category="Visuals")
	void NotifyToyInstanceOfReuse();

	UFUNCTION(BlueprintImplementableEvent, Category="Visuals")
	void StartToyFadeOutDueToNewPlacement();

};

