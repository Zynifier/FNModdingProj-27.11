// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPlaylistManager.generated.h"

class UFortPlaylistAthena;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortPlaylistManager : public UObject
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortPlaylistAthena>> PreloadedPlaylists;

};

