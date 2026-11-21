// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Knockback.generated.h"

class AFortPawn;
class AFortPlayerPawn;
class APawn;

USTRUCT(BlueprintType)
struct KNOCKBACKRUNTIME_API FKnockbackMutatorData : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="KnockbackMutatorData")
	TObjectPtr<APawn> Pawn;

	UPROPERTY(BlueprintReadWrite, Category="KnockbackMutatorData")
	float KnockbackMultiplier;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerKnockbackDataChanged, const FKnockbackMutatorData&, KnockbackData);

USTRUCT()
struct FKnockbackMutatorDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FKnockbackMutatorData> Entries;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class KNOCKBACKRUNTIME_API AFortAthenaMutator_Knockback : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TArray<FKnockbackMutatorData> GetAllPlayersKnockbackData();

	UFUNCTION(BlueprintPure)
	float GetKnockbackMultiplierInitialValue() const;

	UFUNCTION(BlueprintPure)
	float GetPercentDamageLowMaxThreshold() const;

	UFUNCTION(BlueprintPure)
	float GetPercentDamageMediumMaxThreshold() const;

	UFUNCTION(BlueprintCallable)
	void SetPlayersShouldBreakThroughStructures(const bool bActive, AFortPlayerPawn* PlayerPawn);

	UPROPERTY(EditDefaultsOnly, Category="Knockback Data")
	bool bStorePlayerKnockbackData;

	UPROPERTY(EditDefaultsOnly, Category="Knockback Data", meta=(EditCondition="bStorePlayerKnockbackData"))
	bool bReplicatePlayerKnockbackData;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerKnockbackDataChanged OnPlayerKnockbackDataChanged;

	UPROPERTY(Replicated)
	FKnockbackMutatorDataArray AllPlayersKnockbackData;

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Knockback")
	FScalableFloat bDisplayKnockbackDamageNumbersAsPercentage;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Knockback")
	FScalableFloat ConvertToKnockbackDamageMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Knockback")
	FScalableFloat PercentDamageLowMaxThreshold;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Knockback")
	FScalableFloat PercentDamageMediumMaxThreshold;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Knockback")
	float KnockbackMultiplierInitialValue;

private:
	UFUNCTION()
	void HandleBlockedCharacterMovement(FHitResult& InOutImpact, AFortPawn* FortPawn);

};

