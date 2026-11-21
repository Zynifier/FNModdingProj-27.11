// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortCosmeticVariantAction.generated.h"

UINTERFACE()
class URespondsToVariantAction : public UInterface
{
	GENERATED_BODY()
};

class IRespondsToVariantAction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void RespondToTaggedAction(const FGameplayTag& ActionTag, bool bIsApplyingAction);

};

