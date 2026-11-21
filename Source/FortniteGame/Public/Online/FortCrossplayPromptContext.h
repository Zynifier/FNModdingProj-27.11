// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContext/FortLocalPlayerSubsystem.h"
#include "FortCrossplayPromptContext.generated.h"

class UFortPlaylistAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCrossplayPreferenceChanged, bool, IsCrossplayEnabled);

UCLASS(Config=Game, MinimalAPI)
class UFortCrossplayPromptContext : public UFortLocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsCrossplayEnabled() const;

	UFUNCTION(BlueprintPure)
	bool IsPlaylistLimitedPoolMatchmakingEnabled(const UFortPlaylistAthena* PlaylistData) const;

private:
	UPROPERTY(BlueprintAssignable, Category="FortGameOptions", meta=(AllowPrivateAccess="true"))
	FCrossplayPreferenceChanged CrossplayPreferenceChanged;

};

