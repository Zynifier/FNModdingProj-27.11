// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FabricTimelinePreviewComponent.generated.h"

class UTimelineComponent;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FABRICRUNTIME_API UFabricTimelinePreviewComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool GetShouldPreview() const;

	UFUNCTION(BlueprintCallable)
	void PreviewTimeline(UTimelineComponent* Timeline, float SecondsToPlay, bool bReverseAnimation);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	UTimelineComponent* CurrentTimeline;

};

