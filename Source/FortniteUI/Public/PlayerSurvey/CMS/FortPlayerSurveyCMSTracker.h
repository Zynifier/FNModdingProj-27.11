// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPlayerSurveyCMSTracker.generated.h"

class UFortLocalPlayer;
class UFortMcpProfileCommonCore;

UCLASS()
class FORTNITEUI_API UFortPlayerSurveyCMSTracker : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortLocalPlayer> Player;

	UPROPERTY()
	TObjectPtr<UFortMcpProfileCommonCore> McpProfile;

};

