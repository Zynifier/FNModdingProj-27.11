// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "RealTimeThumbnailSubsystem.generated.h"

class UFortThumbnailRenderer;

UCLASS(MinimalAPI, BlueprintType, meta=(DisplayName="Real Time Thumbnails"))
class URealTimeThumbnailSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DeterminesOutputType="ThumbnailRendererClass"))
	UFortThumbnailRenderer* CreateThumbnailRenderer(TSubclassOf<UFortThumbnailRenderer> ThumbnailRendererClass);

	UFUNCTION(BlueprintCallable)
	void DestroyThumbnailRenderer(UFortThumbnailRenderer* ThumbnailRenderer);

};

