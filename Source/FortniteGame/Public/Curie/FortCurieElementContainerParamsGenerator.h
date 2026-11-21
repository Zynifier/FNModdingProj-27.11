// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortCurieElementContainerParamsGenerator.generated.h"

UCLASS(Abstract, EditInlineNew, MinimalAPI)
class UFortCurieElementContainerParamsGenerator : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category="Curie", meta=(Categories="Curie.Element"))
	FGameplayTag ElementTag;

};

