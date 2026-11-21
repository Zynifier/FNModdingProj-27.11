// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Frontend/Spatial/SpatialFrontend.h"
#include "FortEventLevelScreen.generated.h"

class UFortActivatableVideoPanel;
class UFortEventLevelData;

UCLASS(Abstract, MinimalAPI)
class UFortEventLevelScreen : public UAthenaSpatialFrontend
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnEventCinematicVideoFinished();

private:
	UFUNCTION()
	void StreamedVideoOnMediaOpened(const FString& OpenedURL);

	UFUNCTION()
	void StreamedVideoOnMediaPlayerEndReached();

	UFUNCTION()
	void StreamedVideoOnOpenFailure(const FString& OpenedURL);

	UFUNCTION()
	void StreamedVideoOnSkipBeforeVideoURLReceived();

	UFUNCTION()
	void StreamedVideoOnSkipButtonClicked();

	UFUNCTION()
	void StreamedVideoOnUrlFailure(const FString& OpenedURL);

	UFUNCTION()
	void StreamedVideoOnUrlSuccess(const FString& OpenedURL);

	UFUNCTION()
	void StreamedVideoOpeningTimedOut();

	UPROPERTY(EditDefaultsOnly, Category="FortEventLevelScreen")
	TObjectPtr<UFortEventLevelData> EventLevelScreenData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortActivatableVideoPanel> CinematicMovieWidgetInstance;

	UPROPERTY(Transient)
	FTimerHandle StreamedVideoOpeningTimer;

	UPROPERTY(EditDefaultsOnly, Category="ScreenFormat")
	bool bCollapseTopbar;

	UPROPERTY(EditDefaultsOnly, Category="ScreenFormat")
	bool bCollapseBottombar;

};

