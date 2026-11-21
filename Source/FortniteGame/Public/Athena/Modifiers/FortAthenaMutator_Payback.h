// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_Payback.generated.h"

class AFortPlayerStateAthena;
class APlayerState;
class UGameplayEffect;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPaybackKill, AFortPlayerStateAthena*, KillerPlayerState, AFortPlayerStateAthena*, VictimPlayerState);

USTRUCT()
struct FPaybackMutatorEffectData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> KillerPlayerState;

	UPROPERTY()
	uint8 VictimTeam;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> VictimPlayerStates;

	UPROPERTY()
	float StartTime;

	UPROPERTY()
	float EndTime;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Payback : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	void GetAllPlayersMarkedForPayback(TArray<AFortPlayerStateAthena*>& OutPlayerStates) const;

	UFUNCTION(BlueprintPure)
	float GetHighestPaybackTimeRemaining(const APlayerState* KillerPlayerState) const;

	UFUNCTION(BlueprintPure)
	void GetPaybackTeams(TArray<uint8>& OutTeams, const APlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure)
	float GetPaybackTimeRemaining(const APlayerState* KillerPlayerState, const uint8 VictimTeam) const;

	UFUNCTION(BlueprintPure)
	void GetPlayersToPayBack(TArray<AFortPlayerStateAthena*>& OutPlayerStatesToPayBack, const APlayerState* AttackerPlayerState) const;

	UFUNCTION(BlueprintPure)
	void GetTeamPlayersMarkedForPayback(TArray<AFortPlayerStateAthena*>& OutPlayerStates, const uint8 Team) const;

	UFUNCTION(BlueprintPure)
	bool IsMarkedForPayback(const APlayerState* PlayerState) const;

	UFUNCTION(BlueprintPure)
	bool IsMarkedForPaybackByTeam(const APlayerState* PlayerState, const uint8 Team) const;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Payback")
	TSubclassOf<UGameplayEffect> PaybackMarkerEffectClass;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Payback")
	FScalableFloat bEffectLastsUntilRespawn;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Payback")
	FScalableFloat DefaultEffectDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Payback")
	FGameplayTag SetByCallerDurationTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Payback")
	FGameplayTag ShowPaybackHUDTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Payback")
	FScalableFloat bNewEffectPerKill;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Payback")
	FScalableFloat ExtraPointsPerPaybackKill;

	UPROPERTY(BlueprintAssignable)
	FOnPaybackKill OnPaybackKill;

private:
	UFUNCTION(NetMulticast, Unreliable)
	void NetMulticast_OnPaybackKill(AFortPlayerStateAthena* KillerPlayerState, AFortPlayerStateAthena* VictimPlayerState);

	UFUNCTION()
	void OnDeadStateChanged(AFortPlayerStateAthena* VictimPlayerState, bool bDead);

	UPROPERTY(Replicated)
	TArray<FPaybackMutatorEffectData> PaybackEffectDataArray;

};

UCLASS()
class UFortCheatManager_Payback : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void PaybackDebug(float TextScale = 1.000000f);

};

