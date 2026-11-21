// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUI/DynamicUITypes.h"
#include "DynamicUIDeprecation.generated.h"

class UWidget;

USTRUCT()
struct FDynamicUIUnallowed
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(AllowAbstract="false", AllowedClasses="/Script/UMG.UserWidget"))
	TSoftClassPtr<UWidget> Widget;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(EditCondition="bUseUniqueID"))
	FName UniqueID;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	EDynamicUIUnallowedBehavior Behavior;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	uint8 bTargetAll : 1;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(InlineEditConditionToggle))
	uint8 bUseUniqueID : 1;

};

