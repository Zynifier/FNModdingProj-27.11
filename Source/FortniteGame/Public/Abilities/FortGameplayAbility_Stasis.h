// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbility_Stasis.generated.h"

UCLASS(BlueprintType)
class UFortGameplayAbility_Stasis : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AppendAllowedActionTags(const FGameplayTagContainer& NewAllowedActionTags);

	UFUNCTION(BlueprintPure)
	virtual bool IsActionAllowed(const FGameplayTag& InActionTag) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveAllowedActionTags(const FGameplayTagContainer& ActionTagsToRemove);

protected:
	UPROPERTY(EditAnywhere, Replicated, Category="FortGameplayAbility_Stasis")
	FGameplayTagContainer AllowedActionTags;

};

UCLASS(BlueprintType)
class UFortGameplayAbility_Stasis_NoMovementOrFalling : public UFortGameplayAbility_Stasis
{
	GENERATED_BODY()

};

UCLASS(BlueprintType)
class UFortGameplayAbility_Stasis_NoMovementOrTurning : public UFortGameplayAbility_Stasis
{
	GENERATED_BODY()

};

