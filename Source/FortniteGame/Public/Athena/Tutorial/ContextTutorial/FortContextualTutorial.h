// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortContextualTutorial.generated.h"

class AActor;
class AFortPlayerController;
class UFortContextualTutorialDefinition;
class UFortHighlightObjectInWorldComponent;

UCLASS(MinimalAPI)
class UFortContextualTutorial : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> WeakMarkerActor;

	UPROPERTY(Transient)
	FText MarkerText;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortHighlightObjectInWorldComponent> MarkerHighlightComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortContextualTutorialDefinition> TutorialDefinition;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> OwnerController;

};

