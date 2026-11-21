// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicUIWidgetTarget.generated.h"

class UWidget;

USTRUCT()
struct FDynamicUIWidgetTarget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI")
	FName WidgetPath;

	UPROPERTY(Transient)
	TSoftClassPtr<UWidget> WidgetClass;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI", meta=(EditCondition="bUseUniqueID"))
	FName UniqueID;

	UPROPERTY(EditDefaultsOnly, Category="Dynamic UI|Override")
	uint8 bUseUniqueID : 1;

};

