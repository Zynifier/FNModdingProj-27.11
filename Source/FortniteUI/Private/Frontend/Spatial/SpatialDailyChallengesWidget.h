// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Spatial/SpatialScreen.h"
#include "SpatialDailyChallengesWidget.generated.h"

class UFortDailyChallengeStickyNoteWidget;

UCLASS(Abstract)
class USpatialDailyChallengesWidget : public UAthenaSpatialScreen
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDailyChallengeStickyNoteWidget> StickyNote_Top;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDailyChallengeStickyNoteWidget> StickyNote_Middle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDailyChallengeStickyNoteWidget> StickyNote_Bottom;

};

