// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_RootMotionInterrupt.generated.h"

UENUM()
namespace EMontageInterrupt
{
	enum Type
	{
		Any = 0,
		RootMotionOnly = 1,
		None = 2,
	};
}

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Object"), meta=(ShowWorldContextPin))
class UFortAnimNotifyState_RootMotionInterrupt : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interrupt")
	TEnumAsByte<EMontageInterrupt::Type> MontageInterrupt;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Interrupt")
	uint8 bAllowMoveInput : 1;

};

