// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "FabricInteractableViewModel.h"
#include "FabricButtonBaseViewModel.generated.h"

UCLASS(BlueprintType, meta=(Category="Fabric UI"))
class UFabricButtonBaseViewModel : public UFabricInteractableViewModel
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FabricButtonBaseViewModel")
	ECheckBoxState ToggleState;

};

