// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SocialStyle.h"
#include "FortSocialStyle.generated.h"

class USocialStyleDataAsset;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"))
class UFortSocialStyle : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Properties")
	FSocialStyle Style;

	UPROPERTY(EditAnywhere, Category="Properties")
	TObjectPtr<USocialStyleDataAsset> OverrideStyle;

};

