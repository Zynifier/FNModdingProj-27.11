// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocialFontStyle.h"
#include "SocialFontStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialFontStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FSocialFontStyle Style;

};

