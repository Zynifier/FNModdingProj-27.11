// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocialListStyle.h"
#include "SocialListStyleDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialListStyleDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FSocialListStyle Style;

};

