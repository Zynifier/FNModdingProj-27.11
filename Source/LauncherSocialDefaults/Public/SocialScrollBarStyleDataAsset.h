// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateTypes.h"
#include "SocialScrollBarStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialScrollBarStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FScrollBarStyle Style;

};

