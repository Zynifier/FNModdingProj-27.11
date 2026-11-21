// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortLocomotionAnimAsset.generated.h"

class UFortLocomotionAnimAsset;
class UFortLocomotionAnimSetData;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortLocomotionAnimAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parent")
	TObjectPtr<UFortLocomotionAnimAsset> Parent;

	UPROPERTY(EditAnywhere, Category="Sets")
	TObjectPtr<UFortLocomotionAnimSetData> MasculineSet;

	UPROPERTY(EditAnywhere, Category="Sets")
	TObjectPtr<UFortLocomotionAnimSetData> FeminineSet;

};

