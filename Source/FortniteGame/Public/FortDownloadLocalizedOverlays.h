// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LocalizedOverlays.h"
#include "FortDownloadLocalizedOverlays.generated.h"

class UMediaPlayer;

UCLASS(MinimalAPI, HideCategories=("Object"))
class UFortDownloadLocalizedOverlays : public ULocalizedOverlays
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Player")
	TObjectPtr<UMediaPlayer> MediaPlayer;

};

