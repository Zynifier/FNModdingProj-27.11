// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PartyBeaconState.h"
#include "UObject/NoExportTypes.h"
#include "Online/FortMatchmakingEnums.h"
#include "Online/FortOnlineSessionTypes.h"
#include "FortSearchPass.generated.h"

class UFortSessionHelper;

USTRUCT()
struct FFortSearchPassParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ControllerId;

	UPROPERTY()
	FName SessionName;

	UPROPERTY()
	FString BestDatacenterId;

	UPROPERTY()
	int32 MaxProcessedSearchResults;

};

USTRUCT()
struct FFortSearchPassState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BestSessionIdx;

	UPROPERTY()
	bool bWasCanceled;

	UPROPERTY()
	EFortSessionHelperJoinResult FailureType;

	UPROPERTY()
	TEnumAsByte<EMatchmakingState::Type> MatchmakingState;

	UPROPERTY()
	TEnumAsByte<EPartyReservationResult::Type> LastBeaconResponse;

};

USTRUCT()
struct FMMAttemptState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BestSessionIdx;

	UPROPERTY()
	int32 NumSearchResults;

	UPROPERTY()
	TEnumAsByte<EMatchmakingState::Type> State;

	UPROPERTY()
	TEnumAsByte<EPartyReservationResult::Type> LastBeaconResponse;

};

UCLASS(Config=Game)
class UFortSearchPass : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortSessionHelper> SessionHelper;

	UPROPERTY(Transient)
	FFortSearchPassParams CurrentSearchParams;

	UPROPERTY(Transient)
	FFortSearchPassState CurrentSearchPassState;

};

