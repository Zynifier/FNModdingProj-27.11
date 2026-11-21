// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerLandingAnimInstance.generated.h"

UCLASS(HideCategories=("AnimInstance"))
class FORTNITEGAME_API UFortPlayerLandingAnimInstance : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Landing", meta=(BlueprintThreadSafe))
	void ResetCanExitLanding() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Landing", meta=(BlueprintThreadSafe))
	void SetCanExitLanding() const;

};

