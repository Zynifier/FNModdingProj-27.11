// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "AthenaSpectatorPlayerListRowData.generated.h"

class AFortPlayerStateAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIsSpectatorTargetChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnKillsChanged);

UCLASS(MinimalAPI, BlueprintType)
class UAthenaSpectatorPlayerListRowData : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="PlayerState"))
	const AFortPlayerStateAthena* GetPlayerState();

	UFUNCTION()
	void SetKills(AFortPlayerStateAthena* PS, int32 InKills);

	UPROPERTY(BlueprintAssignable)
	FOnIsSpectatorTargetChanged OnIsSpectatorTargetChanged;

	UPROPERTY(BlueprintAssignable)
	FOnKillsChanged OnKillsChanged;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorPlayerListRowData")
	int32 Rank;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorPlayerListRowData")
	int32 TeamNumber;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorPlayerListRowData")
	FLinearColor TeamColor;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorPlayerListRowData")
	FString PlayerName;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorPlayerListRowData")
	int32 Kills;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorPlayerListRowData")
	bool IsRecordingPlayer;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSpectatorPlayerListRowData")
	bool IsSpectatorTarget;

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY()
	FUniqueNetIdRepl PlayerUniqueId;

};

