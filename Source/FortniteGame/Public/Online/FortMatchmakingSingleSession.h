// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PartyBeaconState.h"
#include "Online/FortMatchmakingPolicy.h"
#include "Online/FortOnlineSessionTypes.h"
#include "FortMatchmakingSingleSession.generated.h"

class UFortSessionHelper;

USTRUCT()
struct FFortInviteSessionParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TEnumAsByte<EMatchmakingState::Type> State;

	UPROPERTY()
	FText FailureReason;

	UPROPERTY()
	TEnumAsByte<EPartyReservationResult::Type> LastBeaconResponse;

};

UCLASS()
class UFortMatchmakingSingleSession : public UFortMatchmakingPolicy
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FFortInviteSessionParams CurrentSessionParams;

	UPROPERTY(Transient)
	TObjectPtr<UFortSessionHelper> SessionHelper;

};

