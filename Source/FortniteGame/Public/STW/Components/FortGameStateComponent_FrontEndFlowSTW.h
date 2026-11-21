// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "Engine/DataTable.h"
#include "FortClientEventInterface.h"
#include "FortGameStateComponent_FrontEndFlowSTW.generated.h"

class AFortClientAnnouncement;
class UWorld;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_FrontEndFlowSTW : public UGameStateComponent, public IFortClientEventInterface
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_FrontEndFlowSTW(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	void OnSatelliteAnnouncementEnded(AFortClientAnnouncement* Announcement);

	UPROPERTY(EditDefaultsOnly, Category="Announcements")
	TSubclassOf<AFortClientAnnouncement> SatelliteCinematicAnnouncement;

	UPROPERTY(EditDefaultsOnly, Category="Worlds")
	TSoftObjectPtr<UWorld> CompositeWorld;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	FDataTableRowHandle OnboardingCompleteZoneStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	FDataTableRowHandle OnboardingWatchSatelliteCineStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="Stats")
	FDataTableRowHandle OnboardingNameHomebaseStatHandle;

};

