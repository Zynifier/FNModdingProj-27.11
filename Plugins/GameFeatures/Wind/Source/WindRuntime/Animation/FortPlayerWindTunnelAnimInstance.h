// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerWindTunnelAnimInstance.generated.h"

UCLASS(HideCategories=("AnimInstance"))
class UFortPlayerWindTunnelAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerWindTunnelAnimInstance")
	uint8 bApplyWindSlideAdditive : 1;

};

