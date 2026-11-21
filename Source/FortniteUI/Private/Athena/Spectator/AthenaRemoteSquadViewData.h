// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "AthenaRemoteSquadViewData.generated.h"

class UAthenaRemotePlayerViewData;
class UAthenaRemoteSquadViewData;
class UFortMinigameTeamIdentification;

UCLASS(BlueprintType)
class UAthenaRemoteSquadViewData : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEventDelegate, UAthenaRemoteSquadViewData*, SquadData);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIntDelegate, UAthenaRemoteSquadViewData*, SquadData, int32, IntParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLinearColorDelegate, UAthenaRemoteSquadViewData*, SquadData, FLinearColor, ColorParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerDelegate, UAthenaRemoteSquadViewData*, SquadData, UAthenaRemotePlayerViewData*, PlayerData);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUInt8Delegate, UAthenaRemoteSquadViewData*, SquadData, uint8, IntParam);

public:
	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is Eliminated"))
	bool GetIsEliminated() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Kill Score"))
	int32 GetKillScore() const;

	UFUNCTION(BlueprintPure)
	const UFortMinigameTeamIdentification* GetMinigameTeamId() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Place"))
	int32 GetPlace() const;

	UFUNCTION(BlueprintPure)
	const TArray<UAthenaRemotePlayerViewData*>& GetPlayerDatas() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Color"))
	FLinearColor GetSquadColor() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Id"))
	int32 GetSquadId() const;

	UFUNCTION(BlueprintPure)
	int32 GetSquadSessionRank() const;

	UPROPERTY(BlueprintAssignable)
	FPlayerDelegate OnPlayerAdded;

	UPROPERTY(BlueprintAssignable)
	FUInt8Delegate OnSquadIdChanged;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnSquadKillScoreChanged;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnSquadPlaceChanged;

	UPROPERTY(BlueprintAssignable)
	FLinearColorDelegate OnSquadColorChanged;

	UPROPERTY(BlueprintAssignable)
	FEventDelegate OnSquadEliminated;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnSquadSessionRankChanged;

private:
	UFUNCTION()
	void HandlePlayerDeadStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool InEliminated);

	UFUNCTION()
	void HandlePlayerKillscoreChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InKillScore);

	UFUNCTION()
	void HandlePlayerPlaceChanged(UAthenaRemotePlayerViewData* InPlayerData, int32 InPlace);

	UFUNCTION()
	void HandleSessionRankChanged(UAthenaRemotePlayerViewData* InPlayerData, const int32 InSessionRank);

	UPROPERTY()
	TArray<TObjectPtr<UAthenaRemotePlayerViewData>> PlayerDataArray;

};

