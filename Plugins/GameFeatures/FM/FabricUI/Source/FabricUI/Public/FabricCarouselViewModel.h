// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FabricInteractableViewModel.h"
#include "FabricCarouselViewModel.generated.h"

UCLASS(BlueprintType, meta=(Category="Fabric UI"))
class UFabricCarouselViewModel : public UFabricInteractableViewModel
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Category="FabricCarouselViewModel")
	bool bPresetEnabled;

	UPROPERTY(BlueprintReadWrite, Category="FabricCarouselViewModel")
	bool bShowBorder;

};

