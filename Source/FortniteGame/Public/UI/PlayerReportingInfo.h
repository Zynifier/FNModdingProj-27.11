// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerReportingInfo.generated.h"

class UFortLocalPlayer;
class UReportablePlayerInfo;

USTRUCT(BlueprintType)
struct FPlayerReportingInfoContainer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortLocalPlayer> Owner;

	UPROPERTY()
	TArray<TObjectPtr<UReportablePlayerInfo>> AllPlayerInfo;

	UPROPERTY()
	TArray<TObjectPtr<UReportablePlayerInfo>> AllIslandInfo;

};

