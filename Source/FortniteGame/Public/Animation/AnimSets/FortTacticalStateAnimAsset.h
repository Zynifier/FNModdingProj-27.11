// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortTacticalStateAnimAsset.generated.h"

class UFortTacticalStateAnimAsset;
class UFortTacticalStateAnimSetData;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortTacticalStateAnimAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parent")
	TObjectPtr<UFortTacticalStateAnimAsset> Parent;

	UPROPERTY(EditAnywhere, Category="Sets")
	TObjectPtr<UFortTacticalStateAnimSetData> MasculineSet;

	UPROPERTY(EditAnywhere, Category="Sets")
	TObjectPtr<UFortTacticalStateAnimSetData> FeminineSet;

};

