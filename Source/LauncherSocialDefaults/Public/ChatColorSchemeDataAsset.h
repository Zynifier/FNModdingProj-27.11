// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ChatColorScheme.h"
#include "ChatColorSchemeDataAsset.generated.h"

UCLASS(BlueprintType)
class UChatColorSchemeDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FChatColorScheme ChatColorData;

};

