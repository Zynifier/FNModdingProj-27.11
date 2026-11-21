// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "CreativeVideoPlayerWorldSubsystem.generated.h"

class APlayerController;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCreativeVideoPlayerNotifyFullscreenChange, APlayerController*, TargetPlayer, bool, bIsClosing);

UCLASS()
class CREATIVEVIDEOPLAYERRUNTIME_API UCreativeVideoPlayerWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FCreativeVideoPlayerNotifyFullscreenChange OnNotifyFullscreenChange;

};

