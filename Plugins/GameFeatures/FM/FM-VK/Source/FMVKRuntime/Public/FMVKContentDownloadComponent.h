// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "FMVKContentDownloadComponent.generated.h"

UCLASS(Config=Game, DefaultConfig, HideCategories=("Trigger", "PhysicsVolume"))
class FMVKRUNTIME_API UFMVKContentDownloadComponent : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFMVKContentDownloadComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY(Config)
	FString DefaultLinkCode;

};

