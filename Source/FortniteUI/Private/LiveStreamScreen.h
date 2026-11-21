// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Media/FortActivatableVideoPanel.h"
#include "LiveStreamScreen.generated.h"

class UFortStreamMediaSource;

UCLASS(Abstract)
class ULiveStreamScreen : public UFortActivatableVideoPanel
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="LiveStreamScreen")
	TObjectPtr<UFortStreamMediaSource> StreamMediaSource;

private:
	UFUNCTION()
	void OnRetrieveVideoUrlResult(const FString& Url);

};

