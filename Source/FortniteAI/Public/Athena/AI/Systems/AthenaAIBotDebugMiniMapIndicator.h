// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "UI/HUDIndicator/FortMiniMapIndicator.h"
#include "AthenaAIBotDebugMiniMapIndicator.generated.h"

USTRUCT()
struct FBotDebugInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	int32 BotID;

	UPROPERTY(Transient)
	int32 SquadID;

	UPROPERTY(Transient)
	FString BTActiveTasks;

	UPROPERTY(Transient)
	EAlertLevel AlertLevel;

	UPROPERTY(Transient)
	FVector Location;

};

UCLASS()
class UAthenaAIBotDebugMiniMapIndicator : public UFortMiniMapIndicator
{
	GENERATED_BODY()

private:
	UPROPERTY(Replicated)
	TArray<FBotDebugInfo> BotDebugInfoList;

	UPROPERTY(Replicated)
	FSlateBrush DebugMinimapIconBrush;

};

