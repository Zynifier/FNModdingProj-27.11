// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateTypes.h"
#include "SocialCheckBoxStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialCheckBoxStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FCheckBoxStyle Style;

};

