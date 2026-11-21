// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "FortBlendBehaviorAnimMetaData.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object"))
class UFortBlendBehaviorAnimMetaData : public UAnimMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	bool bShouldHidePropsDuringBlendInFrontEnd;

};

