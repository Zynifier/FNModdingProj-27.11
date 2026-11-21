// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimMetaData.h"
#include "FortMontageSlotBlendMetaData.generated.h"

UCLASS(HideCategories=("Object"))
class UFortMontageSlotBlendMetaData : public UAnimMetaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMontageSlotBlendMetaData")
	float FullBodyToUpperbodyInMotionBlendTime;

};

