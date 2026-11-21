// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "Building/BuildingTypes.h"
#include "FortCreativeRoundSettings.generated.h"

class AFortPlayerController;
class UFortWorldItemDefinition;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCreativeRoundSettings : public ABuildingProp
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Round Settings")
	int32 GetResourceGivenPerRound(const EFortResourceType::Type InResourceType) const;

	UFUNCTION(BlueprintPure, Category="Round Settings")
	int32 GetResourceGivenToWinnersPerRound(const EFortResourceType::Type InResourceType) const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Round Settings")
	int32 GetRoundIndex() const;

	UFUNCTION(BlueprintPure, Category="Round Settings")
	bool IsActive() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Legacy", meta=(DisplayName="RoundLegacy"))
	int32 RoundIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool bKeepItemsBetweenRoundsOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions", meta=(DisplayAfter="bKeepItemsBetweenRoundsOverride", EditCondition="bKeepItemsBetweenRoundsOverride"))
	bool bKeepItemsBetweenRounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Legacy", meta=(ScriptName="KeepItemsAtEndOfRound"))
	int32 KeepItemsBetweenRounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions", meta=(DisplayName="Keep Resources Between Rounds"))
	float PercentageOfResourcesKeptBetweenRounds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool bReloadAndRestockWeaponsEachRoundOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions", meta=(DisplayAfter="bReloadAndRestockWeaponsEachRoundOverride", EditCondition="bReloadAndRestockWeaponsEachRoundOverride"))
	bool bReloadAndRestockWeaponsEachRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Legacy", meta=(ScriptName="ReloadAndRestockWeaponsAtEndOfRound"))
	int32 ReloadAndRestockWeaponsEachRound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Round Settings")
	bool bIsRelevantThisRound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool bEnableOnMinigameStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Legacy")
	int32 Active;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Round Settings")
	bool bActiveDuringMinigame;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Round Settings")
	int32 WinningTeamOnMessageReceived;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions")
	bool bLastStandingWinsOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions", meta=(DisplayAfter="bLastStandingWinsOverride", EditCondition="bLastStandingWinsOverride"))
	bool bLastStandingWins;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Legacy")
	int32 LastTeamStandingWins;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Round Settings")
	TMap<TObjectPtr<UFortWorldItemDefinition>, int32> RestockAmmoAmounts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Round Settings")
	int32 DefaultRestockAmmoAmount;

protected:
	UFUNCTION(BlueprintCallable, Category="Round Settings")
	void ClearResourcesGivenPerRound();

	UFUNCTION(BlueprintCallable, Category="Round Settings")
	void ClearResourcesGivenToWinnersPerRound();

	UFUNCTION(BlueprintCallable, Category="Round Settings")
	void EndRound(AFortPlayerController* InstigatorPC);

	UFUNCTION(BlueprintCallable, Category="Round Settings")
	void SetResourceGivenPerRound(const EFortResourceType::Type InResourceType, const int32 Amount);

	UFUNCTION(BlueprintCallable, Category="Round Settings")
	void SetResourceGivenToWinnersPerRound(const EFortResourceType::Type InResourceType, const int32 Amount);

};

