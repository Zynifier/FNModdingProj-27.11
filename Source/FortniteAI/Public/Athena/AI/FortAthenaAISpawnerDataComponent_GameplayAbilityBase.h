// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_GameplayAbilityBase.generated.h"

class UFortAbilitySet;
class UGameplayEffect;

USTRUCT(BlueprintType)
struct FInitialGameplayEffectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="InitialGameplayEffectInfo")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditAnywhere, Category="InitialGameplayEffectInfo")
	float Level;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_GameplayAbilityBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FGameplayTagContainer GetLooseTagsToApplyToPawn() const;

	UFUNCTION(BlueprintCallable)
	void SetLooseTagsToApplyToPawn(const FGameplayTagContainer& InGameplayTagContainer);

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	void GetInitialGameplayAbilities(TArray<UFortAbilitySet*>& OutGASets) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	void GetInitialGameplayEffects(TArray<FInitialGameplayEffectInfo>& OutGEs) const;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAISpawnerDataComponent_GameplayAbilityBase", meta=(AllowPrivateAccess="true"))
	TArray<FInitialGameplayEffectInfo> InitialGameplayEffect;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAISpawnerDataComponent_GameplayAbilityBase", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UFortAbilitySet>> InitialGameplayAbilitiesSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaAISpawnerDataComponent_GameplayAbilityBase", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer LooseTagsToApplyToPawn;

};

