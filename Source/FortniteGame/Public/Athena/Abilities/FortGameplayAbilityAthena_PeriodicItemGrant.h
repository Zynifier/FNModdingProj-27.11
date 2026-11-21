// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortGameplayAbilityAthena_PeriodicItemGrant.generated.h"

class AFortPlayerController;
class UFortWorldItemDefinition;

USTRUCT()
struct FActiveItemGrantInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ActiveItemGrantInfo")
	TObjectPtr<UFortWorldItemDefinition> Item;

	UPROPERTY(EditDefaultsOnly, Category="ActiveItemGrantInfo")
	FScalableFloat AmountToGive;

	UPROPERTY(EditDefaultsOnly, Category="ActiveItemGrantInfo")
	FScalableFloat MaxAmount;


	FORTNITEGAME_API bool operator==(const FActiveItemGrantInfo& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FActiveItemGrantInfo& Value);
};

UCLASS()
class UFortGameplayAbilityAthena_PeriodicItemGrant : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StartItemAwardTimers();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StopItemAwardTimers();

protected:
	UPROPERTY(EditDefaultsOnly, Category="Granted Items")
	TMap<FActiveItemGrantInfo, FScalableFloat> ItemsToGrant;

	UPROPERTY()
	TArray<FTimerHandle> ActiveTimers;

private:
	UPROPERTY()
	TObjectPtr<AFortPlayerController> OwnerControllerCachedValue;

};

