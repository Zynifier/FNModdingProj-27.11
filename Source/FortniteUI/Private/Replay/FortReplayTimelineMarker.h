// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "Replay/FortReplayTypes.h"
#include "FortReplayTimelineMarker.generated.h"

class UCommonLazyImage;
class UObject;

UCLASS(Abstract)
class UFortReplayTimelineMarker : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Icons", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D", ArraySizeEnum="/Script/FortniteGame.EFortReplayEventType"))
	TSoftObjectPtr<UObject> MarkerIcons[4];

	UPROPERTY(BlueprintReadOnly, Export, Category="FortReplayTimelineMarker", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_MarkerIcon;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Event Type"))
	EFortReplayEventType DesignTime_EventType;
#endif

};

