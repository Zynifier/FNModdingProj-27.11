// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WaitingRoomState.generated.h"

UCLASS(Config=Game)
class UWaitingRoomState : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Config)
	int32 GracePeriodMins;

};

