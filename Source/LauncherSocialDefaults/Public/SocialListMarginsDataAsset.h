// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocialListMargins.h"
#include "SocialListMarginsDataAsset.generated.h"

UCLASS(BlueprintType)
class USocialListMarginsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FSocialListMargins Style;

};

