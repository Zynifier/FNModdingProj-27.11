// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricInteractableViewModel.h"
#include "FabricKnobViewModel.generated.h"

UCLASS(BlueprintType, meta=(Category="Fabric UI"))
class UFabricKnobViewModel : public UFabricInteractableViewModel
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FabricKnobViewModel")
	bool bValueVisible;

};

