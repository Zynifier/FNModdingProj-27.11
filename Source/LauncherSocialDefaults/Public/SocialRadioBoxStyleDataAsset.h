// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateTypes.h"
#include "SocialRadioBoxStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialRadioBoxStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FCheckBoxStyle Style;

};

