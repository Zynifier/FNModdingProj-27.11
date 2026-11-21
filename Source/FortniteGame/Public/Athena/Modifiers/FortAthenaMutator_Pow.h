// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Pow.generated.h"

class AFortAthenaMutator_Pow;
class AFortPlayerStateAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRespawnTimeRemainingUpdate, int32, TimeLeft);

USTRUCT(BlueprintType)
struct FPowPlayerDataEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="PowPlayerDataEntry")
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PowPlayerDataEntry")
	float CurrentMaxShield;

	UPROPERTY(BlueprintReadOnly, Transient, Category="PowPlayerDataEntry")
	float CurrentShield;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<AFortAthenaMutator_Pow> POWMutator;

};

USTRUCT(BlueprintType)
struct FPowPlayerDataArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortAthenaMutator_Pow> OwningMutator;

	UPROPERTY()
	TArray<FPowPlayerDataEntry> Entries;

};

UCLASS(MinimalAPI, HideCategories=("Actor", "Replication", "FortAthenaMutator", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Pow : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetPlayerCurrentShield(AFortPlayerStateAthena* Player) const;

	UPROPERTY(BlueprintAssignable)
	FOnRespawnTimeRemainingUpdate TimeRemainingUpdated;

protected:
	UFUNCTION()
	void OnRep_RespawningCurrentlyAllowed();

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FFortRespawnLogicData_Teams RespawnSettings;

	UPROPERTY(EditDefaultsOnly, Category="Messaging")
	TArray<FAthenaGameMessageData> IntroMessages;

	UPROPERTY(EditDefaultsOnly, Category="Messaging")
	FAthenaGameMessageData RespawningOffMessage;

	UPROPERTY(EditDefaultsOnly, Category="Messaging")
	FAthenaGameMessageData RespawnsWillBeOffMessage;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat RespawningTimeAllowed;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat GrantMaxShieldAtRespawnsOff;

	UPROPERTY(EditDefaultsOnly, Category="Mechanics")
	FScalableFloat GrantMaxHealthAtRespawnsOff;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortAthenaMutator_Pow")
	FPowPlayerDataArray PlayerData;

private:
	UPROPERTY(ReplicatedUsing=OnRep_RespawningCurrentlyAllowed)
	bool bRespawningCurrentlyAllowed;

};

