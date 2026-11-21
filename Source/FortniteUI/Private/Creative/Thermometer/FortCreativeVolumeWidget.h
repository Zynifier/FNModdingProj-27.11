// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortCreativeVolumeWidget.generated.h"

class AFortGameState;
class AFortVolume;
class APlayerState;

UCLASS(Abstract, NotBlueprintable, meta=(DisableNativeTick))
class UFortCreativeVolumeWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCreativeVolumeWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION()
	virtual void BindToVolumeManager();

	UFUNCTION(BlueprintPure)
	AFortVolume* GetVolume() const;

	UFUNCTION()
	virtual void OnGameInstanceGameStateSet(AFortGameState* GameState);

	UFUNCTION()
	void OnVolumeManagerClientEnterVolume(APlayerState* PlayerState, AFortVolume* Volume);

};

