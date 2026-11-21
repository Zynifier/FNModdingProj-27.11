// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortItemChooserData.h"
#include "FortFloppingRabbitChooserData.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortFloppingRabbitChooserData : public UFortItemChooserData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortFloppingRabbitChooserData")
	bool bOneHandGrip;

};

